#include "point.h"
#include <stdlib.h>

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

Point& Point::operator=(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
	return *this;
}
Point::~Point(){ }

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

int Point::getHeight(Point p1) {

	int jarak;

	jarak = abs(getY() - p1.getY());
	return jarak;
}

int Point::getWidth(Point p1) {
	int jarak;

	jarak = abs(getX() - p1.getX());
	return jarak;
}

Point Point::setHeight(int scale, Point p1) {


	static int length = getHeight(p1);
	if(getY()<p1.getY()) {

		setY(getY() - (length*(scale - 1)/2));
		p1.setY(p1.getY() + (length*(scale - 1)/2));
	}
	else {
		setY(getY() + (length*(scale - 1)/2));
		p1.setY(p1.getY() - (length*(scale - 1)/2)); 	
	}
	return p1;
}
		
Point Point::setWidth(int scale, Point p1) {

	static int length = getWidth(p1);
	if(getX()<p1.getX()) {
		setX(getX() - (length*(scale - 1)/2));
		p1.setX(p1.getX() + (length*(scale - 1)/2));
	}
	else {
		setX(getX() + (length*(scale - 1)/2));
		p1.setX(p1.getX() - (length*(scale - 1)/2)); 	
	}

	return p1;
}
