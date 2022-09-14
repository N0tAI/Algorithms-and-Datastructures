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

tree_node_t* bst_search(tree_node_t* root, int value) {
	tree_node_t* current = root;
	while (current != NULL) {
		if (current->value == value)
			return current;
		else if (current->value < value)
			current = current->right;
		else
			current = current->left;
	}
}

tree_node_t* bst_insert(tree_node_t* root, int value) {
	if (root == NULL)
		return create_tree_node(value);
	
	tree_node_t* current = root;
	tree_node_t* prev = NULL;
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

tree_node_t* bst_delete(tree_node_t* root, void* value) {
	if (root == NULL)
		return root;

	tree_node_t* current = root;
	tree_node_t* previous = NULL;

	while(current != NULL && current->value != value) {
		previous = current;
		if (current->value < value)
			current = current->left;
		else
			current = current->right;
	}

	if (current != NULL) {
		// move any subtree elements around
	}

	return current;
}

tree_node_t* bst_from_preorder(int array[], size_t array_size) {
	if (array == NULL || array_size < 1)
		return NULL;

	const tree_node_t* root = create_tree_node(array[0]);
	if (array_size == 1 || root == NULL)
		return root;

	tree_node_t* current = root;
	stack_t* stack = create_stack(NULL, 0);
	if (stack == NULL)
		return current;

	size_t index = 1;
	while (index < array_size) {
		if (array[index] < current->value) {
			tree_node_t* temp = create_tree_node(array[index++]);
			current->left = temp;
			push(stack, current);
			current = temp;
		}
		else {
			if (array[index] > current->value && stack->top != NULL && ((tree_node_t*)stack->top)->value > array[index]) {
				tree_node_t* temp = create_tree_node(array[index++]);
				current->right = temp;
				current = temp;
			}
			else
				current = pop(stack);
		}
	}

	return root;
}

tree_node_t* bst_from_inorder(int array[], size_t array_size) {

}

tree_node_t* bst_from_postorder(int array[], size_t array_size) {

}
#endif