#include "lower_triangular_matrix.hpp"

template<typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(size_t length) : Matrix<T>::Matrix(length, length, (length* (length + 1)) / 2, 0) { }

#define ROW_MAJOR_FORM

template<typename T>
size_t LowerTriangularMatrix<T>::translate_index(size_t row, size_t col) {
	if (row >= Matrix<T>::length() || col >= Matrix<T>::width())
		return -1;
#ifdef ROW_MAJOR_FORM
	return (row * (row - 1) / 2 + col - 1);
#elif
	return ((col - 1) * _length - ((col - 2) * (col - 1)) / 2 + row - col;
#endif
}