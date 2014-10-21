#pragma once

class control
{

public:
	control();//constructor
	float currentQuad;//Store current quadrant (enum)

	sf::Vector2i mouseCoords;//mouse coordinates
	sf::Vector2i LastmouseCoords;//store a set of coordinates
	sf::Vector2i TempmouseCoords;//store the difference between 2 vectors

	virtual void HandleKeyboard();//Keyboard control
	virtual void getMouseCoords();//get mouse coordinates
	virtual void mouseControl();//mouse control
	virtual void setQuad(float a)//set quad
	{
		currentQuad = a;
	}

};