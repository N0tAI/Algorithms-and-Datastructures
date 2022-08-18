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

long long evaluation(char* postfix) {
	Stack* stack = (Stack*)create_stack(NULL, 0);
	
	for (size_t index = 0; postfix[index] != '\0'; index++) {
		char current = postfix[index];
		if (is_number(current))
			push(stack, current - '0');
		else {
			int right = pop(stack);
			int result = pop(stack);

			switch (current) {
			case '+':
				result += right;
				break;
			case '-':
				result -= right;
				break;
			case '*':
				result *= right;
				break;
			case '/':
				result /= right;
				break;
			}
			push(stack, result);
		}
		if (stack->length == 1)
			return pop(stack);
		return (long long) -1;
	}
}