#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

void init();
void myDrawFunction();

GLfloat yspeed = 0.0f;
GLfloat ztranslate = -300.0f;
GLfloat ytranslate = 0.0f;
GLfloat xtranslate = 0.0f;

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			yspeed += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			yspeed -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			ztranslate += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			ztranslate -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			xtranslate += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			xtranslate -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			ytranslate += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			ytranslate -= .1f;
		/////
		/////

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
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);


	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f); // (fov, aspect, near z, far z)
}


void myDrawFunction() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
	glRotatef(yspeed, 0.0f, 1.0f, 0.0f);
	glTranslatef(xtranslate, ytranslate, ztranslate);
	drawCube(50,50,50);


	

	glEnd();
}