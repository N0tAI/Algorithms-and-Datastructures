// O(n) time
// O(n) space (head recursion)
int natural_sum_recursive(const int num) {
	if (num > 0)
		return natural_sum(num - 1) + num;
	return 0;
}

// These two functions are tail recursive and optimised in a way in which the compiler can translate this into a simple loop, removing all stack space
// O(n) time
// O(1) space
int natural_sum_recursive_acculate(const int num, int acc) {
	if(num < 0)
		return acc;
	return natural_sum_recursive_acculate(num - 1, acc + num);
}
int natural_sum_recursive_opt(const int num) {
	return natural_sum_recursive_acculate(num - 1, num);
}

// O(n) time
// O(1) space (1 variable)
int natural_sum_iterative(int num) {
	int sum = 0;
	for (; num > 0; num--)
		sum += num;
	return sum;
}

// O(1) time
// O(1) space (1 variable)
int natural_sum_constant(const int num) {
	return num * (num + 1) / 2;
}