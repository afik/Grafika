#ifndef _PICKER_H
#define _PICKER_H

#include "buffer.h"
#include "pixel.h"
#include "point.h"
#include "warna.h"

class Picker{
	public:
		Picker();
		~Picker();
		
		Warna getColour(Point P, Buffer buff);
		
		void drawPicker(Buffer buff);
	private:
		Warna warna;
		
};


#endif
