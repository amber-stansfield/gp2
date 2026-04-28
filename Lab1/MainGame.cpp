#include "MainGame.h"
#include <iostream>
#include <string>




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


	_gameDisplay.initDisplay(); 

	SDL_SetRelativeMouseMode(SDL_TRUE);

	light1 = Light({ 0, 10, 5 }, { 1, 1, 1 });
	//light1.shadow.init(4096, 4096);
	cout << "res";
	cout << _gameDisplay.getScreenWidth();
	cout << _gameDisplay.getScreenHeight();
	cout << "\n";
	light1.shadow.init(_gameDisplay.getScreenWidth(), _gameDisplay.getScreenWidth());

	shadowShader.init("..\\res\\shadow");
	//scene1 = Scene();

	instanceModels();


	shader.init("..\\res\\shader"); //new shader



	_camera = Camera(glm::vec3(0, 0, -5), 5, 1.777778f, 0.1f, 10000);

	cameraSens = _camera.camSens;
	moveSpeed = _camera.moveSpeed;

}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{

		auto begin = _clock.now();

		PhysicsUpdate();
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
			_camera.RotateY(evnt.motion.xrel * cameraSens);
			_camera.Pitch(-evnt.motion.yrel * cameraSens);
			break;
		}
	}
	
}

void MainGame::PhysicsUpdate()
{

	screwRiver->getTransform()->SetPos(glm::vec3(-1, 0.5, -2));
	screwRiver->getTransform()->SetRot(glm::vec3(glm::radians(180.0f), glm::radians(180.0f) * sin(counter), glm::radians(90.0f) * sin(counter)));
	screwRiver->getTransform()->SetScale(glm::vec3(0.05f, 0.05f, 0.05f));

	//lerp to follow camera
	Camera::CameraBasis b = _camera.getBasis();
	glm::vec3 worldOffset = b.right * gun->getTransform()->getLocalOffset().x +
		b.up * gun->getTransform()->getLocalOffset().y +
		b.forward * gun->getTransform()->getLocalOffset().z;


	glm::vec3 targetPos = _camera.getPos() + worldOffset;

	gun->getTransform()->SetPos(glm::vec3(*gun->getTransform()->GetPos() + (targetPos - *gun->getTransform()->GetPos()) * 0.85f));
	//gun->getTransform()->SetPos(targetPos);

	glm::quat gunRot = gun->pointFromCam(_camera);

	gun->getTransform()->SetQRot(gunRot);

	light->getTransform()->SetPos(glm::vec3(6* cos(counter), -abs(4 * sin(counter)), 5 * sin(counter)));

	light1.position = *light->getTransform()->GetPos();



	
}

void MainGame::shadowPass(float nearPlane, float farPlane, glm::vec3 lightPos)
{
	glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), 1.0f, nearPlane, farPlane);

	std::vector<glm::mat4> shadowTransforms;
	shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(1, 0, 0), glm::vec3(0, -1, 0)));
	shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(-1, 0, 0), glm::vec3(0, -1, 0)));
	shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0, 1, 0), glm::vec3(0, 0, 1)));
	shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0, -1, 0), glm::vec3(0, 0, -1)));
	shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0, 0, 1), glm::vec3(0, -1, 0)));
	shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0, 0, -1), glm::vec3(0, -1, 0)));

	glEnable(GL_DEPTH_TEST);

	light1.shadow.bindForWriting();
	for (int i = 0; i < 6; i++)
	{

		glFramebufferTexture2D(
			GL_FRAMEBUFFER,
			GL_DEPTH_ATTACHMENT,
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			light1.shadow.depthCube,
			0
		);

		glClear(GL_DEPTH_BUFFER_BIT);

		shadowShader.Bind();
		shadowShader.setMat4("shadowMatrices[0]", shadowTransforms[i]);
		shadowShader.setVec3("lightPos", lightPos);
		shadowShader.setFloat("farPlane", farPlane);

		for (auto& obj : scene1.objects)
		{
			shadowShader.setMat4("model", obj->getTransform()->GetModel());
			obj->getMesh()->draw();
		}
	}


	light1.shadow.unbind();
	glViewport(0, 0, _gameDisplay.getScreenWidth(), _gameDisplay.getScreenHeight());
}

void MainGame::setShaderParams(Object obj)
{
	if (obj.getID() == floor->getID()) {
		glUniform1f(glGetUniformLocation(shader.program, "UVScale"), 10.0f);

	}
	else {

		glUniform1f(glGetUniformLocation(shader.program, "UVScale"), 1.0f);
	}
	if (obj.getID() == wibbleCube->getID()) {
		glUniform1f(glGetUniformLocation(shader.program, "wibble"), 1);
	}
	else {

		glUniform1f(glGetUniformLocation(shader.program, "wibble"), 0.0f);
	}
	if (obj.getID() == light->getID())
	{
		glUniform1f(glGetUniformLocation(shader.program, "texMult"), 1000.0f);
	}
	else {

		glUniform1f(glGetUniformLocation(shader.program, "texMult"), 1.0f);
	}
}

void MainGame::drawGame()
{
	Sleep(5.0f);
	_gameDisplay.clearDisplay(0.13f, 0.6f, 0.71f, 0.0f);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);

	glm::vec3 lightPos = light1.position;
	float nearPlane = 0.1f;
	float farPlane  = 5000.0f;

	shadowPass(nearPlane, farPlane, lightPos);


	shader.Bind();

	glUniform3f(glGetUniformLocation(shader.program, "lightPos0"), light1.position.x, light1.position.y, light1.position.z);
	glUniform3f(glGetUniformLocation(shader.program, "viewPos0"), _camera.getPos().x, _camera.getPos().y, _camera.getPos().z);
	glUniform1f(glGetUniformLocation(shader.program, "farPlane"), farPlane);




	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_CUBE_MAP, light1.shadow.depthCube);
	shader.setInt("shadowCube", 1);
	shader.setFloat("farPlane", farPlane);




	glUniform1f(glGetUniformLocation(shader.program, "counter"), counter);

	glUniform3f(glGetUniformLocation(shader.program, "lightColour0"), 0.7f, 0.3f, 0.4f);



	for (auto& obj : scene1.objects) {

		setShaderParams(*obj);

		shader.setMat4("model", obj->getTransform()->GetModel());
		//glUniformMatrix4fv(glGetUniformLocation(shader.program, "model"),1,GL_FALSE, glm::value_ptr(obj->getTransform()->GetModel()));
		shader.Update(*obj->getTransform(), _camera);
		obj->getTexture()->Bind(0);
		obj->getMesh()->draw();
	}

	counter = counter + 1.0f * (frameTime * 0.001);


	_gameDisplay.swapBuffer();
}


void MainGame::instanceModels()
{
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

	gun = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\gun.obj"),
		ResourceManager::LoadTexture("..\\res\\Water.jpg"));
	gun->getTransform()->SetScale(glm::vec3(0.1f, 0.1f, 0.1f));
	gun->getTransform()->SetRot(glm::vec3(0, glm::radians(-90.0f), glm::radians(180.0f)));
	gun->getTransform()->setLocalOffset(glm::vec3(-0.6f, 0.6f, 0.6f));

	duglet = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\duglet.obj"),
		ResourceManager::LoadTexture("..\\res\\diglit.png"));
	duglet->getTransform()->SetPos(glm::vec3(0, 2.2f, 0));
	duglet->getTransform()->SetRot(glm::vec3(glm::radians(180.0f), 0, 0));


	light = &scene1.CreateObject(ResourceManager::LoadMesh("..\\res\\cube.obj"),
		ResourceManager::LoadTexture("..\\res\\Water.jpg"));
}