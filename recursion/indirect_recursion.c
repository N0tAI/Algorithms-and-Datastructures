// Indirect recursion is a form of recursion in which a function ends up calling itself by calling another function.
// The number of callees is not limited to just one but just > 0 function invocations between itself

int funca(int i) {
	if (i > 0)
	funcb(--i);
}

int funcb(int i) {
	if (i > 0)
		funca(i / 2);
}