#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "chrono"
#include "iostream"
#include "windows.h"
#include <SDL/SDL_syswm.h>
#include <GL/gl.h>


enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();


protected:

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	float counter = 0;


	long frameTime;

	std::chrono::high_resolution_clock _clock;
	
	float cameraSens;

	Mesh* mesh;
	Shader* shader;
	Texture* texture;
	Transform transform;


	Display _gameDisplay;
	GameState _gameState;
	glm::vec3 vec3example;

};

