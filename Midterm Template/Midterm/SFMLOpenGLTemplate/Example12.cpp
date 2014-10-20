#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

//01 - Include Image header (for loading textures)
#include <SFML\Graphics\Image.hpp>

void init();
void myDrawFunction();

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zRot = 0.0f;
GLfloat xTrans = 0.0f;
GLfloat zTrans = 0.0f;

GLuint windowWidth = 800;
GLuint windowHeight = 800;

//Light1 parameters 
GLfloat LightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 100.0f, 100.0f, 100.0f, 1.0f };

//02 - declare an Image object and a GLuint that will be our texture handler
sf::Image img_data[2];
GLuint texture_handle[2];


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
			yRot += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			yRot -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			xRot += .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			xRot -= .1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			zTrans += .2f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			zTrans -= .2f;
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
			if (Event.type == sf::Event::Resized) {
				glViewport(0, 0, Event.size.width, Event.size.height);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(45.f, Event.size.width / Event.size.height, 1.f, 500.f);
				glMatrixMode(GL_MODELVIEW);
			}
		}

		App.setActive();

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

	//Lighting
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);		// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);	// Position The Light
	glEnable(GL_LIGHT1);								// Enable Light One

	// Setup a perspective projection
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.f, windowWidth / windowHeight, 1.f, 5000.f);
	glMatrixMode(GL_MODELVIEW);

	/////// 03 - Init texture settings
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping

	//LOAD TEXTURE FROM FILE
	img_data[0].loadFromFile("images/box.bmp");	
	img_data[1].loadFromFile("images/logo.bmp");
	//Generate OpenGL texture object
	glGenTextures(2, &texture_handle[0]);
	glGenTextures(2, &texture_handle[1]);
	//Binds texture (this texture will be mapped to polygons)
	//glBindTexture(GL_TEXTURE_2D, texture_handle[0]);
	// Upload data to GPU
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,img_data[0].getSize().x, img_data[0].getSize().y, 0,GL_RGBA, GL_UNSIGNED_BYTE, img_data[0].getPixelsPtr());
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,img_data[1].getSize().x, img_data[1].getSize().y, 0,GL_RGBA, GL_UNSIGNED_BYTE, img_data[1].getPixelsPtr());


	////Generate OpenGL texture object
	
	//Binds texture (this texture will be mapped to polygons)
	//glBindTexture(GL_TEXTURE_2D, texture_handle[1]);
	// Upload data to GPU
	


	// some texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		///*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/

	///////////////////////////



}


void myDrawFunction() {

	// Clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, -600.f);

	glTranslatef(0.f, 0.f, zTrans);

	glRotatef(yRot, 0.f, 1.f, 0.f);
	glRotatef(xRot, 1.f, 0.f, 0.f);


	// Draws a cube
	glBegin(GL_QUADS);

	// Front Face
	glGenTextures(2, &texture_handle[0]);
	glBindTexture(GL_TEXTURE_2D, texture_handle[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_data[0].getSize().x, img_data[0].getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data[0].getPixelsPtr());
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	// Back Face
	glBindTexture(GL_TEXTURE_2D, texture_handle[0]);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	// Top Face
	glBindTexture(GL_TEXTURE_2D, texture_handle[0]);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	// Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture_handle[1]);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	// Right face
	glBindTexture(GL_TEXTURE_2D, texture_handle[1]);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100.0f, -100.0f, -100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(100.0f, 100.0f, 100.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100.0f, -100.0f, 100.0f);
	// Left Face
	glBindTexture(GL_TEXTURE_2D, texture_handle[1]);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, -100.0f, -100.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-100.0f, -100.0f, 100.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 100.0f, -100.0f);
	glEnd();
}