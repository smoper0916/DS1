#pragma once

#include "ChainNode.h"
#include <iostream>

class Chain
{
public:
	Chain(){ tail = head = nullptr; }
	ChainNode* begin() { return head; }
	ChainNode* end() { return NULL; }
	ChainNode* getBig(Student s);
	ChainNode* getHead(){ return head; }
	ChainNode* getTail(){ return tail; }
	void setHead(ChainNode* head){ this->head = head; }
	void setTail(ChainNode* tail){ this->tail = tail; }

	void insertData(Student data);
	void insertData(Student frontData, Student data);
	void deleteData(int stdN);
	void printData();
private:
	ChainNode* head;
	ChainNode* tail;
};