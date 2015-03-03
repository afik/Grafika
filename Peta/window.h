#ifndef _WINDOW_H
#define _WINDOW_H
#include <iostream>
#include "point.h"
#include "warna.h"
#include "bentuk.h"

using namespace std;

class Window{
	public:
		Window();
		Window(Point initPos);
		~Window();

		void setP1(Point p);
		void setP2(Point p);
		Point getP1();
		Point getP2();

		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();

		void zoomIn();
		void zoomOut();

		void draw(Buffer buf, Warna w);

	private:
		Point P1; //posisi pojok kiri atas
		int Panjang;
		int Lebar;
		Point tempP; //untuk hapus
		int tempPjg;
		int tempLebar;
		Point center;
};

#endif

