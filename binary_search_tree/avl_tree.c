// AVL trees are height balanced binary search trees

// Balance Factor = height(root_left) - height(root_right) = { -1, 0, 1 }
// If | Balance Factor | <= 1 then the tree is balanced
// Else | Balance Factor | > 1 then the tree is imbalanced

#include <stddef.h>
#include <stdbool.h>
#include "../trees/binary_tree_linked.h"
#include "../binary_search_tree/avl_tree.h"

typedef long long slong;

slong get_balance(const tree_node_t* root) {
	if (root == NULL)
		return 0;

	slong balance = tree_height_iter(root->left);
	balance -= tree_height_iter(root->right);

	return balance;
}

// TODO verify this code
tree_node_t* left_rotation(tree_node_t* root) {
	if (root == NULL || root->left == NULL)
		return root;

	tree_node_t* left_child = root->left;
	tree_node_t* left_right_child = left_child->right;

	left_child->right = root;
	root->left = left_right_child;

	return left_child;
}

tree_node_t* left_right_rotation(tree_node_t* root) {
	if (root == NULL || root->left == NULL || root->left->right == NULL)
		return root;

	tree_node_t* left_child = root->left;
	tree_node_t* left_right_child = left_child->right;

	root->left = left_right_child->right;
	left_child->right = left_right_child->left;
	left_right_child->left = left_child;
	left_right_child->right = root;

	return left_right_child;
}

tree_node_t* right_rotation(tree_node_t* root) {
	if (root == NULL || root->right == NULL)
		return root;

	tree_node_t* right_child = root->right;
	tree_node_t* right_left_child = right_child->left;

	right_child->left = root;
	root->right = right_left_child;

	return right_child;
}

tree_node_t* right_left_rotation(tree_node_t* root) {
	if (root == NULL || root->right == NULL || root->right->left == NULL)
		return root;

	tree_node_t* right_child = root->right;
	tree_node_t* right_left_child = right_child->left;

	root->right = right_left_child->left;
	right_child->left = right_left_child->right;
	right_left_child->right = right_child;
	right_left_child->left = root;

	return right_left_child;
}

bool is_tree_balanced(const tree_node_t* root) {
	slong balance = get_balance(root);
	return (bool)!!(balance <= 1 && balance >= -1);
}

tree_node_t* balanced_insert(tree_node_t* root, void* value) {
	tree_node_t* current = create_tree_node(value);
	if (root == NULL || current == NULL)
		return current;

	// insertion logic

	// Todo, optimise rebalancing logic
	if (!is_tree_balanced(root)) {
		slong root_balance = get_balance(root);
		slong left_balance = get_balance(root->left);
		slong right_balance = get_balance(root->right);
		if (root_balance == 2)
			left_balance == 1 ? ll_rotation(root) : lr_rotation(root);
		else
			right_balance == 1 ? rr_rotation(root) : rl_rotation(root);
	}
}

tree_node_t* balanced_delete(tree_node_t* root, void* value) {
	if (root == NULL)
		return NULL;

	// deletion logic

	// Rebalancing logic
}

tree_node_t create_avl_tree(tree_node_t* root, void* value)