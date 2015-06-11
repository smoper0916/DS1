#include "Chain.h"

Chain& Chain::operator=(Chain& c){
	ChainNode* currA = begin();
	ChainNode* currB = c.begin();
	while (true){
		if (!currB)
			break;
		currA = new ChainNode(*currB);

		currA = currA->next;
		currB = currB->next;
	}
	return *this;
}

void Chain::insertData(Term data)
{
	if (!tail){
		tail = new ChainNode(data);
		head->next = tail;
	}
	else{
		tail->next = new ChainNode(data);
		tail = tail->next;
	}
}