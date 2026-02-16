#pragma once
#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>
using namespace std;


class Display
{
public:
	Display();
	~Display();
	void initDisplay();
	void swapBuffer();
	void clearDisplay(float,float,float,float);

	int getScreenHeight() { return screenHeight; }
	int getScreenWidth() { return screenWidth; }

	SDL_Window* sdlWindow; //holds pointer to out windows

private:

	void returnError(std::string errorString);

	SDL_GLContext glContext; //global variable to hold the context
	int screenWidth;
	int screenHeight;
};

