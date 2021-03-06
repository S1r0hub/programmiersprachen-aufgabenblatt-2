#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

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

class Rectangle
{
	public:
		Rectangle();
		Rectangle(float xPos, float yPos, float width_, float height_);
		Rectangle(float xPos, float yPos, float width_, float height_, Color const& color_);

		Position const& getPos() const;
		Position getCenter() const;
		float getWidth() const;
		float getHeight() const;
		float getDiagonal() const;		// Diagonalenlaenge
		float getCircumCircle() const;	// Umkreisradius
		float circumference() const;	// Umfang

		void setPos(float x, float y);
		void setScale(float width_, float height_);

		void draw(Window const& window, bool fill) const;
		void draw(Window const& window, Color const& color, bool fill) const;

		bool is_inside(float PointX, float PointY) const;

	private:
		Position position;
		float width;
		float height;
		Color color;
};

#endif