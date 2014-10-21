#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include "Viewport.h"
#include "Vector3.h"
#include "ControlUtilities.h"

class MenuControl : public control
{
public:
	MenuControl()
	{

	}

	void mouseControl()
	{
		mouseCoords = sf::Mouse::getPosition();
		if (mouseCoords.x <= windowWidth / 2 && mouseCoords.y >= windowHeight / 2 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			currentState = GAME;
		}
		//std::cout << currentState << std::endl;
		//std::cout << mouseCoords.x << ", " << TempmouseCoords.x << ", " << currentQuad << ", " << LastmouseCoords.x << std::endl;
	}

};

//will be reworked
class GameControl : public control
{
public:
	GameControl()
	{

	}

	void mouseControl()
	{
		mouseCoords = sf::Mouse::getPosition();
		std::cout << mouseCoords.x << ", " << TempmouseCoords.x << ", " << currentQuad << ", " << LastmouseCoords.x << std::endl;
	}
	void handleKeyboard()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			
		}



	}
};