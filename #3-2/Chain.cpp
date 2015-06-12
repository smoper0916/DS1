#include "Chain.h"

void Chain::insertNode(ChainNode* front, ChainNode* curr)
{
	if (head->right == head){
		front->right = curr;
		front->left = curr;
		curr->left = front;
		curr->right = front;
	}
	else if (front->right == head){
		head->left = curr;
		curr->right = head;
		curr->left = front;
		front->right = curr;
	}
	else{
		curr->right = front->right;
		front->right->left = curr;
		front->right = curr;
		curr->left = front;
	}
}

bool Chain::deleteNode(ChainNode* curr)
{
	if (head->right == head)
		return false;
	else{
		ChainNode* target = head->right;
		target = target->right;
		
		while (target->right == head){
			if (target == curr){
				target->left = target->right;
				target->right->left = target->right;
				target->left->right = target->right;
				delete curr;
				return true;
			}
			target = target->right;
		}
		return false;
	}
}
