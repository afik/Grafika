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
	// cout << poly.getCentrePolygon().getY() << endl;
	// cout << poly.getCentrePolygon().getX() << endl;

	// Point p(400, 400);
	// Polygon poly2(p); 
	// cout << poly2.getCentrePolygon().getY() << endl;
	// cout << poly2.getCentrePolygon().getX() << endl;

	// Polygon poly3(poly2);
	// cout << poly3.getCentrePolygon().getY() << endl;
	// cout << poly3.getCentrePolygon().getX() << endl;

	// Polygon poly4 = poly;	
	// cout << poly4.getCentrePolygon().getY() << endl;
	// cout << poly4.getCentrePolygon().getX() << endl;

	vector<Point> lp;
	Point p(100, 400);
	Point p2(200, 300);
	Point p3(300, 300);
	Point p4(500, 400);
	Point p5(400, 500);
	Point p6(350, 500);
	lp.push_back(p);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	lp.push_back(p5);
	lp.push_back(p6);
	poly.addPoint(lp);
	Buffer buff;
	char input;

	Point* arrayPoint = poly.sortKumpulanPointHorizontal();
	for (int i=0; i<6; i++) {
		cout << "Absis point koordinat ke-" << i << " : " << arrayPoint[i].getX() << endl;
		cout << "Ordinat point koordinat ke-" << i << " : " << arrayPoint[i].getY() << endl;
	}
	cout << "Critical ordinat : " << poly.getCriticalOrdinatPoint(arrayPoint[0], arrayPoint[3]) << endl;
	
	//poly.drawPolygon(buff, *Warna::putih());
	poly.drawPolygon3D(buff, 300, *Warna::putih());
	while(true) {
		if(kbhit()) {
			input = getchar();
			if(input == 'i') {
				poly.moveUp();
				poly.drawPolygon(buff, *Warna::putih());
			} else if(input == 'j') {
				poly.moveLeft();
				poly.drawPolygon(buff, *Warna::putih());
			} else if(input == 'k') {
				poly.moveDown();
				poly.drawPolygon(buff, *Warna::putih());
			} else if(input == 'l') {
				poly.moveRight();
				poly.drawPolygon(buff, *Warna::putih());
			} 
		}
	}
	buff.closeBuffer();
	return 0;
}
