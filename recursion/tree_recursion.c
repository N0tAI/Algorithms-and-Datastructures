// Tree recursion occurs when a function calls recurses multiple times over the course of it's execution
// A great example of tree recursion is a possible implementation of the fibonacci function
int func(int i) {
	if (i <= 0)
		return 1;
	return func(i - 1) + func(i - 2);
}
// this function leads to a complexity akin to pow(2, i) where the number of recursions doubles each successive recursion
// however this could change if we recurse 3 times in a single call with pow(3, i) etc etc