#ifndef THAYBURTDIAGONALMATRIX
#define THAYBURTDIAGONALMATRIX

#include "matrix.hpp"

template<typename T>
class DiagonalMatrix : public Matrix<T> {
protected:
	size_t translate_index(size_t row, size_t col) override;
public:
	DiagonalMatrix(size_t length, size_t width) {}
};

#endif