#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "fill_scan.h"
#include "balok1tm.h"

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
	
	Warna putih;
	Buffer buff;
	char input;
	Point P(400,450);
	Point Pt(300,300);
	/*Point p(400,400);
	Point p1(1000,700);
	Warna biru(0,255,255);
	f.fillPolygon(600, 450, putih, buff);
	f.fillRect(p, 100, 200, putih, buff);
	f.fillPattern(p1, 135, putih, biru, buff);*/
	
	system("clear");
	Balok1TM B;
	B.drawBalok(Pt, P, 100, 100, 20, buff, putih);
	B.drawBalok(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, putih);
	B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);
	//B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);

	while(true) {

		if(kbhit()){
			input = getchar();
		 	if (input == 'l') {
		 		
		 		B.clear(Pt, P.getX(), P.getY(), 100, 100, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, *Warna::hitam());

		 		P.setX(P.getX()+10);
		 		if(P.getX() == Pt.getX()) {
		 			Pt.setX(Pt.getX()+1);
		 		}
		 		B.drawBalok(Pt, P, 100, 100, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);
		 	}

		 	else if (input == 'j') {

		 		B.clear(Pt, P.getX(), P.getY(), 100, 100, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, *Warna::hitam());

		 		P.setX(P.getX()-10);
		 		if(P.getX() == Pt.getX()) {
		 			Pt.setX(Pt.getX()-1);
		 		}
		 		B.drawBalok(Pt, P, 100, 100, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);	
		 	}

		 	else if (input == 'i') {

		 		B.clear(Pt, P.getX(), P.getY(), 100, 100, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, *Warna::hitam());

		 		P.setY(P.getY()-10);
		 		if(P.getY() == Pt.getY()) {
		 			Pt.setY(Pt.getY()-1);
		 		}
		 		B.drawBalok(Pt, P, 100, 100, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);	
		 	}

		 	else if (input == 'k') {

		 		B.clear(Pt, P.getX(), P.getY(), 100, 100, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, *Warna::hitam());
		 		B.clear(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, *Warna::hitam());

		 		P.setY(P.getY()+10);
		 		if(P.getY() == Pt.getY()) {
		 			Pt.setY(Pt.getY()+1);
		 		}
		 		B.drawBalok(Pt, P, 100, 100, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, putih);
				B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);	
		 	}

		 }
	}
	return 0;
}
