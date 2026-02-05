#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>

using namespace glm;
class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
protected:
private:
	vec3 pos;
};


class Mesh
{
public:
	Mesh();
	Mesh(Vertex* verts, unsigned int vertNum);
	~Mesh();

	void Draw();
private:

	enum
	{
		POSITION_VERTEXBUFFER,
		NUM_BUFFERS
	};

	GLuint VAO;
	GLuint VAB[NUM_BUFFERS]; // create our array of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw
};

