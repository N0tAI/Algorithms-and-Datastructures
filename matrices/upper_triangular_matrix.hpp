#ifndef THAYBURTUPPERTRIANGULARMATRIX
#define THAYBURTUPPERTRIANGULARMATRIX

#include "matrix.hpp"

template<typename T>
class UpperTriangularMatrix : public Matrix<T> {
protected:
	size_t translate_index(size_t row, size_t col) override;
public:
	UpperTriangularMatrix(size_t length);
};

#endif