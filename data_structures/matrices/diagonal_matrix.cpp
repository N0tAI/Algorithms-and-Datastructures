#include "diagonal_matrix.hpp"

template<typename T>
DiagonalMatrix<T>::DiagonalMatrix(size_t length, size_t width) : Matrix<T>::Matrix(length, size_t width) {}

template<typename T>
size_t DiagonalMatrix<T>::translate_index(size_t row, size_t col) {
	return (row == col ? row : 0) - 1;
}