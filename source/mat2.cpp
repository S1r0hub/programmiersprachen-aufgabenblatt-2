#define _USE_MATH_DEFINES
#include "mat2.hpp"
#include <cmath>


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

bool Mat2::equal(Mat2 const& m)
{
	bool same = true;
	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k) {
			if (matrix[i][k] != m.matrix[i][k]) {
				same = false;
				break;
			}
		}
	}

	return same;
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

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
	Mat2 m2 = m;
	Vec2 newV = (m2 *= v); // neuer Vektor
	return newV;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m) {
	Mat2 m2 = m;
	Vec2 newV = (m2 *= v);
	return newV;
}

float Mat2::det() const {
	return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

Mat2& Mat2::operator*=(float k)
{
	for (int i = 0; i < 2; ++i) {
		for (int l = 0; l < 2; ++l) {
			matrix[i][l] *= k; 
		}
	}
	return *this;
}

Mat2 inverse(Mat2 const& m)
{
	Mat2 TM{0,m.matrix[0][1],m.matrix[1][0],0};
	TM.matrix[0][0] = m.matrix[1][1];	// switche d an Position von a
	TM.matrix[0][1] *= -1;
	TM.matrix[1][0] *= -1;
	TM.matrix[1][1] = m.matrix[0][0];	// switche a an Position von d
	float detA = m.det();
	if (detA) { return ( TM *= (1 / (detA)) ); }
	return ( TM *= 0 );
}

Mat2 transpose(Mat2 const& m) {
	Mat2 mNew{m.matrix[0][0],m.matrix[1][0],m.matrix[0][1],m.matrix[1][1]};
	return mNew;
}

Mat2 make_rotation_mat2(float phi) {
	Mat2 mNew{(float) cos(phi), (float) -sin(phi), (float) sin(phi), (float) cos(phi)};
	return mNew;
}