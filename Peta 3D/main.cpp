#include "peta.h"
#include "clip.h"
#include "garis.h"
#include "buffer.h"
#include <iostream>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <vector>

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
void drawWindowClip(int xmin, int ymin, int xmax, int ymax, Warna w, Buffer buff){
	Point p1(xmin, ymin);
	Point p2(xmax, ymin);
	Point p3(xmax, ymax);
	Point p4(xmin, ymax);
	Garis g1(p1,p2); g1.drawLine(buff, w);
	Garis g2(p2,p3); g2.drawLine(buff, w);
	Garis g3(p3,p4); g3.drawLine(buff, w);
	Garis g4(p4,p1); g4.drawLine(buff, w);
}
int main(){
	char x;
	int ln[100][4];
	int xc = 500, yc = 500;
	Peta peta;
	vector<Garis> listGaris;
	Garis tempGaris;
	clip c;
	Buffer buff;
	Point awal(500,100);
	peta.definePeta(awal);
	peta.drawPeta3D(buff,10);
	for(int i = 0; i < peta.getNbPolygon(); i++){
		for(int j = 0; j < peta.getPolygon(i).banyakGarisVisiblePolygon(); j++){
			tempGaris = peta.getPolygon(i).getGarisVisiblePolygon(j);
			listGaris.push_back(tempGaris);
		}
	}
	c.setXmin(xc);
	c.setXmax(xc + 50);
	c.setYmin(yc);
	c.setYmax(yc + 50);
	c.setViewSize(200);
	Point anchor(800,600);
	c.setViewAnchor(anchor);
	// clipping(c,ln,listGaris);
	while(true){
		if(kbhit()){
			char input = getchar();
			switch(input){
				case 'i' :{
					c.setYmin(c.getYmin() - 5);
					// drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// clipping(c,ln,listGaris, *Warna::putih(), buff);
					break;
				}
				case 'j' :{
					c.setXmin(c.getXmin() - 5);
					// c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// clipping(c,ln,listGaris, *Warna::putih(), buff);
					break;
				}
				case 'k' : {
					yc = yc + 5 ;
					c.setYmin(c.getYmin() + 5);
					// c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// clipping(c,ln,listGaris, *Warna::putih(), buff);
					break;
				}
				case 'l' :{
					xc = xc + 5;
					c.setXmin(c.getXmin() + 5);
					// c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// clipping(c,ln,listGaris, *Warna::putih(), buff);
					break;
				}
				case 'a' :{
					c.setXmin(c.getXmin() - 5);
					c.setXmax(c.getXmax() + 5);
					c.setYmin(c.getYmin() - 5);
					c.setYmax(c.getYmax() + 5);
					// c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// clipping(c,ln,listGaris, *Warna::putih(), buff);
					break;
				}
				case 'd' :{
					c.setXmin(c.getXmin() + 5);
					c.setXmax(c.getXmax() - 5);
					c.setYmin(c.getYmin() + 5);
					c.setYmax(c.getYmax() - 5);
					// c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					// clipping(c,ln,listGaris, *Warna::putih(), buff);
					break;
				}
				default :
					break;
			}
			drawWindowClip(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
			for (int i = 0; i < listGaris.size(); i++) {
		 		ln[i][0] = listGaris[i].getPointP1().getX();
		 		ln[i][1] = listGaris[i].getPointP1().getY();
		 		ln[i][2] = listGaris[i].getPointP2().getX();
		 		ln[i][3] = listGaris[i].getPointP2().getY();
			}
			for (int i = 0; i < listGaris.size(); i++){
				c.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], *Warna::putih(), buff);
			}
		}
	}
	return 0;
}