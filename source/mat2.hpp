#ifndef MAT2_HPP
#define MAT2_HPP

class Mat2
{
	public:
		// Default-Constructor
		Mat2();
		
		// User-Constructor
		Mat2(int x1, int x2, int y1, int y2);
		
		Mat2& operator*=(Mat2 const& m);

		int matrix[2][2];
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

#endif