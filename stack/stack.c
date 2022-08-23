#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct _stack_node {
	void* value;
	struct _stack_node* next;
};

typedef struct _stack_node stack_node_t;

typedef struct {
	size_t length;
	stack_node_t* top;
} stack_t;

stack_node_t* create_stack_node(void* value);
stack_t* create_stack(void** array, size_t size);
void init_stack(stack_t* stack);

void delete_stack_node(stack_node_t* node);
void rdelete_stack_node(stack_node_t* node);
void delete_stack(stack_t* stack);

void* peek(const stack_t* stack, const size_t index);
void* pop(stack_t* stack);
void push(stack_t* stack, void* value);

stack_node_t* create_stack_node(void* value) {
	stack_node_t* node = (stack_node_t*)malloc(sizeof(stack_node_t*));

	if (node != NULL) {
		node->value = value;
		node->next = NULL;
	}

	return node;
}

stack_t* create_stack(void** array, size_t size) {
	stack_t* stack = (stack_t*)malloc(sizeof(stack_t*));

	if (stack != NULL) {
		init_stack(stack);
		stack->top = NULL;
		for (size_t i = size - 1; i < size; i--)
			push(stack, array[size - i - 1]);
	}

	return stack;
}


void init_stack(stack_t* stack) {
	if (stack != NULL) {
		stack->top = NULL;
		stack->length = 0;
	}
}

void delete_stack_node(stack_node_t* node) {
	free(node);
}

void rdelete_stack_node(stack_node_t* node) {
	stack_node_t* temp = node->next;
	delete_stack_node(node);
	if (temp != NULL)
		rdelete_stack_node(temp);
}

void delete_stack(stack_t* stack) {
	if (stack->top != NULL)
		rdelete_stack_node(stack->top);
	free(stack);
}

void* peek(const stack_t* stack, const size_t index) {
	stack_node_t* node = stack->top;

	for (size_t i = 1; i < index; i++)
		node = node->next;

	return node->value;
}

void* pop(stack_t* stack) {
	if (stack->top == NULL)
		return NULL;

	stack_node_t* node = stack->top;
	void* value = node->value;

	stack->top = node->next;
	stack->length--;

	free(node);

	return value;
}

void push(stack_t* stack, void* value) {
	stack_node_t* node = create_stack_node(value);

	if (node != NULL) {
		node->next = stack->top;
		stack->top = node;
		stack->length++;
	}
}