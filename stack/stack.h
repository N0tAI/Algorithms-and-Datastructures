#ifndef THAYBURTSTACKUTILS
#define THAYBURTSTACKUTILS
#include <stddef.h>

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
#endif