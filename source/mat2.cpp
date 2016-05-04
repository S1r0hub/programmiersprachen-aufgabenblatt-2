#include "mat2.hpp"
#include <iostream>

Mat2::Mat2()
{
	// Einheitsmatrix
	this->matrix[0][0] = 1;
	this->matrix[0][1] = 0;
	this->matrix[1][0] = 0;
	this->matrix[1][1] = 1;
}


Mat2::Mat2(int x1, int x2 = 0, int y1 = 0, int y2 = 0)
{
	// Einheitsmatrix
	this->matrix[0][0] = x1;
	this->matrix[0][1] = x2;
	this->matrix[1][0] = y1;
	this->matrix[1][1] = y2;
}

Mat2& Mat2::operator*=(Mat2 const& m)
{
	Mat2 temp = *this;

	matrix[0][0] = temp.matrix[0][0] * m.matrix[0][0] + temp.matrix[0][1] * m.matrix[1][0];
	matrix[0][1] = temp.matrix[0][0] * m.matrix[0][1] + temp.matrix[0][1] * m.matrix[1][1];
	matrix[1][0] = temp.matrix[1][0] * m.matrix[0][0] + temp.matrix[1][1] * m.matrix[1][0];
	matrix[1][1] = temp.matrix[1][0] * m.matrix[0][1] + temp.matrix[1][1] * m.matrix[1][1];

	return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 newM = m1;	// neue Matrix
	newM *= m2;
	return newM;
}