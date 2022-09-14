#include <stddef.h>
// Mathematical definition of a tri diagonal matrix is:

/*
	  c o l - >
	  _______________
	r | a  a  0  0  0
	o | a  a  a  0  0
	w | 0  a  a  a  0
	| | 0  0  a  a  a
	v | 0  0  0  a  a

	main diagonal = row - col = 0
	(another way to represent is any point where col = row)
	(1,1) (2,2) (3,3) etc is all considered as part of the main diagonal

	lower diagonal = row - col = 1
	(another way to represent is any point where col = row - 1)
	(2,1) (3,2) (4,3) etc is all considered part of the lower diagonal

	upper diagonal = row - col = -1
	(another way to represent is any point where col = row + 1)
	(1,2) (2,3) (3,4) etc is all considered part of the upper diagonal

	any other value (ie where |row - col| > 1 is 0)
*/

// the way to map the location of an element in the matrix to an array

/*
size_t translate_index_tri_band(Matrix* matrix, size_t row, size_t col) {
	size_t diagonal = 1 + row - col;
	// if diagonal is 0 (row - col == -1) then we go to the start of the upper diagonal
	// else if diagonal is 1 (row - col == 0) then we go to the main diagonal
	// else if diagonal is 2 (row - col == 1) then we go the lower diagonal
	// else return -1
	// this matrix stores values as lower diag, main diag, upper diag

	// you can refactor this to some quick math by simple changing the location of lower diag to upper diag and upper diag to lower diag
	if (diagonal > 2) // Out of range
		return (size_t)-1;
	size_t index = 0;
	if (diagonal == 1)
		index = matrix->dimensions - 1 + row - 1;
	else if (diagonal == 0)
		index = matrix->dimensions * 2 - 1;
	index += (row - 1);
	return index;
}
*/

// Square Band Matrix - when there are more than 1 band of diagonals on each side of the main diagonal (but the same amount above and below main)
// Implementing this just requires an extension of the logic for tri band where we have to scale the cases of the matrix