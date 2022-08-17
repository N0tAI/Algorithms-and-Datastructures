// Tail Recursion occurs when a function recurses on itself only when it has completed all other work

int func(int i) {
	i /= 2;
	if (i)
		// This is a useless example of tail recursion how ever it proves the point, providing a base case (i == 0) and only recursing after it has completed all work
		// Tail recursion can also provide optimisation benefits to certain compliers, which can translate the recursion into a loop, greatly reducing the memory impact of your loop
		// however you need to be smart regarding how you do your recursion to ensure that the caller does not need to reserve any of it's variables after recursing
		return func(i - 1);
	return 0;
}