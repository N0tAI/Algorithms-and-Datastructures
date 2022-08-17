// A SparseMatrix matrix is a matrix with more 0 data than non zero data
// to create an EFFICIENT SparseMatrix matrix we can achieve this in two ways

/*
	Coordinate List / 3 column representation

	Compressed SparseMatrix Row
*/

#ifndef THAYBURTSPARSEMATRIX
#define THAYBURTSPARSEMATRIX
#include <iostream>

struct Element
{
	int i;
	int j;
	int x;
};
class SparseMatrix
{
private:
	int m;
	int n;
	int num;
	Element* ele;
public:
	SparseMatrix(int m, int n, int num);
	~SparseMatrix();

	SparseMatrix operator+(SparseMatrix& s);

	friend std::istream& operator>>(std::istream& is, SparseMatrix& s);
	friend std::ostream& operator<<(std::ostream& os, SparseMatrix& s);
};
#endif