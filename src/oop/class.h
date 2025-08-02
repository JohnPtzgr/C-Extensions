#include "../memory/dyn_alloc.h"

typedef struct ClassObject ClassObject;

typedef struct InheritanceListNode
{
  ClassObject* class_object;
  void* class_start;
  void* class_end;
  struct InheritanceListNode* next;
} InheritanceListNode;


typedef struct InheritanceList
{
  struct InheritanceListNode* head;
} InheritanceList;


typedef struct ClassObject
{
  size_t size;

  method_function_t* methods;
  size_t method_count;
  
  size_t mask;
  size_t instance_count;
  void* last_instance;
  InheritanceList inherits_from;
  size_t inherit_count;
} ClassObject;

