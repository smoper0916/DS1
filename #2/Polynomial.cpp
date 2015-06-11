#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial(const Polynomial& p)
{
	terms = p.terms;
	capacity = p.capacity;
	termLinkedList = new Term[capacity];
	for (int i = 0; i < terms; i++)
		termLinkedList[i] = p.termLinkedList[i];
}
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	terms = p.terms;
	capacity = p.capacity;
	delete[] termLinkedList; // 기존 것 제거
	termLinkedList = new Term[capacity];
	for (int i = 0; i < terms; i++)
		termLinkedList[i] = p.termLinkedList[i];
	return *this;
}
Polynomial Polynomial::getAdd(Polynomial& b)
{
	Polynomial c;

	Chain& aTermList = termLinkedList;
	Chain& bTermList = b.getChain();
	Chain& cTermList = c.getChain();

	ChainNode* aPos = aTermList.begin();
	ChainNode* bPos = bTermList.begin();

	while ((aPos != aTermList.end()) && (bPos != bTermList.end()))
	{
		if (aPos->getData().exp == bPos->getData().exp)
		{
			float t = aPos->getData().coef + bPos->getData().coef;
			if (t) cTermList.insertData(Term(t, aPos->getData().exp));
			aPos = aPos->next; bPos = bPos->next;
		}
		else if (aPos->getData().exp < bPos->getData().exp)
		{
			cTermList.insertData(Term(bPos->getData().coef, bPos->getData().exp));
			bPos = bPos->next;
		}
		else
		{
			cTermList.insertData(Term(aPos->getData().coef, aPos->getData().exp));
			aPos = aPos->next;
		}
	}

	for (; aPos != aTermList.end(); aPos = aPos->next)
		cTermList.insertData(Term(aPos->getData().coef, aPos->getData().exp));

	for (; bPos != bTermList.end(); bPos = bPos->next)
		cTermList.insertData(Term(bPos->getData().coef, bPos->getData().exp));
	return c;
}
Polynomial Polynomial::getMultiply(Polynomial& b)
{

	Chain& aTermList = termLinkedList;
	Chain& bTermList = b.getChain();

	ChainNode* aPos = aTermList.begin();
	ChainNode* bPos = bTermList.begin();
	// b와 terms를 비교하여 작은 것을 택한다.

	int aCount = 0; int bCount = 0;
	for (ChainNode* p = aTermList.begin(); p != NULL; p = p->next)
		aCount++;
	for (ChainNode* p = bTermList.begin(); p != NULL; p = p->next)
		bCount++;
	Polynomial *tmp = new Polynomial[(aCount < bCount) ? aCount : bCount];
	Polynomial c;
	if (aCount > bCount)
	{
		while (bPos != bTermList.end())
		{
			for (aPos = 0; aPos < terms; aPos++)
				tmp[bPos].NewTerm(termLinkedList[aPos].coef * b.termLinkedList[bPos].coef, termLinkedList[aPos].exp + b.termLinkedList[bPos].exp);
			bPos++;
		}
		if (bCount >= 1)
		{
			for (int i = 0; i < b.terms; i++)
				c = tmp[i].getAdd(c);
		}
	}
	else {
		while (aPos < terms)
		{
			for (bPos = 0; bPos < b.terms; bPos++)
				tmp[aPos].NewTerm(termLinkedList[aPos].coef * b.termLinkedList[bPos].coef, termLinkedList[aPos].exp + b.termLinkedList[bPos].exp);
			aPos++;
		}
		if (terms >= 1)
		{
			for (int i = 0; i < terms; i++)
				c = tmp[i].getAdd(c);
		}
	}
	delete[] tmp;
	return c;
}
/*
getArray() : 다항식을 입력받는다.
다항식을 입력받은 뒤, Term 객체로 return 시킨다.
*/
void Polynomial::getArray(){
	float coef;
	int exp;

	while (true){
		std::cin >> coef >> exp;
		termLinkedList.insertData(Term(coef, exp));
		if (exp == 0)
			break;
	}
}