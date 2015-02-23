#include "parasut.h"

Parasut::Parasut()
{
	N = 0;
	velocity = 0;
	P1.setX(0);
	P1.setY(0);
	P2.setX(0);
	P2.setY(0);
	position.setX(10);
	position.setY(10);
	radius = 0;
}

Parasut::~Parasut(){}

//setter
//void setN(int N);
void Parasut::setVelocity(int velocity)
{
	this->velocity = velocity;
}
//void setN(int N);
void Parasut::setRadius(int radius)
{
	this->radius = radius;
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

int Parasut::getRadius()
{
	return radius;
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
	Point taliParasut[3];
	Point penerjun[6];
	Warna putih;
	int radius_kepala;
	int radius_badan;
	Bentuk b;
	
	/** Parasut */
	b.setengah_lingkaran(this->getPosition().getX(), this->getPosition().getY()+this->getVelocity(), this->getRadius(), buff, putih);
	/** end of Parasut*/
	
	/** Tali Parasut */
	taliParasut[0].setX(this->getPosition().getX()+this->getRadius());
	taliParasut[0].setY(this->getPosition().getY());
	taliParasut[1].setX(this->getPosition().getX()-this->getRadius());
	taliParasut[1].setY(this->getPosition().getY());
	taliParasut[2].setX(this->getPosition().getX());
	taliParasut[2].setY(this->getPosition().getY()+this->getRadius());
	
	for(i=0; i<3; i++)
	{
		if(i<2)
		{
			Garis g(taliParasut[i].getX(), taliParasut[i].getY()+this->getVelocity(),
					taliParasut[i+1].getX(), taliParasut[i+1].getY()+this->getVelocity());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(taliParasut[i].getX(), taliParasut[i].getY()+this->getVelocity(),
					taliParasut[0].getX(), taliParasut[0].getY()+this->getVelocity());
			g.drawLine(buff, putih);
		}
	}
	/** end of Tali Parasut*/
	
	/** Pilot */
	radius_kepala = this->getRadius()/8;
	radius_badan = this->getRadius()/4;
	
	penerjun[0].setX(taliParasut[2].getX());				//kepala
	penerjun[0].setY(taliParasut[2].getY()-radius_kepala);
	penerjun[1].setX(taliParasut[2].getX()+radius_badan);	//tangan kanan
	penerjun[1].setY(taliParasut[2].getY()+radius_badan);
	penerjun[2].setX(taliParasut[2].getX()-radius_badan);	//tangan kiri
	penerjun[2].setY(taliParasut[2].getY()+radius_badan);
	penerjun[3].setX(taliParasut[2].getX());				//badan
	penerjun[3].setY(taliParasut[2].getY()+radius_badan*2);
	penerjun[4].setX(penerjun[3].getX()+radius_badan);				//kaki kanan
	penerjun[4].setY(penerjun[3].getY()+radius_badan);
	penerjun[5].setX(penerjun[3].getX()-radius_badan);				//kaki kiri
	penerjun[5].setY(penerjun[3].getY()+radius_badan);
	
	b.circle(penerjun[0].getX(), penerjun[0].getY()+this->getVelocity(), radius_kepala, buff, putih);
	
	//Garis tkanan(taliParasut[2],penerjun[1]+this->getVelocity()); tkanan.drawLine(buff,putih);
	//Garis tkiri(taliParasut[2],penerjun[2]+this->getVelocity()); tkiri.drawLine(buff,putih);
	Garis gbadan(taliParasut[2].getX(), taliParasut[2].getY()+this->getVelocity(), penerjun[3].getX(), penerjun[3].getY()+this->getVelocity());
		gbadan.drawLine(buff,putih);
	Garis kkanan(penerjun[3].getX(), penerjun[3].getY()+this->getVelocity(), penerjun[4].getX(), penerjun[4].getY()+this->getVelocity());
		kkanan.drawLine(buff,putih);
	Garis kkiri(penerjun[3].getX(), penerjun[3].getY()+this->getVelocity(), penerjun[5].getX(), penerjun[5].getY()+this->getVelocity());
		kkiri.drawLine(buff,putih);
	
	/** end of Pilot */
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

void Parasut::clearParasut(Buffer buff)
{
	int i;
	Point taliParasut[3];
	Point penerjun[6];
	Warna hitam(0,0,0);
	int radius_kepala;
	int radius_badan;
	Bentuk b;
	
	/** Parasut */
	b.setengah_lingkaran(this->getPosition().getX(), this->getPosition().getY()+this->getVelocity(), this->getRadius(), buff, hitam);
	/** end of Parasut*/
	
	/** Tali Parasut */
	taliParasut[0].setX(this->getPosition().getX()+this->getRadius());
	taliParasut[0].setY(this->getPosition().getY());
	taliParasut[1].setX(this->getPosition().getX()-this->getRadius());
	taliParasut[1].setY(this->getPosition().getY());
	taliParasut[2].setX(this->getPosition().getX());
	taliParasut[2].setY(this->getPosition().getY()+this->getRadius());
	
	for(i=0; i<3; i++)
	{
		if(i<2)
		{
			Garis g(taliParasut[i].getX(), taliParasut[i].getY()+this->getVelocity(),
					taliParasut[i+1].getX(), taliParasut[i+1].getY()+this->getVelocity());
			g.drawLine(buff, hitam);
		}
		else
		{
			Garis g(taliParasut[i].getX(), taliParasut[i].getY()+this->getVelocity(),
					taliParasut[0].getX(), taliParasut[0].getY()+this->getVelocity());
			g.drawLine(buff, hitam);
		}
	}
	/** end of Tali Parasut*/
	
	/** Pilot */
	radius_kepala = this->getRadius()/8;
	radius_badan = this->getRadius()/4;
	
	penerjun[0].setX(taliParasut[2].getX());				//kepala
	penerjun[0].setY(taliParasut[2].getY()-radius_kepala);
	penerjun[1].setX(taliParasut[2].getX()+radius_badan);	//tangan kanan
	penerjun[1].setY(taliParasut[2].getY()+radius_badan);
	penerjun[2].setX(taliParasut[2].getX()-radius_badan);	//tangan kiri
	penerjun[2].setY(taliParasut[2].getY()+radius_badan);
	penerjun[3].setX(taliParasut[2].getX());				//badan
	penerjun[3].setY(taliParasut[2].getY()+radius_badan*2);
	penerjun[4].setX(penerjun[3].getX()+radius_badan);				//kaki kanan
	penerjun[4].setY(penerjun[3].getY()+radius_badan);
	penerjun[5].setX(penerjun[3].getX()-radius_badan);				//kaki kiri
	penerjun[5].setY(penerjun[3].getY()+radius_badan);
	
	b.circle(penerjun[0].getX(), penerjun[0].getY()+this->getVelocity(), radius_kepala, buff, hitam);
	
	//Garis tkanan(taliParasut[2],penerjun[1]+this->getVelocity()); tkanan.drawLine(buff,hitam);
	//Garis tkiri(taliParasut[2],penerjun[2]+this->getVelocity()); tkiri.drawLine(buff,hitam);
	Garis gbadan(taliParasut[2].getX(), taliParasut[2].getY()+this->getVelocity(), penerjun[3].getX(), penerjun[3].getY()+this->getVelocity());
		gbadan.drawLine(buff,hitam);
	Garis kkanan(penerjun[3].getX(), penerjun[3].getY()+this->getVelocity(), penerjun[4].getX(), penerjun[4].getY()+this->getVelocity());
		kkanan.drawLine(buff,hitam);
	Garis kkiri(penerjun[3].getX(), penerjun[3].getY()+this->getVelocity(), penerjun[5].getX(), penerjun[5].getY()+this->getVelocity());
		kkiri.drawLine(buff,hitam);
	
	/** end of Pilot */
	
	/** set anchor point */
	this->P1.setX(100+this->getVelocity());
	this->P1.setY(265);
	this->P2.setX(230+this->getVelocity());
	this->P2.setY(325);
}

