#ifndef _POINT_H
#define _POINT_H
#include <iostream>

using namespace std;

class Point{
	public:
		Point();
		Point(int x, int y);
		Point(const Point& p);
		Point& operator=(const Point& p);
		~Point();
		
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
		int getHeight(Point p1);
		int getWidth(Point p1);
		Point setHeight(int scale, Point p1);
		Point setWidth(int scale, Point p1);
		
	private:
		int x;
		int y;
};

#endif
