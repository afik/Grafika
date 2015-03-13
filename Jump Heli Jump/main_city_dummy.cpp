#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "city_map.h"
#include "garis.h"
#include "buffer.h"
#include "helikopter.h"


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

	city_map map;
	Buffer buf;
	int i, check;
	bool move, on;
	Helikopter falcon;
	Awan awan;
	char input;

	int v = 0;
	int phase = 1;
	on = true;
	falcon.drawHeli(buf, 1);
	
	while (on) {

		check = rand()%200 + 50;
		if (phase %2 == 0)
			map.addBuilding(buf, check);
		else 
			map.addCloud(buf,check);
		
		move = true;
		i = 0;
		
		while (move) {
			if(kbhit()){
				input = getchar();
				if (input == 'i'){
					v+=5;
					falcon.moveUp(buf,1,v);
			 	}
			 	else if (input == 'k') {
			 		v-=5;
					falcon.moveDown(buf,1,v);	
			 	}
			 	cout << v;	
			}

			if(i < 800) {
				i+=10;
			}
			else {
				move = false;
			}
			if (phase %2 == 0)
				map.motion(i, buf, check);
			else 
				map.playCloud(i,buf,check);
			usleep(50000);	
		}
		phase++;
		map.clearAll(buf, check);
	}

	buf.closeBuffer();
	return 0;
}
