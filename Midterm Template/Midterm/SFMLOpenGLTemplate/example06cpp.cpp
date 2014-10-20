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

GLUquadricObj *quadratic; // for gluSphere

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
	// Set color and depth clear value
	glClearDepth(1.f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.f);

	// Enable Z-buffer read and write (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	// example06 //////
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

	GLfloat light_position[] = { 100.0, 100.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//glEnable(GL_COLOR_MATERIAL); // final polygon color will be based on glColor and glMaterial

	quadratic = gluNewQuadric();          // Create A Pointer To The Quadric Object
	gluQuadricNormals(quadratic, GLU_SMOOTH);   // Create Smooth Normals

	///////////////// 
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 1000.f); // (fov, aspect, near z, far z)
}

void myDrawFunction() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, polyMode);
	glTranslatef(0.f, 0.f, -200.f);

	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(yRot, 0.f, 1.f, 0.f);

	glTranslatef(0.f, 0.f, zstep);

	gluSphere(quadratic, 100.0f, 32, 32); //draw a sphere

}