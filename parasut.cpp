#include "kapal.h"

Parasut::Parasut()
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

Parasut::~Parasut(){}

//setter
//void setN(int N);
void Parasut::setVelocity(int velocity)
{
	this->velocity = velocity;
}
void Parasut::setPosition(Point position)
{
	this->position = position;
}

//getter
//int getN();
int Parasut::getVelocity()
{
	return velocity;
}

Point Parasut::getPosition()
{
	return position;
}

Point Parasut::getAnchorP1()
{
	return P1;
}

Point Parasut::getAnchorP2()
{
	return P2;
}

void Parasut::drawParasut(Buffer buff)
{
	int i;
	int n = 4;
	Point lambung[n];
	Point geladak[n];
	Point anjungan[n];
	Point meriam[n];
	Warna putih;
	
	/** lambung Parasut */
	
	/** end of meriam Parasut*/
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

