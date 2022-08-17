// O(2^N) time
unsigned rfib(unsigned x) {
	if (x < 2)
		return x;
	return fib(x - 1) + fib(x - 2);
}

// O(N) time
unsigned ifib(unsigned n) {
	if (n < 2)
		return n;
	unsigned t0 = 0;
	unsigned t1 = 1;
	unsigned sum = 0;
	for (int i = 2; i <= n; i++) {
		sum = t0 + t1;
		t0 = t1;
		t1 = sum;
	}
	return sum;
}

// Unsafe and I can't be asked to fix it in this temp
int fibNums[10] = { -1 };
unsigned mfib(unsigned n) {
	if (n < 2)
		return n;
	if (fibNums[n] == (unsigned)-1) {
		if (fibNums[n - 2] == (unsigned)-1)
			fibNums[n - 2] = mfib(n - 2);
		if (fibNums[n - 1] == (unsigned)-1)
			fibNums[n - 1] = mfib(n - 1);
		fibNums[n] = fibNums[n - 1] + fibNums[n - 2];
	}
	return fibNums[n];
}