#ifndef THAYBURTLOWERTRIANGULARMATRIX
#define THAYBURTLOWERTRIANGULARMATRIX

#include "matrix.hpp"

template<typename T>
class LowerTriangularMatrix : public Matrix<T> {
protected:
	size_t translate_index(size_t row, size_t col) override;
public:
	LowerTriangularMatrix(size_t length);
};

#endif