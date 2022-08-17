#include <stddef.h>
#include <stdbool.h>
#include "stack.h"

bool are_paranthesis_balanced(char* expression) {
	if (expression[0] == '\0')
		return true;
	
	Stack stack = *create_stack(NULL, 0);
	while (*expression != '\0') {
		if (*expression == '(')
			push(&stack, (int)*expression);
		else if (*expression == ')') {
			if (stack.length == 0 || pop(&stack) != (int)'(') {
				delete_stack(&stack);
				return false;
			}
		}
		else if (*expression == '[')
			push(&stack, (int)*expression);
		else if (*expression == ']') {
			if (stack.length == 0 || pop(&stack) != (int)'[') {
				delete_stack(&stack);
				return false;
			}
		}
		else if (*expression == '{')
			push(&stack, (int)*expression);
		else if (*expression == '}') {
			if (stack.length == 0 || pop(&stack) != (int)'{') {
				delete_stack(&stack);
				return false;
			}
		}
		else if (*expression == '<')
			push(&stack, (int)*expression);
		else if (*expression == '>') {
			if (stack.length == 0 || pop(&stack) != (int)'<') {
				delete_stack(&stack);
				return false;
			}
		}
		
		expression++;
	}

	delete_stack(&stack);
	return (bool)(stack.length == 0);
}