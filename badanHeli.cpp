#include "badanHeli.h"

badanHeli::badanHeli()
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

badanHeli::~badanHeli(){}

//setter
//void setN(int N);
void badanHeli::setVelocity(int velocity)
{
	this->velocity = velocity;
}
void badanHeli::setPosition(Point position)
{
	this->position = position;
}

//getter
//int getN();
int badanHeli::getVelocity()
{
	return velocity;
}

Point badanHeli::getPosition()
{
	return position;
}

Point badanHeli::getAnchorP1()
{
	return P1;
}

Point badanHeli::getAnchorP2()
{
	return P2;
}

void badanHeli::drawbadanHeli(Buffer buff, int v)
{
	int i;
	int n = 4;
	Point badan[n];
	Warna Biru(236, 228, 15);
	Warna putih;
	Scanline S;
	
	/** badan badanHeli */
	badan[0].setX(900);
	badan[0].setY(100);
	badan[1].setX(1000);
	badan[1].setY(100);
	badan[2].setX(1000);
	badan[2].setY(150);
	badan[3].setX(900);
	badan[3].setY(150);
	
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX()-v, badan[i].getY(),
					badan[i+1].getX()-v, badan[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX()-v, badan[i].getY(),
					badan[0].getX()-v, badan[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of badan badanHeli*/
	Garis G1(badan[0].getX()-v, badan[0].getY(), badan[3].getX()-v, badan[3].getY());
	Garis G2(badan[1].getX()-v, badan[1].getY(), badan[2].getX()-v, badan[2].getY());

	S.drawScanline(900-v, 100, 990-v, 125, G1, G2, Biru);
	
}

void badanHeli::clearbadanHeli(Buffer buff, int v)
{
	int i;
	int n = 4;
	Point badan[n];
	Warna putih(0,0,0);

	/** badan helikopter */
	badan[0].setX(900);
	badan[0].setY(100);
	badan[1].setX(1000);
	badan[1].setY(100);
	badan[2].setX(1000);
	badan[2].setY(150);
	badan[3].setX(900);
	badan[3].setY(150);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX()-v, badan[i].getY(),
					badan[i+1].getX()-v, badan[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX()-v, badan[i].getY(),
					badan[0].getX()-v, badan[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of badan helikopter*/
}

