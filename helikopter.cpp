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

void Helikopter::drawHeli(Buffer buff)
{
	int i;
	int n = 4;
	Point badan[n];
	Point ekor[n];
	Warna putih;
	
	/** badan helikopter */
	badan[0].setX(700);
	badan[0].setY(100);
	badan[1].setX(800);
	badan[1].setY(100);
	badan[2].setX(800);
	badan[2].setY(150);
	badan[3].setX(700);
	badan[3].setY(150);
	
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX()-this->getVelocity(), badan[i].getY(),
					badan[i+1].getX()-this->getVelocity(), badan[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX()-this->getVelocity(), badan[i].getY(),
					badan[0].getX()-this->getVelocity(), badan[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of badan helikopter*/
	
	/** ekor helikopter */
	ekor[0].setX(800);
	ekor[0].setY(115);
	ekor[1].setX(900);
	ekor[1].setY(115);
	ekor[2].setX(930);
	ekor[2].setY(100);
	ekor[3].setX(930);
	ekor[3].setY(130);
	ekor[4].setX(800);
	ekor[4].setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX()-this->getVelocity(), ekor[i].getY(),
					ekor[i+1].getX()-this->getVelocity(), ekor[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(ekor[i].getX()-this->getVelocity(), ekor[i].getY(),
					ekor[0].getX()-this->getVelocity(), ekor[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of ekor helikopter*/

	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

void Helikopter::clearHeli(Buffer buff)
{
	int i;
	int n = 4;
	Point badan[n];
	Point ekor[n];
	Point anjungan[n];
	Point meriam[n];
	Warna putih(0,0,0);

	/** badan helikopter */
	badan[0].setX(700);
	badan[0].setY(100);
	badan[1].setX(800);
	badan[1].setY(100);
	badan[2].setX(800);
	badan[2].setY(150);
	badan[3].setX(700);
	badan[3].setY(150);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX()-this->getVelocity()+1, badan[i].getY(),
					badan[i+1].getX()-this->getVelocity()+1, badan[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX()-this->getVelocity()+1, badan[i].getY(),
					badan[0].getX()-this->getVelocity()+1, badan[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of badan helikopter*/
	
	/** ekor helikopter */
	ekor[0].setX(800);
	ekor[0].setY(115);
	ekor[1].setX(900);
	ekor[1].setY(115);
	ekor[2].setX(930);
	ekor[2].setY(100);
	ekor[3].setX(930);
	ekor[3].setY(130);
	ekor[4].setX(800);
	ekor[4].setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(ekor[i].getX()-this->getVelocity()+1, ekor[i].getY(),
					ekor[i+1].getX()-this->getVelocity()+1, ekor[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(ekor[i].getX()-this->getVelocity()+1, ekor[i].getY(),
					ekor[0].getX()-this->getVelocity()+1, ekor[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of ekor helikopter*/
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

