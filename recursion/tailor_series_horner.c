#include <stdio.h>

double e(int x, int n) {
	static double s;
	if (!n)
		return s;
	s = 1.0 + x * s / n;
	return e(x, n - 1);
}

double e_no_static_impl(int x, int n, double acc) {
	return e_no_static_impl(x, n - 1, 1.0 + x * acc / n);
}

double e_no_static(int x, int n) {
	return e_no_static_impl(x, n, 0.0);
}

double e_iterative(int x, int n) {
	double s = 1;
	double num = 1;
	double den = 1;

	for (int i = 1; i <= n; i++) {
		num *= x;
		den *= i;
		s += num / den;
	}
	return s;
}