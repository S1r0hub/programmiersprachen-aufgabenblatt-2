#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>

#include <iostream>

Circle::Circle() {
	radius = 0.0;
	position = Position{};
	boundingBox = BoundingBox{};
	color = Color{};
}

Circle::Circle(float xPos, float yPos, float defaultRadius) {
	radius = (defaultRadius < 0 ? (defaultRadius * -1) : defaultRadius);
	position = Position{xPos,yPos};
	boundingBox = BoundingBox{xPos - radius, yPos - defaultRadius, 2*radius, 2*radius};
	color = Color{};
}

Circle::Circle(float xPos, float yPos, float defaultRadius, Color const& color_) {
	radius = (defaultRadius < 0 ? (defaultRadius * -1) : defaultRadius);
	position = Position{xPos,yPos};
	boundingBox = BoundingBox{xPos - radius, yPos - defaultRadius, 2*radius, 2*radius};
	color = color_;
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

// Functional ---------->

void Circle::draw(Window const& window, bool fill) const
{
	draw(window, color, fill);
}

void Circle::draw(Window const& window, Color const& color, bool fill) const
{
	if (fill) {
		int lineCount = 500;
		for (int i = 1; i <= lineCount; ++i) {
			float a = 2*M_PI*((float)i/(float)lineCount);
			window.draw_line(position.x,
							 position.y,
							 position.x + (float)(radius * cos(a)),
							 position.y + (float)(radius * sin(a)),
							 color.r,color.g,color.b);
		}
	}
	else
	{
		int segments = 50;
		for (int i = 1; i <= segments; ++i) {
			float a = 2*M_PI*((float)i/(float)segments);
			float b = 2*M_PI*((float)(i+1)/(float)segments);
			window.draw_line(position.x + (float)(radius * cos(a)),
							 position.y + (float)(radius * sin(a)),
							 position.x + (float)(radius * cos(b)),
							 position.y + (float)(radius * sin(b)),
							 color.r,color.g,color.b);
		}
	}
}

bool Circle::is_inside(float PointX, float PointY) const {
	float diffX = PointX - position.x;
	float diffY = PointY - position.y;
	float diffFromCenter = sqrt(pow(diffX,2) + pow(diffY,2));
	return ((diffFromCenter <= radius) ? true : false);
}