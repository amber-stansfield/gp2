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


	Camera* _camera;

	void run();


protected:

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	float counter = 0;

	const Uint8* keystate = 0;

	long long frameTime;

	std::chrono::high_resolution_clock _clock;
	
	float cameraSens;
	float moveSpeed;
	
	Shader* shader;

	Mesh* floor;
	Shader* floorShader;
	Texture* floorTexture;
	Transform floorTransform;

	Mesh* cube;
	Texture* cubeTexture;
	Transform cubeTransform;

	Mesh* redCube;
	Texture* redCubeTexture;
	Transform redCubeTransform;

	Mesh* houseCube;
	Texture* houseCubeTexture;
	Transform houseCubeTransform;

	Mesh* blueCube;
	Texture* blueCubeTexture;
	Transform blueCubeTransform;


	Mesh* skyBox;
	Texture* skyBoxTexture;
	Transform skyBoxTransform;


	Display _gameDisplay;
	GameState _gameState;

	glm::vec3 vec3example;

};

