#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "position2.hpp"

/* // standardmaessig durch position2.hpp integriert
struct Position
{
	float x,y;
	Position() : x(0), y(0) {}
	Position(float x_, float y_) : x(x_), y(y_) {}
};
*/

class Rectangle
{
	public:
		Rectangle();
		Rectangle(float xPos, float yPos, float width_, float height_);

		Position const& getPos() const;
		Position getCenter() const;
		float getWidth() const;
		float getHeight() const;
		float getDiagonal() const;		// Diagonalenlaenge
		float getCircumCircle() const;	// Umkreisradius
		float circumference() const;	// Umfang

		void setPos(float x, float y);
		void setScale(float width_, float height_);

	private:
		Position position;
		float width;
		float height;
};

#endif