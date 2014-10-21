#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include "Viewport.h"
#include "Vector3.h"

class Bricks : public Viewport
{
public:
	Bricks()
	{


	}

	Bricks(ScreenQuad _sq, ProjectionType _pt, PolygonMode _pm, float tar1, float tar2, float tar3, float eye1, float eye2, float eye3){
		//Camera
		eye = vec3(eye1, eye2, eye3);
		tar = vec3(tar1, tar2, tar3);
		//Setup
		sq = _sq;
		pt = _pt;
		pm = _pm;

		this->fraction = 1.5f;
		this->angle = 0.0f;
		this->rotSpeed = 0.07f;
	}

	void drawSquare()
	{
		glBegin(GL_QUADS);
		//glColor3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0, -1.0, 0);	//Bottom left
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -1.0, 0);	//Bottom right
		glTexCoord2f(1.0, 0); glVertex3f(1.0, 1.0, 0);	//Top right
		glTexCoord2f(0, 0); glVertex3f(-1.0, 1.0, 0);	//Top left

		glEnd();

	}

	//Param
	vec3 objectOrigin = { -1.f, -1.f, 0.f };

};