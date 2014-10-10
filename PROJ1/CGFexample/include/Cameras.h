#ifndef CAMERAS_H
#define CAMERAS_H

#include <vector>
#include <CGFcamera.h>

class Camera{

protected:
	char* id;

public:
	Camera();
	Camera(char* id){
		this->id=id;
	}

};



class Prespective:public Camera{
	
private:
	float near,far,angle;
	float pos[3];
	float target[3];
public:
	Prespective(char* id,float near, float far, float angle, float pos[3], float target[3]){
		this->id=id;
		this->near=near;
		this->angle=angle;
		this->pos[0]=pos[0];
		this->pos[1]=pos[1];
		this->pos[2]=pos[2];
		this->target[0]=target[0];
		this->target[1]=target[1];
		this->target[3]=target[3];
	}

};


#endif