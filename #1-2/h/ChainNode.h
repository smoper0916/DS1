#pragma once
#include "Student.h"
class ChainNode
{
	friend class Chain;
public:
	ChainNode(Student data) : next(NULL){
		this->data = data;
	}
	ChainNode(Student data, ChainNode* next){
		this->data = data;
		this->next = next;
	}

	Student getData(){ return data; }
	void setData(Student data){ this->data = data; }


	ChainNode* getNext(){ return next; }
	void setNext(ChainNode* next){ this->next = next; }
private:
	Student data;
	ChainNode* next;
};