#ifndef THAYBURTSYMMETRICMATRIX
#define THAYBURTSYMMETRICMATRIX
#include "matrix.hpp"

template<typename T>
class SymmetricMatrix : public Matrix<T> {
protected:
	size_t translate_index(size_t row, size_t col) override;
public:
	SymmetricMatrix(size_t length);
};

#endif