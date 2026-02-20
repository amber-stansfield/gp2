#include <vector>
#include "Object.h"
#include "Scene.h"


int Scene::ID = -1;

Object& Scene::CreateObject(Mesh* mesh, Texture* texture)
{
	objects.push_back(std::make_unique<Object>());
	Object& obj = *objects.back();
	int id = ID++;
	obj.setID(id);
	obj.setMesh(mesh);
	obj.setTexture(texture);
	return obj;
}

