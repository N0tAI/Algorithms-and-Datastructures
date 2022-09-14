#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../queue/double_linked_queue.h"
#include "../stack/stack.h"

typedef struct _tree_node_t {
	struct _tree_node_t* left;
	struct _tree_node_t* right;
	void* value;
};

typedef struct _tree_node_t tree_node_t;

void init_tree_node(tree_node_t* node, const void* value) {
	node->value = value;
	node->left = NULL;
	node->right = NULL;
}

tree_node_t* create_tree_node(const void* value) {
	tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));

	if (node != NULL)
		init_tree_node(node, value);

	return node;
}

tree_node_t* create_tree(void* array[], size_t array_size) {
	double_queue_t queue = { .front = NULL, .end = NULL };

	tree_node_t* root = create_tree_node(0);
	if (array != NULL && array_size > 0) {
		root->value = array[0];
		enqueue(&queue, root);

		size_t current_index = 1;
		while (!is_empty(&queue)) {
			tree_node_t* current = dequeue(&queue);

			if (current == NULL)
				continue;
			
			size_t child_index = current_index * 2 - 1;
			if (child_index < array_size) {
				tree_node_t* temp = array[child_index] == -1 ? NULL : create_tree_node(array[child_index]);
				current->left = temp;
				enqueue(&queue, temp);
			}

			child_index++;
			if (child_index < array_size) {
				tree_node_t* temp = array[child_index] == -1 ? NULL : create_tree_node(array[child_index]);
				current->right = temp;
				enqueue(&queue, temp);
			}

			current_index++;
		}
	}

	return root;
}

void display_preorder(tree_node_t* root) {
	if (root != NULL) {
		printf("%d ", root->value);
		display_preorder(root->left);
		display_preorder(root->right);
	}
}

void display_inorder(tree_node_t* root) {
	if (root != NULL) {
		display_inorder(root->left);
		printf("%d ", root->value);
		display_inorder(root->right);
	}
}

void display_postorder(tree_node_t* root) {
	if (root != NULL) {
		display_postorder(root->left);
		display_postorder(root->right);
		printf("%d ", root->value);
	}
}

void display_preorder_iter(const tree_node_t* root) {
	if (root == NULL)
		return;
	
	Stack stack;
	init_stack(&stack);

	push(&stack, root);

	while (stack.top != NULL) {
		tree_node_t* current = pop(&stack);
		printf("%d, ", current->value);

		if (current->right != NULL)
			push(&stack, current->right);
		if (current->left != NULL)
			push(&stack, current->left);
	}
}

void display_inorder_iter(const tree_node_t* root) {
	if (root == NULL)
		return;

	Stack stack;
	init_stack(&stack);

	tree_node_t* current = root;
	do {
		if (current != NULL) {
			push(&stack, current);
			current = current->left;
		}
		else {
			current = pop(&stack);
			printf("%d, ", current->value);
			current = current->right;
		}
	} while (current != NULL && stack.top != NULL);
}

void display_postorder_iter(const tree_node_t* root) {
	if (root == NULL)
		return;

	Stack stack;
	init_stack(&stack);

	tree_node_t* current = root;

	do {
		if (current != NULL) {
			if (current->right != NULL)
				push(&stack, current->right);
			push(&stack, current);
			current = current->left;
		}
		else {
			current = pop(&stack);
			if (current->right == peek(&stack, 0)) {
				tree_node_t* temp = pop(&stack);
				push(&stack, current);
				current = temp;
			}
			else {
				printf("%d, ", current->value);
				current = NULL;
			}
		}

	} while (stack.top != NULL);
}

void rdisplay_level_order(const tree_node_t* root, stack_t* stack) {
	if (root == NULL || stack == NULL)
		return;

	if (root->left != NULL)
		push(stack, root->left);
	if (root->right != NULL)
		push(stack, root->right);
	
	printf("%d, ", root->value);

	rdisplay_level_order(pop(stack), stack);
}

void display_level_order(const tree_node_t* root) {
	if (root == NULL)
		return;

	Stack stack;
	init_stack(&stack);

	rdisplay_level_order(root, &stack);
}

void display_level_order_iter(const tree_node_t* root) {
	if (root == NULL)
		return;

	double_queue_node_t queue;
	init_double_queue(&queue);

	tree_node_t* current = root;
	do {
		printf("%d, ", current->value);
		if (current->left != NULL)
			enqueue_double(&queue, current->left);
		if (current->right != NULL)
			enqueue_double(&queue, current->right);
		current = dequeue_double(&queue);
	} while (current != NULL);
}

size_t tree_height_iter(const tree_node_t* root) {
	if (root == NULL)
		return 0;

	double_queue_t queue;
	init_double_queue(&queue);
	
	size_t tree_height = 0;
	size_t current_layer_size = 0;
	size_t next_layer_size = 0;
	tree_node_t* current = root;
	do {
		if (current->left != NULL) {
			enqueue_double(&queue, current->left);
			next_layer_size++;
		}
		if (current->right != NULL) {
			enqueue_double(&queue, current->right);
			next_layer_size++;
		}
		if (current_layer_size == 0) {
			current_layer_size = next_layer_size;
			next_layer_size = 0;

			tree_height++;
		}
		current_layer_size--;
		current = dequeue_double(&queue);
	} while (queue.front != NULL);

	return tree_height;

}

size_t tree_height(const tree_node_t* root) {
	if (root == NULL)
		return 0;
	size_t left_size = tree_height(root->left);
	size_t right_size = tree_height(root->right);

	if (left_size > right_size)
		return left_size + 1;
	return right_size + 1;
}

size_t tree_count_iter(const tree_node_t* root) {
	if (root == NULL)
		return 0;

	double_queue_t queue;
	init_double_queue(&queue);

	size_t node_count = 0;
	tree_node_t* current = root;
	do {
		node_count++;
		if (current->left != NULL)
			enqueue_double(&queue, current->left);
		if (current->right != NULL)
			enqueue_double(&queue, current->right);
		current = dequeue_double(&queue);
	} while (current != NULL);

	return node_count;
}

size_t tree_count(const tree_node_t* root) {
	if (root != NULL)
		return tree_count(root->left) + tree_count(root->right) + 1;
	return 0;
}

size_t count_leaf_nodes(const tree_node_t* root) {
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
}

size_t count_leaf_nodes_iter(const tree_node_t* root) {
	if (root == NULL)
		return NULL;

	double_queue_t queue;
	init_double_queue(&queue);

	tree_node_t* current = root;
	size_t leaf_count = 0;
	do {
		if (current->left != NULL)
			enqueue_double(&queue, current->left);
		if (current->right != NULL)
			enqueue_double(&queue, current->right);
		else if (current->left == NULL)
			leaf_count++;

		current = dequeue_double(&queue);
	} while (current != NULL);

	return leaf_count;
}