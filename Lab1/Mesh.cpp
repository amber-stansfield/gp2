#include "Mesh.h"
#include <iostream>

std::vector<glm::vec3> positions;

std::vector<glm::vec2> texCoords;

#pragma region oldMeshMethod
//Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
//{
//
//
//	positions.reserve(numVertices); // reserve the all the space needed to hold our data
//
//	texCoords.reserve(numVertices);
//
//
//	glGenVertexArrays(1, &VAO); //generate a vertex array and store it in the VAO
//	glBindVertexArray(VAO); //bind the VAO (any operation that works on a VAO will work on our bound VAO - binding)
//
//	glGenBuffers(NUM_BUFFERS, VBO); //generate our buffers based of our array of data/buffers - GLuint vertexArrayBuffers[NUM_BUFFERS];
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
//	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[TEXCOORD_VB]);
//
//	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
//
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
//
//	glBindVertexArray(0); // unbind our VAO
//}



#pragma endregion

Mesh::Mesh() { drawCount = NULL; }

void Mesh::loadModel(const std::string& filename)
{
	IndexedModel model = OBJModel(filename).ToIndexedModel();
	
	initModel(model);
}

void Mesh::init(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices)
{
	IndexedModel model;
	for (unsigned int i = 0; i < numVertices; i++) {

		model.positions.push_back(*vertices[i].GetPos()); //store our array of vertex positon into a list vec3 positions
		model.texCoords.push_back(*vertices[i].GetTexCoord());
		model.normals.push_back(*vertices[i].GetNormal());

	}

	for (unsigned int i = 0; i < numIndices; i++) 
	{
		model.indices.push_back(indices[i]);
	}
	initModel(model);


}

void Mesh::initModel(const IndexedModel& model)
{
	drawCount = model.indices.size();

	glGenVertexArrays(1, &VAO); //generate a vertex array and store it in the VAO
	glBindVertexArray(VAO); //bind the VAO (any operation that works on a VAO will work on our bound VAO - binding)

	glGenBuffers(NUM_BUFFERS, VBO); //generate our buffers based of our array of data/buffers - GLuint vertexArrayBuffers[NUM_BUFFERS];

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU (determined by type)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[TEXCOORD_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[INDEX_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU



	glBindVertexArray(0); // unbind our VAO
};

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO); // delete arrays
}

void Mesh::draw()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT,0);
	glBindVertexArray(0);
}

