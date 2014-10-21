#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include "Viewport.h"
#include "Vector3.h"
#include "model.h"

class Bullet : public model
{
	Bullet()
	{
		origin = { 0, 0, 0 };
		translate = { 0, 0, 0 };

	}

	Bullet(float x, float y, float z, float size)
	{
		origin = { x, y, z };
		translate = { 0, 0, 0 };
		rad = size;
	}
	std::vector<model*> ListToDraw;
	vec3 origin;
	vec3 translate;
	float rad;



};