#ifndef _WARNA_H
#define _WARNA_H
#include <iostream>

using namespace std;

class Warna{
	public:
		int R;
		int G;
		int B;
		Warna() {
			R=255;
			G=255;
			B=255;
		}
		Warna(int R, int G, int B) {
			this->R = R;
			this->G = G;
			this->B = B;
		}
		~Warna() {}
	private:
	
};

#endif
