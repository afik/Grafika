#ifndef _POLYGON_H
#define _POLYGON_H

#include "point.h"
#include "garis.h"
#include "warna.h"
#include "buffer.h"
#include "pixel.h"
#include <vector>

class Polygon {
	// Atribut kelas
private:
	vector<Point> vertice;
	Warna warna;
	// Method Utama
public:	
	Polygon();
	bool isClosed();
	bool isStop();
	bool isAround(Point p);
	void addPoint(Point p);
	void setWarna(Warna w);
	void drawPolygon();
};

#endif
