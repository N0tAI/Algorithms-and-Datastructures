// Head recursion is where a function recurses on itself BEFORE completeing all of it's other work

int func(int i) {
	if (i > 5)
		i += func(i - 1);	// this is recursive because before i can be reassigned the function must complete it's recursion
							// thus there is work that follows the completion of the recursion
	return i;
}

