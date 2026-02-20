#pragma once
#include <string>
#include <GL\glew.h>

class Texture
{
public:
	Texture();

	~Texture();

	void init(const std::string& filename);

	void Bind(unsigned int unit); // bind upto 32 textures


protected:
private:

	float aniso = 20000.0f;
	GLuint textureHandler;
};
