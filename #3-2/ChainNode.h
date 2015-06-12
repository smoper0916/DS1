#pragma once

#include "Student.h"

class ChainNode
{
	friend class Chain;
public:
	ChainNode();
	~ChainNode();
private:
	Student data;
	ChainNode *right, *left;
};

