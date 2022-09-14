#ifndef THAYBURTAVLEXTENSIONS
#define THAYBURTAVLEXTENSIONS
#include <stddef.h>
#include "binary_search_tree.h"

tree_node_t* left_rotation(tree_node_t* root);
tree_node_t* left_right_rotation(tree_node_t* root);
tree_node_t* right_rotation(tree_node_t* root);
tree_node_t* right_left_rotation(tree_node_t* root);
tree_node_t* balanced_insert(tree_node_t* root, void* value);
tree_node_t* balanced_delete(tree_node_t* root, void* value);

#endif