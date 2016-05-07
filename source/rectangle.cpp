#define _USE_MATH_DEFINES
#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle() {
	position = Position{};
	width = 0;
	height = 0;
	color = Color{};
}

Rectangle::Rectangle(float xPos, float yPos, float width_, float height_) {
	position = Position{xPos,yPos};
	width = (width_ < 0 ? (width_ * -1) : width_);
	height = (height_ < 0 ? (height_ * -1) : height_);
	color = Color{};
}

Rectangle::Rectangle(float xPos, float yPos, float width_, float height_, Color const& color_) {
	position = Position{xPos,yPos};
	width = (width_ < 0 ? (width_ * -1) : width_);
	height = (height_ < 0 ? (height_ * -1) : height_);
	color = color_;
}

// Getter ---------->

Position const& Rectangle::getPos() const {
	return position;
}

Position Rectangle::getCenter() const {
	return Position{position.x + width/2, position.y + height/2};
}

float Rectangle::getWidth() const {
	return width;
}

float Rectangle::getHeight() const {
	return height;
}

float Rectangle::getDiagonal() const {
	return sqrt(pow(width,2) + pow(height,2));
}

float Rectangle::getCircumCircle() const {
	float diagonal = getDiagonal();
	return diagonal/2;
}

float Rectangle::circumference() const {
	return (2*width + 2*height);
}

// Setter ---------->

void Rectangle::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Rectangle::setScale(float width_, float height_) {
	width = (width_ < 0 ? (width_ * -1) : width_);
	height = (height_ < 0 ? (height_ * -1) : height_);
}

// Functional ---------->

void Rectangle::draw(Window const& window, bool fill, bool outline) const
{
	if (fill) {
		int lineCount = height*800;
		for (int i = 0; i < lineCount; ++i) {
			float y = ((float)i/(float)lineCount) * height;
			window.draw_line(position.x,
							 position.y + y,
							 position.x + width,
							 position.y + y,
							 0.5f,0.5f,0.5f);
		}
	}

	if (outline) {
		Color c{0,0,0};
		window.draw_line(position.x, position.y, position.x + width, position.y, c.r, c.g, c.b);
		window.draw_line(position.x + width, position.y, position.x + width, position.y + height, c.r, c.g, c.b);
		window.draw_line(position.x, position.y, position.x, position.y + height, c.r, c.g, c.b);
		window.draw_line(position.x, position.y + height, position.x + width, position.y + height, c.r, c.g, c.b);
	}
}