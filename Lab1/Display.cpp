#include "Display.h"


Display::Display()
{
	_window = nullptr; //initialise to generate null access violation for debugging. 
	_screenWidth = 900;
	_screenHeight = 768; 
}

Display::~Display()
{
	SDL_GL_DeleteContext(_context);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void clearDisplay()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::returnError(std::string errorString)
{
	std::string plob;
	std::cout << errorString;
	std::cout << "press any key to quit...";
	std::cin >> plob;
	std::cout << plob;
	SDL_Quit();
}

void Display::swapBuffer()
{
	SDL_GL_SwapWindow(_window);
}

void Display::initDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	GLenum error = glewInit();
	if (_window == nullptr) { returnError("gloob"); }
	if (glContext == nullptr) { returnError("gloober"); }
	if (error != GLEW_OK) { returnError("glipper"); }
	glClearColor(0.2f, 0.2f, 0.2f, 0.2f);
}