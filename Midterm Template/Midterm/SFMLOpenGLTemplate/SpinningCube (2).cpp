#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

void init();
void myDrawFunction();

GLfloat yspeed = 1.0f;
GLfloat zstep = 0.0f;
GLfloat ystep = 0.0f;
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;


GLdouble vx(0);
GLdouble vy(0);
int main()
{
	// Create the main window
	sf::Window App(sf::VideoMode(800, 800, 32), "My OpenGL Window");//, sf::Style::Fullscreen, 2); // 2 levels of antialiasing

	init(); //Init OpenGL states 

	sf::Event Event;

	///// MAIN LOOP /////
	while (App.isOpen())
	{
		// Clear color and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		///// Real-time input handling
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			yspeed += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			yspeed -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			vy += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			vy -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			vx -= 0.1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			vx += 0.1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			xRot += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			xRot -= .1f;

		///

		while (App.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				App.close();

			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				App.close();

			// Resize event : adjust viewport
			if (Event.type == sf::Event::Resized)
				glViewport(0, 0, Event.size.width, Event.size.height);

		}

		myDrawFunction();

		// Finally, display rendered frame on screen
		App.display();
	}

	return EXIT_SUCCESS;
}

void init()
{
	///// INIT OpenGL /////
	// Set color and depth clear value
	glClearDepth(1.f);
	glClearColor(0.5f, 0.5f, 0.5f, 1.f);

	// Enable Z-buffer read and write (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	//Example03
	//glLineWidth(4.0f);
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); //GL_FILL

	//example04
	glFrontFace(GL_CCW);// INSIDE IS NOT VISIBLE
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);


	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.f, 0.1f, 1000.f); // (fov, aspect, near z, far z)
}

void drawCube(float width, float height, float depth)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 100.0f, 0.0f);     // Green
	glVertex3f(width, height, -depth);
	glVertex3f(-width, height, -depth);
	glVertex3f(-width, height, depth);
	glVertex3f(width, height, depth);

	// Bottom face (y = -100.0f)
	glColor3f(100.0f, 0.5f, 0.0f);     // Orange
	glVertex3f(width, -height, depth);
	glVertex3f(-width, -height, depth);
	glVertex3f(-width, -height, -depth);
	glVertex3f(width, -height, -depth);

	// Front face  (z = 100.0f)
	glColor3f(100.0f, 0.0f, 0.0f);     // Red
	glVertex3f(width, height, depth);
	glVertex3f(-width, height, depth);
	glVertex3f(-width, -height, depth);
	glVertex3f(width, -height, depth);

	// Back face (z = -100.0f)
	glColor3f(100.0f, 100.0f, 0.0f);     // Yellow
	glVertex3f(width, -height, -depth);
	glVertex3f(-width, -height, -depth);
	glVertex3f(-width, height, -depth);
	glVertex3f(width, height, -depth);

	// Left face (x = -100.0f)
	glColor3f(0.0f, 0.0f, 100.0f);     // Blue
	glVertex3f(-width, height, depth);
	glVertex3f(-width, height, -depth);
	glVertex3f(-width, -height, -depth);
	glVertex3f(-width, -height, depth);

	// Right face (x = 100.0f)
	glColor3f(100.0f, 0.0f, 100.0f);     // Magenta
	glVertex3f(width, height, -depth);
	glVertex3f(width, height, depth);
	glVertex3f(width, -height, depth);
	glVertex3f(width, -height, -depth);
	glEnd();
}


//void drawPyramid()
//{
//
//	glBegin(GL_POLYGON);
//
//	glColor3f(1.0f, 1.0f, 0.0f);     
//	glVertex3f(0.0f, 50.0f, 0.0f);
//	glVertex3f(-50.0f, -50.0f, 50.0f);
//	glVertex3f(50.0f, -50.0f, 50.0f);
//
//	// Right
//	glColor3f(1.0f, 0.0f, 0.0f);     // Red
//	glVertex3f(0.0f, 50.0f, 0.0f);
//	glVertex3f(50.0f, -50.0f, 50.0f);
//	glVertex3f(50.0f, -50.0f, -50.0f);
//
//	// Back
//	glColor3f(0.0f, 1.0f, 0.0f);     // Green
//	glVertex3f(0.0f, 50.0f, 0.0f);
//	glVertex3f(50.0f, -50.0f, -50.0f);
//	glVertex3f(-50.0f, -50.0f, -50.0f);
//
//	// Left
//	glColor3f(0.0f, 0.0f, 1.0f);       // Blue
//	glVertex3f(0.0f, 50.0f, 0.0f);
//	glVertex3f(-50.0f, -50.0f, -50.0f);
//	glVertex3f(-50.0f, -50.0f, 50.0f);
//	
//	glColor3f(1.0f, 0.0f, 1.0f);
//	glVertex3f(-50.0f, -50.0f, -50.0f);
//	glVertex3f(50.0f, -50.0f, -50.0f);
//	glVertex3f(50.0f, -50.0f, 50.0f);
//	glVertex3f(-50.0f, -50.0f, 50.0f);
//	
//	glEnd();
//
//	
//}



void DrawPyramid(float side, float height)
{
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glTranslatef(0.f, 0.f, -20.f);

	//glRotatef(yspeed, 0.f, 1.0f, 0.f);
	//glRotatef(xspeed, 1.0f, 0.f, 0.f);

	glBegin(GL_TRIANGLES);

	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(side / 2, 0.0f, side / 2);
	glVertex3f(side / 2, 0.0f, -side / 2);
	glVertex3f(0.0f, height, 0);

	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-side / 2, 0.0f, side / 2);
	glVertex3f(side / 2, 0.0f, side / 2);
	glVertex3f(0.0f, height, 0);

	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(side / 2, 0.0f, -side / 2);
	glVertex3f(-side / 2, 0.0f, -side / 2);
	glVertex3f(0.0f, height, 0);

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-side / 2, 0.0f, -side / 2);
	glVertex3f(-side / 2, 0.0f, side / 2);
	glVertex3f(0.0f, height, 0);

	glEnd();

	glBegin(GL_QUADS);

	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-side / 2, 0.0f, -side / 2);
	glVertex3f(side / 2, 0.0f, -side / 2);
	glVertex3f(side / 2, 0.0f, side / 2);
	glVertex3f(-side / 2, 0.0f, side / 2);




	glEnd();
}

void myDrawFunction() {

	//Here we make sure that the matrix at the bottom of the ModelView stack is identity
	//So that we can start this frame from sctrach (starting from the origin with no rotation)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0f, 80, vx, vy, 0, 0, 1, 0);//positions the camera

	//Here we are moving the camera.
	//This transformation will be applied to ALL objects that are render
	glTranslatef(75.f, 0.f, -450.f);

	// example04
	/*glTranslatef(0.f, ystep, zstep);*/


	//drawPyramid();
	//glPopMatrix();

	//Here we draw our first object.
	//We push a matrix onto the stack so that the set of transformations
	//inside the block do NOT apply to anything else
	glPushMatrix();
	glRotatef(yRot, 0.f, 0.f, 1.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);
	glRotatef(yspeed, 0.f, 1.f, 0.f);
	drawCube(50, 50, 50);
	glPopMatrix();

	xRot += 0.1f;

	//Here we render the second cube. We have to translate first,
	//then rotate, or else it will begin to orbit around the origin.
	glPushMatrix();
	glTranslatef(-200.f, 0.f, 0.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);
	glRotatef(yspeed, 0.f, 1.f, 0.f);
	drawCube(50, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.f, 0.f, 0.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);
	glRotatef(yspeed, 0.f, 1.f, 0.f);
	DrawPyramid(100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-400.f, 0.f, 0.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);
	glRotatef(yspeed, 0.f, 1.f, 0.f);
	DrawPyramid(100, 100);
	glPopMatrix();


}
