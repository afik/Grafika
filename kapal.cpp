#include "kapal.h"

Kapal::Kapal()
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

Kapal::~Kapal(){}

//setter
//void setN(int N);
void Kapal::setVelocity(int velocity)
{
	this->velocity = velocity;
}
void Kapal::setPosition(Point position)
{
	this->position = position;
}

//getter
//int getN();
int Kapal::getVelocity()
{
	return velocity;
}

Point Kapal::getPosition()
{
	return position;
}

Point Kapal::getAnchorP1()
{
	return P1;
}

Point Kapal::getAnchorP2()
{
	return P2;
}

void Kapal::drawKapal(Buffer buff)
{
	int i;
	int n = 4;
	Point lambung[n];
	Point geladak[n];
	Point anjungan[n];
	Point meriam[n];
	Warna putih;
	
	/** lambung kapal */
	lambung[0].setX(100);
	lambung[0].setY(300);
	lambung[1].setX(100);
	lambung[1].setY(325);
	lambung[2].setX(200);
	lambung[2].setY(325);
	lambung[3].setX(230);
	lambung[3].setY(300);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(lambung[i].getX()+this->getVelocity(), lambung[i].getY(),
					lambung[i+1].getX()+this->getVelocity(), lambung[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(lambung[i].getX()+this->getVelocity(), lambung[i].getY(),
					lambung[0].getX()+this->getVelocity(), lambung[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of lambung kapal*/
	
	/** geladak kapal */
	geladak[0].setX(110);
	geladak[0].setY(280);
	geladak[1].setX(110);
	geladak[1].setY(300);
	geladak[2].setX(180);
	geladak[2].setY(300);
	geladak[3].setX(180);
	geladak[3].setY(280);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(geladak[i].getX()+this->getVelocity(), geladak[i].getY(),
					geladak[i+1].getX()+this->getVelocity(), geladak[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(geladak[i].getX()+this->getVelocity(), geladak[i].getY(),
					geladak[0].getX()+this->getVelocity(), geladak[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of geladak kapal*/
	
	/** anjungan kapal */
	anjungan[0].setX(120);
	anjungan[0].setY(265);
	anjungan[1].setX(120);
	anjungan[1].setY(280);
	anjungan[2].setX(150);
	anjungan[2].setY(280);
	anjungan[3].setX(150);
	anjungan[3].setY(265);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(anjungan[i].getX()+this->getVelocity(), anjungan[i].getY(),
					anjungan[i+1].getX()+this->getVelocity(), anjungan[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(anjungan[i].getX()+this->getVelocity(), anjungan[i].getY(),
					anjungan[0].getX()+this->getVelocity(), anjungan[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of anjungan kapal*/
	
	/** meriam kapal */
	meriam[0].setX(190);
	meriam[0].setY(300);
	meriam[1].setX(200);
	meriam[1].setY(300);
	meriam[2].setX(215);
	meriam[2].setY(280);
	meriam[3].setX(205);
	meriam[3].setY(280);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(meriam[i].getX()+this->getVelocity(), meriam[i].getY(),
					meriam[i+1].getX()+this->getVelocity(), meriam[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(meriam[i].getX()+this->getVelocity(), meriam[i].getY(),
					meriam[0].getX()+this->getVelocity(), meriam[0].getY());
			g.drawLine(buff, putih);
		}
	}
	/** end of meriam kapal*/
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

void Kapal::clearKapal(Buffer buff)
{
	int i;
	int n = 4;
	Point lambung[n];
	Point geladak[n];
	Point anjungan[n];
	Point meriam[n];
	Warna hitam(0,0,0);
	
	/** lambung kapal */
	lambung[0].setX(100);
	lambung[0].setY(300);
	lambung[1].setX(100);
	lambung[1].setY(325);
	lambung[2].setX(200);
	lambung[2].setY(325);
	lambung[3].setX(230);
	lambung[3].setY(300);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(lambung[i].getX()+this->getVelocity()-1, lambung[i].getY(),
					lambung[i+1].getX()+this->getVelocity()-1, lambung[i+1].getY());
			g.drawLine(buff, hitam);
		}
		else
		{
			Garis g(lambung[i].getX()+this->getVelocity()-1, lambung[i].getY(),
					lambung[0].getX()+this->getVelocity()-1, lambung[0].getY());
			g.drawLine(buff, hitam);
		}
	}
	/** end of lambung kapal*/
	
	/** geladak kapal */
	geladak[0].setX(110);
	geladak[0].setY(280);
	geladak[1].setX(110);
	geladak[1].setY(300);
	geladak[2].setX(180);
	geladak[2].setY(300);
	geladak[3].setX(180);
	geladak[3].setY(280);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(geladak[i].getX()+this->getVelocity()-1, geladak[i].getY(),
					geladak[i+1].getX()+this->getVelocity()-1, geladak[i+1].getY());
			g.drawLine(buff, hitam);
		}
		else
		{
			Garis g(geladak[i].getX()+this->getVelocity()-1, geladak[i].getY(),
					geladak[0].getX()+this->getVelocity()-1, geladak[0].getY());
			g.drawLine(buff, hitam);
		}
	}
	/** end of geladak kapal*/
	
	/** anjungan kapal */
	anjungan[0].setX(120);
	anjungan[0].setY(265);
	anjungan[1].setX(120);
	anjungan[1].setY(280);
	anjungan[2].setX(150);
	anjungan[2].setY(280);
	anjungan[3].setX(150);
	anjungan[3].setY(265);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(anjungan[i].getX()+this->getVelocity()-1, anjungan[i].getY(),
					anjungan[i+1].getX()+this->getVelocity()-1, anjungan[i+1].getY());
			g.drawLine(buff, hitam);
		}
		else
		{
			Garis g(anjungan[i].getX()+this->getVelocity()-1, anjungan[i].getY(),
					anjungan[0].getX()+this->getVelocity()-1, anjungan[0].getY());
			g.drawLine(buff, hitam);
		}
	}
	/** end of anjungan kapal*/
	
	/** meriam kapal */
	meriam[0].setX(190);
	meriam[0].setY(300);
	meriam[1].setX(200);
	meriam[1].setY(300);
	meriam[2].setX(215);
	meriam[2].setY(280);
	meriam[3].setX(205);
	meriam[3].setY(280);
	
	for(i=0; i<n; i++)
	{
		if(i<3)
		{
			Garis g(meriam[i].getX()+this->getVelocity()-1, meriam[i].getY(),
					meriam[i+1].getX()+this->getVelocity()-1, meriam[i+1].getY());
			g.drawLine(buff, hitam);
		}
		else
		{
			Garis g(meriam[i].getX()+this->getVelocity()-1, meriam[i].getY(),
					meriam[0].getX()+this->getVelocity()-1, meriam[0].getY());
			g.drawLine(buff, hitam);
		}
	}
	/** end of meriam kapal*/
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

