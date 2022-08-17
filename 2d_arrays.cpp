
// Doing this in C is quite obvious as you just have to use malloc instead of new
void two_d_array() {
	// Entirety of a is located on the stack
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

	// Array of int* is on the stack, the arrays they point to is on the heap
	int* b[4];				// Technically this is a jagged array as each of it's sub arrays are not the same
							// However this is just to show the less safe/more trusting nature of this declaration
	b[0] = new int[2];
	b[0] = new int[3];
	b[0] = new int[4];
	b[0] = new int[5];

	// Entirety of c is on the heap (minus the obvious pointer to the array of arrays) (can be even less safe than array b)
	int** c;
	c = new int* [3];
	c[0] = new int[4];
	c[1] = new int[4];
	c[2] = new int[4];
}

// Formulas for accessing data from contiguous arrays

// 2D arrays
// Type Array[a][b]
// Row Major Formula (i to j) A[x][y] = <Base Address> + (x * b + y) * <element size>
// Col Major Formula (j to i) A[x][y] = <Base Address> + (y * a + x) * <element size>

// 3D arrays
// Type Array[a][b][c]

// Row Major Formula (x to z): Array[x][y][z] = <Base Address> + (x * b * c + y * c + z) * <element size>
// Col Major Formula (z to x): Array[x][y][z] = <Base Address> + (z * b * a + y * a + x) * <element size>

// 4D arrays
// Type Array[a][b][c][d]

// Row Major Formula (w to z): Array[w][x][y][z] = <Base Address> + (w * b * c * d + x + c * d + y * d + z) * <element size>
// Col Major Formula (z to w): Array[w][x][y][z] = <Base Address> + (z * c * b * a + y * b * a + x * a + w) * <element size> 

// nD arrays
// Type Array[d1]...[dn]

// Row Major Formula (i1 to in): Array[i1][i2]...[in] = <Base Address> + (i1 * d2 * ... * d(n - 1) * dn + i2 * ... * d(n - 1) * dn + ... + i(n - 1) * dn + in) * <element size>
// Col Major Formula (in to i1): Array[i1][i2]...[in] = <Base Address> + (in * d(n - 1) * ... * d2 * d1 + i(n - 1) * ... * d2 * d1 + ... + i2 * d1 + i1) * <element size>

// The number of calculations to access an n dimensional array is always (n(n - 1)) / 2 or time complexity of O(n^2)
// Can be optimized to (n - 1) or O(n) time complexity by refactoring the equation to take each dimension as a common factor or the rest