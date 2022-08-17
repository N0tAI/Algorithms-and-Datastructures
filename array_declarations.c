void array_declaration_examples() {
	int arr_a[5];						// Doesn't init the entire array
	int arr_b[5] = { 1, 2, 3, 4, 5 };	// Inits the entire array
	int arr_c[5] = { 2, 4, 6 };			// Only inits the first 3 elements
	int arr_d[5] = { 0 };				// Zero inits the entire array
	int arr_e[ ] = { 1, 2, 3, 4, 5 };	// Assumes the number of elements in the array
	// NOTE THAT FOR STRINGS/CHAR ARRAYS THESE BEHAVIOUS WILL BE DIFFERENT(assuming the element number will append an extra null terminaotr)
	// (But you already knew this)
}