#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class CsvParser
{
public:
	CsvParser() {};

	~CsvParser() {};

	vector<float> readObjectFile(string);

};