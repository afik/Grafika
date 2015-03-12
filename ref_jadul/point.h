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
		
	private:
		int x;
		int y;
};

#endif
