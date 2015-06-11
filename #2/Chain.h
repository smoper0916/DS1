#pragma once

#include "ChainNode.h"
#include <iostream>

class Chain
{
public:
	Chain(){ head = new ChainNode(); head->next = tail = NULL; }
	ChainNode* begin() { return head->next; }
	ChainNode* end() { return NULL; }

	ChainNode* getHead(){ return head; }
	ChainNode* getTail(){ return tail; }
	void setHead(ChainNode* head){ this->head = head; }
	void setTail(ChainNode* tail){ this->tail = tail; }

	void insertData(Term data);

	Chain& operator=(Chain&);
private:
	ChainNode* head;
	ChainNode* tail;
	
};