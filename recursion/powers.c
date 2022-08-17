// O(n) time
// O(n) space
int powr(int num, int exp) {
	if (!exp)
		return 1;
	return num * pow(num, exp - 1);
}

// O(n) time
// O(1) space
int powroi(int num, int exp, int acc) {
	if (!exp)
		return acc;
	return powroi(num, exp - 1, acc * num);
}
int powro(int num, int exp) {
	return powroi(num, exp, 1);
}

// O(log2n) time?
// O(1) space
int pownew(int num, int exp) {
	if (!exp)
		return 1;
	if (exp % 2 == 0)
		return pownew(num * num, exp / 2);
	return num * pownew(num * num, (exp - 1) / 2);
}