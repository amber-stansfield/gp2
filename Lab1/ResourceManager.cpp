#include "ResourceManager.h"

std::unordered_map<std::string, Mesh*> ResourceManager::meshes;
std::unordered_map<std::string, Texture*> ResourceManager::textures;

Mesh* ResourceManager::LoadMesh(const std::string filename)
{
	if (meshes.count(filename) == 0) {
		meshes[filename] = new Mesh();
		meshes[filename]->loadModel(filename);
	}
	return meshes[filename];
}

Texture* ResourceManager::LoadTexture(const std::string filename)
{
	if (textures.count(filename) == 0) {
		textures[filename] = new Texture();
		textures[filename]->init(filename);
	}
	return textures[filename];
}