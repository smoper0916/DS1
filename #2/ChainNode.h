#pragma once
#include "Term.h"
class ChainNode
{
	friend class Chain;
	friend class Polynomial;
public:
	ChainNode() :next(NULL), data(){}
	ChainNode(Term data) : next(NULL){
		this->data = data;
	}
	ChainNode(Term data, ChainNode* next){
		this->data = data;
		this->next = next;
	}

	Term getData(){ return data; }
	void setData(Term data){ this->data = data; }


	ChainNode* getNext(){ return next; }
	void setNext(ChainNode* next){ this->next = next; }
private:
	Term data;
	ChainNode* next;
};