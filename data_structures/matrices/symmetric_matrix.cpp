#include "symmetric_matrix.hpp"

// Mathematical definition of a symmetric matrix is that M[i][j] = M[j][i]

/* Symmetric Matrix
	1 1 1 1 1
	1 2 2 2 2
	1 2 3 3 3
	1 2 3 4 4
	1 2 3 4 5
*/

template<typename T>
SymmetricMatrix<T>::SymmetricMatrix(size_t length) : SymmetricMatrix::Matrix::Matrix(length, length * 2 - 1, 0) {}

template<typename T>
size_t SymmetricMatrix<T>::translate_index(const size_t row, const size_t col) {
	return (row < col ? row : col);
}