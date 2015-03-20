#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "garis.h"
#include "warna.h"
#include "buffer.h"
#include "awan.h"
#include "city_map.h"
#include "helikopter.h"
#include "clip.h"
#include "bentuk.h"
#include "fill_scan.h"
#include "baling.h"
#include "ledakan.h"
#include "parasut.h"

using namespace std;

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int main(){
	const int batasAtas = 70;
	const int batasBawah = 470;
	const int batasKanan = 1250;
	const int batasKiri = 10;
	const int windowAtas = 500;
	const int windowBawah = 750;
	const int windowKanan = 700;
	const int windowKiri = 450;
	const int awanAwal = 1250;
	const int tinggi = 200;
	const int clipBack = 150;
	const int clipFront = 150; 
	const int clipVert = 50;

	city_map map;
	Buffer buf; 
	Pixel pixel;
	Helikopter falcon, falconDestroy;
	Baling baling;
	Point center, posPara;
	Ledakan ledakan;
	Parasut para;
	
	clip clip;
	Point va(windowKiri,windowAtas);
	clip.setViewSize(windowKanan-windowKiri);
	clip.setViewAnchor(va);
	
	int radiusAwan, yAwan;
	int sp, check;
	int sudut = 0;
	bool move, on, kena;
	char input;
	int ln[100][4];
	Warna wr[100];
	
	int v = 0;
	int vj = 1;
	int phase = 1;

	Bentuk bentuk;
	int x, y, tempx, tempy;
	int t= 300, c = 1;

	on = true;
	kena = false;

	system("clear");

	//Garis boundary dan window
	static Garis batasA(batasKiri,batasAtas,batasKanan,batasAtas); batasA.drawLine(buf,*Warna::hijau());
	static Garis batasB(batasKiri,batasBawah,batasKanan,batasBawah); batasB.drawLine(buf,*Warna::hijau());
	static Garis batasKa(batasKanan,batasAtas, batasKanan, batasBawah); batasKa.drawLine(buf, *Warna::hijau());
	static Garis batasKi(batasKiri, batasAtas, batasKiri, batasBawah); batasKi.drawLine(buf, *Warna::hijau());
	static Garis windowA(windowKiri,windowAtas,windowKanan,windowAtas); windowA.drawLine(buf,*Warna::merah());
	static Garis windowB(windowKiri,windowBawah,windowKanan,windowBawah); windowB.drawLine(buf,*Warna::merah());
	static Garis windowKa(windowKanan,windowAtas, windowKanan, windowBawah); windowKa.drawLine(buf, *Warna::merah());
	static Garis windowKi(windowKiri, windowAtas, windowKiri, windowBawah); windowKi.drawLine(buf, *Warna::merah());

	falcon.drawHeli(buf, 1);
	for (int i = 0; i<9; i++) {
		ln[i][1] = falcon.allLine[i].getPointP1().getX();
		ln[i][2] = falcon.allLine[i].getPointP1().getY();
		ln[i][3] = falcon.allLine[i].getPointP2().getX();
		ln[i][4] = falcon.allLine[i].getPointP2().getY();
		wr[i] = pixel.getPixel(falcon.allLine[i].getPointP1(),buf);
	}
	pixel.putPixel(*Warna::merah(), falcon.getAnchorP1().getX()-clipBack, falcon.getAnchorP1().getY(), buf);
	pixel.putPixel(*Warna::merah(), falcon.getAnchorP2().getX()+clipFront, falcon.getAnchorP2().getY(), buf);
	clip.setXmin(falcon.getAnchorP1().getX()-clipBack);
 	clip.setXmax(falcon.getAnchorP2().getX()+clipFront);
 	clip.setYmin(falcon.getAnchorP1().getY()-clipVert);
 	clip.setYmax(falcon.getAnchorP2().getY()+clipVert);

 	para.setRadius(30);
	while (on) {

		check = rand()%tinggi + 50;

		//setting objek di map
		if (phase %2 == 0){
			map.addBuilding(buf, check);
			for (int i = 0; i<4; i++){
				ln[i+9][1] = map.getBuilding().allLine[i].getPointP1().getX();
				ln[i+9][2] = map.getBuilding().allLine[i].getPointP1().getY();
				ln[i+9][3] = map.getBuilding().allLine[i].getPointP2().getX();
				ln[i+9][4] = map.getBuilding().allLine[i].getPointP2().getY();
				wr[i+9] = pixel.getPixel(map.getBuilding().allLine[i].getPointP1(),buf);
			}
		}
		else {
			map.addCloud(buf,check-100);
			for (int i = 0; i<12; i++){
				ln[i+9][1] = map.getCloud().allLine[i].getPointP1().getX();
				ln[i+9][2] = map.getCloud().allLine[i].getPointP1().getY();
				ln[i+9][3] = map.getCloud().allLine[i].getPointP2().getX();
				ln[i+9][4] = map.getCloud().allLine[i].getPointP2().getY();
				wr[i+9] = pixel.getPixel(map.getCloud().allLine[i].getPointP1(),buf);
			}
		}
		move = true;
		sp = 0;
		
		//setting scene
		while (move) {
			if(!kena) {
				center.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
				center.setY(falcon.getAnchorP1().getY()-20);
				
				baling.clearBaling(sudut-100,buf);
				center.setX(center.getX()-1);
				center.setY(center.getY());
				baling.setCenter(center);
				baling.rotasiBaling(sudut,buf);
				sudut+=100;
				if(kbhit()){
					pixel.putPixel(*Warna::hitam(), falcon.getPosition(), buf);
					input = getchar();
					if (input == 'i'){
						if (falcon.getAnchorP1().getY()>batasAtas+10){
							v+=5;
							falcon.moveUp(buf,1,v);
						}
						for (int i = 0; i<9; i++) {
							ln[i][1] = falcon.allLine[i].getPointP1().getX();
							ln[i][2] = falcon.allLine[i].getPointP1().getY();
							ln[i][3] = falcon.allLine[i].getPointP2().getX();
							ln[i][4] = falcon.allLine[i].getPointP2().getY();
							wr[i] = pixel.getPixel(falcon.allLine[i].getPointP1(),buf);
						}
				 	}
				 	else if (input == 'k') {
				 		if (falcon.getAnchorP2().getY() < batasBawah-10){
				 			v-=5;
							falcon.moveDown(buf,1,v);
						}
						for (int i = 0; i<9; i++) {
							ln[i][1] = falcon.allLine[i].getPointP1().getX();
							ln[i][2] = falcon.allLine[i].getPointP1().getY();
							ln[i][3] = falcon.allLine[i].getPointP2().getX();
							ln[i][4] = falcon.allLine[i].getPointP2().getY();		
							wr[i] = pixel.getPixel(falcon.allLine[i].getPointP1(),buf);
						}	
				 	}
					pixel.putPixel(*Warna::merah(), falcon.getAnchorP1().getX()-clipBack, falcon.getAnchorP1().getY(), buf);
					pixel.putPixel(*Warna::merah(), falcon.getAnchorP2().getX()+clipFront, falcon.getAnchorP2().getY(), buf);
					clip.setXmin(falcon.getAnchorP1().getX()-clipBack);
				 	clip.setXmax(falcon.getAnchorP2().getX()+clipFront);
	 				clip.setYmin(falcon.getAnchorP1().getY()-clipVert);
	 				clip.setYmax(falcon.getAnchorP2().getY()+clipVert);
				 	//cout << v;	
				}

			if(sp < 730) {
				sp+=10;
			}
			else {
				move = false;
			}

			if (phase %2 == 0){
				map.motion(sp+50, buf, check);
				for (int i = 0; i<4; i++){
					ln[i+9][1] = map.getBuilding().allLine[i].getPointP1().getX();
					ln[i+9][2] = map.getBuilding().allLine[i].getPointP1().getY();
					ln[i+9][3] = map.getBuilding().allLine[i].getPointP2().getX();
					ln[i+9][4] = map.getBuilding().allLine[i].getPointP2().getY();
					wr[i+9] = pixel.getPixel(map.getBuilding().allLine[i].getPointP1(),buf);
				}
			}
			else {
				map.playCloud(sp,buf,check-100);
				for (int i = 0; i<12; i++){
					ln[i+9][1] = map.getCloud().allLine[i].getPointP1().getX();
					ln[i+9][2] = map.getCloud().allLine[i].getPointP1().getY();
					ln[i+9][3] = map.getCloud().allLine[i].getPointP2().getX();
					ln[i+9][4] = map.getCloud().allLine[i].getPointP2().getY();
					wr[i+9] = pixel.getPixel(map.getCloud().allLine[i].getPointP1(), buf);
				}			
			}

				if (phase%2==0) {
					for (int i = 0; i < 13; i++){
						clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], wr[i], buf);
					}
				}
				else {
					for (int i = 0; i < 21; i++){
						clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], wr[i], buf);
					}
				}

				if(phase==3) {
					kena = true;
					tempx = baling.getCenter().getX();
					tempy = baling.getCenter().getY();
					y = baling.getCenter().getY();
					x = baling.getCenter().getX();

					// hapus helikopter
					//falcon.clearHeli(buf, v);
					falconDestroy.setP1(falcon.getAnchorP1());
					falconDestroy.setP2(falcon.getAnchorP2());
					
					// hapus baling-baling
					baling.clearBaling(sudut-100,buf);

					//set parasut
					posPara.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
					posPara.setY(falcon.getAnchorP2().getY());
					para.setPosition(posPara);
					
					//ledakan
					ledakan.setAbsisTitikPusatLedakan((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
					ledakan.setOrdinatTitikPusatLedakan(falcon.getAnchorP2().getY());
					ledakan.meledak();
				}
			}
			
			else {// kena
				
				if(sp < 730) {
				sp+=10;
			}
			else {
				move = false;
			}

			if (phase %2 == 0){
				map.motion(sp+50, buf, check);
				for (int i = 0; i<4; i++){
					ln[i+9][1] = map.getBuilding().allLine[i].getPointP1().getX();
					ln[i+9][2] = map.getBuilding().allLine[i].getPointP1().getY();
					ln[i+9][3] = map.getBuilding().allLine[i].getPointP2().getX();
					ln[i+9][4] = map.getBuilding().allLine[i].getPointP2().getY();
					wr[i+9] = pixel.getPixel(map.getBuilding().allLine[i].getPointP1(),buf);
				}
			}
			else {
				map.playCloud(sp,buf,check-100);
				for (int i = 0; i<12; i++){
					ln[i+9][1] = map.getCloud().allLine[i].getPointP1().getX();
					ln[i+9][2] = map.getCloud().allLine[i].getPointP1().getY();
					ln[i+9][3] = map.getCloud().allLine[i].getPointP2().getX();
					ln[i+9][4] = map.getCloud().allLine[i].getPointP2().getY();
					wr[i+9] = pixel.getPixel(map.getCloud().allLine[i].getPointP1(), buf);
				}			
			}

				if (phase%2==0) {
					for (int i = 0; i < 13; i++){
						clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], wr[i], buf);
					}
				}
				else {
					for (int i = 0; i < 21; i++){
						clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], wr[i], buf);
					}
				}

				falconDestroy.clearpecahHeli(buf);
				falconDestroy.setVelocity(vj);
				falconDestroy.pecahHeli(buf);

				/** Parasut */
				para.clearParasut(buf);
				para.setVelocity((vj*0.5));
				para.drawParasut(buf);
				/** end of parasut */
								
				/** Baling-baling */
				center.setX(((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2)-vj);
				center.setY(falcon.getAnchorP1().getY()+(vj*2));
				
				baling.clearBaling(sudut-10,buf);
				center.setX(center.getX());
				center.setY(center.getY());
				baling.setCenter(center);
				baling.rotasiBaling(sudut,buf);
				sudut+=10;
				/** Baling-baling */

				// bentuk.circle(tempx, tempy, baling.getRadius(), buf, *Warna::hitam());
				// bentuk.circle(x, y, baling.getRadius(), buf, *Warna::kuning());
				
				// if(y >= 300) {
				// 	c = 0;
				// 	t -= 30;
				// }
				// if (y <=300-t) {
				// 	c=1;
				// }
				// tempy = y;
				// tempx = x;
				
				// if(y<320)
				// 	y = y + (c?15: -15);
				// if (y==center.getY()) {
				// 	c = 1;
				// }
				
				vj+=1;				

			}

			usleep(50000);	
		}

		if (phase%2 == 0)
			map.clearAll(1,buf, check);
		else 
			map.clearAll(2,buf,check-100);
		phase++;
	}
	
	buf.closeBuffer();
	return 0;
}