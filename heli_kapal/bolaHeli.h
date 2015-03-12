#ifndef _BOLAHELI_H
#define _BOLAHELI_H
#include "bentuk.h"
#include "buffer.h"

class BolaHeli{
	public:
		BolaHeli();
		~BolaHeli();
		
		//setter
		void setVelocity(int velocity);
		void setCenter(Point center);
		
		//getter
		int getVelocity();
		Point getCenter();
		
		void drawTranslasi(Buffer buff);
		void drawMantul(Buffer buff);
		void clearTranslasi(Buffer buff);
		void clearMantul(Buffer buff);			
		
	private:
		int velocity;	
		Point center;	
		
};

#endif

