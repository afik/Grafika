#include <iostream>
#include "pixel.h"
#include "helikopter.h"
#include "baling.h"
#include "picker.h"

using namespace std;

int main()
{
	Buffer buff;
	Helikopter falcon;
	Baling baling;	
	Point center;
	Pixel p;
	Picker pick;
	int GetX(Garis G, int y);
	
	int i=1;
	int pil;
	
	
	while(1){
	  system("clear");
	  /** menggambar kotak pilihan */
	  pick.drawPicker(buff);
	  
	  /** memilih pilihan warna */
	  Warna warna;
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
	  falcon.setVelocity(i);
	  
	  /** mewarnai helikopter */
	  Point P1(falcon.getAnchorP1().getX(),falcon.getAnchorP1().getY());
	  Point P2(falcon.getAnchorP2().getX(),falcon.getAnchorP1().getY());
	  Point P3(falcon.getAnchorP2().getX(),falcon.getAnchorP2().getY());
	  Point P4(falcon.getAnchorP1().getX(),falcon.getAnchorP2().getY());
	  
	  Garis G1(P1, P4);
	  Garis G2(P2, P3);
	  
	  for(int j = 250; j <= 300 ; j++){
	    Point Pi(GetX(G1,j) , j);
	    Point Pj(GetX(G2,j) , j);
	    Garis g(Pi, Pj);
	    g.drawLine(buff, warna);
	  }
	  
	  /** menggambar baling-baling */
	  center.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
	  center.setY(falcon.getAnchorP1().getY()-20);
	  baling.setCenter(center);
	  baling.rotasiBaling(0,buff);
	  
	  cout << "Pilih warna dari 0 sampe 15: ";
	  cin >> pil;
	
	}
	buff.closeBuffer();
	return 0;
}

int GetX(Garis G, int y){
	return ((y - G.getPointP1().getY())*(G.getPointP2().getX() - G.getPointP1().getX())/(G.getPointP2().getY() - G.getPointP1().getY())) + G.getPointP1().getX();
}
