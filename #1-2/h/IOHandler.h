#pragma once

#include <fstream>
#include "Student.h"
#include "Chain.h"

using namespace std;

class IOHandler
{
public:
	IOHandler(string fileName) : currCursor(0){	this->fileName = fileName;	}

	void save(Student object);
	void load(Chain& stdList);
	void setFileName(string fileName){this->fileName = fileName;}
	string getFileName(){ return fileName; }
private:
	int currCursor;
	string fileName;
};
