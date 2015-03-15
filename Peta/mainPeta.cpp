#include "peta.h"
#include "buffer.h"
#include <cstdio>
#include <cstdlib>


int main(){
	Peta peta;
	Buffer buff;
	int y = 100, x;
	peta.gambarPeta(y,buff,*Warna::putih());
	std::cin >> x;
	buff.closeBuffer();
	return 0;
}
