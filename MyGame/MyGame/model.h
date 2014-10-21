#pragma once

class model
{

public:
	model()
	{
		positionX = 0;
		positionY = 0;

		sizeX = 0;
		sizeY = 0;
	}
	std::vector<model*> ListToDraw;

	float positionX;
	float positionY;

	float sizeX;
	float sizeY;

	void drawBox()
	{
		glBegin(GL_QUADS);
		//glColor3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0, -1.0, 0);	//Bottom left
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -1.0, 0);	//Bottom right
		glTexCoord2f(1.0, 0); glVertex3f(1.0, 1.0, 0);	//Top right
		glTexCoord2f(0, 0); glVertex3f(-1.0, 1.0, 0);	//Top left

		glEnd();
	}

	void drawBox(float centerX,float centerY,float centerZ,float radius)
	{
		glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 1.0);  glVertex3f(centerX - radius, centerY - radius, centerZ + radius);//Bottom left
		glTexCoord2f(1.0, 1.0); glVertex3f(centerX + radius, centerY - radius, centerZ + radius);//Bottom right
		glTexCoord2f(1.0, 0); glVertex3f(centerX + radius, centerY + radius, centerZ + radius);//Top right
		glTexCoord2f(0, 0); glVertex3f(centerX - radius, centerY + radius, centerZ + radius);//Top left
		glEnd();
	}

};