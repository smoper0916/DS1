#include "Chain.h"

ChainNode* Chain::getBig(Student s){
	ChainNode* p;
	ChainNode* big = NULL;

	for (p = begin(); p != NULL; p = p->next){
		if (p->getData() < s){
			if (big){
				if (big->getData() < p->getData())
					big = p;
			}
			else
				big = p;
		}
	}

	if (big){
		p = big;
		big = new ChainNode(*p);
	}
	return big;
}
void Chain::insertData(Student data)
{
	if (!head)
		head = tail = new ChainNode(data);
	else if (data < head->getData()){ // head ��ü
		ChainNode* tmp = new ChainNode(data);
		tmp->next = head;
		head = tmp;
	}
	else{
		tail->next = new ChainNode(data);
		tail = tail->next;
	}
}
void Chain::insertData(Student frontData, Student data)
{
	if (!head)
		std::cout << "Can't Found Data" << endl;
	else{
		ChainNode* current = NULL;
		ChainNode* midNode;
		for (current = begin(); current != end(); current = current->next){
			if (current->data == frontData)
				break;
		}
		midNode = new ChainNode(data);

		midNode->next = current->next;
		current->next = midNode;
		if (current == tail)
			tail = midNode;
	}
}
void Chain::deleteData(int stdN)
{
	ChainNode* previous = NULL;
	ChainNode* current;
	bool isRight = false;
	for (current = begin(); current != end(); current = current->next){
		if (current->getData().getStdN() == stdN){
			isRight = true;
			break;
		}
		previous = current;
	}

	if (!isRight)
		cerr << "���� ���� �й��Դϴ�." << endl;
	else{
		if (head == tail){ // ���Ұ� 1��
			delete head;
			head = tail = NULL;
		}
		else if (!previous){
			ChainNode* tmp = head->next;
			delete head;
			head = tmp;
		}
		else if (current == tail){
			previous->next = NULL;
			delete tail;
			tail = previous;
		}
		else{
			previous->next = current->next;
			current->next = NULL;
			delete current;
		}
	}
}
void Chain::printData(){
	if (!head){
		cerr << "����Ʈ�� ����ֽ��ϴ�." << endl;
		return;
	}
	for (ChainNode* current = begin(); current != end(); current = current->next)
		cout << current->getData() << endl;
}