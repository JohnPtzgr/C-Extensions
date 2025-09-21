#include "functional.h"

void* callable_method_call(callable_t* self, ...) {
  __M_VA_ARG__(16);
  switch (__ARG_CNT__) {
    case 0:
      return self->func_ptr(0);
    case 1:
      return self->func_ptr(__ARG_LIST__[0], 0);
    case 2:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], 0);
    case 3:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], 0);
    case 4:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], 0);
    case 5:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], 0);
    case 6:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], 0);
    case 7:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], 0);
    case 8:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], 0);
    case 9:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], 0);
    case 10:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], 0);
    case 11:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], 0);
    case 12:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], 0);
    case 13:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], 0);
    case 14:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], 0);
    case 15:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], \
        __ARG_LIST__[14], 0);
    case 16:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], \
        __ARG_LIST__[14], __ARG_LIST__[15], 0);
    
    default:
      return NULL;
  }
}

__AUX_CLASS_END_CLASS_OBJ__(callable_t, STATIC)
__AUX_CLASS_END_V_CLASS_OBJ__(callable_t, STATIC,
  .__call__ = (generic_function_t)callable_method_call
)
__AUX_CLASS_END_INSTANCE__(callable_t, STATIC)
__AUX_CLASS_END_META__(callable_t, STATIC)
__AUX_CLASS_END_SEP__(callable_t, STATIC)
DEFAULT_DESTROY(callable_t)

void* callable_t_init(callable_t* self, ...) {
  __AUX_INIT_BEGIN__(callable_t);
  __M_VA_ARG__(1, 0);
  self->func_ptr = __ARG_LIST__[0];
  __AUX_INIT_END__(callable_t);
}


void* lambda_method_call(lambda_t* self, ...) {
  __M_VA_ARG__(16);
  switch (__ARG_CNT__) {
    case 0:
      return self->func_ptr(self->capture, 0);
    case 1:
      return self->func_ptr(self->capture, __ARG_LIST__[0], 0);
    case 2:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], 0);
    case 3:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], 0);
    case 4:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], 0);
    case 5:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], 0);
    case 6:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], 0);
    case 7:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], 0);
    case 8:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], 0);
    case 9:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], 0);
    case 10:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], 0);
    case 11:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], 0);
    case 12:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], 0);
    case 13:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], 0);
    case 14:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], 0);
    case 15:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], \
        __ARG_LIST__[14], 0);
    case 16:
      return self->func_ptr(self->capture, __ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], \
        __ARG_LIST__[14], __ARG_LIST__[15], 0);
    
    default:
      return NULL;
  }
}

void* lambda_set_capture(lambda_t* self, lambda_capture_t* capture) {
  self->capture = capture;
  return self;
}


__AUX_CLASS_END_CLASS_OBJ__(lambda_t, STATIC)
__AUX_CLASS_END_V_CLASS_OBJ__(lambda_t, STATIC,
  .__call__ = (generic_function_t)lambda_method_call,
  .__set__ = (generic_function_t)lambda_set_capture
)
__AUX_CLASS_END_INSTANCE__(lambda_t, STATIC)
__AUX_CLASS_END_META__(lambda_t, STATIC)
__AUX_CLASS_END_SEP__(lambda_t, STATIC)
DEFAULT_DESTROY(lambda_t)

void* lambda_t_init(lambda_t* self, ...) {
  __AUX_INIT_BEGIN__(lambda_t);
  __M_VA_ARG__(2, 0, 0);
  self->func_ptr = __ARG_LIST__[0];
  self->capture = __ARG_LIST__[1];
  __AUX_INIT_END__(lambda_t);
}
