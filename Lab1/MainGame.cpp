#include "MainGame.h"
#include <iostream>
#include <string>


Vertex cubeVertices[] = {

						//  front face

						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1,1)),

						Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,0)),

						// back face
						Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(1,1)),


						Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(0,0)),

						// top face
						Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,0)),

						Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0,1)),

						// bottom face
						Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),

						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),

						// left face
						Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(1,1)),

						Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),

						// right face
						Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(1,0)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(0,0)),
						Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,1)),

						Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(0,1)),
						Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,1)),
						Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(0,0))
};

Vertex skyBoxVertices[] = {

	//  front face

	Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1,1)),


	Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0,1)),
	Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1,1)),

	// back face
	Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(1,1)),
	Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(0,0)),


	Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(0,1)),
	Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(1,1)),

	// top face
	Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1,1)),
	Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0,1)),

	Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0,1)),
	Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,0)),

	// bottom face
	Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),
	Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),

	Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0,1)),
	Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1,1)),

	// left face

	Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(1,1)),


	Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(1,1)),
	Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(0,1)),

	// right face

	Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,1)),
	Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(0,0)),

	Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(0,1)),
	Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(1,1))
};
Vertex floorVertices[] = {

	// top face
	Vertex(glm::vec3(-0.5,  0.0, -0.5), glm::vec2(0,1)),
	Vertex(glm::vec3(0.5,  0.0, -0.5), glm::vec2(1,1)),
	Vertex(glm::vec3(0.5,  0.0,  0.5), glm::vec2(1,0)),

	Vertex(glm::vec3(0.5,  0.0,  0.5), glm::vec2(1,0)),
	Vertex(glm::vec3(-0.5,  0.0,  0.5), glm::vec2(0,0)),
	Vertex(glm::vec3(-0.5,  0.0, -0.5), glm::vec2(0,1)),
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

	_camera = new Camera(glm::vec3(0, 0, -5), 5, 1.777778f, 0.1f, 10000);

	SDL_SetRelativeMouseMode(SDL_TRUE);

	shader = new Shader("..\\res\\shader"); //new shader

	cube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0])); //size calcuated by number of bytes of an array / no bytes of one element
	cubeTexture = new Texture("..\\res\\pikman.jpg");

	redCube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	redCubeTexture = new Texture("..\\res\\redpikmin.png");

	blueCube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	blueCubeTexture = new Texture("..\\res\\bluepikmin.png");

	houseCube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	houseCubeTexture = new Texture("..\\res\\house.png");


	floor = new Mesh(floorVertices, sizeof(floorVertices) / sizeof(floorVertices[0]));
	floorTexture = new Texture("..\\res\\Bricks.jpg");

	skyBox = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	skyBoxTexture = new Texture("..\\res\\sky.png");

	cameraSens = _camera->camSens;
	moveSpeed = _camera->moveSpeed;

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
		cout << "frames: " << frameTime * 0.001f << "\n";

	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_W])
	{
		_camera->MoveForward((frameTime * 0.001f) * moveSpeed);
	}
	else if (keystate[SDL_SCANCODE_S])
	{

		_camera->MoveForward((frameTime * 0.001f) * -moveSpeed);
	}
	if (keystate[SDL_SCANCODE_D])
	{
		_camera->MoveRight((frameTime * 0.001f) * moveSpeed);
	}
	else if (keystate[SDL_SCANCODE_A])
	{

		_camera->MoveRight((frameTime * 0.001f) * -moveSpeed);
	}

	//Sleep(16.8f);
	while(SDL_PollEvent(&evnt) && _camera != NULL) //get and process events
	{
		switch (evnt.type)
		{
		case SDL_MOUSEMOTION:
			_camera->RotateY(evnt.motion.xrel * (frameTime * 0.001f) * cameraSens);
			_camera->Pitch(-evnt.motion.yrel * (frameTime * 0.001f) * cameraSens);
			break;
		}
	}
	
}


void MainGame::drawGame()
{
	_gameDisplay.clearDisplay(0.13f, 0.6f, 0.71f, 0.0f);


	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	//sky
	GLint loc1 = glGetUniformLocation(shader->program, "wibble");
	glUniform1f(loc1, 0.0f);

	GLint scaleLoc1 = glGetUniformLocation(shader->program, "UVScale");
	glUniform1f(scaleLoc1, 0.05f);

	skyBoxTransform.SetScale(glm::vec3(-300, -300, -300));
	skyBoxTransform.SetRot(glm::vec3(glm::radians(180.0), 0, 0));
	skyBoxTransform.SetPos(glm::vec3(1, -85, 1));
	shader->Update(skyBoxTransform, *_camera);
	skyBoxTexture->Bind(0);
	skyBox->Draw();
	


	//floor

	GLint scaleLoc2 = glGetUniformLocation(shader->program, "UVScale");
	glUniform1f(scaleLoc2, 3.5f);

	floorTransform.SetRot(glm::vec3(-glm::radians(90.0), 0, 0));
	floorTransform.SetPos(glm::vec3(0, 3, 3));

	floorTransform.SetScale(glm::vec3(100, 100, 1));


	shader->Update(floorTransform, *_camera);
	floorTexture->Bind(0);
	floor->Draw();

	//house

	glCullFace(GL_FRONT);
	GLint scaleLoc3 = glGetUniformLocation(shader->program, "UVScale");
	glUniform1f(scaleLoc3, 0.07f);

	houseCubeTransform.SetScale(glm::vec3(7, 4, 6));
	houseCubeTransform.SetRot(glm::vec3(0, glm::radians(72.0), 0));
	houseCubeTransform.SetPos(glm::vec3(-11, 0.3, 7));
	shader->Update(houseCubeTransform, *_camera);
	houseCubeTexture->Bind(0);
	houseCube->Draw();



	//cube1
	GLint scaleLoc4 = glGetUniformLocation(shader->program, "UVScale");
	glUniform1f(scaleLoc4, 1.0f);

	GLint loc2 = glGetUniformLocation(shader->program, "counter");
	glUniform1f(loc2, counter);

	GLint loc3 = glGetUniformLocation(shader->program, "wibble");
	glUniform1f(loc3, 1.0f);
	
	cubeTransform.SetPos(glm::vec3(0, 0, 1));
	cubeTransform.SetRot(glm::vec3(0.5, counter / 4, 180));
	//transform.SetScale(glm::vec3(1,1,1));


	shader->Bind();
	shader->Update(cubeTransform, *_camera);
	cubeTexture->Bind(0);
	cube->Draw();

	//cube2
	redCubeTransform.SetPos(glm::vec3(1, 0, 1));
	redCubeTransform.SetRot(glm::vec3(0.5, 180, counter / 4));

	shader->Bind();
	shader->Update(redCubeTransform, *_camera);
	redCubeTexture->Bind(0);
	redCube->Draw();


	//cube3
	blueCubeTransform.SetPos(glm::vec3(-1, 0, 1));
	blueCubeTransform.SetRot(glm::vec3(counter / 4, 0.5, 180));

	shader->Bind();
	shader->Update(blueCubeTransform, *_camera);
	blueCubeTexture->Bind(0);
	blueCube->Draw();

	glCullFace(GL_BACK);
	counter = counter + 1.0f * (frameTime * 0.001);



	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
}