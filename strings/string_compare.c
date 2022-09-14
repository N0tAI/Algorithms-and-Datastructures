#include <stddef.h>
#include <stdbool.h>
#include <string.h>

int string_compare(char* str, char* cmp) {
	if (str == cmp)
		return 0;
	while (*str != *cmp && *str != '\0' && *cmp != '\0') {
		str++;
		cmp++;
	}
	return ((int)*cmp) - ((int)*str); // if equal return 0 if str < cmp return > 0 else return < 0
}

bool is_palindrome(char* str) {
	size_t size = strlen(str);
	for (char* rev = str + size - 1; rev > str; rev--, str++) {
		if (*str != *rev)
			return false;
	}
	return true;
}