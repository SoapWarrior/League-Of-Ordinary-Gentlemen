#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <math.h>
#include <iostream>
#include "ControlUtilities.h"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

control::control()
{
	currentQuad = -1;
	mouseCoords.x = 1; mouseCoords.y = 1;
	LastmouseCoords.x = 3; LastmouseCoords.y = 3;
	TempmouseCoords.x = 2; TempmouseCoords.y = 2;
}

void control::HandleKeyboard(){


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){

		exit(EXIT_SUCCESS);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){


	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){


	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){


	}
}

void control::getMouseCoords()
{
	mouseCoords = sf::Mouse::getPosition();
}

void control::mouseControl()
{
	std::cout << mouseCoords.x << ", " << TempmouseCoords.x  << ", " << LastmouseCoords.x << std::endl;
	TempmouseCoords = mouseCoords - LastmouseCoords;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		LastmouseCoords = mouseCoords;

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		LastmouseCoords = mouseCoords;

	}
}

