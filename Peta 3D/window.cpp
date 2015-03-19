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

int Window::getPanjang() {
	return Panjang;
}

int Window::getLebar() {
	return Lebar;
}

Point Window::getP1(){
 return P1;
}

void Window::moveLeft(){
	// P1.setX(P1.getX()-5);
	// P1.setX(P1.getX()-5);
	// tempP = P1;	
	// tempPjg = Panjang;
	// tempLebar = Lebar;
	// center.setX(center.getX()-5);
	// if (P1.getX()>10) {
		tempP = P1;	
		P1.setX(P1.getX()-5);
		tempPjg = Panjang;
		tempLebar = Lebar;
		center.setX(center.getX()-5);
	// }
	// else {
	// 	P1 = tempP;
	// 	tempP = P1;	
	// 	tempPjg = Panjang;
	// 	tempLebar = Lebar;
	// 	center.setX(center.getX()-5);
	// }
}

void Window::moveRight(){
	// P1.setX(P1.getX()+5);
	// tempP = P1;
	// tempPjg = Panjang;
	// tempLebar = Lebar;
	// center.setX(center.getX()+5);
	// if (P1.getX()<800){
		tempP = P1;
		P1.setX(P1.getX()+5);
		tempPjg = Panjang;
		tempLebar = Lebar;
		center.setX(center.getX()+5);
	// }
	// else {
	// 	P1 = tempP;	
	// 	tempP = P1;
	// 	tempPjg = Panjang;
	// 	tempLebar = Lebar;
	// 	center.setX(center.getX()+5);
	// }
}

void Window::moveUp(){
	// P1.setY(P1.getY()-5);
	// tempP = P1;
	// tempPjg = Panjang;
	// tempLebar = Lebar;
	// center.setY(center.getY()-5);
	// if (P1.getY()>10){
		tempP = P1;
		P1.setY(P1.getY()-5);
		tempPjg = Panjang;
		tempLebar = Lebar;
		center.setY(center.getY()-5);
	// }
	// else {
	// 	P1 = tempP;
	// 	tempP = P1;
	// 	tempPjg = Panjang;
	// 	tempLebar = Lebar;
	// 	center.setY(center.getY()-5);
	// }
}

void Window::moveDown(){
	// P1.setY(P1.getY()+5);
	// tempP = P1;
	// tempPjg = Panjang;
	// tempLebar = Lebar;
	// center.setY(center.getY()+5);
	// if (P1.getY()<800){
		tempP = P1;
		P1.setY(P1.getY()+5);
		tempPjg = Panjang;
		tempLebar = Lebar;
		center.setY(center.getY()+5);
	// }
	// else {
	// 	P1 = tempP;
	// 	tempP = P1;
	// 	tempPjg = Panjang;
	// 	tempLebar = Lebar;
	// 	center.setY(center.getY()+5);
	// }
}

void Window::zoomIn(){
	// Panjang -= 6;
	// Lebar -= 6;
	// tempP = P1;
	// tempPjg = Panjang;
	// tempLebar = Lebar;
	// P1.setY(center.getY()-((Lebar/2)-3));
	// P1.setX(center.getX()-((Panjang/2)-3));
	// if (Panjang > 6){
		tempP = P1;
		tempPjg = Panjang;
		tempLebar = Lebar;
		Panjang -= 6;
		Lebar -= 6;
		P1.setY(center.getY()-((Lebar/2)-3));
		P1.setX(center.getX()-((Panjang/2)-3));
	// }
	// else 
	// {
	// 	Panjang = tempPjg;
	// 	Lebar = tempLebar;
	// 	tempP = P1;
	// 	tempPjg = Panjang;
	// 	tempLebar = Lebar;
	// 	P1.setY(center.getY()-((Lebar/2)-3));
	// 	P1.setX(center.getX()-((Panjang/2)-3));
	// }
}

void Window::zoomOut(){
	// Panjang += 6;
	// Lebar += 6;
	// tempP = P1;
	// tempPjg = Panjang;
	// tempLebar = Lebar;
	// P1.setY(center.getY()-((Lebar/2)+3));
	// P1.setX(center.getX()-((Panjang/2)+3));
	// if (Panjang < 200)	{
		tempP = P1;
		tempPjg = Panjang;
		tempLebar = Lebar;
		Panjang += 6;
		Lebar += 6;
		P1.setY(center.getY()-((Lebar/2)+3));
		P1.setX(center.getX()-((Panjang/2)+3));
	// }	
	// else 
	// {
	// 	Panjang = tempPjg;
	// 	Lebar = tempLebar;
	// 	tempP = P1;
	// 	tempPjg = Panjang;
	// 	tempLebar = Lebar;
	// 	P1.setY(center.getY()-((Lebar/2)+3));
	// 	P1.setX(center.getX()-((Panjang/2)+3));
	// }
}

void Window::draw(Buffer buf, Warna warna){
	Bentuk bentuk;
	bentuk.persegi(tempP,tempPjg,tempLebar,buf,*Warna::hitam());
	bentuk.persegi(P1,Panjang,Lebar,buf,warna);
}