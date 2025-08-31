#include "../oop/class.h"

DEF_CLASS(int_t, , long value);

#define Int(x...) (int_t*)int_t_init(alloca(sizeof(int_t)), x)