#include "clip.h"

    clip::clip() {

    }

	clip::~clip() {

	}

	void clip::setXmin(int x) {
		xmin = x;
	}

	void clip::setXmax(int x) {
		xmax = x;
	}

	void clip::setYmin(int x) {
		ymin = x;
	}

	void clip::setYmax(int x) {
		ymax = x;
	}

	double clip::getXmin() {
		return xmin;
	}

	double clip::getXmax() {
		return xmax;
	}

	double clip::getYmin() {
		return ymin;
	}

	double clip::getYmax() {
		return ymax;
	}


	int clip::getViewSize(){
		return viewSize;
	}

	Point clip::getViewAnchor(){
		return viewAnchor;
	}

	outcode clip::compute_outcode(int x, int y) {
		outcode oc = 0;
		if (y > ymax)
			oc |= TOP;
		else if (y < ymin)
			oc |= BOTTOM;

		if (x > xmax)
			oc |= RIGHT;
		else if (x < xmin)
			oc |= LEFT;

		return oc;
	}


	void clip::setViewSize(int vs){
		viewSize = vs;
	}

	void clip::setViewAnchor(Point p){
		viewAnchor = p;
	}

void clip::cohen_sutherland (double x1, double y1, double x2, double y2, Buffer buff) {

	bool accept;
	bool done;
	outcode outcode1, outcode2;

	accept = false;
	done = false;

	outcode1 = compute_outcode(x1, y1);
	outcode2 = compute_outcode(x2, y2);

	do {
		if (outcode1 == 0 && outcode2 == 0) {
			accept = true;
			done = true;
		}
		else if (outcode1 & outcode2) {
			done = true;
		}
		else {
			double x, y;
			int outcode_ex = outcode1 ? outcode1 : outcode2;

			if (outcode_ex & TOP) {
				x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
				y = ymax;
			}

			else if (outcode_ex & BOTTOM) {
				x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
				y = ymin;	
			}

			else if (outcode_ex & RIGHT) {
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
				x = xmax;
			}

			else {
				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
				x = xmin;	
			}

			if (outcode_ex == outcode1) {
				x1 = x;
				y1 = y;
				outcode1 = compute_outcode(x1, y1);
			}

			else {
				x2 = x;
				y2 = y;
				outcode2 = compute_outcode(x2, y2);	
			}
		}
	} while (!done);

	if (accept) {
		int x1v = (viewSize/(xmax-xmin)*(x1-xmin))+viewAnchor.getX();
		int y1v = (viewSize/(xmax-xmin)*(y1-ymin))+viewAnchor.getY();
		int x2v = (viewSize/(xmax-xmin)*(x2-xmin))+viewAnchor.getX();
		int y2v = (viewSize/(xmax-xmin)*(y2-ymin))+viewAnchor.getY();
		
		Point p1(x1v,y1v);Point p2(x2v,y2v);
		Garis g(x1v,y1v,x2v,y2v);
		g.drawLine(buff, *Warna::putih());
	}
}
