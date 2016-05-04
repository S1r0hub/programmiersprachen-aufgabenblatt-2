#include "vec2.hpp"

// Memberfunktionen

Vec2& Vec2::operator+=(Vec2 const& v)
{
	x += v.x;
	y += v.y;
	return *this;
} 

Vec2& Vec2::operator-=(Vec2 const& v)
{
	x -= v.x; 
	y -= v.y;
	return *this;
}

Vec2& Vec2::operator*=(float v)
{
	x *= v;
	y *= v;
	return *this;
} 

Vec2& Vec2::operator/=(float v)
{
	x /= v;
	y /= v;
	return *this;
}

// freie Funktionen

Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
	Vec2 newVec{u.x + v.x, u.y + v.y};
	return newVec;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
	Vec2 newVec{u.x - v.x, u.y - v.y};
	return newVec;
}

Vec2 operator*(Vec2 const& v, float s)
{
	Vec2 newVec{v.x * s, v.y * s};
	return newVec;
}

Vec2 operator/(Vec2 const& v, float s)
{
	Vec2 newVec{v.x / s, v.y / s};
	return newVec;
}

Vec2 operator*(float s, Vec2 const& v)
{
	Vec2 newVec{s * v.x, s * v.y};
	return newVec;
}
