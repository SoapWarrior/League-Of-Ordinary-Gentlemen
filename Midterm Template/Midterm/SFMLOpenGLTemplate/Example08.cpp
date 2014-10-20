#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

void init();
void myDrawFunction();

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zRot = 0.0f;
GLfloat zRot2 = 0.0f;
GLfloat xTrans = 0.0f;
GLboolean light = TRUE;
GLboolean model = TRUE;
GLint polyMode = GL_FILL;
GLfloat xtrans = 0.0f;
GLfloat ytrans = 0.0f;
GLfloat ztrans = 0.0f;


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
			zRot += 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			zRot -= 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			xtrans += 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			xtrans -= 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			ztrans += 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			ztrans -= 1.0f;

		while (App.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				App.close();

			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				App.close();

			// Example05 - toggle wireframe mode ON/OFF
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::K))
			if (polyMode == GL_FILL)
				polyMode = GL_LINE;
			else polyMode = GL_FILL;


			// Resize event : adjust viewport
			if (Event.type == sf::Event::Resized)
				glViewport(0, 0, Event.size.width, Event.size.height);


			// L key: switch Light ON/OFF
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::L))
			if (light) {
				glDisable(GL_LIGHTING);
				light = FALSE;
			}
			else {
				glEnable(GL_LIGHTING);
				light = TRUE;
			}

			// M key: switch shading model (smooth | flat)
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::M))
			if (model) {
				glShadeModel(GL_FLAT);
				model = 0;
			}
			else {
				glShadeModel(GL_SMOOTH);
				model = 1;
			}


		}

		myDrawFunction();
		gluLookAt(xtrans, ytrans, ztrans,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
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

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f); // (fov, aspect, near z, far z)
	//gluLookAt(xtrans,ytrans,ztrans,
	//	0.0, 0.0, 0.0,
	//	0.0, 1.0, 0.0);
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

void drawPy(){
	glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
	// Front
	glColor3f(100.0f, 0.0f, 0.0f);     // Red
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 100.0f, 0.0f);     // Green
	glVertex3f(-100.0f, -100.0f, 100.0f);
	glColor3f(0.0f, 0.0f, 100.0f);     // Blue
	glVertex3f(100.0f, -100.0f, 100.0f);

	// Right
	glColor3f(100.0f, 0.0f, 0.0f);     // Red
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 100.0f);     // Blue
	glVertex3f(100.0f, -100.0f, 100.0f);
	glColor3f(0.0f, 100.0f, 0.0f);     // Green
	glVertex3f(100.0f, -100.0f, -100.0f);

	// Back
	glColor3f(100.0f, 0.0f, 0.0f);     // Red
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 100.0f, 0.0f);     // Green
	glVertex3f(100.0f, -100.0f, -100.0f);
	glColor3f(0.0f, 0.0f, 100.0f);     // Blue
	glVertex3f(-100.0f, -100.0f, -100.0f);

	// Left
	glColor3f(100.0f, 0.0f, 0.0f);       // Red
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 100.0f);       // Blue
	glVertex3f(-100.0f, -100.0f, -100.0f);
	glColor3f(0.0f, 100.0f, 0.0f);       // Green
	glVertex3f(-100.0f, -100.0f, 100.0f);
	glEnd();   // Done drawing the pyramid
}
void myDrawFunction() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.f, 0.f, -300.f);

	glPolygonMode(GL_FRONT_AND_BACK, polyMode);

	//glPushMatrix();

	// example08 - Invert trans x rot
	
	glTranslatef(xTrans, 0.f, ztrans);
	glRotatef(zRot, 0.f, 1.0f, 0.f);
	glBegin(GL_QUADS);
	drawPy();
	//drawCube(50, 50, 50);
	glEnd();


	glPopMatrix();
	
	
}





