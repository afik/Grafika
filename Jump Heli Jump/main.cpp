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
#include "picker.h"

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


Warna picker(Buffer buff) {
	int pil;
	Picker pick;
	Warna warna;
	Helikopter falcon;
	Baling baling;	
	Point center;
	
	do {
	  
	  system("clear");
	  /** menggambar kotak pilihan */
	  pick.drawPicker(buff);
	  
	  /** memilih pilihan warna */
	  switch(pil){
	    case 0: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 1: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 2: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 3: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 4: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 5: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 6: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 7: 
	      warna = pick.getColour(415+(pil*80), 425, buff);
	      break;
	    case 8: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 9: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 10: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 11: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 12: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 13: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 14: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    case 15: 
	      warna = pick.getColour(415+((pil-8)*80), 505, buff);
	      break;
	    default: break;
	  }	
	  
	  /** menggambar helikopter */
	  falcon.drawHeli(buff,1);
	  falcon.setVelocity(1);
	  
	  /** mewarnai helikopter */
	  Point kiribawah(falcon.getAnchorP1().getX(),falcon.getAnchorP2().getY());
	  int lebar = falcon.getAnchorP2().getX() - falcon.getAnchorP1().getX();
	  int panjang = falcon.getAnchorP2().getY() - falcon.getAnchorP1().getY();
	  fillScan fill;
	  fill.fillRect(kiribawah, lebar, panjang, warna, buff);
	  
	  /** menggambar baling-baling */
	  center.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
	  center.setY(falcon.getAnchorP1().getY()-20);
	  baling.setCenter(center);
	  baling.rotasiBaling(0,buff);
	  
	  cout << "Masukkan -1 untuk keluar" << endl;
	  cout << "Pilih warna dari 0 sampe 15: ";
	  cin >> pil;
	}while (pil != -1);

	return warna;
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
	Helikopter falcon;
	Baling baling;
	fillScan fill;
	Point centerHeli;
	
	clip clip;
	Point va(windowKiri,windowAtas);
	clip.setViewSize(windowKanan-windowKiri);
	clip.setViewAnchor(va);
	
	int radiusAwan, yAwan;
	int sp, check;
	int sudut = 0;
	bool move, on;
	char input;
	int ln[100][4];
	Warna wr[100];
	
	int v = 0;
	int phase = 1;
	on = true;
	bool pilihWarna = true;
	bool play = true;
	Warna warnaHeli;

	Point kiribawah;
	int panjang = 69;
	int lebar = 49;

	while (play)
	{
		if (pilihWarna) {
			warnaHeli = picker(buf);
			pilihWarna = false;
		}
		else {
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
			Point pW(windowKiri,windowBawah);

			//draw and fill heli
			falcon.drawHeli(buf, 1);
			for (int i = 0; i<9; i++) {
				ln[i][1] = falcon.allLine[i].getPointP1().getX();
				ln[i][2] = falcon.allLine[i].getPointP1().getY();
				ln[i][3] = falcon.allLine[i].getPointP2().getX();
				ln[i][4] = falcon.allLine[i].getPointP2().getY();
				wr[i] = pixel.getPixel(falcon.allLine[i].getPointP1(),buf);
			}
			kiribawah.setX(falcon.getAnchorP2().getX());
			kiribawah.setY(falcon.getAnchorP2().getY());
	  		fill.fillRect(kiribawah, panjang, lebar, warnaHeli, buf);
	
			clip.setXmin(falcon.getAnchorP1().getX()-clipBack);
		 	clip.setXmax(falcon.getAnchorP2().getX()+clipFront);
		 	clip.setYmin(falcon.getAnchorP1().getY()-clipVert);
		 	clip.setYmax(falcon.getAnchorP2().getY()+clipVert);

			while (on) {
				check = rand()%tinggi + 50;
				if (phase %2 == 0){
					map.addBuilding(buf, check);
					for (int i = 0; i<map.getPoly().numVisibleLine; i++){
						ln[i+9][1] = map.getPoly().visibleLine[i].getPointP1().getX();
						ln[i+9][2] = map.getPoly().visibleLine[i].getPointP1().getY();
						ln[i+9][3] = map.getPoly().visibleLine[i].getPointP2().getX();
						ln[i+9][4] = map.getPoly().visibleLine[i].getPointP2().getY();
						wr[i+9] = pixel.getPixel(map.getPoly().visibleLine[i].getPointP1(),buf);
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
				
				while (move) {
					//setup frame
					fill.fillRect(pW, windowKanan-windowKiri, windowBawah-windowAtas, *Warna::hitam(), buf);
					windowA.drawLine(buf,*Warna::merah());
					windowB.drawLine(buf,*Warna::merah());
					windowKa.drawLine(buf,*Warna::merah());
					windowKi.drawLine(buf,*Warna::merah());
					batasA.drawLine(buf,*Warna::hijau());
					kiribawah.setX(falcon.getAnchorP2().getX());
					kiribawah.setY(falcon.getAnchorP2().getY());
					fill.fillRect(kiribawah, panjang, lebar, warnaHeli, buf);
	
					//baling
					centerHeli.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
					centerHeli.setY(falcon.getAnchorP1().getY());
					baling.clearBaling(sudut-100,buf);
					centerHeli.setX(centerHeli.getX()-1);
					centerHeli.setY(centerHeli.getY());
					baling.setCenter(centerHeli);
					baling.rotasiBaling(sudut,buf);
					sudut+=100;
					
					//get line for clipping baling
					if (phase%2==0) { //building
						for (int i=0; i<12; i++){
							ln[i+9+map.getPoly().numVisibleLine][1] = baling.allLine[i].getPointP1().getX();
							ln[i+9+map.getPoly().numVisibleLine][2] = baling.allLine[i].getPointP1().getY();
							ln[i+9+map.getPoly().numVisibleLine][3] = baling.allLine[i].getPointP2().getX();
							ln[i+9+map.getPoly().numVisibleLine][4] = baling.allLine[i].getPointP2().getY();
							wr[i+9+map.getPoly().numVisibleLine] = pixel.getPixel(baling.allLine[i].getPointP1(),buf);
						}
					}
					else  {
						for (int i=0; i<12; i++){
							ln[i+21][1] = baling.allLine[i].getPointP1().getX();
							ln[i+21][2] = baling.allLine[i].getPointP1().getY();
							ln[i+21][3] = baling.allLine[i].getPointP2().getX();
							ln[i+21][4] = baling.allLine[i].getPointP2().getY();
							wr[i+21] = pixel.getPixel(baling.allLine[i].getPointP1(),buf);
						}
					}
					
					//on key press
					if(kbhit()){
						input = getchar();
						//move heli up
						if (input == 'i'){
							if (falcon.getAnchorP1().getY()>batasAtas+30){
								v+=5;
								kiribawah.setX(falcon.getAnchorP2().getX());
								kiribawah.setY(falcon.getAnchorP2().getY());
								fill.fillRect(kiribawah, panjang, lebar, *Warna::hitam(), buf);
								falcon.moveUp(buf,1,v);
								kiribawah.setX(falcon.getAnchorP2().getX());
								kiribawah.setY(falcon.getAnchorP2().getY());
								fill.fillRect(kiribawah, panjang, lebar, warnaHeli, buf);
	
							}
							for (int i = 0; i<9; i++) {
								ln[i][1] = falcon.allLine[i].getPointP1().getX();
								ln[i][2] = falcon.allLine[i].getPointP1().getY();
								ln[i][3] = falcon.allLine[i].getPointP2().getX();
								ln[i][4] = falcon.allLine[i].getPointP2().getY();
								wr[i] = pixel.getPixel(falcon.allLine[i].getPointP1(),buf);
							}
					 	}
					 	//move heli down
					 	else if (input == 'k') {
					 		if (falcon.getAnchorP2().getY() < batasBawah-10){
					 			v-=5;
								kiribawah.setX(falcon.getAnchorP2().getX());
								kiribawah.setY(falcon.getAnchorP2().getY());
								fill.fillRect(kiribawah, panjang, lebar, *Warna::hitam(), buf);
								falcon.moveDown(buf,1,v);
								kiribawah.setX(falcon.getAnchorP2().getX());
								kiribawah.setY(falcon.getAnchorP2().getY());
								fill.fillRect(kiribawah, panjang, lebar, warnaHeli, buf);
								}
							for (int i = 0; i<9; i++) {
								ln[i][1] = falcon.allLine[i].getPointP1().getX();
								ln[i][2] = falcon.allLine[i].getPointP1().getY();
								ln[i][3] = falcon.allLine[i].getPointP2().getX();
								ln[i][4] = falcon.allLine[i].getPointP2().getY();		
								wr[i] = pixel.getPixel(falcon.allLine[i].getPointP1(),buf);
							}	
					 	}

					 	//move clipping window follow heli
						clip.setXmin(falcon.getAnchorP1().getX()-clipBack);
					 	clip.setXmax(falcon.getAnchorP2().getX()+clipFront);
		 				clip.setYmin(falcon.getAnchorP1().getY()-clipVert);
		 				clip.setYmax(falcon.getAnchorP2().getY()+clipVert);
					 	
					}

					//change displacement for building and cloud
					if(sp < 720) {
						sp+=10;
					}
					else {
						move = false;
					}

					//move building and cloud
					if (phase %2 == 0){
						map.motion(sp+50, buf, check);
						for (int i = 0; i<map.getPoly().numVisibleLine; i++){
							ln[i+9][1] = map.getPoly().visibleLine[i].getPointP1().getX();
							ln[i+9][2] = map.getPoly().visibleLine[i].getPointP1().getY();
							ln[i+9][3] = map.getPoly().visibleLine[i].getPointP2().getX();
							ln[i+9][4] = map.getPoly().visibleLine[i].getPointP2().getY();
							wr[i+9] = pixel.getPixel(map.getPoly().visibleLine[i].getPointP1(),buf);
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

					//do clipping
					if (phase%2==0) { //building 
						for (int i = 0; i < 25; i++){
							clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], wr[i], buf);
						}
					}
					else { //cloud
						for (int i = 0; i < 33; i++){
							clip.cohen_sutherland (ln[i][1], ln[i][2], ln[i][3], ln[i][4], wr[i], buf);
						}
					}

					usleep(50000);	
				}

				//clear building and cloud in the end of every phase
				if (phase%2 == 0)
					map.clearAll(1,buf, check);
				else 
					map.clearAll(2,buf,check-100);
				phase++;
			}
		}
	}
	buf.closeBuffer();
	return 0;
}