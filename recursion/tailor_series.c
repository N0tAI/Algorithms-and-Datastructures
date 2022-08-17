#include <stdio.h>

double e(int x, int n) {
	static double p = 1;
	static double f = 1;
	double r;
	if (!n)
		return 1;

	r = e(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p / f;
}

double e_opt_int(const int x, const int n, const int max, const double acc, const double factorial, const double power) {
	if (n > max)
		return acc;
	return e_opt_int(x, n + 1, max, acc + (power / factorial), factorial * n, power * x);
}
double e_opt(const int x, const int n) {
	return e_opt_int(x, 2, n, 1.0, 1.0, 1.0);
}