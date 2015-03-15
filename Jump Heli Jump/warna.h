#ifndef _WARNA_H
#define _WARNA_H
#include <iostream>

using namespace std;

class Warna{
	public:
		Warna();
		Warna(int R, int G, int B);
		Warna(const Warna& w);
		Warna& operator=(const Warna& w);
		~Warna();
		
		void setRed(int R);
		void setGreen(int G);
		void setBlue(int B);
		
		int getRed();
		int getGreen();
		int getBlue();
		
		static Warna* putih() {return wputih;}
		static Warna* hitam() {return whitam;}
		static Warna* merah() {return wmerah;}
		static Warna* biru() {return wbiru;}
		static Warna* hijau() {return whijau;}
		static Warna* kuning() {return wkuning;}
		static Warna* coklat() {return wcoklat;}
		static Warna* ungu() {return wungu;}
		static Warna* oranye() {return woranye;}
		static Warna* birutoska() {return wbirutoska;}
		static Warna* pink() {return wpink;}
		static Warna* birulangit() {return wbirulangit;}
		static Warna* softpink() {return wsoftpink;}
		static Warna* orenmuda() {return worenmuda;}
		static Warna* abu() {return wabu;}
		static Warna* violet() {return wviolet;}
		static Warna* shockpink() {return wshockpink;}

	private:
		static Warna* wputih;
		static Warna* whitam;
		static Warna* wmerah;
		static Warna* wbiru;
		static Warna* whijau;
		static Warna* wkuning;
		static Warna* wcoklat;
		static Warna* wungu;
		static Warna* woranye;
		static Warna* wbirutoska;
		static Warna* wpink;
		static Warna* wbirulangit;
		static Warna* wsoftpink;
		static Warna* worenmuda;
		static Warna* wabu;
		static Warna* wviolet;
		static Warna* wshockpink;
		int R;	//Red
		int G;	//Green
		int B;	//Blue
};

#endif
