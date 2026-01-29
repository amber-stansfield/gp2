#pragma once
#include "CsvParser.h"
#include <vector>
#include <glm/common.hpp>


using namespace glm;
//#include <iostream>

class Model
{
public:

	Model();
	~Model();

	vec3 modelToWorldPoint(vec3);

	vec3 transformVector(vec3 );

	vec3 getBasisVector();

	float yaw = 45;
	void readModelFile(string);

	float TransformPos[3];

	vector<float> verts;

	CsvParser parser;

};
