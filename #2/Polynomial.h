#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "Chain.h"
#include <iostream>
using namespace std;

class Polynomial
{
	friend std::ostream& operator<<(std::ostream& os, Polynomial& p);
private:
	Chain termLinkedList; // 0�� �ƴ� ���� �迭
public:
	/* ������ */
	Polynomial(){}
	Polynomial(Polynomial&); // ���������

	Polynomial operator=(Polynomial&); // '=' ������ �����ε�

	/* Functions */
	void getArray();
	Chain& getChain(){ return termLinkedList; }
	/*
		���׽� ����
	*/
	Polynomial getAdd(Polynomial&);
	/*
		���׽� ����
	*/
	Polynomial getMultiply(Polynomial&);
	
};
#endif