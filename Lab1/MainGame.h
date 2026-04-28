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
#include "Object.h"
#include <SDL/SDL_syswm.h>
#include "scene.h"
#include "ResourceManager.h"
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>
#include "light.cpp"
#include <cmath>


enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();


	Camera _camera;

	void run();



protected:

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void setShaderParams(Object obj);
	void shadowPass(float nearPlane, float farPlane, glm::vec3 lightPos);
	void PhysicsUpdate();
	void instanceModels();

	float counter = 0;

	const Uint8* keystate = 0;

	long long frameTime;

	Scene scene1;

	std::chrono::high_resolution_clock _clock;
	
	float cameraSens;
	float moveSpeed;
	
	Shader shader;

	Shader shadowShader;
	
	Object* screwRiver;

	Object* skyBox;

	Object* floor;

	Object* wibbleCube;

	Object* duglet;

	Object* light;

	Object* gun;

	Light light1;



	Display _gameDisplay;
	GameState _gameState;

	glm::vec3 vec3example;

};

