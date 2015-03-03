#include "window.h"

Window::Window(){
	P1.setX(300); P1.setY(300);
	Panjang = 50; Lebar = 50;
	center.setX(P1.getX()+(Panjang/2));
	center.setY(P1.getY()+(Lebar/2));
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
}

Window::Window(Point initPos){
	P1.setX(initPos.getX());
	P1.setY(initPos.getY());
	Panjang = 50; Lebar = 50;
	center.setX(P1.getX()+(Panjang/2));
	center.setY(P1.getY()+(Lebar/2));
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
}

Window::~Window(){

}

void Window::setP1(Point p){
	tempP = P1;
	P1.setX(p.getX());
}

Point Window::getP1(){
 return P1;
}

void Window::moveLeft(){
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
	P1.setX(P1.getX()-5);
	center.setX(center.getX()-5);
}

void Window::moveRight(){
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
	P1.setX(P1.getX()+5);
	center.setX(center.getX()+5);
}

void Window::moveUp(){
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
	P1.setY(P1.getY()-5);
	center.setY(center.getY()-5);
}

void Window::moveDown(){
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
	P1.setY(P1.getY()+5);
	center.setY(center.getY()+5);
}

void Window::zoomIn(){
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
	P1.setY(center.getY()-((Lebar/2)-3));
	P1.setX(center.getX()-((Panjang/2)-3));
	Panjang -= 6;
	Lebar -= 6;
}

void Window::zoomOut(){
	tempP = P1;
	tempPjg = Panjang;
	tempLebar = Lebar;
	P1.setY(center.getY()-((Lebar/2)+3));
	P1.setX(center.getX()-((Panjang/2)+3));
	Panjang += 6;
	Lebar += 6;
}

void Window::draw(Buffer buf, Warna warna){
	Bentuk bentuk;
	bentuk.persegi(tempP,tempPjg,tempLebar,buf,*Warna::hitam());
	bentuk.persegi(P1,Panjang,Lebar,buf,warna);
}