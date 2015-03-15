#ifndef _PETA_H
#define _PETA_H
#include "polygon.h"
#include <vector>
#include "point.h"
#include "buffer.h"
#include "warna.h"

class Peta{
	public:
		Peta();
		~Peta();
		void definePeta(Point p0);
		void drawPeta(Buffer buff);
		void drawPeta3D(Buffer buff, int height);

		void setPolygon(Point center, vector<Point> p);
		Polygon getPolygon(int i);
		int getNbPolygon();

	private:
		vector<Point> bentukPersegi(Point a1, Point a2);
		/* data */
		vector<Polygon> listPolygon;
};

#endif