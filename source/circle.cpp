#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>

Circle::Circle() {
	radius = 0.0;
	position = Position{0,0};
	boundingBox = BoundingBox{0,0,0,0};
}

Circle::Circle(float xPos, float yPos, float defaultRadius) {
	radius = (defaultRadius < 0 ? (defaultRadius * -1) : defaultRadius);
	position = Position{xPos,yPos};
	boundingBox = BoundingBox{xPos - radius, yPos - defaultRadius, 2*radius, 2*radius};
}

// Getter ---------->

Position const& Circle::getPos() const {
	return position; }

BoundingBox Circle::getBBox() const {
	return boundingBox; }

float Circle::getRadius() const {
	return radius; }

float Circle::getDiameter() const {
	return 2*radius; }

float Circle::circumference() const {
	return 2*M_PI*radius;
}

// Setter ---------->

void Circle::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Circle::setRadius(float radius_) {
	radius = (radius_ < 0 ? (radius_ * -1) : radius_);
	boundingBox = BoundingBox{position.x - radius, position.y - radius, 2*radius, 2*radius};
}