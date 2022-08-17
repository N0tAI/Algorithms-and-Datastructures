#include <iostream>
#include "sparse_matrix.hpp"

SparseMatrix::~SparseMatrix() {
	delete[] ele;
}
SparseMatrix::SparseMatrix(int m, int n, int num) : m(m), n(n), num(num) {
	ele = new Element[this->num];
}

SparseMatrix SparseMatrix::operator+(SparseMatrix& s)
{
	int i, j, k;
	if (m != s.m || n != s.n)
		return SparseMatrix(0, 0, 0);
	SparseMatrix* sum = new SparseMatrix(m, n, num + s.num);

	i = j = k = 0;
	while (i < num && j < s.num)
	{
		if (ele[i].i < s.ele[j].i)
			sum->ele[k++] = ele[i++];
		else if (ele[i].i > s.ele[j].i)
			sum->ele[k++] = s.ele[j++];
		else
		{
			if (ele[i].j < s.ele[j].j)
				sum->ele[k++] = ele[i++];
			else if (ele[i].j > s.ele[j].j)
				sum->ele[k++] = s.ele[j++];
			else
			{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}
	for (; i < num; i++)sum->ele[k++] = ele[i];
	for (; j < s.num; j++)sum->ele[k++] = s.ele[j];
	sum->num = k;

	return *sum;

}

std::istream& operator>>(std::istream& is, SparseMatrix& s)
{
	std::cout << "Enter non-zero elements";
	for (int i = 0; i < s.num; i++)
		std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
	return is;
}
std::ostream& operator<<(std::ostream& os, SparseMatrix& s)
{
	int k = 0;
	for (int i = 0; i < s.m; i++)
	{
		for (int j = 0; j < s.n; j++)
		{
			if (s.ele[k].i == i && s.ele[k].j == j)
				std::cout << s.ele[k++].x << " ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	return os;
}