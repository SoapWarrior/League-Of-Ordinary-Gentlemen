#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Vector3.h"

enum ScreenQuad{	//What quadrant of the screen our viewport is
	MAIN,
	GAME
};
enum ProjectionType{	//Type of projection in the viewport
	PERSPECTIVE,
	ORTHOGONAL
};
enum PolygonMode{	//How to render polygons
	WIREFRAME,
	FILL
};

class Viewport{
public:
	Viewport(){	//Default blank constructor.
	}
	Viewport(ScreenQuad _sq, ProjectionType _pt, PolygonMode _pm,float eye1, float eye2, float eye3, float tar1, float tar2, float tar3){
		//Camera
		eye=vec3(eye1,eye2,eye3);
		tar=vec3(tar1,tar2,tar3);

		//Setup
		sq=_sq;
		pt=_pt;
		pm=_pm;

		fraction = 1.5f;
		angle = 0.0f;
		rotSpeed = 0.07f;
	}


	//Camera
	vec3 eye;
	vec3 tar; 

	float angle;
	float rotSpeed;
	float fraction;

	/*void trcamLeft()//translate cam left
	{
		eye.x -= tar.x * fraction;//moves camera towards the x direction
		eye.z -= tar.z * fraction;//moves camera towards the z direction
	}
	void rotcamLeft()//rotate camera left
	{
		angle -= rotSpeed;//radians
		tar.x = sin(angle);//calculates the x direction
		tar.z = -cos(angle);//calculates the z direction(like x and y plane)
	}
	
	void trcamRight()//translate came right
	{
		eye.x -= tar.x * fraction;//moves camera towards the x direction
		eye.z -= tar.z * fraction;//moves camera towards the z direction
	}
	void rotcamRight()//rotate came right
	{
		angle += rotSpeed;//radians
		tar.x = sin(angle);//calculates the x direction
		tar.z = -cos(angle);//calculates the z direction(like x and y plane)
	}

	void trcamForward()//translate came forward
	{
		eye.x += tar.x * fraction;//moves camera towards the x direction
		eye.z += tar.z * fraction;//moves camera towards the z direction
	}
	void rotcamUp()//rotate came up
	{
		angle += 0.02f;//radians
		tar.y = -sin(angle);//calculates the y direction
	}

	void trcamBackward()//translate cam backward
	{
		eye.x -= tar.x * fraction;//moves camera towards the x direction
		eye.z -= tar.z * fraction;//moves camera towards the z direction
	}
	void rotcamDown()//rotate came  down
	{
		angle += 0.02f;//radians
		tar.y = -sin(angle);//calculates the y direction
	}

	void trcamUp()
	{

		eye.y -= tar.y * fraction;//moves camera towards the x direction
		eye.x -= tar.x * fraction;//moves camera towards the x direction
	}

	void trcamDown()
	{
		eye.y += tar.y * fraction;//moves camera towards the x direction
		eye.x += tar.x * fraction;//moves camera towards the x direction
	}*/

	//Setup
	ScreenQuad sq;		//Screen area. Left/Right.
	ProjectionType pt;	//Projection type. Perspective/Orthogonal
	PolygonMode pm;		//Polygon render mode. Wireframe/fill.
};

float windowWidth(1600), windowHeight(900);
float currentState = MAIN;

#endif