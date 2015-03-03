#include "bolaHeli.h"

BolaHeli::BolaHeli() {
	velocity = 0;
}

BolaHeli::~BolaHeli() {
	
}

void BolaHeli::setVelocity(int velocity){
	this.velocity = velocity;
}

void BolaHeli::setCenter(Point center){
	this.center = center;
}
		
int BolaHeli::getVelocity() {
	return velocity;
}

Point BolaHeli::getCenter(){
	return center;
}

void BolaHeli::drawTranslasi(Buffer buff){
	Warna warna;
	
}

void BolaHeli::drawMantul(Buffer buff){
	Warna warna;
	
}

void BolaHeli::clearTranslasi(Buffer buff){
	Warna warna;
	
}	

void BolaHeli::clearMantul(Buffer buff){
	Warna warna;
	
}
