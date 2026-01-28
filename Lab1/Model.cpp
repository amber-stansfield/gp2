#include "Model.h"

Model::Model()
{

}

Model::~Model()
{

}

vector<float> Model::modelToWorldPoint(vector<float> point){
	vector<float> i = getBasisVectorI();
	vector<float> j = getBasisVectorJ();
	vector<float> k = getBasisVectorK();

	return transformVector(i, j, k, point);
}

vector<float> Model::transformVector(vector<float> i, vector<float> j, vector<float> k, vector<float> v) {
	float intermediate1 = v[0] * i[0] * i[1] * i[2];
	float intermediate2 = v[1] * j[0] * j[1] * j[2];
	float intermediate3 = v[2] * k[0] * k[1] * k[2];
	vector<float> output = { 0,0,0 };
	output[0] = intermediate1;
	output[1] = intermediate2;
	output[2] = intermediate3;
	return output;
}

vector<float> Model::getBasisVectorI() {
	vector<float> i = {0,0,0};
	i[0] = cos(yaw);
	i[1] = 0;
	i[2] = sin(yaw);
	return i;
}
vector<float> Model::getBasisVectorJ() {
	vector<float> j = {0,0,0};
	j[0] = 0;
	j[1] = 1;
	j[2] = 0;
	return j;
}
vector<float> Model::getBasisVectorK() {
	vector<float> k = { 0,0,0 };
	k[0] = -sin(yaw);
	k[1] = 0;
	k[2] = cos(yaw);
	return k;
}


void Model::readModelFile(string name)
{
	verts = parser.readObjectFile(name);
}