// Binary Search trees have no duplicates
// Inorder traversal of a BST is also in sorted order
// Search complexity is based off of the height of the BST (log2n) (max number of searches is height(tree) + 1)
#ifndef THAYBURTBINARYSEARCHTREE
#define THAYBURTBINARYSEARCHTREE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../stack/stack.h"
#include "../trees/binary_tree_linked.h"

TreeNode* bst_search(const TreeNode* root, const int value) {
	TreeNode* current = root;
	while (current != NULL) {
		if (current->value == value)
			return current;
		else if (current->value < value)
			current = current->right;
		else
			current = current->left;
	}
}

TreeNode* bst_insert(const TreeNode* root, const int value) {
	if (root == NULL)
		return create_tree_node(value);
	
	TreeNode* current = root;
	TreeNode* prev = NULL;
	do {
		prev = current;
		if (current->value < value)
			current = current->right;
		else if (current->value > value)
			current = current->left;
		else
			return current;
	} while (current != NULL);

	if (prev->value < value)
		current = prev->right = create_tree_node(value);
	else
		current = prev->left = create_tree_node(value);
	return current;
}

TreeNode* bst_delete(const TreeNode* root) {
	if (root == NULL)
		return root;

	TreeNode* current = root;
}

TreeNode* bst_from_preorder(const int array[], const size_t array_size) {
	if (array == NULL || array_size < 1)
		return NULL;

	const TreeNode* root = create_tree_node(array[0]);
	if (array_size == 1 || root == NULL)
		return root;

	TreeNode* current = root;
	Stack* stack = create_stack(NULL, 0);
	if (stack == NULL)
		return current;

	size_t index = 1;
	while (index < array_size) {
		if (array[index] < current->value) {
			TreeNode* temp = create_tree_node(array[index++]);
			current->left = temp;
			push(stack, current);
			current = temp;
		}
		else {
			if (array[index] > current->value && stack->top != NULL && ((TreeNode*)stack->top)->value > array[index]) {
				TreeNode* temp = create_tree_node(array[index++]);
				current->right = temp;
				current = temp;
			}
			else
				current = pop(stack);
		}
	}

	return root;
}

TreeNode* bst_from_inorder(const int array[], const size_t array_size) {

}

TreeNode* bst_from_postorder(const int array[], const size_t array_size) {

}
#endif