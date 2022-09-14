#ifndef THAYBURTTOEPLITZMATRIX
#define THAYBURTTOEPLITZMATRIX
#include "matrix.hpp"

template<typename T>
class ToeplitzMatrix : public Matrix {
protected:
	size_t translate_index(size_t row, size_t col) override;
public:
	ToeplitzMatrix(size_t length);
};

#endif