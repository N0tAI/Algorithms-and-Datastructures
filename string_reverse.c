#include <stddef.h>
#include <string.h>

char* string_reverse(char* str) {
	size_t size = strlen(str);
	char* new_str = (char*)malloc(sizeof(char) * size + 1);
	
	if (new_str == NULL)
		return NULL;
	
	for (size_t i = size - 1; i < size; i--)
		new_str[size - i] = str[i];
	new_str[size] = '\0';
	return new_str;
}