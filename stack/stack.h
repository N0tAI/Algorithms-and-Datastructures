#ifndef THAYBURTSTACKUTILS
#define THAYBURTSTACKUTILS
#include <stddef.h>

struct _StackNode {
	int value;
	struct _StackNode* next;
};

typedef struct _StackNode StackNode;

typedef struct {
	size_t length;
	StackNode* top;
} Stack;

StackNode* create_stack_node(const int value);
Stack* create_stack(const int* array, const size_t size);

void delete_stack_node(StackNode* node);
void rdelete_stack_node(StackNode* node);
void delete_stack(Stack* stack);

int peek(const Stack* stack, const size_t index);
int pop(Stack* stack);
void push(Stack* stack, const int value);

#endif