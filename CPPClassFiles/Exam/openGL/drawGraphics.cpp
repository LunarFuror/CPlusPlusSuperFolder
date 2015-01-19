/*
 * drawGraphics.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: lunarfuror
 */
#include "drawGraphics.h"

drawGraphics::drawGraphics(){
	red = 0;
	green = 0;
	blue = 0;
	menuType = 0;
	cursorPosition = 0;
}

void drawGraphics::drawBattleMenu(){

}

void drawGraphics::drawMessage(){

}

void drawGraphics::drawGameMenu(){

}

void drawGraphics::drawCharacterInfo(){

}

void drawGraphics::drawCharacter(){

}

void drawGraphics::drawEnemy(){

}

void drawGraphics::drawCharacterHealth(){

}

void drawGraphics::drawEnemyHealth(){

}

void drawGraphics::drawBackWindow(){


}

void drawGraphics::drawBattleSpace(){

}

void drawGraphics::drawBox(double x, double y, double height, double width){
	x = ((x / 300) * 2) - 1.333;
	y = (((y / 300) * 2) - 1) * -1;
	height = height / 300;
	width = width / 300;
	glBegin(GL_QUADS);
		glColor3d(red,green,blue);
		glVertex2d(x, y);
		glVertex2d(x, y - height);
		glVertex2d(x + width, y-height);
		glVertex2d(x + width, y);
		glEnd();
}

void drawGraphics::setBoxColor(double r, double g, double b){
	if(r < 0) {r = 0;}
	if(r > 255) {r = 255;}
	if(g < 0) {g = 0;}
	if(g > 255) {g = 255;}
	if(b < 0) {b = 0;}
	if(b > 255) {b = 255;}

	red = r/255;
	green = g/255;
	blue = b/255;
}

void drawGraphics::drawCompass(){
	glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
		glColor3f( 0.0f, 1.0f, 1.0f);
	  glVertex3f( 0.0f, 0.1f, 0.0f);              // Top
	  glColor3f( 1.0f, 1.0f, 1.0f);
	  glVertex3f( 0.0f,-0.1f, 0.0f);              // Bottom
	  glColor3f( 1.0f, 1.0f, 0.0f);
	  glVertex3f( x1, y1, z1);              // coords
	glEnd();
}

void drawGraphics::setX(double x){
	x1 = x;
}

void drawGraphics::setY(double y){
	y1 = y;
}

void drawGraphics::setZ(double z){
	z1 = z;
}

double drawGraphics::getX(){
	return x1;
}

double drawGraphics::getY(){
	return y1;
}

double drawGraphics::getZ(){
	return z1;
}


