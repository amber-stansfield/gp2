#pragma once
#include <string>
#include <GL\glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
public:

	Shader();

	void init(const std::string& filename);

	void Bind(); //Set gpu to use our shaders
	void Update(const Transform& transform, const Camera& camera);

	std::string Shader::LoadShader(const std::string& fileName);

	void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

	GLuint Shader::CreateShader(const std::string& text, unsigned int type);


	void setMat4(const std::string& name, const glm::mat4& matrix);

	void Shader::setVec3(const std::string& name, const glm::vec3& vec3);

	void Shader::setFloat(const std::string& name, const float Float);
	

	void Shader::setInt(const std::string& name, const int Int);

	GLuint program; // Track the shader program GLuint shaders[NUM_SHADERS];
	~Shader();


protected:

private:
	static const unsigned int NUM_SHADERS = 2; // number of shaders

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS

	};

	
	GLuint shaders[NUM_SHADERS];//array of shaders
	GLuint uniforms[NUM_UNIFORMS]; //no of uniform variables

};
