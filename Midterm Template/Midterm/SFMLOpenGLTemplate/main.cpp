#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML\Graphics\Image.hpp>

void init();
void DrawGame();
void DrawUI();
void DrawSquare(float width,float height);
void DrawTriangle();
void Viewports();
void KeyboardHandle();

float xtranslate[];
float ytranslate[];

GLuint windowWidth = 1024;
GLuint windowHeight = 768;

sf::Image img_data;
GLuint texture_handle;


int main()
{
	sf::Window Game(sf::VideoMode(windowWidth, windowHeight, 32), "Midterm Game");

	init();

	sf::Event Event;
	while (Game.isOpen())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		while (Game.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				Game.close();

			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				Game.close();


		}
		Game.setActive();
		KeyboardHandle();
		Viewports();
		Game.display();
	}
}

void init()
{	
	glClearDepth(1.f);
	glClearColor(0.5f, 0.5f, 0.5f, 1.f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f); 	

	/*glEnable(GL_TEXTURE_2D);							
	img_data.loadFromFile("images/box.bmp");
	glGenTextures(1, &texture_handle);	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_data.getSize().x, img_data.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data.getPixelsPtr());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);*/
	

}

void Viewports(){

	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);
	
	DrawGame();
}

void DrawGame(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawSquare(5, 9);
	

}

void DrawUI(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void KeyboardHandle(){
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W));
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S));
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D));

	

}

void DrawSquare(float width,float height){
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(width, height);
	glVertex2f(-width, height);
	glVertex2f(-width,-height);
	glVertex2f(width,-height);
	glEnd();

}

void DrawTriangle(){

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);	
	glEnd();

}