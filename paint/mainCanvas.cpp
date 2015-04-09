#include "canvas.h"
#include "point.h"
#include <iostream>

using namespace std;

int main() {

	Canvas area;
	Point screen(300,100);

	area.setVertex(screen);
	area.setPanjang(700);
	area.setLebar(500);

	area.drawCanvas();
	return 0;
}