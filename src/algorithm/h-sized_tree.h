#include "../memory/dyn_alloc_.h"


typedef struct __H_SIZED_TREE_NODE__ {
  void** values;
  size_t size;
  size_t capacity;
} __H_SIZED_TREE_NODE__;

typedef struct __H_SIZED_TREE__ {
  __H_SIZED_TREE_NODE__* root;
  size_t depth;
} __H_SIZED_TREE__;

size_t __defer_tree_init__(__H_SIZED_TREE__* tree);
size_t __defer_tree_destroy__(__H_SIZED_TREE__* tree);
size_t __defer_tree_add__(__H_SIZED_TREE__* tree, void* instance);
void* __defer_tree_find_node__(__H_SIZED_TREE__* tree, void* instance);
size_t __defer_tree_find__(__H_SIZED_TREE__* tree, void* instance);
size_t __defer_tree_remove__(__H_SIZED_TREE__* tree);