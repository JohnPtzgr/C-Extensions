#include "../src/oop/classes.h"
#include "../src/oop/templates.h"

CLASS(__TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, cls_t),
  __T_ARG_A__ a;
  __T_ARG_B__ b,
  2
)
CLASS_END(__TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, cls_t),
  self->a = 1;
  self->b = 10;
) DEFAULT_DESTROY

#include "../src/oop/templates_undef.h"
