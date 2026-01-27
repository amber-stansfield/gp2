#pragma once
#include "Model.h"
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include <cmath>

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	Model _model;
	Display _gameDisplay;
	GameState _gameState;

};

