#ifndef _CANVAS_H
#define _CANVAS_H

#include "buffer.h"
#include "garis.h"
#include "bentuk.h"
#include "warna.h"
#include "buffer.h"

class Canvas{
	public:
		Canvas();
		~Canvas();
		
		Point getVertex();
		int getPanjang();
		int getLebar();
		void setVertex(Point p);
		void setPanjang(int length);
		void setLebar(int width);
		void drawCanvas();

	private:
		Bentuk area;
		Point vertex;
		int panjang;
		int lebar;
};

#endif
