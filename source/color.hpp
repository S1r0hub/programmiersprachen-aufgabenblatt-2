#ifndef COLOR_HPP
#define COLOR_HPP

struct Color
{
	double r,g,b = 0;
	Color() : r(0),g(0),b(0) {}
	Color(double r_, double g_, double b_) {
		r = (r_ > 1 ? 1.0 : ( r_ > 0 ? r_ : 0.0));
		g = (g_ > 1 ? 1.0 : ( g_ > 0 ? g_ : 0.0));
		b = (b_ > 1 ? 1.0 : ( b_ > 0 ? b_ : 0.0));
	}
};

#endif