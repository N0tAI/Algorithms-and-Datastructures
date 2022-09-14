#ifndef THAYBURTMATRIX
#define THAYBURTMATRIX
#include <cstddef>

// TODO: Independant research to implement each math and comparison operator
// TODO: Look into templating the Matrix size
// TODO: Look into enforcing that all matrix types implement certain operators/comparison functions
template<typename _T>
class Matrix {
protected:
	T* _items;
	T _default_value;
	size_t _length;
	size_t _width;
	size_t _item_size;
	virtual size_t translate_index(size_t row, size_t col);
	Matrix(size_t length, size_t width, size_t item_size, int default_value);
public:
	size_t size();
	size_t length();
	size_t width();
	Matrix();
	Matrix(size_t length);
	Matrix(size_t length, size_t width);
	Matrix(size_t length, size_t width, int default_value);
	void set(size_t row, size_t col, int);
	int& get(size_t row, size_t col);
	class MatrixRow {
		size_t _row;
		Matrix& _matrix;
	public:
		MatrixRow(Matrix& matrix, size_t row);
		int& operator[](size_t col);
		int operator[](size_t col) const;
		explicit operator size_t();
	};
	MatrixRow& operator[](size_t row);
	MatrixRow operator[](size_t row) const;
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator/(const Matrix& other);
	Matrix operator%(const Matrix& other);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator/=(const Matrix& other);
	Matrix& operator%=(const Matrix& other);
	bool operator<(const Matrix& other);
	bool operator>(const Matrix& other);
	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
	bool operator<=(const Matrix& other);
	bool operator>=(const Matrix& other);
};
#endif