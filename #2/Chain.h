#pragma once

#include "ChainNode.h"
#include <iostream>

class Chain
{
public:
	Chain(){ head = new ChainNode(); head->next = tail = NULL; }
	ChainNode* begin() { return head->next; }
	ChainNode* end() { return NULL; }
	ChainNode* getBig(Term s);
	ChainNode* getHead(){ return head; }
	ChainNode* getTail(){ return tail; }
	void setHead(ChainNode* head){ this->head = head; }
	void setTail(ChainNode* tail){ this->tail = tail; }

	void insertData(Term data);
	void insertData(Term frontData, Term data);
	void deleteData(int stdN);
	void printData();
private:
	ChainNode* head;
	ChainNode* tail;
};