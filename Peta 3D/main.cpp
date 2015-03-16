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

int main(){
	char x;
	int xc = 50, yc = 50;
	Peta peta;
	vector<Garis> listGaris;
	clip c;
	Buffer buff;
	Point awal(500,500);
	peta.definePeta(awal);
	peta.drawPeta3D(buff,10);
	c.setXmin(xc);
	c.setXmax(xc + 50);
	c.setYmin(yc);
	c.setYmax(yc + 50);

	while(true){
		if(kbhit()){
			char input = getchar();
			switch(input){
				case 'i' :{
					c.setYmin(c.getYmin() - 5);
					c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					break;
				}
				case 'j' :{
					c.setXmin(c.getXmin() - 5);
					c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					break;
				}
				case 'k' : {
					yc = yc + 5 ;
					c.setYmin(c.getYmin() + 5);
					c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					break;
				}
				case 'l' :{
					xc = xc + 5;
					c.setXmin(c.getXmin() + 5);
					c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					break;
				}
				case 'a' :{
					c.setXmin(c.getXmin() - 5);
					c.setXmax(c.getXmax() + 5);
					c.setYmin(c.getYmin() - 5);
					c.setYmax(c.getYmax() + 5);
					c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					break;
				}
				case 'd' :{
					c.setXmin(c.getXmin() + 5);
					c.setXmax(c.getXmax() - 5);
					c.setYmin(c.getYmin() + 5);
					c.setYmax(c.getYmax() - 5);
					c.cohen_sutherland(c.getXmin(), c.getYmin(), c.getXmax(), c.getYmax(), *Warna::putih(), buff);
					break;
				}
				default :
					break;
			}
		}
	}
	return 0;
}