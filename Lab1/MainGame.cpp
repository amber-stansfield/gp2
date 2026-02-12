#include "MainGame.h"
#include <iostream>
#include <string>


Vertex vertices[] = { /*Vertex(glm::vec3(0, 0, 0), glm::vec2(1,0)),
						Vertex(glm::vec3(0, 0, 1), glm::vec2(0,1)),
						Vertex(glm::vec3(0, 1, 1), glm::vec2(0.5,0)),*/

						//Vertex(glm::vec3(0, 1, 1), glm::vec2(0,1)),
						//Vertex(glm::vec3(0, 1, 0), glm::vec2(1,1)),
						//Vertex(glm::vec3(0, 0, 0), glm::vec2(0,0)),

						
						// front face
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, 0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(0,0)),

						Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1,1)),

						// top face
						Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(0,0)),


						Vertex(glm::vec3(0.5, -0.5, 0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),

						// bottom face

						Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5, 0.5, -0.5), glm::vec2(0,1)),


						Vertex(glm::vec3(0.5, 0.5, 0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(0,0)),

						// left side face
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5, 0.5, -0.5), glm::vec2(0,1)),


						Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1,1)),

						// right side face
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5, 0.5, 0.5), glm::vec2(0,0)),

						Vertex(glm::vec3(0.5, 0.5, 0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5, -0.5, 0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),

						// back face
						Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(0.5, 0.5, 0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(0,1)),

						Vertex(glm::vec3(0.5, 0.5, 0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(0.5, -0.5, 0.5), glm::vec2(1,0)),
						


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
	SDL_SetRelativeMouseMode(SDL_TRUE);
	mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0])); //size calcuated by number of bytes of an array / no bytes of one element

	shader = new Shader("..\\res\\shader"); //new shader
	texture = new Texture("..\\res\\bricks.jpg");


	cameraSens = shader->_camera->camSens;

}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		auto begin = _clock.now();
		
		drawGame();
		processInput();
		auto end = _clock.now();
		frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		cout << frameTime;
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;


	while(SDL_PollEvent(&evnt) && shader->_camera != NULL) //get and process events
	{
		switch (evnt.type)
		{
		case SDL_MOUSEMOTION:
			shader->_camera->RotateY(evnt.motion.xrel * (frameTime / 1000.0f) * cameraSens);
			shader->_camera->Pitch(-evnt.motion.yrel * (frameTime / 1000.0f) * cameraSens);

	
		}

		
	}
	
}


void MainGame::drawGame()
{
	_gameDisplay.clearDisplay();



	//Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
	//Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
	//Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };

	transform.SetPos(glm::vec3(0, 0, 1));
	transform.SetRot(glm::vec3(0.5, counter / 4, 180));
	
	
	//transform.SetPos(glm::vec3(0, -0.5, 1));
	//transform.SetScale(glm::vec3(1,1,1));

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