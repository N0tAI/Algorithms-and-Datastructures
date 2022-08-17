int factorial_inner(int num, int acc) {
	if (!num)
		return acc;
	return factorial_inner(num - 1, acc * num);
}
int factorial(int num) {
	return factorial_inner(num, 1);
}

int ncr(int n, int r) {
	int numerator = factorial(n);
	int denominator = factorial(r) * factorial(n - r);
	return numerator / denominator;
}