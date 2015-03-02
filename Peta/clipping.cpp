#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "garis.h"
#include "bentuk.h"

#define MAX 100
using namespace std;

enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8};

typedef unsigned int outcode;

outcode compute_outcode(int x, int y, int xmin, int ymin, int xmax, int ymax) {

	outcode oc = 0;
	if (y > ymax)
		oc |= TOP;
	else if (y < ymin)
		oc |= BOTTOM;

	if (x > xmax)
		oc |= RIGHT;
	else if (x < xmin)
		oc |= LEFT;

	return oc;
}

void cohen_sutherland (double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax, Buffer buff) {

	bool accept;
	bool done;
	outcode outcode1, outcode2;

	accept = false;
	done = false;

	outcode1 = compute_outcode(x1, y1, xmin, ymin, xmax, ymax);
	outcode2 = compute_outcode(x2, y2, xmin, ymin, xmax, ymax);

	do {
		if (outcode1 == 0 && outcode2 == 0) {
			accept = true;
			done = true;
		}
		else if (outcode1 & outcode2) {
			done = true;
		}
		else {
			double x, y;
			int outcode_ex = outcode1 ? outcode1 : outcode2;

			if (outcode_ex & TOP) {
				x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
				y = ymax;
			}

			else if (outcode_ex & BOTTOM) {
				x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
				y = ymin;	
			}

			else if (outcode_ex & RIGHT) {
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
				x = xmax;
			}

			else {
				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
				x = xmin;	
			}

			if (outcode_ex == outcode1) {
				x1 = x;
				y1 = y;
				outcode1 = compute_outcode(x1, y1, xmin, ymin, xmax, ymax);
			}

			else {
				x2 = x;
				y2 = y;
				outcode2 = compute_outcode(x2, y2, xmin, ymin, xmax, ymax);	
			}
		}
	} while (!done);

	if (accept) {
		Garis g(x1, y1, x2, y2);
		g.drawLine(buff, *Warna::putih());
	}
}

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

	int n;
	int i, j;
	int ln[100][4];
	int clip[4];
	Buffer buf;
	Warna putih;
	Bentuk persegi;


	cout << "Enter the number of lines to be clipped" << endl;
	n = 2;

	cout << "Enter the x and y coordinates of line endpoints" << endl;
	ln[0][0] = 110;
	ln[0][1] = 110;
	ln[0][2] = 180;
	ln[0][3] = 110;
	ln[1][0] = 110;
	ln[1][1] = 110;
	ln[1][2] = 170;
	ln[1][3] = 220;

	cout << "Enter the x and y coordinates of left-top and right-bottom corners" << endl;	
	clip[0] = 100;
	clip[1] = 100;
	clip[2] = 200;
	clip[3] = 200;

	Point p(clip[0], clip[1]);
	Garis g;
	persegi.persegi(p, clip[2]-clip[0], clip[3]-clip[1], buf, putih);
	
	Point p1, p2;
	for (i=0; i<n; i++) {

		p1.setX(ln[i][0]); 
		p1.setY(ln[i][1]);
		p2.setX(ln[i][2]); 
		p2.setY(ln[i][3]);

		g.setPointP1(p1);
		g.setPointP2(p2);
		g.drawLine(buf, putih);
	}
	system("clear");
	// char c = getchar();
	// if (kbhit()) {
	persegi.persegi(p, clip[2]-clip[0], clip[3]-clip[0], buf, putih);

		for (int i = 0; i < n; i++){
			cohen_sutherland (ln[i][0], ln[i][1], ln[i][2], ln[i][3],clip[0], clip[1], clip[2], clip[3], buf);
		}
	// }

	buf.closeBuffer();
}
