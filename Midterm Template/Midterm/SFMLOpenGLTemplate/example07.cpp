#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

void init();
void myDrawFunction();

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zstep = 0.0f;
GLboolean light = TRUE;
GLboolean model = TRUE;
GLint polyMode = GL_FILL;



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
			yRot += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			yRot -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			xRot += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			xRot -= .1f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			zstep += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			zstep -= .1f;
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

		// Finally, display rendered frame on screen
		App.display();
	}

	return EXIT_SUCCESS;
}

void init()
{
	///// INIT OpenGL /////

	glEnable(GL_DEPTH_TEST);

	// Example09
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_FLAT);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Antialiasing
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 1000.f); // (fov, aspect, near z, far z)

}

void myDrawFunction() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, -100.f);

	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);

	glTranslatef(0.f, 0.f, zstep);

	//	glLineWidth(4.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// draw a rectangle (floor)

	glTranslatef(-50.f, 0.f, 0.f);
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-100.f, -100.f, -100.f);
	glVertex3f(0.f, 100.f, -100.f);
	glVertex3f(100.f, -100.f, -100.f);
	glEnd();

	//Example09
	glBlendFunc(GL_SRC_ALPHA, GL_ONE); //(1.0, 1.0, 1.0, 1.0)

	glTranslatef(100.f, 0.f, 20.f);
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-100.f, -100.f, -100.f);
	glVertex3f(0.f, 100.f, -100.f);
	glVertex3f(100.f, -100.f, -100.f);
	glEnd();

}
