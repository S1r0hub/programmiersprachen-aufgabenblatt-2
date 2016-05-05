#ifndef MAT2_HPP
#define MAT2_HPP

#include "vec2.hpp"

class Mat2
{
	public:
		// Default-Constructor
		Mat2();
		
		// User-Constructor
		Mat2(float x1, float x2, float y1, float y2);
		
		Mat2& operator*=(Mat2 const& m);
		Vec2 operator*=(Vec2 const& v);
		Mat2& operator*=(float k);

		float matrix[2][2];
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
Vec2 operator*(Mat2 &m, Vec2 const& v);
float Mat2Det(Mat2 &m);
Mat2 Mat2Inv(Mat2 &m);

#endif