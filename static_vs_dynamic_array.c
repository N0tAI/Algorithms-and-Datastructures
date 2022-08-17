#include <stdlib.h>

void static_stack_array() {
	int arr[10]; // Allocate

	// Stack space shrinks reclaiming array, and potentially corrupting the array to any other functions in the call chain
}

void dynamic_heap_array() {
	size_t arrCount = 5;

	int* arr = (int*)malloc(sizeof(int) * arrCount); // Allocate

	free(arr);	// Ensure you free the given heap space after use
	// This heap space is not allocated on the stack thus is not at risk of corruption if another function in the call chain attempts to read from it
}