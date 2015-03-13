#include <iostream>
#include "buffer.h"
#include "picker.h"

using namespace std;

int main(){
	Picker pick;
	Buffer buff;
	Point P(300, 200);
	
	pick.drawPicker(buff);
	//pick.getColour(P, buff);
	
	return 0;
}
