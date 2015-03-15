#ifndef _CLIP_H
#define _CLIP_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "garis.h"
#include "bentuk.h"
#include "buffer.h"
#include <vector>

#define MAX 100

enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8};
typedef unsigned int outcode;

class clip {

public:
	clip();
	~clip();
	double getXmin();
	double getXmax();
	double getYmin();
	double getYmax();
	int getViewSize();
	Point getViewAnchor();
	void setXmin(int x);
	void setXmax(int x);
	void setYmin(int x);
	void setYmax(int x);
	void setViewSize(int vs);
	void setViewAnchor(Point p);
	outcode compute_outcode(int x, int y);
	void cohen_sutherland (double x1, double y1, double x2, double y2, Warna w, Buffer buff);
	std::vector<Garis> cekGaris(Garis* input); 

private:
	double xmin, xmax, ymin, ymax;
	int viewx, viewy, pjg, lbr;
	int viewSize;
	Point viewAnchor;
};

#endif