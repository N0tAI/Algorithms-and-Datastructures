#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

StackNode* create_stack_node(const int value) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode*));

	if (node != NULL) {
		node->value = value;
		node->next = NULL;
	}

	return node;
}

Stack* create_stack(const int* array, const size_t size) {
	Stack* stack = (Stack*)malloc(sizeof(Stack*));

	if (stack != NULL) {
		stack->top = NULL;
		for (size_t i = size - 1; i < size; i--)
			push(stack, array[size - i - 1]);
	}

	return stack;
}

void delete_stack_node(StackNode* node) {
	free(node);
}

void rdelete_stack_node(StackNode* node) {
	StackNode* temp = node->next;
	delete_stack_node(node);
	if (temp != NULL)
		rdelete_stack_node(temp);
}

void delete_stack(Stack* stack) {
	if (stack->top != NULL)
		rdelete_stack_node(stack->top);
	free(stack);
}

int peek(const Stack* stack, const size_t index) {
	StackNode* node = stack->top;

	for (size_t i = 1; i < index; i++)
		node = node->next;

	return node->value;
}

int pop(Stack* stack) {
	StackNode* node = stack->top;
	int value = node->value;

	stack->top = node->next;
	stack->length--;

	free(node);

	return value;
}

void push(Stack* stack, const int value) {
	StackNode* node = create_stack_node(value);

	if (node != NULL) {
		node->next = stack->top;
		stack->top = node;
		stack->length++;
	}
}