#include "../src/oop/classes.h"
#include "../src/oop/templates.h"

CLASS(__TEMPLATE_VA(cls_t),
  __T_ARG_A__ a;
  __T_ARG_B__ b,
  2
)
CLASS_END(__TEMPLATE_VA(cls_t), 2,
  self->a = 1;
  self->b = 10;
  DefaultObject a;
  INIT(DefaultObject, &a);
) {
  self->a = 0;
  self->b = 0;
}

#include "../src/oop/templates_undef.h"
