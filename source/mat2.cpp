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


Mat2::Mat2(float x1, float x2 = 0, float y1 = 0, float y2 = 0)
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

Vec2 Mat2::operator*=(Vec2 const& v)
{
	Vec2 retV;	// returned Vector, Berechnung erfolgt Zeile v. Matrix * Spalte v. Vektor
	retV.x = matrix[0][0] * v.x + matrix[0][1] * v.y;
	retV.y = matrix[1][0] * v.x + matrix[1][1] * v.y;
	return retV;
}

Vec2 operator*(Mat2 &m, Vec2 const& v)
{
	Vec2 newV = (m *= v); // neuer Vektor
	return newV;
}

float Mat2Det(Mat2 &m)
{
	// Determinante berechnen
	return (m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0]);
}

Mat2 Mat2Inv(Mat2 &m)
{
	Mat2 TM{0,m.matrix[0][1],m.matrix[1][0],0};
	TM.matrix[0][0] = m.matrix[1][1];	// switche d an Position von a
	TM.matrix[0][1] *= -1;
	TM.matrix[1][0] *= -1;
	TM.matrix[1][1] = m.matrix[0][0];	// switche a an Position von d
	float mult = ( 1 / (m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0]) );
	return ( mult * TM );
}