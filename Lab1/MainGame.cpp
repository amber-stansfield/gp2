#include "MainGame.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
#include <iomanip>
MainGame::MainGame()
{
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();
	gameLoop();
}

void MainGame::initSystems()
{
	_gameDisplay.initDisplay();
	initaliseModels();

}

void MainGame::initaliseModels()
{
	_model.readModelFile("models\\cube.csv");
	//cout << ".../gp2/Lab1/models/cube.csv";
}



void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();

	}
}

void MainGame::processInput()
{
	SDL_Event blope;
	while (SDL_PollEvent(&blope)) {
		switch(blope.type)
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
	}
}

void MainGame::drawGame()
{
	glClearDepth(1.0); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear colour and depth buffer - set colour to colour defined in glClearColor

	
	// old code for testing only 



	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.1f, 0.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-0.1f, 0.0f, 1.0f);
	glEnd();


	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0, -0.5f);
	glVertex2f(0, 0.25f);
	glVertex2f(0.5f, 0.5f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.5f, -0.25f);
	glVertex2f(0, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0, -0.5f);
	glVertex2f(0, 0.25f);
	glVertex2f(-0.5f, -0.25f);
	glEnd();

	

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0, 0.25f);
	glVertex2f(-0.5f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(0, 0.25f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0, 0.75f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();


	srand(std::time({}));



	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < _model.verts.size(); i++)
	{
			//float intermediate = _model.verts[i]+ _model.TransformPos[2];
			//_model.verts[i] = std::clamp(_model.verts[i], -1, 1);
		
	}
	for (int i = 0; i < _model.verts.size(); i+=3)
	{
		glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		vector<float> modelpoint = {0,0,0};
		modelpoint[0] = _model.verts[i];
		modelpoint[1] = _model.verts[i+1];
		modelpoint[2] = _model.verts[i+2];
		vector<float> worldpoint = _model.modelToWorldPoint(modelpoint);
		glVertex3d(modelpoint[0],modelpoint[1],modelpoint[2]);
	}
	glEnd();

	_gameDisplay.swapBuffer();
}