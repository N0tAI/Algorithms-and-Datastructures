#ifndef THAYBURTSTACKUTILS
#define THAYBURTSTACKUTILS
#include <stddef.h>

struct _StackNode {
	void* value;
	struct _StackNode* next;
};

typedef struct _StackNode StackNode;

typedef struct {
	size_t length;
	StackNode* top;
} Stack;

StackNode* create_stack_node(const void* value);
Stack* create_stack(const void** array, const size_t size);
void init_stack(Stack* stack);

void delete_stack_node(StackNode* node);
void rdelete_stack_node(StackNode* node);
void delete_stack(Stack* stack);

void* peek(const Stack* stack, const size_t index);
void* pop(Stack* stack);
void push(Stack* stack, const void* value);

#endif