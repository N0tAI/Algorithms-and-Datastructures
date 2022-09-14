#include "matrix.hpp"

Matrix::MatrixRow::MatrixRow(Matrix& matrix, size_t row) : _row(row), _matrix(matrix) { }
int& Matrix::MatrixRow::operator[](size_t col) {
	return _matrix.get(_row, col);
}
Matrix::MatrixRow::operator size_t() {
	return _row;
}

size_t Matrix::translate_index(size_t row, size_t col) {
	auto i = _length * row + col;
	if (i < size())
		return i;
	return -1;
}

Matrix::~Matrix() {
	delete _items;
}

size_t Matrix::size() {
	return _length * _length;
}
size_t Matrix::length() {
	return _length;
}
size_t Matrix::width() {
	return _width;
}

Matrix::Matrix() : Matrix(3) {}

Matrix::Matrix(size_t length) : Matrix::Matrix(length, length) {}

Matrix::Matrix(size_t length, size_t width) : Matrix::Matrix(length, width, 0) {}

Matrix::Matrix(size_t length, size_t width, int default_value) : Matrix::Matrix(length, width, length * width, default_value) {}

Matrix::Matrix(size_t length, size_t width, size_t item_size, int default_value) : _length(length), _width(width), _default_value(default_value), _item_size(item_size) {
	_items = new int[_item_size];
}

void Matrix::set(size_t row, size_t col, int value) {
	auto index = translate_index(row, col);
	if (index < _item_size)
		_items[index] = value;
}

int& Matrix::get(size_t row, size_t col) {
	if (row > _length || col > _width)
		return _default_value;
	auto index = translate_index(row, col);
	if(index > size())
		return _default_value;
	return _items[index];
}

Matrix::MatrixRow& Matrix::operator[](size_t row) {
	MatrixRow temp_row(*this, row);
	return temp_row;
}