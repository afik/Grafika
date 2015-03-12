#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "city_map.h"
#include "garis.h"
#include "buffer.h"
#include "helikopter.h"


using namespace std;

int main() {

	city_map map;
	Buffer buf;
	int i, check;
	bool move, on;
	Helikopter falcon;

	on = true;
	falcon.drawHeli(buf, 1);

	while (on) {

		check = rand()%200 + 50;
		cout << check << endl;
		map.addBuilding(buf, check);
		move = true;
		i = 0;

		while (move) {

			if(i < 800) {
				i+=10;
			}
			else {
				move = false;
			}

			map.motion(i, buf, check);
			usleep(50000);	
		}

		map.clearAll(buf, check);
	}
	
	return 0;
}
