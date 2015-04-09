#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "window.h"
#include "peta.h"

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

int main()
{
	Buffer buff;
	Warna warna;
	Pixel pixel;
	Peta peta;
	Point posisi(300,300);
	char input;

	Window window(posisi);

	window.draw(buff, *Warna::putih());
	peta.gambarPeta(100,buff);
	while(true){
		if(kbhit()){
			input = getchar();
			if (input == 'j'){
				window.moveLeft();
		 		window.draw(buff, *Warna::putih());
		 		
		 	}
		 	else if (input == 'l') {
		 		window.moveRight();
		 		window.draw(buff, *Warna::putih());
		 	}
		 	else if (input == 'i') {
		 		window.moveUp();
		 		window.draw(buff, *Warna::putih());
		 	}
		 	else if (input == 'k') {
		 		window.moveDown();
		 		window.draw(buff, *Warna::putih());
		 	}
		 	else if (input == 'a') {
		 		window.zoomIn();
		 		window.draw(buff, *Warna::putih());
		 	}
		 	else if (input == 's') {
		 		window.zoomOut();
		 		window.draw(buff, *Warna::putih());
		 	}		
		 }
 	}
	buff.closeBuffer();
	return 0;
}
