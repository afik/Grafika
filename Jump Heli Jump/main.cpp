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
	const int batasBawah = 370;
	const int batasKanan = 1250;
	const int batasKiri = 10;
	const int windowAtas = 400;
	const int windowBawah = 750;
	const int windowKanan = 795;
	const int windowKiri = 445;
	const int awanAwal = 1250;

	Buffer buf; 
	Pixel pixel;
	int radiusAwan, yAwan;

	system("clear");

	//Garis boundary dan window
	static Garis batasA(batasKiri,batasAtas,batasKanan,batasAtas); batasA.drawLine(buf,*Warna::hijau());
	static Garis batasB(batasKiri,batasBawah,batasKanan,batasBawah); batasB.drawLine(buf,*Warna::hijau());
	static Garis batasKa(batasKanan,batasAtas, batasKanan, batasBawah); batasKa.drawLine(buf, *Warna::hijau());
	static Garis batasKi(batasKiri, batasAtas, batasKiri, batasBawah); batasKi.drawLine(buf, *Warna::hijau());
	static Garis windowA(windowKiri,windowAtas,windowKanan,windowAtas); windowA.drawLine(buf,*Warna::merah());
	static Garis windowB(windowKiri,windowBawah,windowKanan,windowBawah); windowB.drawLine(buf,*Warna::merah());
	static Garis windowKa(windowKanan,windowAtas, windowKanan, windowBawah); windowKa.drawLine(buf, *Warna::merah());
	static Garis windowKi(windowKiri, windowAtas, windowKiri, windowBawah); windowKi.drawLine(buf, *Warna::merah());

	//awan
	Awan a(buf,awanAwal,200,50);
	pixel.putPixel(*Warna::kuning(),a.getBoundary()[0], a.getBoundary()[1],buf);	
	pixel.putPixel(*Warna::kuning(),a.getBoundary()[0], a.getBoundary()[2],buf);	
	
	getchar();
	buf.closeBuffer();
	return 0;
}