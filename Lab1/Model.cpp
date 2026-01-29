#include "Model.h"

Model::Model()
{

}

Model::~Model()
{

}

vec3 Model::modelToWorldPoint(vec3 point){

	return transformVector(point);
}

vec3 Model::transformVector(vec3 v) {

}

vec3 Model::getBasisVector() {
	vec3 output;
	return output;
}


void Model::readModelFile(string name)
{
	verts = parser.readObjectFile(name);
}