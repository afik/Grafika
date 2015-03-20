#include "polygon.h"
#include "clip.h"
#include "garis.h"
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
	int ukuranX = 1000;
	int ukuranY = 600;
	Polygon poly;
	int **matriks;
	matriks = (int**) malloc (ukuranY*sizeof(int*));
	for (int i = 0; i < ukuranY; ++i){
		matriks[i] = (int*) malloc (ukuranX*sizeof(int));
	}
	for (int i = 0; i < ukuranY; ++i){
		for(int j = 0; j < ukuranX; j++){
			matriks[i][j] = 0;
		}
	}
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
	// for (int i=0; i<4; i++) {
	// 	cout << "Hasil sorting absis point ke-" << i << " : " << hasilSorting[i].getX() << endl;
	// 	cout << "Hasil sorting ordinat point ke-" << i << " : " << hasilSorting[i].getY() << endl;
	// }
	// cout << "Critical ordinat : " << poly.getCriticalOrdinatPoint(hasilSorting[0], hasilSorting[3]) << endl;

	Polygon poly2;
	vector<Point> lp2;
	Point p21(570, 505);
	Point p22(625, 510);
	Point p23(600, 525);
	Point p24(545, 520);
	lp2.push_back(p21);
	lp2.push_back(p22);
	lp2.push_back(p23);
	lp2.push_back(p24);
	poly2.addPoint(lp2);

	Buffer buff;
	char input;
	int heigth = 100;
	poly2.drawPolygon3D(buff, heigth, *Warna::putih(), matriks);
	poly.drawPolygon3D(buff, heigth, *Warna::putih(), matriks);
	
	// for (int i=0; i<poly.banyakGarisVisiblePolygon(); i++) {
	// 	cout << "Garis ke-" << i << " poin A : (" << poly.getGarisVisiblePolygon(i).getPointP1().getX() 
	// 	     << "," << poly.getGarisVisiblePolygon(i).getPointP1().getY() << ")" << endl;
	// 	cout << "Garis ke-" << i << " poin B : (" << poly.getGarisVisiblePolygon(i).getPointP2().getX() 
	// 	     << "," << poly.getGarisVisiblePolygon(i).getPointP2().getY() << ")" << endl;
	// 	cout << "=======================================================================" << endl;
	// }
	
	// poly.clearPolygon(heigth, matriks);
	
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
		clipping.cohen_sutherland(x1,y1,x2,y2,*Warna::putih(),buff,matriks);
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
