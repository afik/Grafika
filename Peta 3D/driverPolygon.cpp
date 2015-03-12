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
	Point p(100, 100);
	Point p2(200, 100);
	Point p3(200, 200);
	Point p4(100, 200);
	lp.push_back(p);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	poly.addPoint(lp);
	Buffer buff;
	char input;
	
	poly.drawPolygon(buff);
	while(true) {
		if(kbhit()) {
			input = getchar();
			if(input == 'i') {
				poly.moveUp();
				poly.drawPolygon(buff);
			} else if(input == 'j') {
				poly.moveLeft();
				poly.drawPolygon(buff);
			} else if(input == 'k') {
				poly.moveDown();
				poly.drawPolygon(buff);
			} else if(input == 'l') {
				poly.moveRight();
				poly.drawPolygon(buff);
			} 
		}
	}
	buff.closeBuffer();
	return 0;
}