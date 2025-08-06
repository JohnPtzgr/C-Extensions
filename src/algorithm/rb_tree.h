#include <stdio.h>
#include <stdlib.h>
#define __TEMPLATE__
#ifndef __T_ARG_A__
#define __T_ARG_A__
#endif
#ifndef __T_ARG_B__
#define __T_ARG_B__ int
#endif
#ifndef __T_ARG_C__
#define __DEFAULT_KEY_COMPARE__
#endif
#include "../oop/templates.h"


#ifdef __DEFAULT_KEY_COMPARE__
char __TEMPLATE_1(__T_ARG_A__, defaultKeyCompare)(__T_ARG_B__ keyA, __T_ARG_B__ keyB) {
  return keyA < keyB;
}

#undef __T_ARG_C__
#define __T_ARG_C__ __TEMPLATE_1(__T_ARG_A__, defaultKeyCompare)
#endif

char __TEMPLATE_2(__T_ARG_A__, __T_ARG_C__, areKeysEqual)(__T_ARG_B__ keyA, __T_ARG_B__ keyB) {
  return !(__T_ARG_C__(keyA, keyB) || __T_ARG_C__(keyB, keyA));
}


typedef enum { __RB_TREE_RED__, __RB_TREE_BLACK__ } __RB_TREE_COLOR_T__;

typedef struct RBNode {
  __T_ARG_B__ key;
  void* data;
  __RB_TREE_COLOR_T__ color;
  struct RBNode* left, *right, *parent;
} RBNode;

RBNode* __TEMPLATE_1(__T_ARG_A__, createNode)(__T_ARG_B__ key, void* data) {
  RBNode* node = (RBNode*)malloc(sizeof(RBNode));
  node->key = key;
  node->data = data;
  node->color = __RB_TREE_RED__;
  node->left = node->right = node->parent = NULL;
  return node;
}

void __TEMPLATE_1(__T_ARG_A__, leftRotate)(RBNode **root, RBNode *x) {
  RBNode* y = x->right;
  x->right = y->left;
  if (y->left) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (!x->parent) {
    *root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void __TEMPLATE_1(__T_ARG_A__, rightRotate)(RBNode **root, RBNode *y) {
  RBNode *x = y->left;
  y->left = x->right;
  if (x->right) {
    x->right->parent = y;
  }
  x->parent = y->parent;
  if (!y->parent) {
    *root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }
  x->right = y;
  y->parent = x;
}

void __TEMPLATE_1(__T_ARG_A__, insertFixup)(RBNode **root, RBNode *z) {
  while (z->parent && z->parent->color == __RB_TREE_RED__) {
    if (z->parent == z->parent->parent->left) {
      RBNode *y = z->parent->parent->right;
      if (y && y->color == __RB_TREE_RED__) {
        z->parent->color = __RB_TREE_BLACK__;
        y->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          __TEMPLATE_1(__T_ARG_A__, leftRotate)(root, z);
        }
        z->parent->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        __TEMPLATE_1(__T_ARG_A__, rightRotate)(root, z->parent->parent);
      }
    } else {
      RBNode *y = z->parent->parent->left;
      if (y && y->color == __RB_TREE_RED__) {
        z->parent->color = __RB_TREE_BLACK__;
        y->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          __TEMPLATE_1(__T_ARG_A__, rightRotate)(root, z);
        }
        z->parent->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        __TEMPLATE_1(__T_ARG_A__, leftRotate)(root, z->parent->parent);
      }
    }
  }
  (*root)->color = __RB_TREE_BLACK__;
}

void __TEMPLATE_1(__T_ARG_A__, rbInsert)(__T_ARG_B__ key, void* data, RBNode** root) {
  RBNode *z = __TEMPLATE_1(__T_ARG_A__, createNode)(key, data);
  RBNode *y = NULL;
  RBNode *x = *root;

  while (x) {
    y = x;
    if (__T_ARG_C__(z->key, x->key)) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (!y) {
    *root = z;
  } else if (__T_ARG_C__(z->key, y->key)) {
    y->left = z;
  } else {
    y->right = z;
  }
  __TEMPLATE_1(__T_ARG_A__, insertFixup)(root, z);
}

RBNode* __TEMPLATE_1(__T_ARG_A__, rbFind)(__T_ARG_B__ key, RBNode** root) {
  RBNode* node = *root;
  while (node) {
    if (__TEMPLATE_2(__T_ARG_A__, __T_ARG_C__, areKeysEqual)(key, node->key)) {
      return node;
    } else if (__T_ARG_C__(key, node->key)) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return NULL;
}

RBNode* __TEMPLATE_1(__T_ARG_A__, treeMinimum)(RBNode* node) {
  while (node->left) {
    node = node->left;
  }
  return node;
}

void __TEMPLATE_1(__T_ARG_A__, transplant)(RBNode **root, RBNode *u, RBNode *v) {
  if (!u->parent) {
    *root = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  if (v) {
    v->parent = u->parent;
  }
}

void __TEMPLATE_1(__T_ARG_A__, deleteFixup)(RBNode **root, RBNode *x, RBNode *xParent) {
  while (x != *root && (!x || x->color == __RB_TREE_BLACK__)) {
    if (x == xParent->left) {
      RBNode *w = xParent->right;
      if (w && w->color == __RB_TREE_RED__) {
        w->color = __RB_TREE_BLACK__;
        xParent->color = __RB_TREE_RED__;
        __TEMPLATE_1(__T_ARG_A__, leftRotate)(root, xParent);
        w = xParent->right;
      }
      if ((!w->left || w->left->color == __RB_TREE_BLACK__) &&
        (!w->right || w->right->color == __RB_TREE_BLACK__)) {
        if (w) {
          w->color = __RB_TREE_RED__;
        }
        x = xParent;
        xParent = x->parent;
      } else {
        if (!w->right || w->right->color == __RB_TREE_BLACK__) {
          if (w->left) {
            w->left->color = __RB_TREE_BLACK__;
          }
          if (w) {
            w->color = __RB_TREE_RED__;
          }
          __TEMPLATE_1(__T_ARG_A__, rightRotate)(root, w);
          w = xParent->right;
        }
        if (w) {
          w->color = xParent->color;
        }
        xParent->color = __RB_TREE_BLACK__;
        if (w && w->right) {
          w->right->color = __RB_TREE_BLACK__;
        }
        __TEMPLATE_1(__T_ARG_A__, leftRotate)(root, xParent);
        x = *root;
      }
    } else {
      RBNode *w = xParent->left;
      if (w && w->color == __RB_TREE_RED__) {
        w->color = __RB_TREE_BLACK__;
        xParent->color = __RB_TREE_RED__;
        __TEMPLATE_1(__T_ARG_A__, rightRotate)(root, xParent);
        w = xParent->left;
      }
      if ((!w->right || w->right->color == __RB_TREE_BLACK__) &&
        (!w->left || w->left->color == __RB_TREE_BLACK__)) {
        if (w) {
          w->color = __RB_TREE_RED__;
        }
        x = xParent;
        xParent = x->parent;
      } else {
        if (!w->left || w->left->color == __RB_TREE_BLACK__) {
          if (w->right) {
            w->right->color = __RB_TREE_BLACK__;
          }
          if (w) {
            w->color = __RB_TREE_RED__;
          }
          __TEMPLATE_1(__T_ARG_A__, leftRotate)(root, w);
          w = xParent->left;
        }
        if (w) {
          w->color = xParent->color;
        }
        xParent->color = __RB_TREE_BLACK__;
        if (w && w->left) {
          w->left->color = __RB_TREE_BLACK__;
        }
        __TEMPLATE_1(__T_ARG_A__, rightRotate)(root, xParent);
        x = *root;
      }
    }
  }
  if (x) {
    x->color = __RB_TREE_BLACK__;
  }
}

void __TEMPLATE_1(__T_ARG_A__, rbDelete)(__T_ARG_B__ key, RBNode** root) {
  RBNode *z = __TEMPLATE_1(__T_ARG_A__, rbFind)(key, root);
  if (!z) {
    return;
  }
  RBNode *y = z;
  RBNode *x;
  RBNode *xParent;
  __RB_TREE_COLOR_T__ yOriginalColor = y->color;
  if (!z->left) {
    x = z->right;
    xParent = z->parent;
    __TEMPLATE_1(__T_ARG_A__, transplant)(root, z, z->right);
  } else if (!z->right) {
    x = z->left;
    xParent = z->parent;
    __TEMPLATE_1(__T_ARG_A__, transplant)(root, z, z->left);
  } else {
    y = __TEMPLATE_1(__T_ARG_A__, treeMinimum)(z->right);
    yOriginalColor = y->color;
    x = y->right;
    if (y->parent == z) {
      xParent = y;
    }
    else {
      __TEMPLATE_1(__T_ARG_A__, transplant)(root, y, y->right);
      y->right = z->right;
      if (y->right) {
        y->right->parent = y;
      }
      xParent = y->parent;
    }
    __TEMPLATE_1(__T_ARG_A__, transplant)(root, z, y);
    y->left = z->left;
    if (y->left) {
      y->left->parent = y;
    }
    y->color = z->color;
  }
  free(z);
  if (yOriginalColor == __RB_TREE_BLACK__) {
    __TEMPLATE_1(__T_ARG_A__, deleteFixup)(root, x, xParent);
  }
}

void __TEMPLATE_1(__T_ARG_A__, inorderHelper)(RBNode *node) {
  if (node) {
    __TEMPLATE_1(__T_ARG_A__, inorderHelper)(node->left);
    printf("%d(%s) ", node->key, node->color == __RB_TREE_RED__ ? "R" : "B");
    __TEMPLATE_1(__T_ARG_A__, inorderHelper)(node->right);
  }
}

void __TEMPLATE_1(__T_ARG_A__, inorder)(RBNode** root) {
  __TEMPLATE_1(__T_ARG_A__, inorderHelper)(*root);
  printf("\n");
}

void __TEMPLATE_1(__T_ARG_A__, freeTree)(RBNode* node) {
  if (node) {
    __TEMPLATE_1(__T_ARG_A__, freeTree)(node->left);
    __TEMPLATE_1(__T_ARG_A__, freeTree)(node->right);
    free(node);
  }
}

#include "../oop/templates_undef.h"
