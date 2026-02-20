#include "MainGame.h"
#include <iostream>
#include <string>

unsigned int indices[] = { 0,1,2 };


MainGame::MainGame()
{
	_gameState = GameState::PLAY;

	Display* _gameDisplay = new Display(); //new display

	//Camera _camera;

	
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

	/*skyBoxTexture = new Texture;*/
	SDL_SetRelativeMouseMode(SDL_TRUE);

	_gameDisplay.initDisplay(); 

	//scene1 = Scene();

	skyBox = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\cube.obj"),
		ResourceManager::LoadTexture("..\\res\\sky.png"));

	skyBox->getTransform()->SetScale(glm::vec3(-100, -70, -100));
	//skyBox->getTransform()->SetRot(glm::vec3(0, 0, 0));

	floor = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\plane.obj"),
		ResourceManager::LoadTexture("..\\res\\bricks.jpg"));
	
	floor->getTransform()->SetPos(glm::vec3(0, 2, 0));
	floor->getTransform()->SetScale(glm::vec3(20, 1, 20));
	floor->getTransform()->SetRot(glm::vec3(glm::radians(180.0f), 0, 0));


	screwRiver = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\screwer.obj"),
		ResourceManager::LoadTexture("..\\res\\screwer.png"));

	wibbleCube = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\cube.obj"),
		ResourceManager::LoadTexture("..\\res\\Water.jpg"));

	wibbleCube->getTransform()->SetPos(glm::vec3(1, 1, -2));

	duglet = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\duglet.obj"),
		ResourceManager::LoadTexture("..\\res\\diglit.png"));

	duglet->getTransform()->SetPos(glm::vec3(0, 2.2f, 0));

	duglet->getTransform()->SetRot(glm::vec3(glm::radians(180.0f), 0, 0));


	//ScrewRiver->getMesh()->loadModel("..\\res\\screwer.obj");

	//ScrewRiver->getTexture()->init("..\\res\\screwer.png");

	//cubeTexture->init("..\\res\\screwer.png");

	//skyBox->loadModel("..\\res\\screwer.obj");

	//skyBoxTexture->init("..\\res\\sky.png");

	shader.init("..\\res\\shader"); //new shader

	_camera = Camera(glm::vec3(0, 0, -5), 5, 1.777778f, 0.1f, 10000);




	//redCube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	//redCubeTexture = new Texture("..\\res\\redpikmin.png");

	//blueCube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	//blueCubeTexture = new Texture("..\\res\\bluepikmin.png");

	//houseCube = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	//houseCubeTexture = new Texture("..\\res\\house.png");


	//floor = new Mesh(floorVertices, sizeof(floorVertices) / sizeof(floorVertices[0]));
	//floorTexture = new Texture("..\\res\\Bricks.jpg");

	//skyBox = new Mesh(cubeVertices, sizeof(cubeVertices) / sizeof(cubeVertices[0]));
	//skyBoxTexture = new Texture("..\\res\\sky.png");

	cameraSens = _camera.camSens;
	moveSpeed = _camera.moveSpeed;

}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{

		auto begin = _clock.now();
		
		drawGame();
		PhysicsUpdate();
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
		_camera.MoveForward((frameTime * 0.001f) * moveSpeed);
	}
	else if (keystate[SDL_SCANCODE_S])
	{

		_camera.MoveForward((frameTime * 0.001f) * -moveSpeed);
	}
	if (keystate[SDL_SCANCODE_D])
	{
		_camera.MoveRight((frameTime * 0.001f) * moveSpeed);
	}
	else if (keystate[SDL_SCANCODE_A])
	{

		_camera.MoveRight((frameTime * 0.001f) * -moveSpeed);
	}

	//Sleep(16.8f);
	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
		case SDL_MOUSEMOTION:
			_camera.RotateY(evnt.motion.xrel * (frameTime * 0.001f) * cameraSens);
			_camera.Pitch(-evnt.motion.yrel * (frameTime * 0.001f) * cameraSens);
			break;
		}
	}
	
}

void MainGame::PhysicsUpdate()
{

	screwRiver->getTransform()->SetPos(glm::vec3(-1, 0.5, -2));
	screwRiver->getTransform()->SetRot(glm::vec3(glm::radians(180.0f), glm::radians(180.0f) * sin(counter), glm::radians(90.0f) * sin(counter)));
	screwRiver->getTransform()->SetScale(glm::vec3(0.05f, 0.05f, 0.05f));


	floor->getTransform()->SetRot(glm::vec3(glm::radians(180.0f), 0, 0));
	
}

void MainGame::drawGame()
{

	_gameDisplay.clearDisplay(0.13f, 0.6f, 0.71f, 0.0f);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	shader.Bind();


	//glUniform1f(glGetUniformLocation(shader.program, "UVScale"), 1.0f);

	//glUniform1f(glGetUniformLocation(shader.program, "wibble"), 0.0f);

	glUniform1f(glGetUniformLocation(shader.program, "counter"), counter);

	


	for (auto& obj : scene1.objects) {

		if (obj->getID() == floor->getID()) {
			glUniform1f(glGetUniformLocation(shader.program, "UVScale"), 10.0f);

		}
		else {

			glUniform1f(glGetUniformLocation(shader.program, "UVScale"), 1.0f);
		}
		if (obj->getID() == wibbleCube->getID()) {
			glUniform1f(glGetUniformLocation(shader.program, "wibble"), 1);
		}
		else {

			glUniform1f(glGetUniformLocation(shader.program, "wibble"), 0.0f);
		}
		shader.Update(*obj->getTransform(), _camera);
		obj->getTexture()->Bind(0);
		obj->getMesh()->draw();
	}



	////house

	//glCullFace(GL_FRONT);
	//GLint scaleLoc3 = glGetUniformLocation(shader->program, "UVScale");
	//glUniform1f(scaleLoc3, 0.07f);

	//houseCubeTransform.SetScale(glm::vec3(7, 4, 6));
	//houseCubeTransform.SetRot(glm::vec3(0, glm::radians(72.0), 0));
	//houseCubeTransform.SetPos(glm::vec3(-11, 0.3, 7));
	//shader->Update(houseCubeTransform, _camera);
	//houseCubeTexture->Bind(0);
	//houseCube->Draw();



	////cube1
	//GLint scaleLoc4 = glGetUniformLocation(shader->program, "UVScale");
	//glUniform1f(scaleLoc4, 1.0f);


	//GLint loc3 = glGetUniformLocation(shader->program, "wibble");
	//glUniform1f(loc3, 1.0f);
	//
	//cubeTransform.SetPos(glm::vec3(0, 0, 1));
	//cubeTransform.SetRot(glm::vec3(0.5, counter / 4, 180));
	////transform.SetScale(glm::vec3(1,1,1));


	//shader->Bind();
	//shader->Update(cubeTransform, _camera);
	//cubeTexture->Bind(0);
	//cube->Draw();

	////cube2
	//redCubeTransform.SetPos(glm::vec3(1, 0, 1));
	//redCubeTransform.SetRot(glm::vec3(0.5, 180, counter / 4));

	//shader->Bind();
	//shader->Update(redCubeTransform, _camera);
	//redCubeTexture->Bind(0);
	//redCube->Draw();


	////cube3
	//blueCubeTransform.SetPos(glm::vec3(-1, 0, 1));
	//blueCubeTransform.SetRot(glm::vec3(counter / 4, 0.5, 180));

	//shader->Bind();
	//shader->Update(blueCubeTransform, _camera);
	//blueCubeTexture->Bind(0);
	//blueCube->Draw();

	//glCullFace(GL_BACK);
	counter = counter + 1.0f * (frameTime * 0.001);




	_gameDisplay.swapBuffer();
}