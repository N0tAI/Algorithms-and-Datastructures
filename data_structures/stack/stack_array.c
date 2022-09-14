#include <stddef.h>
#include <stdlib.h>

typedef struct {
	size_t size;
	size_t top;			// Be smarter to use an actual pointer just sayin
	int* values;
} ArrayStack;

ArrayStack* array_stack_create(const int array[], const size_t size) {
	ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	if (stack != NULL) {
		if (size > 0) {
			stack->values = (int*)malloc(sizeof(array[0]) * size);
			if (stack->values == NULL)
				return stack;
			for (size_t i = size - 1; i < size; i--)
				stack->values[size - 1 - i] = array[i];
			stack->top = size - 1;
		}
		else
			stack->top = (size_t)-1;
	}

	return stack;

}

int array_stack_peek(ArrayStack* stack) {
	if (stack->size > 0)
		return stack->values[0];
	return 0;
}
int array_stack_pop(ArrayStack* stack) {
	if (stack->top < stack->size)
		return stack->values[stack->top];
	return 0;
}

void array_stack_push(ArrayStack* stack, const int value) {
	if (stack->size - 1 == stack->top) {
		return;
	
	stack->top++;
	stack->values[stack->top] = value;
}

int array_stack_is_empty(ArrayStack* stack) {
	return stack->top >= stack->size;
}

int array_stack_is_full(ArrayStack* stack) {
	return stack->top == stack->size - 1;
}