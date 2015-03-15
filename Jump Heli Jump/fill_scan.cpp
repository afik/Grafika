#include "fill_scan.h"

FillScan::FillScan(){

}

int FillScan::GetX(Garis G, int y){
	return ((y - G.getPointP1().getY())*(G.getPointP2().getX() - G.getPointP1().getX())/(G.getPointP2().getY() - G.getPointP1().getY())) + G.getPointP1().getX();
}
