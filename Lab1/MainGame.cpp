#include "MainGame.h"
#include <iostream>
#include <string>

Vertex vertices[] = { Vertex(glm::vec3(0, 0, 0), glm::vec2(1,0)),
						Vertex(glm::vec3(0, 0, 1), glm::vec2(0,1)),
						Vertex(glm::vec3(0, 1, 1), glm::vec2(0.5,0)),

						Vertex(glm::vec3(0, 1, 1), glm::vec2(0,1)),
						Vertex(glm::vec3(0, 1, 0), glm::vec2(1,1)),
						Vertex(glm::vec3(0, 0, 0), glm::vec2(0,0)),

						Vertex(glm::vec3(0, 0, 0), glm::vec2(0,0)),
						Vertex(glm::vec3(0, 1, 0), glm::vec2(0,0)),
						Vertex(glm::vec3(1, 1, 0), glm::vec2(0,0)),

						Vertex(glm::vec3(0, 0, 0), glm::vec2(0,0)),
						Vertex(glm::vec3(1, 0, 0), glm::vec2(0,0)),
						Vertex(glm::vec3(1, 1, 0), glm::vec2(0,0)),

						Vertex(glm::vec3(0, 0, 1),glm::vec2(0,0)),
						Vertex(glm::vec3(0, 1, 0),glm::vec2(0,0)),
						Vertex(glm::vec3(1, 1, 0),glm::vec2(0,0)),

						Vertex(glm::vec3(0, 1, 1), glm::vec2(0,0)),
						Vertex(glm::vec3(1, 1, 0),	glm::vec2(0,0)),
						Vertex(glm::vec3(1, 1, 1),	glm::vec2(0,0))

};

MainGame::MainGame()
{
	_gameState = GameState::PLAY;

	Display* _gameDisplay = new Display(); //new display

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
	

	mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0])); //size calcuated by number of bytes of an array / no bytes of one element

	shader = new Shader("..\\res\\shader"); //new shader
	texture = new Texture("..\\res\\Water.jpg");

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
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
		}
	}
	
}


void MainGame::drawGame()
{
	_gameDisplay.clearDisplay();



	//Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
	//Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
	//Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };



	transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
	transform.SetRot(glm::vec3(0.0, 0.0, counter * 5));
	transform.SetScale(glm::vec3(sinf(counter), sinf(counter), sinf(counter)));

	shader->Bind();
	shader->Update(transform);
	texture->Bind(0);
	mesh->Draw();
	counter = counter + 0.01;

	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
}