#include "peta.h"
#include <iostream>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(){
	char x;
	Peta peta;
	Buffer buff;
	peta.drawPeta(buff);
	cin >> x;
	return 0;
}