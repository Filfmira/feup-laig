#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "CGFobject.h"


class Primitive{
public:
	virtual void draw(){};
	virtual char* getNome(){return "gg";};

};

class Rectangle: public Primitive{
private:
	float x1;
	float x2;
	float y1;
	float y2;
public:
	Rectangle(float x1, float y1, float x2, float y2){
		this->x1 = x1;	
		this->x2 = x2;

		this->y1 = y1;	
		this->y2 = y2;
	}
		
	void draw(){
		//glRectf(x1,y1,x2,y2);

		glPushMatrix();
			
			//glMultMatrixf(tra1); 
			glNormal3f(0,0,1) ;
			
			glBegin(GL_QUADS);
				//glTexCoord2d(0,0);
				glVertex3d(x1,y1,0);
				//glTexCoord2d(1,0);
				glVertex3d(x1,y2,0);
				//glTexCoord2d(1,1);
				glVertex3d(x2,y2,0);
				//glTexCoord2d(0,1);
				glVertex3d(x2,y1,0);
			glEnd();

		glPopMatrix();
	};

	char* getNome(){return "Rectangulo";};
};

class Triangle: public Primitive{

private:
	float x1;
	float x2;
	float x3;
	float y1;
	float y2;
	float y3;
	float z1;
	float z2;
	float z3;

public:

	Triangle(float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3){

		this->x1 = x1;	
		this->x2 = x2;
		this->x3 = x3;

		this->y1 = y1;	
		this->y2 = y2;
		this->y3 = y3;

		this->z1 = z1;	
		this->z2 = z2;
		this->z3 = z3;
	}
	
	void draw(){
		glPushMatrix();			
			//glMultMatrixf(tra1); 
			glNormal3f(0,0,1) ;
			glBegin(GL_TRIANGLES);
				glVertex3d(x1,y1,z1);
				glVertex3d(x2,y2,z2);
				glVertex3d(x3,y3,z3);
			glEnd();
		glPopMatrix();
	
	};

	char* getNome(){return "Triangulo";};
};


class Cylinder: public Primitive{
private:
	float base;
	float top;
	float height;
	int slices;
	int stacks;

public:
	Cylinder (float base, float top, float height, int slices, int stacks){
		this->base = base;
		this->top = top;
		this->height = height;
		this->slices = slices;
		this->stacks = stacks;
	};

	void draw(){
		//glPushMatrix();
			gluCylinder(gluNewQuadric(), base, top, height,  slices, stacks);
		//glPopMatrix();
	};

	char* getNome(){return "Cilindro";};
};
#endif
