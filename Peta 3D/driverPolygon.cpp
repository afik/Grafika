#include "polygon.h"
#include <iostream>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int main() {
	Polygon poly;
	vector<Point> lp;
	Point p(550, 495);
	Point p2(605, 500);
	Point p3(580, 515);
	Point p4(525, 510);
	lp.push_back(p);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	poly.addPoint(lp);
	
	Point* hasilSorting = poly.sortKumpulanPointHorizontal();
	for (int i=0; i<4; i++) {
		cout << "Hasil sorting absis point ke-" << i << " : " << hasilSorting[i].getX() << endl;
		cout << "Hasil sorting ordinat point ke-" << i << " : " << hasilSorting[i].getY() << endl;
	}
	cout << "Critical ordinat : " << poly.getCriticalOrdinatPoint(hasilSorting[0], hasilSorting[3]) << endl;
/*
	Polygon poly2;
	vector<Point> lp2;
	Point p21(600, 400);
	Point p22(700, 300);
	Point p32(800, 300);
	Point p42(1000, 400);
	Point p52(900, 500);
	Point p62(850, 500);
	lp2.push_back(p21);
	lp2.push_back(p22);
	lp2.push_back(p32);
	lp2.push_back(p42);
	lp2.push_back(p52);
	lp2.push_back(p62);
	poly2.addPoint(lp2);*/

	Buffer buff;
	char input;
<<<<<<< HEAD
	int heigth = 10;
=======
	int heigth = 300;
>>>>>>> bffce23450bbfddf7b78c74954a4014b87d8d24f
	
	poly.drawPolygon3D(buff, heigth, *Warna::putih());
	
	for (int i=0; i<poly.banyakGarisVisiblePolygon(); i++) {
		cout << "Garis ke-" << i << " poin A : (" << poly.getGarisVisiblePolygon(i).getPointP1().getX() 
		     << "," << poly.getGarisVisiblePolygon(i).getPointP1().getY() << ")" << endl;
		cout << "Garis ke-" << i << " poin B : (" << poly.getGarisVisiblePolygon(i).getPointP2().getX() 
		     << "," << poly.getGarisVisiblePolygon(i).getPointP2().getY() << ")" << endl;
		cout << "=======================================================================" << endl;
	}
	
	poly.clearPolygon(heigth);
	
	// CLIPPING TEST
	/*Bentuk gambarBatasClipping;
	Point kiriatas(400,400);
	gambarBatasClipping.persegi(kiriatas,100,100,buff,*Warna::putih);*/
	clip clipping;
	clipping.setXmin(495);
	clipping.setXmax(510);
	clipping.setYmin(470);
	clipping.setYmax(510);
	for (int i=0; i<poly.banyakGarisVisiblePolygon(); i++) {
		double x1 = (double) poly.getGarisVisiblePolygon(i).getPointP1().getX();
		double y1 = (double) poly.getGarisVisiblePolygon(i).getPointP1().getY();
		double x2 = (double) poly.getGarisVisiblePolygon(i).getPointP2().getX();
		double y2 = (double) poly.getGarisVisiblePolygon(i).getPointP2().getY();
		clipping.cohen_sutherland(x1,y1,x2,y2,buff);
	}
	
	//poly2.drawPolygon3D(buff, heigth, *Warna::putih());
	/*while(true) {
		if(kbhit()) {
			input = getchar();
			if(input == 'i') {
				poly.moveUp(heigth);
				//poly2.moveUp(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				//poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} else if(input == 'j') {
				poly.moveLeft(heigth);
				//poly2.moveLeft(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				//poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} else if(input == 'k') {
				poly.moveDown(heigth);
				//poly2.moveDown(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				//poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} else if(input == 'l') {
				poly.moveRight(heigth);
				//poly2.moveRight(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				//poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} 
		}
	}*/
	buff.closeBuffer();
	return 0;
}
