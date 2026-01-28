#pragma once
#include "CsvParser.h"
#include <vector>
//#include <iostream>

class Model
{
public:

	Model();
	~Model();

	vector<float> modelToWorldPoint(vector<float>);

	vector<float> transformVector(vector<float>, vector<float>, vector<float>, vector<float>);

	vector<float> getBasisVectorI();
	vector<float> getBasisVectorJ();
	vector<float> getBasisVectorK();

	float yaw = 45;
	void readModelFile(string);

	float TransformPos[3];

	vector<float> verts;

	CsvParser parser;

};
