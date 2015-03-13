#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "garis.h"
#include "warna.h"
#include "buffer.h"
#include "awan.h"
#include "city_map.h"
#include "helikopter.h"
#include "clip.h"
#include "bentuk.h"

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
	const int batasAtas = 70;
	const int batasBawah = 470;
	const int batasKanan = 1250;
	const int batasKiri = 10;
	const int windowAtas = 500;
	const int windowBawah = 750;
	const int windowKanan = 700;
	const int windowKiri = 450;
	const int awanAwal = 1250;
	const int tinggi = 200;

	city_map map;
	Buffer buf; 
	Pixel pixel;
	Helikopter falcon;
	
	clip clip;
	Point va(windowKiri,windowAtas);
	clip.setViewSize(windowKanan-windowKiri);
	clip.setViewAnchor(va);
	
	int radiusAwan, yAwan;
	int i, check;
	bool move, on;
	char input;
	int ln[100][4];
	
	int v = 0;
	int phase = 1;
	on = true;

	system("clear");
	falcon.drawHeli(buf, 1);
	
	pixel.putPixel(*Warna::merah(), falcon.getAnchorP1(), buf);
	pixel.putPixel(*Warna::merah(), falcon.getAnchorP2(), buf);
	clip.setXmin(falcon.getAnchorP1().getX());
 	clip.setXmax(falcon.getAnchorP2().getX());
 	clip.setYmin(falcon.getAnchorP1().getY());
 	clip.setYmax(falcon.getAnchorP2().getY());


	//Garis boundary dan window
	static Garis batasA(batasKiri,batasAtas,batasKanan,batasAtas); batasA.drawLine(buf,*Warna::hijau());
	static Garis batasB(batasKiri,batasBawah,batasKanan,batasBawah); batasB.drawLine(buf,*Warna::hijau());
	static Garis batasKa(batasKanan,batasAtas, batasKanan, batasBawah); batasKa.drawLine(buf, *Warna::hijau());
	static Garis batasKi(batasKiri, batasAtas, batasKiri, batasBawah); batasKi.drawLine(buf, *Warna::hijau());
	static Garis windowA(windowKiri,windowAtas,windowKanan,windowAtas); windowA.drawLine(buf,*Warna::merah());
	static Garis windowB(windowKiri,windowBawah,windowKanan,windowBawah); windowB.drawLine(buf,*Warna::merah());
	static Garis windowKa(windowKanan,windowAtas, windowKanan, windowBawah); windowKa.drawLine(buf, *Warna::merah());
	static Garis windowKi(windowKiri, windowAtas, windowKiri, windowBawah); windowKi.drawLine(buf, *Warna::merah());


	while (on) {
		check = rand()%tinggi + 50;
		if (phase %2 == 0)
			map.addBuilding(buf, check);
		else 
			map.addCloud(buf,check-100);
		
		move = true;
		i = 0;
		
		while (move) {
			if(kbhit()){
				pixel.putPixel(*Warna::hitam(), falcon.getPosition(), buf);
				input = getchar();
				if (input == 'i'){
					v+=5;
					falcon.moveUp(buf,1,v);
			 	}
			 	else if (input == 'k') {
			 		v-=5;
					falcon.moveDown(buf,1,v);	
			 	}
				pixel.putPixel(*Warna::kuning(), falcon.getPosition(), buf);
				clip.setXmin(falcon.getAnchorP1().getX());
			 	clip.setXmax(falcon.getAnchorP2().getX());
 				clip.setYmin(falcon.getAnchorP1().getY());
 				clip.setYmax(falcon.getAnchorP2().getY());
			 	//cout << v;	
			}


			if(i < 720) {
				i+=10;
			}
			else {
				move = false;
			}

			if (phase %2 == 0)
				map.motion(i+50, buf, check);
			else 
				map.playCloud(i,buf,check-100);
			usleep(50000);	
		}
		if (phase%2 == 0)
			map.clearAll(1,buf, check);
		else 
			map.clearAll(2,buf,check-100);
		phase++;
	}

	buf.closeBuffer();
	return 0;
}