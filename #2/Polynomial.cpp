#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial(Polynomial& p)
{	
	termLinkedList = p.getChain();
}
Polynomial Polynomial::operator=(Polynomial& p)
{
	termLinkedList = p.getChain();
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
		int bPosCnt = 0;
		while (bPos != bTermList.end())
		{
			for (aPos = aTermList.begin(); aPos != aTermList.end(); aPos = aPos->next)
				tmp[bPosCnt].getChain().insertData(Term(aPos->getData().coef * bPos->getData().coef, aPos->getData().exp + bPos->getData().exp));
			bPosCnt++; bPos = bPos->next;
		}
		if (bCount >= 1)
		{
			for (int i = 0; i < bCount; i++)
				c = tmp[i].getAdd(c);
		}
	}
	else {
		int aPosCnt = 0;
		while (aPos != aTermList.end())
		{
			for (bPos = bTermList.begin(); bPos != bTermList.end(); bPos = bPos->next)
				tmp[aPosCnt].getChain().insertData(Term(aPos->getData().coef * bPos->getData().coef, aPos->getData().exp + bPos->getData().exp));
			aPosCnt++; aPos = aPos->next;
		}
		if (aCount >= 1)
		{
			for (int i = 0; i < aCount; i++)
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