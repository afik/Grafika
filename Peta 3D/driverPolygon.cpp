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
	poly2.addPoint(lp2);

	Buffer buff;
	char input;
	int heigth = 300;
	
	//poly.drawPolygon(buff, *Warna::putih());
	poly.drawPolygon3D(buff, heigth, *Warna::putih());
	poly2.drawPolygon3D(buff, heigth, *Warna::putih());
	while(true) {
		if(kbhit()) {
			input = getchar();
			if(input == 'i') {
				poly.moveUp(heigth);
				poly2.moveUp(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} else if(input == 'j') {
				poly.moveLeft(heigth);
				poly2.moveLeft(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} else if(input == 'k') {
				poly.moveDown(heigth);
				poly2.moveDown(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} else if(input == 'l') {
				poly.moveRight(heigth);
				poly2.moveRight(heigth);
				poly.drawPolygon3D(buff, heigth, *Warna::putih());
				poly2.drawPolygon3D(buff, heigth, *Warna::putih());
			} 
		}
	}
	buff.closeBuffer();
	return 0;
}
