#pragma once

#include "ChainNode.h"

class Chain
{
public:
	Chain(){
		head = new ChainNode();
	}
	void insertNode(ChainNode*, ChainNode*);
	bool deleteNode(ChainNode*);
private:
	ChainNode* head;
};

