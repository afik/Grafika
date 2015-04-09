#ifndef _CITY_MAP_H
#define _CITY_MAP_H

#include "garis.h"
#include "warna.h"
#include "bentuk.h"
#include "awan.h"
#include "polygon.h"
#include "fill_scan.h"

using namespace std;

class city_map
{
	public:
		city_map();
		~city_map();

		void addCloud(Buffer buf, int height);
		void addBuilding(Buffer buf, int height);
		void playCloud(int x,Buffer buf, int height);
		void motion(int x, Buffer buf, int height);
		Polygon getPoly();
		Awan getCloud();
		void setBuilding(int offset, Buffer buf, int height);
		void clearBuilding(int x,Buffer buf, int height);
		void clearCloud(Buffer buf);
		void clearAll(int flag, Buffer buf, int height);

	private:
		static const int lebarBuilding = 75;

		Polygon poly, poly2;
		Awan awan;
		int tempAwan, posAwan;
		Point pBuild, pPoly;
		int tempBuild, posBuild;

		int ukuranX;
		int ukuranY;
		int **matriks;
	
};

#endif