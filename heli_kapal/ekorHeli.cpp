#include "ekorHeli.h"

ekorHeli::ekorHeli()
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

ekorHeli::~ekorHeli(){}

//setter
//void setN(int N);
void ekorHeli::setVelocity(int velocity)
{
	this->velocity = velocity;
}
void ekorHeli::setPosition(Point position)
{
	this->position = position;
}

//getter
//int getN();
int ekorHeli::getVelocity()
{
	return velocity;
}

Point ekorHeli::getPosition()
{
	return position;
}

Point ekorHeli::getAnchorP1()
{
	return P1;
}

Point ekorHeli::getAnchorP2()
{
	return P2;
}

void ekorHeli::drawekorHeli(Buffer buff, int v)
{
	int i;
	int n = 5;
	Point ekor[n];
	Warna putih;
	
	/** ekor helikopter */
	ekor[0].setX(1000);
	ekor[0].setY(115);
	ekor[1].setX(1100);
	ekor[1].setY(115);
	ekor[2].setX(1130);
	ekor[2].setY(100);
	ekor[3].setX(1130);
	ekor[3].setY(130);
	ekor[4].setX(1000);
	ekor[4].setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX()-v, ekor[i].getY(),
					ekor[i+1].getX()-v, ekor[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(ekor[i].getX()-v, ekor[i].getY(),
					ekor[0].getX()-v, ekor[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of ekor helikopter*/
}

void ekorHeli::clearekorHeli(Buffer buff, int v)
{
	
	int i;
	int n = 5;
	Point ekor[n];
	Warna putih(0,0,0);

	ekor[0].setX(1000);
	ekor[0].setY(115);
	ekor[1].setX(1100);
	ekor[1].setY(115);
	ekor[2].setX(1130);
	ekor[2].setY(100);
	ekor[3].setX(1130);
	ekor[3].setY(130);
	ekor[4].setX(1000);
	ekor[4].setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(ekor[i].getX()-v, ekor[i].getY(),
					ekor[i+1].getX()-v, ekor[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(ekor[i].getX()-v, ekor[i].getY(),
					ekor[0].getX()-v, ekor[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of ekor helikopter*/
}

