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

	 glm::quat pointFromCam(Camera _camera) {
		Camera::CameraBasis b = _camera.getBasis();

		glm::mat3 basis(b.right, b.up, -b.forward);
		glm::quat gunRot = glm::quat_cast(basis);

		// model-space corrections for the gun mesh
		gunRot *= glm::angleAxis(glm::radians(90.0f), glm::vec3(0, 1, 0));
		gunRot *= glm::angleAxis(glm::radians(180.0f), glm::vec3(0, 0, 1));

		return gunRot;
	}

	~Object() {};

private:

	int ID;

	Transform transform;

	Mesh* mesh;

	Texture* texture;

};