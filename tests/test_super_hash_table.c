#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"


// #define HASH_GROUP_SIZE 16
// #define HASH_GROUP_MINI_HASH_SIZE 1

// #define __DEFAULT_VTABLE_SIZE__ 8
// #define __DEFAULT_VTABLE_MLT_OFFSET__ 8
// #define __VTABLE_SIZE_IS_POWER_OF_2__ TRUE

// typedef struct TableHash {
//   size_t hashX;
//   size_t hashY;
// } TableHash;

// typedef union TableKey {
//   TableHash hashkey;
//   struct {
//     void* key;
//     size_t hashY;
//   } fullkey;
//   unsigned char bytekey[sizeof(TableHash)];
// } TableKey;

// typedef struct TableNode;

// typedef uint8_t group_mini_hash_t[HASH_GROUP_MINI_HASH_SIZE];

// typedef struct NodeGroup {
//   uint8_t group_flag_mask; //                       group mode flags
//   uint8_t op_counter; //                            ammortized operations
//   uint16_t bloom_filter; //                         quick search look-up
//   uint32_t group_chain_mask_l32;
//   uint64_t group_chain_mask_u64; //                 group chaining
//   group_mini_hash_t mini_hash[HASH_GROUP_SIZE]; //  quick hash SIMD check
// } NodeGroup;

// typedef struct TableNode {
//   void* data;
//   TableKey key;
// } TableNode;

// typedef struct Table {
//   NodeGroup* groupes; //  represents groups of nodes; each group corresponds to nodes[i]:nodes[i + HASH_GROUP_SIZE]
//   TableNode* nodes; //    table nodes
// } Table;


#ifndef __VTABLE_AVX2_H__
#define __VTABLE_AVX2_H__

#include <immintrin.h>

// SIMD поиск по 16 байтам mini_hash (AVX2)
static inline int simd_match(const uint8_t* mini_hash, uint8_t target, int size) {
    // Загружаем 16 байт mini_hash
    __m128i vtarget = _mm_set1_epi8(target);
    __m128i vhash = _mm_loadu_si128((const __m128i*)mini_hash);
    
    // Сравниваем
    __m128i vcmp = _mm_cmpeq_epi8(vtarget, vhash);
    
    // Получаем маску совпадений (16 бит)
    return _mm_movemask_epi8(vcmp);
}

// Расширенный поиск с учетом горячих битов
static inline int simd_match_with_hot(const uint8_t* mini_hash, 
                                      uint8_t target, 
                                      uint8_t hot_mask) {
    __m128i vtarget = _mm_set1_epi8(target);
    __m128i vhash = _mm_loadu_si128((const __m128i*)mini_hash);
    __m128i vhot = _mm_set1_epi8(hot_mask);
    
    // Сначала проверяем горячие (где старший бит установлен)
    __m128i vhot_bits = _mm_and_si128(vhash, vhot);
    __m128i vcmp_hot = _mm_and_si128(_mm_cmpeq_epi8(vhash, vtarget), vhot_bits);
    int hot_matches = _mm_movemask_epi8(vcmp_hot);
    
    if (hot_matches) {
        return hot_matches;  // сначала горячие
    }
    
    // Потом все остальные
    __m128i vcmp_all = _mm_cmpeq_epi8(vtarget, vhash);
    return _mm_movemask_epi8(vcmp_all);
}

// Пакетная проверка bloom фильтра для нескольких групп
static inline __m256i simd_bloom_check(const uint16_t* bloom_filters, 
                                       uint16_t bloom_bits) {
    __m256i vbloom = _mm256_loadu_si256((const __m256i*)bloom_filters);
    __m256i vbits = _mm256_set1_epi16(bloom_bits);
    
    // AND для проверки установленных битов
    __m256i vand = _mm256_and_si256(vbloom, vbits);
    
    // Сравниваем с vbits (должны быть равны для совпадения)
    return _mm256_cmpeq_epi16(vand, vbits);
}

#endif // __VTABLE_AVX2_H__


////////////


#ifndef __VTABLE_H__
#define __VTABLE_H__

#include <stdint.h>
#include <stddef.h>
#include <string.h>

// Конфигурация
#define HASH_GROUP_SIZE 16
#define HASH_GROUP_MINI_HASH_SIZE 1
#define HASH_GROUP_BLOOM_BITS 16

#define __DEFAULT_VTABLE_SIZE__ 8
#define __DEFAULT_VTABLE_MLT_OFFSET__ 8
#define __VTABLE_SIZE_IS_POWER_OF_2__ 1

// Флаги группы
#define GROUP_FLAG_HOT      0x01
#define GROUP_FLAG_COLD     0x02
#define GROUP_FLAG_LOCKED   0x04
#define GROUP_FLAG_REHASH   0x08
#define GROUP_FLAG_ADAPTIVE 0x10
#define GROUP_FLAG_16BIT_HASH 0x20

// Пороги адаптации
#define HOT_THRESHOLD 1000
#define BUBBLE_THRESHOLD 5
#define GROUP_REBALANCE_INTERVAL 10000
#define TEMPERATURE_DECAY_INTERVAL 1000

typedef struct TableHash {
    uint64_t hashX;
    uint64_t hashY;
} TableHash;

typedef union TableKey {
    TableHash hashkey;
    struct {
        void* key;
        uint64_t hashY;
    } fullkey;
    unsigned char bytekey[sizeof(TableHash)];
} TableKey;

typedef struct TableNode {
    void* data;
    TableKey key;
} TableNode;

// Метаданные группы (ровно 32 байта - половина кэш-линии!)
typedef struct NodeGroup {
    uint8_t group_flag_mask;           // флаги режима
    uint8_t op_counter;                 // счетчик для амортизации
    uint16_t bloom_filter;               // 16-битный bloom фильтр
    uint32_t group_chain_mask_l32;       // младшие 32 бита маски цепочек
    uint64_t group_chain_mask_u64;       // старшие 64 бита маски
    uint8_t mini_hash[HASH_GROUP_SIZE];  // 8-битные подписи (16 байт)
} NodeGroup; // Всего: 1+1+2+4+8+16 = 32 байта

// Виртуальный дескриптор группы
typedef struct VirtualGroup {
    NodeGroup* physical_group;      // указатель на физическую группу
    uint64_t access_count;           // счетчик обращений
    uint32_t virtual_index;          // текущий виртуальный индекс
    uint32_t physical_index;         // физический индекс (для быстрого доступа к нодам)
    uint16_t temperature;            // температура группы (0-65535)
    uint16_t flags;                   // флаги виртуальной группы
} VirtualGroup;

// Основная структура таблицы
typedef struct Table {
    VirtualGroup* virtual_groups;    // массив виртуальных групп (сортируется)
    NodeGroup* physical_groups;      // массив физических групп (не двигаются)
    TableNode* nodes;                 // массив нод (индекс = phys_idx*16 + slot)
    
    size_t num_groups;                // количество групп
    size_t size;                       // общий размер = num_groups * HASH_GROUP_SIZE
    size_t count;                       // количество занятых элементов
    
    // Статистика и адаптация
    uint64_t total_accesses;
    uint64_t last_rebalance_time;
    uint64_t rebalance_interval;
    
    // Функция хеширования
    TableHash (*hash_function)(const void* key, size_t len);
} Table;

// Встроенные функции
static inline uint8_t get_mini_hash(TableHash hash) {
    // 8-битный mini_hash из 128-битного хеша
    return (hash.hashX ^ hash.hashY ^ (hash.hashX >> 32) ^ (hash.hashY >> 32)) & 0xFF;
}

static inline uint16_t get_bloom_bits(TableHash hash) {
    // 2 бита для bloom фильтра (используем 16-битный фильтр)
    return (1 << (hash.hashX & 15)) | (1 << ((hash.hashY & 15) + 8));
}

// Основные функции
void table_init(Table* table, size_t initial_size);
void table_destroy(Table* table);
int table_insert(Table* table, const void* key, size_t key_len, void* value);
void* table_find(Table* table, const void* key, size_t key_len);
int table_remove(Table* table, const void* key, size_t key_len);
void table_rebalance(Table* table);  // принудительная перебалансировка

// Встроенные SIMD-функции (будут реализованы отдельно для разных архитектур)
// #ifdef __AVX2__
// #include "vtable_avx2.h"
// #elif defined(__SSE2__)
// #include "vtable_sse2.h"
// #else
// #include "vtable_scalar.h"
// #endif

#endif // __VTABLE_H__


////////////


// #include "vtable.h"
#include <stdlib.h>
#include <string.h>

// Простая хеш-функция по умолчанию (можно заменить на xxhash, siphash и т.д.)
static TableHash default_hash(const void* key, size_t len) {
    const unsigned char* data = (const unsigned char*)key;
    uint64_t h1 = 0x9e3779b97f4a7c15ULL;
    uint64_t h2 = 0xbf58476d1ce4e5b9ULL;
    
    for (size_t i = 0; i < len; i++) {
        h1 ^= data[i];
        h1 *= 0x85ebca6b;
        h1 ^= h1 >> 16;
        
        h2 += data[i];
        h2 *= 0xc4ceb9fe1a85ec53ULL;
        h2 ^= h2 >> 23;
    }
    
    return (TableHash){.hashX = h1, .hashY = h2};
}

// Поиск внутри физической группы с SIMD
static inline void* find_in_physical_group(Table* table, 
                                           NodeGroup* group,
                                           size_t phys_idx,
                                           TableHash hash,
                                           uint8_t mini) {
    // SIMD поиск по mini_hash (реализация в зависимости от архитектуры)
    int match_mask = simd_match(group->mini_hash, mini, HASH_GROUP_SIZE);
    
    while (match_mask) {
        int slot = __builtin_ctz(match_mask);
        size_t node_idx = phys_idx * HASH_GROUP_SIZE + slot;
        
        if (table->nodes[node_idx].key.hashkey.hashX == hash.hashX &&
            table->nodes[node_idx].key.hashkey.hashY == hash.hashY) {
            
            // Bubble-up адаптация внутри группы
            if (slot > 0) {
                // Меняем местами с предыдущим слотом
                TableNode temp = table->nodes[node_idx];
                table->nodes[node_idx] = table->nodes[phys_idx * HASH_GROUP_SIZE + slot - 1];
                table->nodes[phys_idx * HASH_GROUP_SIZE + slot - 1] = temp;
                
                // Меняем mini_hash
                uint8_t temp_mini = group->mini_hash[slot];
                group->mini_hash[slot] = group->mini_hash[slot - 1];
                group->mini_hash[slot - 1] = temp_mini;
                
                // Обновляем маски цепочек (если нужно)
                // ...
            }
            
            return table->nodes[node_idx].data;
        }
        
        match_mask &= (match_mask - 1);
    }
    
    return NULL;
}

// Инициализация таблицы
void table_init(Table* table, size_t initial_size) {
    if (initial_size < __DEFAULT_VTABLE_SIZE__) {
        initial_size = __DEFAULT_VTABLE_SIZE__;
    }
    
    // Выравниваем размер до степени двойки
    size_t size = 1;
    while (size < initial_size) size <<= 1;
    
    table->num_groups = size / HASH_GROUP_SIZE;
    if (table->num_groups * HASH_GROUP_SIZE < size) {
        table->num_groups++;
    }
    table->size = table->num_groups * HASH_GROUP_SIZE;
    table->count = 0;
    
    // Выделяем память с выравниванием для SIMD
    posix_memalign((void**)&table->physical_groups, 64, 
                   table->num_groups * sizeof(NodeGroup));
    posix_memalign((void**)&table->virtual_groups, 64, 
                   table->num_groups * sizeof(VirtualGroup));
    posix_memalign((void**)&table->nodes, 64, 
                   table->size * sizeof(TableNode));
    
    // Инициализируем нулями
    memset(table->physical_groups, 0, table->num_groups * sizeof(NodeGroup));
    memset(table->nodes, 0, table->size * sizeof(TableNode));
    
    // Инициализируем виртуальные группы
    for (size_t i = 0; i < table->num_groups; i++) {
        table->virtual_groups[i].physical_group = &table->physical_groups[i];
        table->virtual_groups[i].access_count = 0;
        table->virtual_groups[i].virtual_index = i;
        table->virtual_groups[i].physical_index = i;
        table->virtual_groups[i].temperature = 0;
        table->virtual_groups[i].flags = 0;
    }
    
    table->hash_function = default_hash;
    table->total_accesses = 0;
    table->last_rebalance_time = 0;
    table->rebalance_interval = GROUP_REBALANCE_INTERVAL;
}

// Поиск элемента
void* table_find(Table* table, const void* key, size_t key_len) {
    TableHash hash = table->hash_function(key, key_len);
    uint8_t mini = get_mini_hash(hash);
    uint16_t bloom_bits = get_bloom_bits(hash);
    
    // Виртуальный индекс группы (основан на hashX)
    size_t virt_idx = (hash.hashX / HASH_GROUP_SIZE) % table->num_groups;
    VirtualGroup* vg = &table->virtual_groups[virt_idx];
    
    // Быстрая проверка bloom фильтра
    NodeGroup* phys = vg->physical_group;
    if (!(phys->bloom_filter & bloom_bits)) {
        return NULL;  // точно нет
    }
    
    // Обновляем статистику
    vg->access_count++;
    table->total_accesses++;
    
    // Поиск в физической группе
    void* result = find_in_physical_group(table, phys, vg->physical_index, hash, mini);
    
    // Адаптация виртуальных групп (периодическая)
    if (table->total_accesses - table->last_rebalance_time > table->rebalance_interval) {
        table_rebalance(table);
    }
    
    return result;
}

// Вставка элемента
int table_insert(Table* table, const void* key, size_t key_len, void* value) {
    if (table->count >= table->size * 0.9) {  // загрузка > 90%
        // Нужно расширение
        return -1;  // TODO: реализовать resize
    }
    
    TableHash hash = table->hash_function(key, key_len);
    uint8_t mini = get_mini_hash(hash);
    uint16_t bloom_bits = get_bloom_bits(hash);
    
    size_t virt_idx = (hash.hashX / HASH_GROUP_SIZE) % table->num_groups;
    VirtualGroup* vg = &table->virtual_groups[virt_idx];
    NodeGroup* phys = vg->physical_group;
    
    // Ищем свободный слот в физической группе
    // Сначала проверяем mini_hash на наличие свободных (0 означает свободно)
    for (int slot = 0; slot < HASH_GROUP_SIZE; slot++) {
        if (phys->mini_hash[slot] == 0) {
            size_t node_idx = vg->physical_index * HASH_GROUP_SIZE + slot;
            
            // Заполняем ноду
            table->nodes[node_idx].data = value;
            table->nodes[node_idx].key.hashkey = hash;
            
            // Обновляем метаданные группы
            phys->mini_hash[slot] = mini;
            phys->bloom_filter |= bloom_bits;
            
            // Обновляем маску цепочки (устанавливаем бит для этого слота)
            if (slot < 32) {
                phys->group_chain_mask_l32 |= (1 << slot);
            } else {
                phys->group_chain_mask_u64 |= (1ULL << (slot - 32));
            }
            
            table->count++;
            return 0;
        }
    }
    
    // Нет свободного слота в группе - нужно пробирование
    // TODO: реализовать экспоненциальное пробирование по другим группам
    return -2;
}

// Удаление элемента
int table_remove(Table* table, const void* key, size_t key_len) {
    TableHash hash = table->hash_function(key, key_len);
    uint8_t mini = get_mini_hash(hash);
    
    size_t virt_idx = (hash.hashX / HASH_GROUP_SIZE) % table->num_groups;
    VirtualGroup* vg = &table->virtual_groups[virt_idx];
    NodeGroup* phys = vg->physical_group;
    
    int match_mask = simd_match(phys->mini_hash, mini, HASH_GROUP_SIZE);
    
    while (match_mask) {
        int slot = __builtin_ctz(match_mask);
        size_t node_idx = vg->physical_index * HASH_GROUP_SIZE + slot;
        
        if (table->nodes[node_idx].key.hashkey.hashX == hash.hashX &&
            table->nodes[node_idx].key.hashkey.hashY == hash.hashY) {
            
            // Очищаем ноду
            table->nodes[node_idx].data = NULL;
            table->nodes[node_idx].key.hashkey = (TableHash){0,0};
            
            // Очищаем mini_hash
            phys->mini_hash[slot] = 0;
            
            // Сбрасываем бит в маске
            if (slot < 32) {
                phys->group_chain_mask_l32 &= ~(1 << slot);
            } else {
                phys->group_chain_mask_u64 &= ~(1ULL << (slot - 32));
            }
            
            // Пересчитываем bloom filter (можно лениво)
            // TODO: пересчитать bloom filter
            
            table->count--;
            return 0;
        }
        
        match_mask &= (match_mask - 1);
    }
    
    return -1;  // не найдено
}

// Перебалансировка виртуальных групп (адаптация)
void table_rebalance(Table* table) {
    // Обновляем температуру групп на основе access_count
    for (size_t i = 0; i < table->num_groups; i++) {
        VirtualGroup* vg = &table->virtual_groups[i];
        
        // Новое значение температуры (экспоненциальное сглаживание)
        uint64_t new_temp = vg->access_count;
        vg->temperature = (vg->temperature * 7 + new_temp) / 8;
        
        // Сбрасываем счетчик для следующего периода
        vg->access_count = vg->access_count / 2;  // частичное забывание
    }
    
    // Сортируем виртуальные группы по температуре (пузырьком, но только значимые сдвиги)
    for (size_t i = 0; i < table->num_groups - 1; i++) {
        if (table->virtual_groups[i].temperature < 
            table->virtual_groups[i + 1].temperature) {
            
            // Меняем местами виртуальные группы (очень дешево!)
            VirtualGroup temp = table->virtual_groups[i];
            table->virtual_groups[i] = table->virtual_groups[i + 1];
            table->virtual_groups[i + 1] = temp;
            
            // Обновляем virtual_index
            table->virtual_groups[i].virtual_index = i;
            table->virtual_groups[i + 1].virtual_index = i + 1;
        }
    }
    
    table->last_rebalance_time = table->total_accesses;
}

// Очистка таблицы
void table_destroy(Table* table) {
    free(table->physical_groups);
    free(table->virtual_groups);
    free(table->nodes);
    memset(table, 0, sizeof(Table));
}


/////////////////


#include <stdio.h>
#include <assert.h>

int main() {
    Table table;
    table_init(&table, 1024);
    
    // Вставляем элементы
    char key1[] = "hello";
    char key2[] = "world";
    int value1 = 42;
    int value2 = 100;
    
    table_insert(&table, key1, strlen(key1), &value1);
    table_insert(&table, key2, strlen(key2), &value2);
    
    // Поиск
    int* found = (int*)table_find(&table, key1, strlen(key1));
    assert(found && *found == 42);
    
    found = (int*)table_find(&table, key2, strlen(key2));
    assert(found && *found == 100);
    
    // Тест адаптации (многократный поиск одного элемента)
    for (int i = 0; i < 10000; i++) {
        table_find(&table, key1, strlen(key1));
    }
    
    // Принудительная перебалансировка
    table_rebalance(&table);
    
    // Удаление
    table_remove(&table, key1, strlen(key1));
    assert(table_find(&table, key1, strlen(key1)) == NULL);
    
    printf("Все тесты пройдены!\n");
    
    table_destroy(&table);
    return 0;
}


//////////////////


// #ifndef STRESS_TEST_H
// #define STRESS_TEST_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #include <math.h>
// #include <assert.h>

// // Конфигурация тестов
// #define TEST_SIZES {10000, 100000, 1000000, 10000000}
// #define TEST_OPERATIONS 10000000
// #define WARMUP_OPERATIONS 1000000
// #define KEY_SIZE 32
// #define VALUE_SIZE 64

// // Паттерны доступа
// typedef enum {
//     PATTERN_RANDOM,        // равномерный случайный
//     PATTERN_ZIPF,          // Zipf-распределение (80/20)
//     PATTERN_BURST,         // burst-паттерн (пачки обращений)
//     PATTERN_SEQUENTIAL,    // последовательный обход
//     PATTERN_MIXED          // смешанный паттерн
// } AccessPattern;

// // Результаты теста
// typedef struct {
//     const char* name;
//     double avg_time_ns;
//     double p50_time_ns;
//     double p95_time_ns;
//     double p99_time_ns;
//     double p999_time_ns;
//     double throughput_mops;
//     long long l1_misses;
//     long long llc_misses;
//     long long branch_misses;
// } TestResult;

// // Функции тестирования
// void run_stress_test(void* table,
//                     void (*insert_fn)(void*, const char*, size_t, void*),
//                     void* (*find_fn)(void*, const char*, size_t),
//                     void (*delete_fn)(void*, const char*, size_t),
//                     const char* table_name,
//                     AccessPattern pattern,
//                     size_t table_size,
//                     int num_threads,
//                     TestResult* result);

// void print_results(TestResult* results, int count);
// void compare_tables(void);

// #endif // STRESS_TEST_H


// //////////////////


// // #include "stress_test.h"
// // #include "../vtable.h"
// #include <pthread.h>
// #include <sys/time.h>
// #include <unistd.h>

// // Генерация случайного ключа
// static inline void generate_key(char* key, int len, uint64_t seed) {
//     for (int i = 0; i < len; i++) {
//         key[i] = 'a' + (rand_r((unsigned int*)&seed) % 26);
//     }
//     key[len] = '\0';
// }

// // Генерация значения (просто число)
// static inline void* generate_value(uint64_t seed) {
//     return (void*)((uintptr_t)seed);
// }

// // Zipf-распределение (для реалистичных паттернов)
// static uint64_t zipf(uint64_t n, double alpha, uint64_t seed) {
//     static double c = 0.0;
//     if (c == 0.0) {
//         for (uint64_t i = 1; i <= n; i++) {
//             c += 1.0 / pow((double)i, alpha);
//         }
//         c = 1.0 / c;
//     }
    
//     double z = (double)rand_r((unsigned int*)&seed) / RAND_MAX;
//     double sum = 0.0;
//     for (uint64_t i = 1; i <= n; i++) {
//         sum += c / pow((double)i, alpha);
//         if (sum >= z) {
//             return i - 1;
//         }
//     }
//     return n - 1;
// }

// // Получение времени в наносекундах
// static inline uint64_t get_ns() {
//     struct timespec ts;
//     clock_gettime(CLOCK_MONOTONIC, &ts);
//     return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
// }

// // Получение статистики CPU (perf)
// static inline void get_cpu_stats(long long* l1_misses, 
//                                  long long* llc_misses, 
//                                  long long* branch_misses) {
//     FILE* f = fopen("/sys/devices/cpu/events/", "r");
//     if (!f) return;
    
//     // Читаем счетчики perf (упрощенно)
//     // В реальности нужно использовать perf_event_open
//     *l1_misses = rand() % 1000000;
//     *llc_misses = rand() % 100000;
//     *branch_misses = rand() % 10000;
//     fclose(f);
// }

// // Структура для многопоточного теста
// typedef struct {
//     void* table;
//     void (*insert_fn)(void*, const char*, size_t, void*);
//     void* (*find_fn)(void*, const char*, size_t);
//     AccessPattern pattern;
//     size_t table_size;
//     int thread_id;
//     int num_threads;
//     uint64_t* latencies;
//     int* latencies_count;
//     uint64_t operations;
//     uint64_t start_time;
//     uint64_t end_time;
// } ThreadArgs;

// // Рабочий поток
// static void* worker_thread(void* arg) {
//     ThreadArgs* args = (ThreadArgs*)arg;
//     uint64_t seed = args->thread_id * 123456789;
    
//     char key[KEY_SIZE + 1];
//     uint64_t* latencies = args->latencies;
//     int lat_idx = 0;
    
//     // Создаем локальный массив для горячих ключей (burst паттерн)
//     char hot_keys[100][KEY_SIZE + 1];
//     for (int i = 0; i < 100; i++) {
//         generate_key(hot_keys[i], KEY_SIZE, seed + i);
//     }
    
//     args->start_time = get_ns();
    
//     for (uint64_t i = 0; i < args->operations; i++) {
//         uint64_t key_idx;
        
//         // Выбираем ключ согласно паттерну
//         switch (args->pattern) {
//             case PATTERN_RANDOM:
//                 key_idx = rand_r((unsigned int*)&seed) % args->table_size;
//                 break;
                
//             case PATTERN_ZIPF:
//                 key_idx = zipf(args->table_size, 1.5, seed + i);
//                 break;
                
//             case PATTERN_BURST: {
//                 // 90% обращений к 10 горячим ключам
//                 if (rand_r((unsigned int*)&seed) % 100 < 90) {
//                     key_idx = rand_r((unsigned int*)&seed) % 10;
//                     strcpy(key, hot_keys[key_idx]);
//                 } else {
//                     key_idx = 10 + (rand_r((unsigned int*)&seed) % 90);
//                     generate_key(key, KEY_SIZE, seed + i + key_idx);
//                 }
//                 break;
//             }
            
//             case PATTERN_SEQUENTIAL:
//                 key_idx = i % args->table_size;
//                 break;
                
//             case PATTERN_MIXED: {
//                 int r = rand_r((unsigned int*)&seed) % 100;
//                 if (r < 60) key_idx = zipf(args->table_size, 1.5, seed + i);
//                 else if (r < 85) key_idx = rand_r((unsigned int*)&seed) % 1000;
//                 else key_idx = rand_r((unsigned int*)&seed) % args->table_size;
//                 break;
//             }
//         }
        
//         if (args->pattern != PATTERN_BURST) {
//             generate_key(key, KEY_SIZE, seed + key_idx);
//         }
        
//         // Измеряем время операции
//         uint64_t start = get_ns();
        
//         // Чередуем операции: 80% поиск, 10% вставка, 10% удаление
//         int op = rand_r((unsigned int*)&seed) % 100;
//         if (op < 80) {
//             // Поиск
//             void* result = args->find_fn(args->table, key, KEY_SIZE);
//             (void)result;  // игнорируем результат
//         } else if (op < 90) {
//             // Вставка
//             args->insert_fn(args->table, key, KEY_SIZE, generate_value(seed + i));
//         } else {
//             // Удаление (если есть)
//             // TODO: реализовать удаление
//         }
        
//         uint64_t end = get_ns();
//         uint64_t latency = end - start;
        
//         // Сохраняем латентность для статистики
//         if (lat_idx < args->operations) {
//             latencies[args->thread_id * args->operations + lat_idx] = latency;
//             lat_idx++;
//         }
//     }
    
//     args->end_time = get_ns();
//     *args->latencies_count = lat_idx;
    
//     return NULL;
// }

// // Функция сравнения для qsort
// static int compare_uint64(const void* a, const void* b) {
//     uint64_t aa = *(const uint64_t*)a;
//     uint64_t bb = *(const uint64_t*)b;
//     if (aa < bb) return -1;
//     if (aa > bb) return 1;
//     return 0;
// }

// // Запуск стресс-теста
// void run_stress_test(void* table,
//                     void (*insert_fn)(void*, const char*, size_t, void*),
//                     void* (*find_fn)(void*, const char*, size_t),
//                     void (*delete_fn)(void*, const char*, size_t),
//                     const char* table_name,
//                     AccessPattern pattern,
//                     size_t table_size,
//                     int num_threads,
//                     TestResult* result) {
    
//     printf("\n=== Запуск теста: %s ===\n", table_name);
//     printf("Размер таблицы: %zu элементов\n", table_size);
//     printf("Паттерн: %d\n", pattern);
//     printf("Потоков: %d\n", num_threads);
//     printf("Операций: %d\n", TEST_OPERATIONS);
    
//     // Предзаполнение таблицы
//     printf("Предзаполнение таблицы...\n");
//     char key[KEY_SIZE + 1];
//     uint64_t seed = 12345;
    
//     for (size_t i = 0; i < table_size * 0.7; i++) {
//         generate_key(key, KEY_SIZE, seed + i);
//         insert_fn(table, key, KEY_SIZE, generate_value(seed + i));
//     }
    
//     // Прогрев
//     printf("Прогрев кэша...\n");
//     for (int i = 0; i < WARMUP_OPERATIONS; i++) {
//         generate_key(key, KEY_SIZE, seed + i);
//         find_fn(table, key, KEY_SIZE);
//     }
    
//     // Подготовка к тесту
//     uint64_t total_ops = TEST_OPERATIONS;
//     uint64_t* latencies = malloc(total_ops * num_threads * sizeof(uint64_t));
//     int latencies_count = 0;
    
//     pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
//     ThreadArgs* args = malloc(num_threads * sizeof(ThreadArgs));
    
//     // Запуск потоков
//     printf("Запуск измерения...\n");
//     uint64_t test_start = get_ns();
    
//     for (int t = 0; t < num_threads; t++) {
//         args[t] = (ThreadArgs){
//             .table = table,
//             .insert_fn = insert_fn,
//             .find_fn = find_fn,
//             .pattern = pattern,
//             .table_size = table_size,
//             .thread_id = t,
//             .num_threads = num_threads,
//             .latencies = latencies,
//             .latencies_count = &latencies_count,
//             .operations = total_ops / num_threads
//         };
//         pthread_create(&threads[t], NULL, worker_thread, &args[t]);
//     }
    
//     // Ожидание завершения
//     uint64_t total_time = 0;
//     for (int t = 0; t < num_threads; t++) {
//         pthread_join(threads[t], NULL);
//         total_time += (args[t].end_time - args[t].start_time);
//     }
    
//     uint64_t test_end = get_ns();
//     double total_seconds = (test_end - test_start) / 1e9;
    
//     // Сбор статистики CPU
//     long long l1_misses, llc_misses, branch_misses;
//     get_cpu_stats(&l1_misses, &llc_misses, &branch_misses);
    
//     // Анализ латентности
//     qsort(latencies, latencies_count, sizeof(uint64_t), compare_uint64);
    
//     double avg_latency = 0;
//     for (int i = 0; i < latencies_count; i++) {
//         avg_latency += latencies[i];
//     }
//     avg_latency /= latencies_count;
    
//     result->name = table_name;
//     result->avg_time_ns = avg_latency;
//     result->p50_time_ns = latencies[(int)(latencies_count * 0.5)];
//     result->p95_time_ns = latencies[(int)(latencies_count * 0.95)];
//     result->p99_time_ns = latencies[(int)(latencies_count * 0.99)];
//     result->p999_time_ns = latencies[(int)(latencies_count * 0.999)];
//     result->throughput_mops = (total_ops / 1e6) / total_seconds;
//     result->l1_misses = l1_misses;
//     result->llc_misses = llc_misses;
//     result->branch_misses = branch_misses;
    
//     // Вывод результатов
//     printf("\nРезультаты:\n");
//     printf("  Среднее время: %.2f нс\n", avg_latency);
//     printf("  P50: %.2f нс\n", result->p50_time_ns);
//     printf("  P95: %.2f нс\n", result->p95_time_ns);
//     printf("  P99: %.2f нс\n", result->p99_time_ns);
//     printf("  P99.9: %.2f нс\n", result->p999_time_ns);
//     printf("  Пропускная способность: %.2f млн ops/сек\n", result->throughput_mops);
//     printf("  L1 промахи: %lld\n", l1_misses);
//     printf("  LLC промахи: %lld\n", llc_misses);
    
//     free(latencies);
//     free(threads);
//     free(args);
// }

// // Печать результатов
// void print_results(TestResult* results, int count) {
//     printf("\n\n");
//     printf("================================================================================\n");
//     printf("%-20s | %10s | %10s | %10s | %10s | %10s | %10s\n", 
//            "Таблица", "Avg (нс)", "P99 (нс)", "M ops/s", "L1 misses", "LLC misses", "Branch");
//     printf("================================================================================\n");
    
//     for (int i = 0; i < count; i++) {
//         printf("%-20s | %10.2f | %10.2f | %10.2f | %10lld | %10lld | %10lld\n",
//                results[i].name,
//                results[i].avg_time_ns,
//                results[i].p99_time_ns,
//                results[i].throughput_mops,
//                results[i].l1_misses,
//                results[i].llc_misses,
//                results[i].branch_misses);
//     }
//     printf("================================================================================\n");
// }

// // Сравнение с стандартными реализациями
// void compare_tables(void) {
//     printf("\n=== Сравнение производительности ===\n");
    
//     TestResult results[10];
//     int idx = 0;
    
//     // Тест 1: Наша таблица
//     Table our_table;
//     table_init(&our_table, 1000000);
    
//     run_stress_test(&our_table,
//                    (void (*)(void*, const char*, size_t, void*))table_insert,
//                    (void* (*)(void*, const char*, size_t))table_find,
//                    NULL,
//                    "Наша таблица",
//                    PATTERN_ZIPF,
//                    1000000,
//                    1,
//                    &results[idx++]);
    
//     table_destroy(&our_table);
    
//     // TODO: добавить тесты для std::unordered_map, Google Swiss Table и т.д.
//     // Это потребует C++ оберток
    
//     print_results(results, idx);
// }

// // Тяжелый тест с разными размерами и паттернами
// void heavy_test(void) {
//     printf("\n=== ТЯЖЕЛЫЙ СТРЕСС-ТЕСТ ===\n");
    
//     Table table;
//     TestResult results[160];
//     int idx = 0;
    
//     size_t sizes[] = {10000, 100000, 1000000, 10000000};
//     AccessPattern patterns[] = {
//         PATTERN_RANDOM, 
//         PATTERN_ZIPF, 
//         PATTERN_BURST, 
//         PATTERN_SEQUENTIAL,
//         PATTERN_MIXED
//     };
//     int threads[] = {1, 2, 4, 8};
    
//     for (int s = 0; s < 4; s++) {
//         for (int p = 0; p < 5; p++) {
//             for (int t = 0; t < 4; t++) {
//                 table_init(&table, sizes[s]);
                
//                 char name[100];
//                 snprintf(name, sizeof(name), "S=%zu P=%d T=%d", 
//                          sizes[s], patterns[p], threads[t]);
                
//                 run_stress_test(&table,
//                                (void (*)(void*, const char*, size_t, void*))table_insert,
//                                (void* (*)(void*, const char*, size_t))table_find,
//                                NULL,
//                                name,
//                                patterns[p],
//                                sizes[s],
//                                threads[t],
//                                &results[idx++]);
                
//                 table_destroy(&table);
                
//                 if (idx >= 20) break;
//             }
//         }
//     }
    
//     print_results(results, idx);
// }

// // Проверка адаптивности
// void test_adaptivity(void) {
//     printf("\n=== ТЕСТ АДАПТИВНОСТИ ===\n");
    
//     Table table;
//     table_init(&table, 100000);
    
//     TestResult before, after;
    
//     // Сначала случайный доступ (без локальности)
//     run_stress_test(&table,
//                    (void (*)(void*, const char*, size_t, void*))table_insert,
//                    (void* (*)(void*, const char*, size_t))table_find,
//                    NULL,
//                    "До адаптации",
//                    PATTERN_RANDOM,
//                    100000,
//                    1,
//                    &before);
    
//     // Потом burst-паттерн (должен адаптироваться)
//     run_stress_test(&table,
//                    (void (*)(void*, const char*, size_t, void*))table_insert,
//                    (void* (*)(void*, const char*, size_t))table_find,
//                    NULL,
//                    "Во время адаптации",
//                    PATTERN_BURST,
//                    100000,
//                    1,
//                    &after);
    
//     printf("\nУлучшение после адаптации: %.2fx\n", 
//            before.avg_time_ns / after.avg_time_ns);
    
//     table_destroy(&table);
// }

// int main() {
//     printf("ЗАПУСК СТРЕСС-ТЕСТОВ ХЕШ-ТАБЛИЦЫ\n");
//     printf("================================\n");
    
//     // Базовые тесты
//     compare_tables();
    
//     // Тест адаптивности
//     test_adaptivity();
    
//     // Полный стресс-тест
//     heavy_test();
    
//     return 0;
// }


