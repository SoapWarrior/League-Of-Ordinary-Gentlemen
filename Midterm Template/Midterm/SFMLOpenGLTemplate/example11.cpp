#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <stdio.h>	// Header File For Standard Input/Output

void init();
void myDrawFunction1();
void myDrawFunction2();
void myDrawFunction3();
void myDrawFunction4();
void setViewports();

//EXAMPLE 11
void loadFile();
void readLine(FILE*, char*);

// Data structures - example11
typedef struct tagVERTEX {
	float x, y, z;
	float u, v;
} VERTEX;

typedef struct tagTRIANGLE {
	VERTEX vertex[3];
} TRIANGLE;

typedef struct tagObject {
	int numtriangles;
	TRIANGLE* triangle;
} OBJECT;

OBJECT world1;


GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zRot = 0.0f;
GLfloat xTrans = 0.0f;
GLboolean light = TRUE;
GLboolean model = TRUE;
GLint polyMode = GL_FILL;

GLuint windowWidth = 1024;
GLuint windowHeight = 768;

//Example11
GLfloat x, y, z;

int main()
{
	// Create the main window
	sf::Window App(sf::VideoMode(windowWidth, windowHeight, 32), "My OpenGL Window");//, sf::Style::Fullscreen, 2); // 2 levels of antialiasing

	init(); //Init OpenGL states 

	sf::Event Event;

	///// MAIN LOOP /////
	while (App.isOpen())
	{
		// Clear color and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		///// Real-time input handling
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			zRot += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			zRot -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			xTrans += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			xTrans -= .1f;
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
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::K)) {
				if (polyMode == GL_FILL)
					polyMode = GL_LINE;
				else polyMode = GL_FILL;

				glPolygonMode(GL_FRONT_AND_BACK, polyMode);
			}


			//// Resize event : adjust viewport
			//if (Event.type == sf::Event::Resized) {
			//	glViewport(0, 0, Event.size.width, Event.size.height);
			//	glMatrixMode(GL_PROJECTION);
			//	glLoadIdentity();
			//	gluPerspective(90.f, Event.size.width / Event.size.height, 1.f, 500.f);
			//	glMatrixMode(GL_MODELVIEW);

			//}

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
		App.setActive();

		// Example 09
		setViewports();
		//////

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

	//Example11
	loadFile();
}

void setViewports() {

	
	///// Viewport Top Left Corner
	// Setup a perspective projection
	glViewport(0, windowHeight / 2, windowWidth / 2, windowHeight / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 1000.f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	myDrawFunction1();

	///// Viewport Top Right Corner
	// Setup a perspective projection
	glViewport(windowWidth / 2, windowHeight / 2, windowWidth / 2, windowHeight /2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 1000.f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	myDrawFunction2();

	///// Viewport 1
	// Setup a perspective projection
	glViewport(0, 0, windowWidth / 2, windowHeight/2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 0.1f, 1000.f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	myDrawFunction3();

	///// Viewport 2
	// Setup a perspective projection
	glViewport(windowWidth / 2, 0, windowWidth / 2, windowHeight / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 1000.f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	myDrawFunction4();





}

void readLine(FILE *fp, char *string) {
	do
	{
		fgets(string, 255, fp);

	} while (string[0] == 'g'); // endline character
	return;
}

void loadFile() {
	float x, y, z, u, v;
	int numtriangles = 1; // in this example, I’ll load 1 triangle only
	FILE *inputfile;
	char line[255];
	inputfile = fopen("3dworld.txt", "rt");

	world1.triangle = new TRIANGLE[numtriangles];
	world1.numtriangles = numtriangles;

	for (int vert = 0; vert < 3; vert++){
		readLine(inputfile, line);
		sscanf(line, "%f %f %f", &x, &y, &z);
		world1.triangle[0].vertex[vert].x = x;
		world1.triangle[0].vertex[vert].y = y;
		world1.triangle[0].vertex[vert].z = z;
	}
	fclose(inputfile);
	return;
}




void myDrawFunction1() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, -200.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(zRot, 0.f, 1.f, 0.f);


	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 50.0f);
	for (int v = 0; v < 3; v++)
		glVertex3f(world1.triangle[0].vertex[v].x,
		world1.triangle[0].vertex[v].y,
		world1.triangle[0].vertex[v].z);
	glEnd();


}
void myDrawFunction2() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, -200.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(zRot, 0.f, 1.f, 0.f);


	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 100.0f, 0.0f);
	for (int v = 0; v < 3; v++)
		glVertex3f(world1.triangle[0].vertex[v].x,
		world1.triangle[0].vertex[v].y,
		world1.triangle[0].vertex[v].z);
	glEnd();


}
void myDrawFunction3() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, -200.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(zRot, 0.f, 1.f, 0.f);


	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 100.0f, 100.0f);
	for (int v = 0; v < 3; v++)
		glVertex3f(world1.triangle[0].vertex[v].x,
		world1.triangle[0].vertex[v].y,
		world1.triangle[0].vertex[v].z);
	glEnd();


}
void myDrawFunction4() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, -200.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);
	glRotatef(zRot, 0.f, 1.f, 0.f);


	glBegin(GL_TRIANGLES);
	glColor3f(50.0f, 0.0f, 50.0f);
	for (int v = 0; v < 3; v++)
		glVertex3f(world1.triangle[0].vertex[v].x,
		world1.triangle[0].vertex[v].y,
		world1.triangle[0].vertex[v].z);
	glEnd();


}