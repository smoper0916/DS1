#pragma once

#include "ChainNode.h"

class Chain
{
public:
	Chain(){
		head = new ChainNode();
		
	}
	void insertNode(ChainNode*, ChainNode*);
	void deleteNode(ChainNode*);
private:
	ChainNode* head;
};

