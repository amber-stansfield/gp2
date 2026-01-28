#include "CsvParser.h"


vector<float>CsvParser::readObjectFile(string name) {
	
	vector<float> output;
	int index = 0;
	ifstream file;
	cout << name;
	file.open(name, ios::in);
	string line;
	string data;

	if (!file.is_open()) {
		cout << " Failed to open" << endl;
	}

	while (getline(file,line)) {
		stringstream ss(line);

		while (getline(ss, line, ',')) {

			output.push_back(stof(line));
		}
		
	}
	//cout << (output.begin());
	auto outputFront = output.begin();
	for (int i = 0; i < output.size(); i++) {
		cout << output[i];
	}
	file.close();
	return output;
	
}