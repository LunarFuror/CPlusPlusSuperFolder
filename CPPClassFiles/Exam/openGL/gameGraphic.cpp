/*
 * gameGraphic.cpp
 *
 *  Created on: Feb 27, 2014
 *      Author: lunarfuror
 */
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>

void initGL(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void drawBackground(){
	//DRAW BACK
		glBegin(GL_QUADS); // draw back
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(-1.3f, -0.3f);

			glColor3f(0.2f, 0.2f, 0.5f);
			glVertex2f(1.33f, -0.3f);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(1.33f, 1.0f);

			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex2f(-1.33f, 1.0f);

			//DRAW BORDER
			//bottom
			glColor3f(0.4f, 0.4f, 0.4f);
			glVertex2f(-1.33f, -1.0f);
			glVertex2f(1.33f,-1.0f);
			glColor3f(0.6f, 0.6f, 0.6f);
			glVertex2f(1.3f,-0.97f);
			glVertex2f(-1.3f,-0.97f);

			//right
			glColor3f(0.4f, 0.4f, 0.4f);
			glVertex2f(1.33f, -1.0f);
			glVertex2f(1.33f, 1.0f);
			glColor3f(0.6f, 0.6f, 0.6f);
			glVertex2f(1.3f, 0.97f);
			glVertex2f(1.3f, -0.97f);

			//top
			glColor3f(0.6f, 0.6f, 0.6f);
			glVertex2f(1.33f, 1.0f);
			glVertex2f(-1.33f, 1.0f);
			glColor3f(0.4f, 0.4f, 0.4f);
			glVertex2f(-1.3f, 0.97f);
			glVertex2f(1.3f, 0.97f);

			//left
			glColor3f(0.6f, 0.6f, 0.6f);
			glVertex2f(-1.33f, 1.0f);
			glVertex2f(-1.33f, -1.0f);
			glColor3f(0.4f, 0.4f, 0.4f);
			glVertex2f(-1.3f, -0.97f);
			glVertex2f(-1.3f, 0.97f);
		glEnd();
}

void drawEnemy(){
	glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(-1.27f, 0.0f);
		glVertex2f(-0.03f, 0.0f);
		glVertex2f(-0.03f, 0.94f);
		glVertex2f(-1.27f, 0.94f);
	glEnd();
}

void drawPlayer(){
	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2f(0.03f, -0.27f);
		glVertex2f(1.27f, -0.27f);
		glVertex2f(1.27f, 0.66f);
		glVertex2f(0.03f, 0.66f);
	glEnd();
}

void drawMenu(){
	glBegin(GL_QUADS); // DRAW BACKGROUND
		glColor3f(0.5f, 0.8f, 0.5f);
		glVertex2f(0.43f, -0.97f);
		glVertex2f(1.3f, -0.97f);
		glVertex2f(1.3f, -0.3f);
		glVertex2f(0.43f, -0.3f);
	glEnd();
	glRasterPos2f(0, 0);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char *) "min");
}

void drawMessage(){
	glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.8f);
		glVertex2f(-1.3f, -0.97f);
		glVertex2f(0.43f, -0.97f);
		glVertex2f(0.43f, -0.3f);
		glVertex2f(-1.3f, -0.3f);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	drawBackground();
	drawEnemy();
	drawPlayer();
	drawMenu();
	drawMessage();
	glFlush();
}

void reshape(GLsizei width, GLsizei height){

	if(height == 0){ // prevent divide by 0
		height = 1;
	}

	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(width >= height){ // aspect >= 1 set height from -1 to 1 with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else{ 							//aspect < 1 set width from -1 to 1 with larger height
		gluOrtho2D(-1.0, -1.0, -1.0 / aspect, 1.0/aspect);
	}
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Rediculously Overdone");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	initGL();

	glutMainLoop();

	return 0;
}

