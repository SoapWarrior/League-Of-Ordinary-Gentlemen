#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
//01 - Include Image header (for loading textures)
#include <SFML\Graphics\Image.hpp>
#include <iostream>
#include "Viewport.h"
#include "Loader.h"
#include "Menu.h"
#include "model.h"
#include "Timer.h"
#include "Utilities.h"
#include "Vector3.h"
#include "Vector.h"
#include "Vector4.h"
#include "ControlUtilities.h"
#include "Controls.h"
#include "Bricks.h"
#include "Bullet.h"


sf::RenderWindow window;
sf::Event event;

bool running;
MenuControl cmain;
GameControl cgame;
Menu view1;
Viewport view2;
SceneLoader loader;	//Loads in a text file.
std::vector<Bricks*> brickList;
std::vector<Bullet*> bulletList;
float numBricks = 2;
float numBullets = 0;

model Test;

//sf::Texture cat;	//Our cat texture.

//02 - declare an Image object and a GLuint that will be our texture handler
sf::Image img_data;
GLuint texture_handle;

void initShapes()
{
	for (int i = 1; i <= numBricks; i++)
	{
		brickList.push_back(new Bricks(-3.5*i,10.0,0,1));
	}
	
}
void drawShapes()
{
	for (int i = 0; i < numBricks; i++)
	{
		brickList[i]->drawBox();
	}
}

void handleKeyboard()
{
	//std::cout << view2.eye.x << " " << view2.eye.y << std::endl; // -12:9  -24:21
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		brickList[0]->origin.y += 0.1;
		//view2.tar.y+= 0.1f;
	//	view2.eye.y += view2.tar.y * view2.fraction;//moves camera towards the x direction
	//	view2.eye.x += view2.tar.x * view2.fraction;//moves camera towards the x direction
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		brickList[0]->origin.y -= 0.1;
	//	view2.eye.y -= view2.tar.y * view2.fraction;//moves camera towards the x direction
	//	view2.eye.x -= view2.tar.x * view2.fraction;//moves camera towards the x direction
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		brickList[0]->origin.x += 0.2;
		//view2.tar.x += 0.1f;
	//	view2.eye.y += view2.tar.x * view2.fraction;//moves camera towards the x direction
	//	view2.eye.x += view2.tar.y * view2.fraction;//moves camera towards the x direction
		brickList[0]->rots += 10.1f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		brickList[0]->origin.x -= 0.2;
	//	std::cout << brickList[0]->rots;
		//view2.tar.x -= 0.1f;
	//	view2.eye.y -= view2.tar.x * view2.fraction;//moves camera towards the x direction
	//	view2.eye.x -= view2.tar.y * view2.fraction;//moves camera towards the x direction
	}
}

void ReshapeWindow(float winWidth,float winHeight){
	windowWidth=winWidth;
	windowHeight=winHeight;
}
void SetupGL(){
	ReshapeWindow(windowWidth,windowHeight);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f,0.0f,0.0f,1);
	initShapes();
	//cat.loadFromFile("grumpy.png");
}
void Setup(){
	SetupGL();

	view1=Menu(ScreenQuad::MAIN,ProjectionType::ORTHOGONAL,
		PolygonMode::FILL,0,0,-10,0,1,0);
	//gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);
	view2=Viewport(ScreenQuad::GAME,ProjectionType::ORTHOGONAL,
		PolygonMode::FILL, -12, 9, -20, 0, 1, 0);
	
	loader=SceneLoader("test.txt");
}

void Display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//View1 LEFT	/////////////////////////////
	//Set the viewport and projection matrix.
	glViewport(0,0,windowWidth,windowHeight);	//Set the viewport
	glMatrixMode(GL_PROJECTION);	//Set projection matrix.
	glLoadIdentity();				//Reset projection matrix.
	glOrtho(-1, 1, -1, 1, 0.0001f, 1000);	//Orthographic projection.

	//Change to modelview in order to draw.
	glMatrixMode(GL_MODELVIEW);		//Set modelview matrix.
	glLoadIdentity();				//Reset modelview matrix.

	//Set rendering parameters if needed.
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	//Set polygon render mode.

	//Set camera.
	gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);

	//Draw stuff.
//	view1.drawSquare();


	//TEXTURING	/////////////////
	glEnable(GL_TEXTURE_2D);
	//LOAD TEXTURE FROM FILE
	img_data.loadFromFile("images/box.bmp");

	//Generate OpenGL texture object
	glGenTextures(1, &texture_handle);

	//Binds texture (this texture will be mapped to polygons)
	glBindTexture(GL_TEXTURE_2D, texture_handle);

	// Upload data to GPU
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGBA,
		img_data.getSize().x, img_data.getSize().y, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, img_data.getPixelsPtr()
		);
	// some texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);



	if (currentState == MAIN)
	{
		view1.drawSquare();
	}
	//View 2 RIGHT
	//Set the viewport and projection matrix.
	glViewport(0, 0, windowWidth, windowHeight);//viewport size
	glMatrixMode(GL_PROJECTION);	//Set projection matrix.
	glLoadIdentity();				//Reset projection matrix.
	gluPerspective(60, 1, 0.1f, 1000);	//Perspective


	//Change to modelview in order to draw.
	glMatrixMode(GL_MODELVIEW);		//Set modelview matrix.
	glLoadIdentity();				//Reset modelview matrix.

	//Set rendering parameters if needed.
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	//Set polygon render mode.

	//Set camera.
	gluLookAt(view2.eye.x, view2.eye.y, view2.eye.z,
		view2.tar.x+view2.eye.x, view2.tar.y+view2.eye.y, view2.tar.z,
		0, 1, 0);

	//Draw stuff.
	if (currentState == GAME)
	{
		Test.drawBox(-24,22,0,0.4);
		drawShapes();
	}

}

int main(){
	window.create(sf::VideoMode((unsigned int)windowWidth,(unsigned int)windowHeight),"MyWindow");
	window.setFramerateLimit(60);

	Setup();

	running=true;
	while(running){
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed)
				running=false;
			else if(event.type==sf::Event::Resized)
				ReshapeWindow((float)event.size.width,(float)event.size.height);
		}
		if (currentState == MAIN)
		{
			cmain.HandleKeyboard();
			cmain.mouseControl();
		}
		else if (currentState == GAME)
		{
			cgame.HandleKeyboard();
			handleKeyboard();
		}
		Display();
		window.display();
	}
	return 0;
}