#pragma once

#include "ChainNode.h"
#include "Student.h"

class ChainIterator
{
	friend class Chain;
public: 
	ChainIterator(ChainNode* startNode = 0) { current = startNode; } 
	ChainIterator(ChainIterator& chain){
		if (chain.getNode())
			current = new ChainNode(*chain.current);
	}
	ChainIterator& operator=(ChainIterator& chain){
		if (current)
			delete current;
		if (chain.getNode())
			current = new ChainNode(*chain.getNode());
		return *this;
	}
//	~ChainIterator(){ if (current) delete current; }
	Student& operator*() const { return current->data; } 
	ChainNode* getNode() const { return current; } 
	ChainIterator& operator++();
	ChainIterator operator++(int);
	bool operator!=(const ChainIterator right) const;
	bool operator==(const ChainIterator right) const;
private: 
	ChainNode* current; 
};