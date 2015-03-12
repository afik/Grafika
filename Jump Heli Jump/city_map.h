#ifndef _CITY_MAP_H
#define _CITY_MAP_H

#include "garis.h"
#include "warna.h"
#include "bentuk.h"

using namespace std;

class city_map
{
	public:
		city_map();
		~city_map();

		void addBuilding(Buffer buf, int height);
		void motion(int x, Buffer buf, int height);
		Bentuk getBuilding();
		void setBuilding(int offset, Buffer buf, int height);
		void clearBuilding(int offset, Buffer buf, int height);
		void clearAll(Buffer buf, int height);

	private:
		Bentuk b;
};

#endif