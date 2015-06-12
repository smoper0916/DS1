#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "Chain.h"
#include <iostream>
using namespace std;

class Polynomial
{
	friend std::ostream& operator<<(std::ostream& os, Polynomial& p);
private:
	Chain termLinkedList; // 0이 아닌 항의 배열
public:
	/* 생성자 */
	Polynomial(){}
	Polynomial(Polynomial&); // 복사생성자

	Polynomial operator=(Polynomial&); // '=' 연산자 오버로딩

	/* Functions */
	void getArray();
	Chain& getChain(){ return termLinkedList; }
	/*
		다항식 덧셈
	*/
	Polynomial getAdd(Polynomial&);
	/*
		다항식 곱셈
	*/
	Polynomial getMultiply(Polynomial&);
	
};
#endif