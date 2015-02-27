#include "helikopter.h"

Helikopter::Helikopter()
{
	N = 0;
	velocity = 0;
	P1.setX(0);
	P1.setY(0);
	P2.setX(0);
	P2.setY(0);
	position.setX(0);
	position.setY(0);
}

Helikopter::~Helikopter(){}

//setter
//void setN(int N);
void Helikopter::setVelocity(int velocity)
{
	this->velocity = velocity;
}
void Helikopter::setPosition(Point position)
{
	this->position = position;
}

//getter
//int getN();
int Helikopter::getVelocity()
{
	return velocity;
}

Point Helikopter::getPosition()
{
	return position;
}

Point Helikopter::getAnchorP1()
{
	return P1;
}

Point Helikopter::getAnchorP2()
{
	return P2;
}

void Helikopter::drawHeli(Buffer buff, int scale)
{
	badan.drawbadanHeli(buff, scale, this->getVelocity());
	//badan.zoom(buff, 2, this->getVelocity());
	ekor.drawekorHeli(buff, this->getVelocity());
	

	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

void Helikopter::clearHeli(Buffer buff, int scale)
{
	badan.clearbadanHeli(buff, scale, this->getVelocity());
	ekor.clearekorHeli(buff, this->getVelocity());
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

void Helikopter::drawJatuh(Buffer buff, int scale) {
	badan.drawbadanJatuh(buff, scale, this->getVelocity());
	ekor.drawekorJatuh(buff, this->getVelocity());
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

void Helikopter::clearJatuh(Buffer buff, int scale) {
	badan.clearbadanJatuh(buff, scale, this->getVelocity());
	ekor.clearekorJatuh(buff, this->getVelocity());
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);

}