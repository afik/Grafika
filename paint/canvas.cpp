#include "canvas.h"

Canvas::Canvas() {

}

Canvas::~Canvas() {

}

Point Canvas::getVertex() {
    return vertex;
}

int Canvas::getPanjang() {
    return panjang;
}

int Canvas::getLebar() {
    return lebar;
}

void Canvas::setVertex(Point p) {
    vertex = p;
}

void Canvas::setPanjang(int length) {
    panjang = length;
}

void Canvas::setLebar(int width) {
    lebar = width;
}

void Canvas::drawCanvas() {
    Buffer b;
    Warna w;

    area.persegi(vertex, panjang, lebar, b, w);
}