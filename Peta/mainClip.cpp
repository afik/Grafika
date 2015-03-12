#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "window.h"
#include "peta.h"
#include "buffer.h"
#include "clip.h"
#include "scanline.h"
#include "fill.h"

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
	Peta peta;
	Buffer buff;
	clip clip;
	int y = 100, x;
	peta.gambarPeta(y,buff,*Warna::putih());
	Bentuk bentuk;
    Scanline scan;
    Fill fill;
    Garis w1(801,501,801,599);
    Garis w2(899,501,899,599);
    int ln[100][4];
    int numSumatra = 0,numJawa = 0,numKalimantan = 0,numSulawesi = 0;

    Pixel pixel;
    Point view(800, 500);
    bentuk.persegi(view, 100, 100, buff, *Warna::putih());
    Point posisi(300,300);
	char input;

	Window window(posisi);

	window.draw(buff, *Warna::putih());
	
	while(1){
		for (int i = 801; i<899; i++){
			for (int j = 501; j<599; j++){
				pixel.putPixel(*Warna::hitam(),i,j,buff);
			}
		}

		if(kbhit()){
			input = getchar();
			if (input == 'j'){
				window.moveLeft();
		 		window.draw(buff, *Warna::putih());
		 		peta.gambarPeta(y,buff,*Warna::putih());
		 	}
		 	else if (input == 'l') {
		 		window.moveRight();
		 		window.draw(buff, *Warna::putih());
		 		peta.gambarPeta(y,buff,*Warna::putih());
		 	}
		 	else if (input == 'i') {
		 		window.moveUp();
		 		window.draw(buff, *Warna::putih());
		 		peta.gambarPeta(y,buff,*Warna::putih());
		 	}
		 	else if (input == 'k') {
		 		window.moveDown();
		 		window.draw(buff, *Warna::putih());
		 		peta.gambarPeta(y,buff,*Warna::putih());
		 	}
		 	else if (input == 'a') {
		 		window.zoomIn();
		 		window.draw(buff, *Warna::putih());
		 		peta.gambarPeta(y,buff,*Warna::putih());
		 	}
		 	else if (input == 's') {
		 		window.zoomOut();
		 		window.draw(buff, *Warna::putih());
		 		peta.gambarPeta(y,buff,*Warna::putih());
		 	}		
		 }

		clip.setXmin(window.getP1().getX());
	 	clip.setXmax(window.getP1().getX()+window.getPanjang());
	 	clip.setYmin(window.getP1().getY());
	 	clip.setYmax(window.getP1().getY()+window.getLebar());

	 	numSumatra = sizeof(peta.petaSumatra)/sizeof (*peta.petaSumatra);
	 	for (int i = 0; i < numSumatra; i++) {
	 		ln[i][1] = peta.petaSumatra[i].getPointP1().getX();
	 		ln[i][2] = peta.petaSumatra[i].getPointP1().getY();
	 		ln[i][3] = peta.petaSumatra[i].getPointP2().getX();
	 		ln[i][4] = peta.petaSumatra[i].getPointP2().getY();
	 	}

	 	for (int i = 0; i < numSumatra; i++){
			clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], buff);
		}

	 	numJawa = sizeof(peta.petaJawa)/sizeof (*peta.petaJawa);
	 	for (int i = 0; i < numJawa; i++) {
	 		ln[i][1] = peta.petaJawa[i].getPointP1().getX();
	 		ln[i][2] = peta.petaJawa[i].getPointP1().getY();
	 		ln[i][3] = peta.petaJawa[i].getPointP2().getX();
	 		ln[i][4] = peta.petaJawa[i].getPointP2().getY();
	 	}

	 	for (int i = 0; i < numJawa; i++){
			clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], buff);
		}

	 	numKalimantan = sizeof(peta.petaKalimantan)/sizeof (*peta.petaKalimantan);
	 	for (int i = 0; i < numKalimantan; i++) {
	 		ln[i][1] = peta.petaKalimantan[i].getPointP1().getX();
	 		ln[i][2] = peta.petaKalimantan[i].getPointP1().getY();
	 		ln[i][3] = peta.petaKalimantan[i].getPointP2().getX();
	 		ln[i][4] = peta.petaKalimantan[i].getPointP2().getY();
	 	}

	 	for (int i = 0; i < numKalimantan; i++){
			clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], buff);
		}

	 	numSulawesi = sizeof(peta.petaSulawesi)/sizeof (*peta.petaSulawesi);
	 	for (int i = 0; i < numSulawesi; i++) {
	 		ln[i][1] = peta.petaSulawesi[i].getPointP1().getX();
	 		ln[i][2] = peta.petaSulawesi[i].getPointP1().getY();
	 		ln[i][3] = peta.petaSulawesi[i].getPointP2().getX();
	 		ln[i][4] = peta.petaSulawesi[i].getPointP2().getY();
	 	}

	 	for (int i = 0; i < numSulawesi; i++){
			clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], buff);
		}


	}
 	buff.closeBuffer();
	return 0;
}