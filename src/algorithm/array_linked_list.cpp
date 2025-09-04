#include <stdlib.h>
#include <cstring>
#include <iostream>

template <typename T>
class ArrayLinkedList {
 public:
  T* data;
  size_t size;
  size_t capacity;
  size_t head;
  size_t* prev;
  size_t* next;
  size_t* stack;
  ArrayLinkedList(size_t capacity = 4) {
    size = 0;
    this->capacity = capacity;
    data = (T*)malloc(capacity * sizeof(T));
    prev = (size_t*)malloc(capacity * sizeof(size_t));
    next = (size_t*)malloc(capacity * sizeof(size_t));
    stack = (size_t*)malloc(capacity * sizeof(size_t));
    for (size_t i = 0; i < capacity; ++i) {
      stack[i] = i - 1;
    }
    head = -1;
    for (size_t i = 0; i < capacity; ++i) {
      std::cout << stack[i] << "\n";
    }
    std::cout << "X:\n";
  }
  size_t StackHead() {
    return capacity - size - 1;
  }
  void PushStack(size_t node_index) {
    size_t stack_head = 1 + StackHead();
    stack[stack_head] = node_index;
    size--;
  }
  void PopStack() {
    size++;
  }
  void Expand() {
    T* data_new = (T*)malloc(capacity * sizeof(T) * 2);
    size_t* prev_new = (size_t*)malloc(capacity * sizeof(size_t) * 2);
    size_t* next_new = (size_t*)malloc(capacity * sizeof(size_t) * 2);
    size_t* stack_new = (size_t*)malloc(capacity * sizeof(size_t) * 2);
    memcpy(data_new, data, capacity * sizeof(T));
    memcpy(prev_new, prev, capacity * sizeof(size_t));
    memcpy(next_new, next, capacity * sizeof(size_t));
    memcpy(stack_new, stack, capacity * sizeof(size_t));
    std::cout << "\n\n\t"<< StackHead() <<"\n";
    for (size_t i = 0; i < capacity; ++i) {
      stack[StackHead() + i] = capacity + i - 1;
    }
    capacity = capacity * 2;
    for (size_t i = 0; i < capacity; ++i) {
      std::cout << stack[i] << "\n";
    }
    std::cout << "X:\n";
    free(data);
    free(next);
    free(prev);
    free(stack);
    data = data_new;
    next = next_new;
    prev = prev_new;
    stack = stack_new;
  }
  void Shrink() {
    T* data_new = (T*)malloc(capacity * sizeof(T) / 2);
    size_t* prev_new = (size_t*)malloc(capacity * sizeof(size_t) / 2);
    size_t* next_new = (size_t*)malloc(capacity * sizeof(size_t) / 2);
    size_t* stack_new = (size_t*)malloc(capacity * sizeof(size_t) / 2);
    memcpy(data_new, data, capacity * sizeof(T) / 2);
    memcpy(prev_new, prev, capacity * sizeof(size_t) / 2);
    memcpy(next_new, next, capacity * sizeof(size_t) / 2);
    memcpy(stack_new, stack, capacity * sizeof(size_t) / 2);
    capacity = capacity / 2;
    free(data);
    free(next);
    free(prev);
    free(stack);
    data = data_new;
    next = next_new;
    prev = prev_new;
    stack = stack_new;
  }
  size_t Alloc() {
    if (size + 1 == capacity) {
      Expand();
    }
    size_t new_node = stack[StackHead()];
  }
  void PushBack(size_t node_index, const T& value) {
    if (size + 1 == capacity) {
      Expand();
    }
    size_t new_node = stack[StackHead()];
    PopStack();
    if (node_index != -1) {
      size_t next_node = next[node_index];
      next[new_node] = next_node;
      prev[new_node] = node_index;
      next[node_index] = new_node;
      prev[next_node] = new_node;
    } else {
      next[new_node] = new_node;
      prev[new_node] = new_node;
      head = new_node;
    }
    if (next[node_index] == head && node_index != head) {
      head = new_node;
    }
    data[new_node] = value;
  }
  void PushFront(size_t node_index, const T& value) {
    if (size + 1 == capacity) {
      Expand();
    }
    std::cout << StackHead() << "\n";
    size_t new_node = stack[StackHead()];
    PopStack();
    if (node_index != -1) {
      size_t prev_node = prev[node_index];
      next[new_node] = node_index;
      prev[new_node] = prev_node;
      prev[node_index] = new_node;
      next[prev_node] = new_node;
    } else {
      next[new_node] = new_node;
      prev[new_node] = new_node;
      head = new_node;
    }
    if (node_index == head) {
      head = new_node;
    }
    data[new_node] = value;
  }
  void Pop(size_t node_index) {
    if (size - 1 == capacity / 4) {
      Shrink();
    }
    prev[next[node_index]] = prev[node_index];
    next[prev[node_index]] = next[node_index];
    PushStack(node_index);
    if (node_index == head) {
      head = next[node_index];
    }
  }
  ~ArrayLinkedList() {
    std::cout << "destroy!\n\n";
    size_t node = head;
    for (size_t i = 0; i < size; ++i) {
      std::cout << data[node] << "\n";
      node = next[node];
    }
    free(data);
    free(next);
    free(prev);
    free(stack);
  }
};


int main() {
  ArrayLinkedList<int> q;
  q.PushFront(-1, 9);
  q.PushFront(q.head, 89);
  q.PushFront(q.head, 189);
  q.PushFront(q.head, 289);
  q.PushFront(q.head, 389);
  q.PushFront(q.head, 89);
  q.PushFront(q.head, 189);
  q.PushFront(q.head, 289);
  q.PushFront(q.head, 1389);
  q.PushFront(q.head, 89);
  q.PushFront(q.head, 189);
  q.PushFront(q.head, 289);
  q.PushFront(q.head, 2389);
  q.PushFront(q.head, 89);
  q.PushFront(q.head, 189);
  q.PushFront(q.head, 289);
  q.PushFront(q.head, 3389);
  q.PushFront(q.head, 89);
  q.PushFront(q.head, 189);
  q.PushFront(q.head, 289);
  q.PushFront(q.head, 4389);
  std::cout << q.data[q.head] << "\n";
  return 0;
} 
 