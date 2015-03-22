#ifndef _CLIPPING_H
#define _CLIPPING_H
#include "window.h"
#include "peta.h"
#include "point.h"
#include "buffer.h"

class Clipping{
	public:
		Clipping();
		~Clipping();
		void view(Point titikAwal, Buffer buff);
};


#endif