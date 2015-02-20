#ifndef _WARNA_H
#define _WARNA_H
#include <iostream>

using namespace std;

class Warna{
	public:
		Warna();
		Warna(int R, int G, int B);
		~Warna();
		
		void setRed(int R);
		void setGreen(int G);
		void setBlue(int B);
		
		int getRed();
		int getGreen();
		int getBlue();
	private:
		int R;	//Red
		int G;	//Green
		int B;	//Blue
};

#endif
