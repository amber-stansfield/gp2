#pragma once
#include "Mesh.h"
#include "Texture.h"
#include "unordered_map"

class ResourceManager {
public:
	static Mesh* LoadMesh(const std::string filename);

	static Texture* LoadTexture(const std::string filename);



private:
	static std::unordered_map<std::string, Mesh*> meshes;
	static std::unordered_map<std::string, Texture*> textures;
};