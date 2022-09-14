#ifndef THAYBURTBSTEXTENSION
#define THAYBURTBSTEXTENSION
#include <stddef.h>
#include "../trees/binary_tree_linked.h"

tree_node_t* bst_search(tree_node_t* root, int value);
tree_node_t* bst_insert(tree_node_t* root, int value);
tree_node_t* bst_delete(tree_node_t* root);
tree_node_t* bst_from_preorder(int array[], size_t array_size);
tree_node_t* bst_from_inorder(int array[], size_t array_size);
tree_node_t* bst_from_postorder(int array[], size_t array_size);

#endif