#include <stddef.h>
#include <stdio.h>

void swap(char* var, char* other) {
	char temp = *other;
	*other = *var;
	*var = temp;
}
// low and high are the first and last index of the string respectively
void permutations(char* str, size_t low, size_t high) {
	if (low == high) {
		printf(str);
		return;
	}
	for (size_t i = low; i <= high; i++) {
		swap(str + low, str + i);
		permutations(str, low + 1, high);
		swap(str + low, str + i);
	}
}