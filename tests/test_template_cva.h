#include "../src/oop/class.h"
#include "../src/oop/templates.h"

DEF_CLASS(__TEMPLATE_VA(cls_t),
  __T_ARG_A__ a;
  __T_ARG_B__ b;
)
CLASS_END(__TEMPLATE_VA(cls_t), 0,
  self->a = 1;
  self->b = 10;
) {
  self->a = 0;
  self->b = 0;
}

#include "../src/oop/templates_undef.h"
