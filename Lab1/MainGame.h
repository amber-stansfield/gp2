#pragma once
#include "Mesh.h"
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "CsvParser.h"
#include <cmath>

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void initaliseModels();

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	Mesh _mesh;
	Display _gameDisplay;
	GameState _gameState;

};

