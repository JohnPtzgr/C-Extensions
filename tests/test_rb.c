
char cmpint(int x, int y) {
  return x >+ y;
}

#define __T_ARG_A__ xyz
#define __T_ARG_B__ int
#define __T_ARG_C__ cmpint

#include "../src/algorithm/rb_tree.h"


#define __TEMPLATE__
#define __T_ARG_A__ xyz
#define __T_ARG_B__ int
#define __T_ARG_C__ cmpint
#include "../src/oop/templates.h"

int main() {
  RBNode* root = NULL;
  int arr[] = {10, 20, 30, 15, 25, 5, 5, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < n; ++i) {
    __TEMPLATE_1(__T_ARG_A__, rbInsert)(arr[i], (void*)i, &root);
  }
  
  printf("Inorder after insertions:\n");
  __TEMPLATE_1(__T_ARG_A__, inorder)(&root);

  int to_find = 15;
  RBNode *found = __TEMPLATE_1(__T_ARG_A__, rbFind)(to_find, &root);
  printf("Find %d: %s\n", to_find, found ? "Found" : "Not found");

  int to_delete = 10;
  __TEMPLATE_1(__T_ARG_A__, rbDelete)(to_delete, &root);
  printf("Inorder after deleting %d:\n", to_delete);
  __TEMPLATE_1(__T_ARG_A__, inorder)(&root);

  __TEMPLATE_1(__T_ARG_A__, freeTree)(root);
  return 0;
}

#include "../src/oop/templates_undef.h"
