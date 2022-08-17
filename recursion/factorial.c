// O(n) time
// O(n) space
int factorial(int num) {
	if (!num)
		return 1;
	return num * factorial(num - 1);
}

// O(n) time
// O(1) space
int factorial_recursive_optimized_inner(int num, int acc) {
	if (!num)
		return acc;
	return factorial_recursive_optimized_inner(num - 1, acc * num);
}
int factorial_recursive_optimized(int num) {
	return factorial_recursive_optimized_inner(num, 1);
}

// O(n) time
// O(1) space
int factorial_iterative(int num) {
	int sum = num;
	if (!num)
		return 1;
	while (num > 2)
		sum *= --num;
	return sum;
}

// no way to calc this in constant time