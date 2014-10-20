#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

void init();
void myDrawFunction();

GLfloat yspeed = 0.0f;
GLfloat zstep = 0.0f;

GLint polyMode;


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

		/////

		while (App.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				App.close();

			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				App.close();

			// Example05 - toggle wireframe mode ON/OFF
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W)) {
				glGetIntegerv(GL_POLYGON_MODE, &polyMode);

				if (polyMode == GL_FILL)
					polyMode = GL_LINE;
				else polyMode = GL_FILL;
			}

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


	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f); // (fov, aspect, near z, far z)
}

void myDrawFunction() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-110.f, 0.f, -250.f);

	// example03
	glRotatef(yspeed, 0.f, 1.f, 0.f);

	glPolygonMode(GL_FRONT_AND_BACK, polyMode);

	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

	// Non-convex polygon - see how polygons are filled?
	glBegin(GL_POLYGON);
	glVertex2f(-100.0, 100.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(100.0, 100.0);
	glVertex2f(100.0, -100.0);
	glVertex2f(-100.0, -100.0);
	glEnd();

	// Multiple triangles to draw the same object
	glTranslatef(220.f, 0.f, 0.f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(-0.0, 0.0);
	glVertex2f(100.0, 100.0);
	glVertex2f(100.0, -100.0);
	glVertex2f(-100.0, -100.0);
	glVertex2f(-100.0, 100.0);

	glEnd();

}