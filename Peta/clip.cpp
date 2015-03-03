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

	void clip::cohen_sutherland (int offsetx, int offsety, double x1, double y1, double x2, double y2, Buffer buff) {

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
			Garis g(x1+offsetx, y1+offsety, x2+offsetx, y2+offsety);
			g.drawLine(buff, *Warna::putih());
		}
	}

	std::vector<Garis> clip::cekGaris(Garis* input) {
		vector<Garis> output;

		for (int i = 0; i<(sizeof(input)/sizeof(*input)); i++) {

			if((input[i].getPointP1().getX() > xmin && input[i].getPointP1().getX() < xmax) && 
				(input[i].getPointP1().getY() > ymin && input[i].getPointP1().getY() < ymax)) {
				output.push_back(input[i]);
			}

			if((input[i].getPointP2().getX() > xmin && input[i].getPointP2().getX() < xmax) && 
				(input[i].getPointP2().getY() > ymin && input[i].getPointP2().getY() < ymax)) {
				output.push_back(input[i]);
			}
		}

		return output;
	}