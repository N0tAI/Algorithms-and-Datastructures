#include "upper_triangular_matrix.hpp"

template<typename T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(size_t length) : Matrix<T>::Matrix(length, (length* (length + 1)) / 2, 0) { }

#define ROW_MAJOR_FORM
//#undef ROW_MAJOR_FORM
template<typename T>
size_t UpperTriangularMatrix<T>::translate_index(size_t row, size_t col) {
	if (row >= _length || col >= _length)
		return -1;
#ifdef ROW_MAJOR_FORM
	return ((row - 1) * _length - ((row - 2) * (row - 1)) / 2 + col - row);
#elif
	return (col * (col - 1) / 2 + row - 1);
#endif
}

#undef ROW_MAJOR_FORM