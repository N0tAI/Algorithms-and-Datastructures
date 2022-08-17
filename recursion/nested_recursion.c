// When a function recurses on itself using a recursion of itself as at least one parameter

int func(int i) {
	if (i > 100)
		return i - 10;
	return func(func(i + 11));
}