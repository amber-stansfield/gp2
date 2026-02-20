#pragma once
#include "Transform.h"
#include "Texture.h"
#include "Mesh.h"
struct Object{

public:

	Object(){};

	Transform* getTransform() { return &transform; }

	Mesh* getMesh() { return this->mesh; }
	
	Texture* getTexture() { return this->texture; }

	int getID() { return this->ID; }


	void setID(int id) { ID = id; }

	void setMesh(Mesh* m) { mesh = m; }
	void setTexture(Texture* t) { texture = t; }



	~Object() {};

private:

	int ID;

	Transform transform;

	Mesh* mesh;

	Texture* texture;

};