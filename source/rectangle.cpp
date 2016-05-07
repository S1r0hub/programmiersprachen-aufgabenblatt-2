#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle() {
	position = Position{0,0};
	width = 0;
	height = 0;
}

Rectangle::Rectangle(float xPos, float yPos, float width_, float height_) {
	position = Position{xPos,yPos};
	width = width_;
	height = height_;
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

// Setter ---------->

void Rectangle::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Rectangle::setScale(float width_, float height_) {
	width = (width_ < 0 ? (width_ * -1) : width_);
	height = (height_ < 0 ? (height_ * -1) : height_);
}