#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include "Viewport.h"
#include "Vector3.h"
#include "model.h"

class Bricks : public model
{
public:
	Bricks()
	{
		origin = { 0, 0, 0 };
		translate = { 0, 0, 0 };

	}

	Bricks(float x, float y, float z, float size)
	{
		origin = { x, y, z };
		translate = { 0, 0, 0 };
		rad = size;
	}
	std::vector<model*> ListToDraw;
	vec3 origin;
	vec3 translate;
	float rad;




	void drawBox()
	{
		glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 1.0);  glVertex3f(origin.x - rad, origin.y - rad, origin.z + rad);//Bottom left
		glTexCoord2f(1.0, 1.0); glVertex3f(origin.x + rad, origin.y - rad, origin.z + rad);//Bottom right
		glTexCoord2f(1.0, 0); glVertex3f(origin.x + rad, origin.y + rad, origin.z + rad);//Top right
		glTexCoord2f(0, 0); glVertex3f(origin.x - rad, origin.y + rad, origin.z + rad);//Top left
		glEnd();
	}



};