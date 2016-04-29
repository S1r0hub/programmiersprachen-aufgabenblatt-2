#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2
{
	public:
		Vec2() : x(0), y(0) {}
		Vec2(float x, float y) : x(x), y(y) {}

		Vec2& operator+=(Vec2 const& v);
		Vec2& operator-=(Vec2 const& v);
		Vec2& operator*=(float v);
		Vec2& operator/=(float v);
		
		float x;
		float y;
};

// Freie Funktionen

Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);

#endif