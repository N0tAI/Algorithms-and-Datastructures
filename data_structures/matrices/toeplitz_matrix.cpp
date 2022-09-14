#include "toeplitz_matrix.hpp"

// Toeplitz matrix is a matrix where all values are non zero AND all elements in a diagonal are the same
/*
    r o w
    -----------
  c | 2 3 4 5 6
  o | 7 2 3 4 5
  l | 8 7 2 3 4
    | 9 8 7 2 3
    | 1 9 8 7 2

    M[row, col] = M[row - 1, col - 1]

    only need to store a single row and single column or n + n -1 elements
    for any index A[i, j]
    if col <= row get from index row - col
    else (col > row) get from index 1D size + col - row - 1
*/

template<typename T>
ToeplitzMatrix<T>::ToeplitzMatrix(size_t length) : Matrix<T>::Matrix(length, 2 * length - 1, 0) {}

template<typename T>
size_t ToeplitzMatrix<T>::translate_index(size_t row, size_t col) {
    if (row > _length || col > _length)
        return -1;
    return (col > row ? _length + col - row - 1 : row - col);
}