#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "position2.hpp"
#include "color.hpp"
#include "window.hpp"

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
		Circle(float xPos, float yPos, float defaultRadius, Color const& color_);

		Position const& getPos() const;
		BoundingBox getBBox() const;
		float getRadius() const;		// Radius
		float getDiameter() const;		// Durchmesser
		float circumference() const;	// Umfang

		void setPos(float x, float y);
		void setRadius(float radius_);

		void draw(Window const& window, bool fill) const;
		void draw(Window const& window, Color const& color, bool fill) const;

		bool is_inside(float PointX, float PointY) const;

	private:
		float radius;
		Position position;
		BoundingBox boundingBox;
		Color color;
};

#endif