#ifndef CAMERAS_H
#define CAMERAS_H

#include <vector>
#include "CGFcamera.h"
#include "CGFapplication.h"
#include <string>
#include <sstream>

class Camera{

protected:
	CGFcamera* c;
	string id;
public:
	Camera(){};
	Camera(CGFcamera* c,string id){
		this->id=(string)id;
		this->c=c;
	}
	string getId(){return id;}
	CGFcamera* getCamera(){return this->c;}
	//virtual void updateProjectionMatrix(int width, int height){};
	//virtual void applyView(){};
	//virtual void mostrar(string *a){};

};



class Prespective:public CGFcamera{
	
private:
	float near, far,angle;
	float pos[3];
	float target[3];
public:
	Prespective(float near, float far, float angle, float pos[3], float target[3]){
		this->near=near;
		this->angle=angle;
		this->pos[0]=pos[0];
		this->pos[1]=pos[1];
		this->pos[2]=pos[2];
		this->target[0]=target[0];
		this->target[1]=target[1];
		this->target[3]=target[3];
	}

	void updateProjectionMatrix(int width, int height){
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		float aspect = (float) width / (float) height;
		gluPerspective(angle, aspect, near, far);
	}

	void applyView() {
	/*gluPerspective(angle, 1.0, near, far);
	gluLookAt(pos[0],pos[1],pos[2],target[0],target[1],target[2],0,1,0);*/
	}

};

class Ortho:public CGFcamera{
	private:
	float near, far,left,right,top,bottom;
	string direction;
public:
	Ortho(string direction,float near, float far, float left, float right, float top, float bottom)
	{
		this->direction=direction;
		this->near=near;
		this->far=far;
		this->left=left;
		this->right=right;
		this->top=top;
		this->bottom=bottom;
	}

	void updateProjectionMatrix(int width, int height)
	{
		glMatrixMode(GL_PROJECTION);//lens
		glLoadIdentity();
		glOrtho(left, right, bottom, top, near, far);

	}

	void applyView()
	{
		CGFcamera::applyView();
		if(direction=="x")
		{
			//glOrtho(left, right, bottom, top, near, far);
			printf("entou no x foudasse\n");
			gluLookAt(near, 0.0, 0.0, far, 0.0, 0.0, 0.0, 1.0, 0.0);
		}
		else if(direction=="y")
		{
			//glOrtho(left, right, bottom, top, near, far);
			gluLookAt(0.0, near, 0.0, 0.0, far, 0.0, 1.0, 1.0, 1.0);

		}
		else if(direction=="z")
		{

			//glOrtho(left, right, bottom, top, near, far);
			gluLookAt(0.0, 0.0, near, 0.0, 0.0, far, 0.0, 1.0, 0.0);
		}
		else
		{
			printf("%s\n",direction);
			return;
		}
	}

};


#endif