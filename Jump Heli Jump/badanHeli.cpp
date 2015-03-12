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


void badanHeli::drawbadanHeli(Buffer buff, int scale, int v)
{
	int i;
	int n = 4;
	Point badan[n];
	Warna Biru(236, 228, 15);
	Warna putih;
	//Scanline S;
	
	/** badan badanHeli */
	badan[0].setX(220);
	badan[0].setY(100);
	badan[1].setX(150);
	badan[1].setY(100);
	badan[2].setX(150);
	badan[2].setY(150);
	badan[3].setX(220);
	badan[3].setY(150);
	
	this->P1.setX(220-v);
	this->P1.setY(100);
	this->P2.setX(150-v);
	this->P2.setY(150);
	
	badan[1] = badan[0].setWidth(scale, badan[1]);
	badan[2] = badan[1].setHeight(scale, badan[2]);
	badan[3] = badan[2].setWidth(scale, badan[3]);
	badan[0] = badan[3].setHeight(scale, badan[0]);
	
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

	//S.drawScanline(900-v, 100, 990-v, 125, G1, G2, Biru);
	
}

void badanHeli::clearbadanHeli(Buffer buff, int scale, int v)
{
	int i;
	int n = 4;
	Point badan[n];
	Warna putih(0,0,0);

	/** badan helikopter */
	
	badan[0].setX(220);
	badan[0].setY(100);
	badan[1].setX(150);
	badan[1].setY(100);
	badan[2].setX(150);
	badan[2].setY(150);
	badan[3].setX(220);
	badan[3].setY(150);
	
	this->P1.setX(220-v);
	this->P1.setY(100);
	this->P2.setX(150-v);
	this->P2.setY(150);
	
	badan[1] = badan[0].setWidth(scale, badan[1]);
	badan[2] = badan[1].setHeight(scale, badan[2]);
	badan[3] = badan[2].setWidth(scale, badan[3]);
	badan[0] = badan[3].setHeight(scale, badan[0]);	

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

void badanHeli::drawPecah(Buffer buff, Point P1, Point P2, int v)
{
	int i;
	int n = 4;
	Point badan[n];
	Warna Biru(236, 228, 15);
	Warna putih;
	//Scanline S;
	
	/** badan badanHeli */
	badan[0].setX(P1.getX());
	badan[0].setY(P1.getY());
	badan[1].setX(P2.getX());
	badan[1].setY(P1.getY()-20);
	badan[2].setX(P2.getX()+20);
	badan[2].setY(P2.getY()-20);
	badan[3].setX(P1.getX()+20);
	badan[3].setY(P2.getY());
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX()-v-0.5, badan[i].getY()+v,
					badan[i+1].getX()-v-0.5, badan[i+1].getY()+v);
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX()-v-0.5, badan[i].getY()+v,
					badan[0].getX()-v-0.5, badan[0].getY()+v);
			g.drawLine(buff, putih);
		}
	}
	/** end of badan badanHeli*/

	//S.drawScanline(900-v, 100, 990-v, 125, G1, G2, Biru);
	
}

void badanHeli::clearPecah(Buffer buff, Point P1, Point P2, int v)
{
	int i;
	int n = 4;
	Point badan[n];
	Warna Biru(236, 228, 15);
	Warna putih(0,0,0);
	//Scanline S;
	
	/** badan badanHeli */
	badan[0].setX(P1.getX());
	badan[0].setY(P1.getY());
	badan[1].setX(P2.getX());
	badan[1].setY(P1.getY()-20);
	badan[2].setX(P2.getX()+20);
	badan[2].setY(P2.getY()-20);
	badan[3].setX(P1.getX()+20);
	badan[3].setY(P2.getY());
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX()-v-0.5, badan[i].getY()+v,
					badan[i+1].getX()-v-0.5, badan[i+1].getY()+v);
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX()-v-0.5, badan[i].getY()+v,
					badan[0].getX()-v-0.5, badan[0].getY()+v);
			g.drawLine(buff, putih);
		}
	}
	/** end of badan badanHeli*/
}

void badanHeli::badanHeliUp(Buffer buff, int scale, int v) {

	int i;
	int n = 4;
	Point badan[n];
	Warna Biru(236, 228, 15);
	Warna putih;
	//Scanline S;
	
	/** badan badanHeli */
	badan[0].setX(220);
	badan[0].setY(100);
	badan[1].setX(150);
	badan[1].setY(100);
	badan[2].setX(150);
	badan[2].setY(150);
	badan[3].setX(220);
	badan[3].setY(150);
	
	this->P1.setX(220-v);
	this->P1.setY(100);
	this->P2.setX(150-v);
	this->P2.setY(150);
	
	badan[1] = badan[0].setWidth(scale, badan[1]);
	badan[2] = badan[1].setHeight(scale, badan[2]);
	badan[3] = badan[2].setWidth(scale, badan[3]);
	badan[0] = badan[3].setHeight(scale, badan[0]);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX(), badan[i].getY()-v,
					badan[i+1].getX(), badan[i+1].getY()-v);
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX(), badan[i].getY()-v,
					badan[0].getX(), badan[0].getY()-v);
			g.drawLine(buff, putih);
		}
	}
	/** end of badan badanHeli*/

}

void badanHeli::clearHeliUp(Buffer buff, int scale, int v) {

	int i;
	int n = 4;
	Point badan[n];
	Warna Biru(236, 228, 15);
	Warna putih(0,0,0);
	//Scanline S;
	
	/** badan badanHeli */
	badan[0].setX(220);
	badan[0].setY(100);
	badan[1].setX(150);
	badan[1].setY(100);
	badan[2].setX(150);
	badan[2].setY(150);
	badan[3].setX(220);
	badan[3].setY(150);
	
	this->P1.setX(220-v);
	this->P1.setY(100);
	this->P2.setX(150-v);
	this->P2.setY(150);
	
	badan[1] = badan[0].setWidth(scale, badan[1]);
	badan[2] = badan[1].setHeight(scale, badan[2]);
	badan[3] = badan[2].setWidth(scale, badan[3]);
	badan[0] = badan[3].setHeight(scale, badan[0]);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(badan[i].getX(), badan[i].getY()-v,
					badan[i+1].getX(), badan[i+1].getY()-v);
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(badan[i].getX(), badan[i].getY()-v,
					badan[0].getX(), badan[0].getY()-v);
			g.drawLine(buff, putih);
		}
	}
	/** end of badan badanHeli*/
	
}
