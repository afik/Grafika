#ifndef _PETA_H
#define _PETA_H
#include "polygon.h"
#include <vector>
#include "point.h"

class Peta{
	public:
		Peta();
		~Peta();
		void definePeta();
		void drawPeta();

		void setPolygon(int i, vector<Point> p);
		Polygon getPolygon(int i);
		int getNbPolygon();

	private:
	/* data */
		vector<Polygon> listPolygon;
};

#endif