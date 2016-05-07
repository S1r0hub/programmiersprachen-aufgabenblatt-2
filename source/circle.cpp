#include "circle.hpp"

Circle::Circle() {
	radius = 0.0;
	position = Position{0,0};
	boundingBox = BoundingBox{0,0,0,0};
}

Circle::Circle(float xPos, float yPos, float defaultRadius) {
	radius = defaultRadius;
	position = Position{xPos,yPos};
	boundingBox = BoundingBox{xPos - defaultRadius, yPos - defaultRadius, 2*defaultRadius, 2*defaultRadius};
}

// Getter ---------->

float Circle::getRadius() const {
	return radius; }

float Circle::getDiameter() const {
	return 2*radius; }

Position const& Circle::getPos() const {
	return position; }

BoundingBox Circle::getBBox() const {
	return boundingBox; }

// Setter ---------->

void Circle::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Circle::setRadius(float radius_) {
	radius = (radius_ < 0 ? (radius_ * -1) : radius_);
	boundingBox = BoundingBox{position.x - radius, position.y - radius, 2*radius, 2*radius};
}