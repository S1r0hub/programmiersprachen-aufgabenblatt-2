#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "position2.hpp"

/* // standardmaessig durch position2.hpp integriert
struct Position
{
	float x,y;
	Position() : x(0), y(0) {}
	Position(float x_, float y_) : x(x_), y(y_) {}
};
*/

struct BoundingBox
{
	float x,y;
	float width,height;
	BoundingBox() : x(0), y(0), width(0), height(0) {}
	BoundingBox(float x_, float y_, float width_, float height_) :
				x(x_), y(y_), width(width_), height(height_) {}
};

class Circle
{
	public:
		Circle();
		Circle(float xPos, float yPos, float defaultRadius);

		float getRadius() const;		// Radius
		float getDiameter() const;	// Durchmesser

		Position const& getPos() const;
		BoundingBox getBBox() const;

		void setPos(float x, float y);
		void setRadius(float radius_);

	private:
		float radius;
		Position position;
		BoundingBox boundingBox;
};

#endif