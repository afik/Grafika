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
	ekor[0].setX(150);		//P1x
	ekor[0].setY(115);		//P1y
	ekor[1].setX(100);		//P1x+100
	ekor[1].setY(115);		//P1y
	ekor[2].setX(80);		//P2
	ekor[2].setY(100);		//P1y-15
	ekor[3].setX(80);		//P2
	ekor[3].setY(130);		//P2y
	ekor[4].setX(150);		//P1x
	ekor[4].setY(130);		//P2y
	
	this->P1.setX(150-v);
	this->P1.setY(115);
	this->P2.setX(80-v);
	this->P2.setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX()-v, ekor[i].getY(),
					ekor[i+1].getX()-v, ekor[i+1].getY());
			g.drawLine(buff, putih);
			allLine[i] = g;
		}
		else
		{
			Garis g(ekor[i].getX()-v, ekor[i].getY(),
					ekor[0].getX()-v, ekor[0].getY());
			g.drawLine(buff, putih);
			allLine[i] = g;
		}
	}

	// for (int i = 1; i<n; i++) {
	// 	printf("%d %d %d %d\n", allLine[i].getPointP1().getX(), 
	// 							allLine[i].getPointP1().getY(),
	// 							allLine[i].getPointP2().getX(),
	// 							allLine[i].getPointP2().getY());
	// }
	/** end of ekor helikopter*/
}

void ekorHeli::clearekorHeli(Buffer buff, int v)
{
	
	int i;
	int n = 5;
	Point ekor[n];
	Warna putih(0,0,0);

	ekor[0].setX(150);		//P1x
	ekor[0].setY(115);		//P1y
	ekor[1].setX(100);		//P1x+100
	ekor[1].setY(115);		//P1y
	ekor[2].setX(80);		//P2
	ekor[2].setY(100);		//P1y-15
	ekor[3].setX(80);		//P2
	ekor[3].setY(130);		//P2y
	ekor[4].setX(150);		//P1x
	ekor[4].setY(130);		//P2y
	
	this->P1.setX(150-v);
	this->P1.setY(115);
	this->P2.setX(80-v);
	this->P2.setY(130);
	
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

void ekorHeli::drawPecah(Buffer buff, Point P1, Point P2, int v)
{
	int i;
	int n = 5;
	Point ekor[n];
	Warna putih;
	
	/** ekor helikopter */
	ekor[0].setX(P1.getX()+100);		//P1x
	ekor[0].setY(P1.getY()+15);		//P1y
	ekor[1].setX(P1.getX()+200);		//P1x+100
	ekor[1].setY(P1.getY()+15);		//P1y
	ekor[2].setX(P2.getX()+130);		//P2x
	ekor[2].setY(P1.getY());		//P1y-15
	ekor[3].setX(P2.getX()+130);		//P2x
	ekor[3].setY(P2.getY()-20);		//P2y
	ekor[4].setX(P1.getX()+100);		//P1x
	ekor[4].setY(P2.getY()-20);		//P2y
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX(), ekor[i].getY()+v,
					ekor[i+1].getX(), ekor[i+1].getY()+v);
			g.drawLine(buff, putih);
			allLine[i] = g;
		}
		else
		{
			Garis g(ekor[i].getX(), ekor[i].getY()+v,
					ekor[0].getX(), ekor[0].getY()+v);
			g.drawLine(buff, putih);
			allLine[i] = g;
		}
	}
	/** end of ekor helikopter*/
}

void ekorHeli::clearPecah(Buffer buff, Point P1, Point P2, int v)
{
	int i;
	int n = 5;
	Point ekor[n];
	Warna putih(0,0,0);
	
	/** ekor helikopter */
	ekor[0].setX(P1.getX()+100);		//P1x
	ekor[0].setY(P1.getY()+15);		//P1y
	ekor[1].setX(P1.getX()+200);		//P1x+100
	ekor[1].setY(P1.getY()+15);		//P1y
	ekor[2].setX(P2.getX()+130);		//P2x
	ekor[2].setY(P1.getY());		//P1y-15
	ekor[3].setX(P2.getX()+130);		//P2x
	ekor[3].setY(P2.getY()-20);		//P2y
	ekor[4].setX(P1.getX()+100);		//P1x
	ekor[4].setY(P2.getY()-20);		//P2y
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX(), ekor[i].getY()+v,
					ekor[i+1].getX(), ekor[i+1].getY()+v);
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(ekor[i].getX(), ekor[i].getY()+v,
					ekor[0].getX(), ekor[0].getY()+v);
			g.drawLine(buff, putih);
		}
	}
	/** end of ekor helikopter*/
}

void ekorHeli::ekorHeliUp(Buffer buff, int scale, int v) {

	int i;
	int n = 5;
	Point ekor[n];
	Warna putih;
	
	/** ekor helikopter */
	ekor[0].setX(150);		//P1x
	ekor[0].setY(115);		//P1y
	ekor[1].setX(100);		//P1x+100
	ekor[1].setY(115);		//P1y
	ekor[2].setX(80);		//P2
	ekor[2].setY(100);		//P1y-15
	ekor[3].setX(80);		//P2
	ekor[3].setY(130);		//P2y
	ekor[4].setX(150);		//P1x
	ekor[4].setY(130);		//P2y
	
	this->P1.setX(150-v);
	this->P1.setY(115);
	this->P2.setX(80-v);
	this->P2.setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX(), ekor[i].getY()-v,
					ekor[i+1].getX(), ekor[i+1].getY()-v);
			g.drawLine(buff, putih);
			allLine[i] = g;
		}
		else
		{
			Garis g(ekor[i].getX(), ekor[i].getY()-v,
					ekor[0].getX(), ekor[0].getY()-v);
			g.drawLine(buff, putih);
			allLine[i] = g;
		}
	}

}


void ekorHeli::clearEkorUp(Buffer buff, int scale, int v) {

	int i;
	int n = 5;
	Point ekor[n];
	Warna putih(0,0,0);
	
	/** ekor helikopter */
	ekor[0].setX(150);		//P1x
	ekor[0].setY(115);		//P1y
	ekor[1].setX(100);		//P1x+100
	ekor[1].setY(115);		//P1y
	ekor[2].setX(80);		//P2
	ekor[2].setY(100);		//P1y-15
	ekor[3].setX(80);		//P2
	ekor[3].setY(130);		//P2y
	ekor[4].setX(150);		//P1x
	ekor[4].setY(130);		//P2y
	
	this->P1.setX(150-v);
	this->P1.setY(115);
	this->P2.setX(80-v);
	this->P2.setY(130);
	
	for(i=0; i<n; i++)
	{
		if(i<4)
		{
			Garis g(ekor[i].getX(), ekor[i].getY()-v,
					ekor[i+1].getX(), ekor[i+1].getY()-v);
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(ekor[i].getX(), ekor[i].getY()-v,
					ekor[0].getX(), ekor[0].getY()-v);
			g.drawLine(buff, putih);
		}
	}
}
