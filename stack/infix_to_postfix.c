#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int precedence(char x) {
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	return 0;
}

int is_number(char x) {
	return precedence(x) == 0;
}

char* convert(char* infix_str) {
	if (infix_str == NULL)
		return NULL;

	size_t str_size = 0;
	for (; infix_str[str_size] != '\0'; str_size++);

	if (str_size < 3)
		return NULL;

	Stack* stack = create_stack(infix_str, str_size);

	char* postfix = (char*)malloc(sizeof(char) * str_size);

	if(postfix != NULL)
	{
		size_t infix_index = 0;
		size_t postfix_index = 0;
		while(infix_str[infix_index] != '\0') {
			if (is_number(infix_str[infix_index]))
				postfix[postfix_index++] = infix_str[infix_index++];
			else {
				if (precedence(infix_str[infix_index]) > precedence(stack->top))
					push(stack, infix_str[infix_index++]);
				else {
					postfix[postfix_index++] = pop(stack);
				}
			}
		}
		while (stack->length > 0)
			postfix[postfix_index++] = pop(stack);
		postfix[postfix_index] = '\0';
	}

	return postfix;
}