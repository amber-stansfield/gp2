#include "Model.h"

Model::Model()
{
	Transform[0] = 1;
	Transform[1] = 1;
	Transform[2] = 1;

	poly[0][0] = -1;
	poly[0][1] = -1;
	poly[0][2] = 0;

	poly[1][0] = 1;
	poly[1][1] = -1;
	poly[1][2] = 0;

	poly[2][0] = 0;
	poly[2][1] = 1;
	poly[2][2] = 0;
}

Model::~Model()
{

}