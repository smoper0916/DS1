#include "Chain.h"

Chain& Chain::operator=(Chain& c){
	head = new ChainNode();

	head->next = c.head->next;

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