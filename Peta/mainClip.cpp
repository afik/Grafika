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
    std::vector<Garis> garis1, garis2, garis3, garis4;

    Point view(1000, 500);
    bentuk.persegi(view, 50, 50, buff, *Warna::putih());
    Point posisi(300,300);
	char input;

	Window window(posisi);

	window.draw(buff, *Warna::putih());
	
	while(true){
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
 	}
 	clip.setXmin(window.getP1().getX());
 	clip.setXmax(window.getP1().getX()+window.getPanjang());
 	clip.setYmin(window.getP1().getY());
 	clip.setYmax(window.getP1().getY()+window.getLebar());

 	garis1 = clip.cekGaris(peta.petaSumatra);
 	for (int i=0; i<garis1.size();i++) {
 		clip.cohen_sutherland(view.getX(),view.getY(),garis1[i].getPointP1().getX(),garis1[i].getPointP1().getY(),garis1[i].getPointP2().getX(),garis1[i].getPointP2().getY(),buff);
 	}

	garis2 = clip.cekGaris(peta.petaJawa);
 	for (int i=0; i<garis2.size();i++) {
 		clip.cohen_sutherland(view.getX(),view.getY(),garis2[i].getPointP1().getX(),garis2[i].getPointP1().getY(),garis2[i].getPointP2().getX(),garis2[i].getPointP2().getY(),buff);
 	}

 	garis3 = clip.cekGaris(peta.petaKalimantan);
 	for (int i=0; i<garis3.size();i++) {
 		clip.cohen_sutherland(view.getX(),view.getY(),garis3[i].getPointP1().getX(),garis3[i].getPointP1().getY(),garis3[i].getPointP2().getX(),garis3[i].getPointP2().getY(),buff);
 	}

 	garis4 = clip.cekGaris(peta.petaSulawesi);
 	for (int i=0; i<garis4.size();i++) {
 		clip.cohen_sutherland(view.getX(),view.getY(),garis4[i].getPointP1().getX(),garis4[i].getPointP1().getY(),garis4[i].getPointP2().getX(),garis4[i].getPointP2().getY(),buff);
 	} 	

 	buff.closeBuffer();
	return 0;
}