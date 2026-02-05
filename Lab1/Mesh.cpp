#include "Mesh.h"


Mesh::Mesh() {};

Mesh::Mesh(Vertex* verts,unsigned int vertNum)
{
	drawCount = vertNum;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(NUM_BUFFERS, VAB);
	glBindBuffer(GL_ARRAY_BUFFER, VAB[POSITION_VERTEXBUFFER]);
	glBufferData(GL_ARRAY_BUFFER, vertNum * sizeof(verts[0]), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
}

void Mesh::Draw()
{


	Vertex verts[3]{
		Vertex(vec3(-0.5, -0.5, 0)),
		Vertex(vec3(0, 0.5, 0)),
		Vertex(vec3(0.5, -0.5, 0))
	};

	glBindVertexArray(VAO);


	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);




}
