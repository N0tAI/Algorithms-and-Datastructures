#include <stdio.h>

void recursion(int n) {
	if (n > 0) {
		printf("%d", n);
		tail_recursive(n - 1);
	}
}