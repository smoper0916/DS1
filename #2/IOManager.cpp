//#include <iostream>
#include "IOManager.h"
//#include "Term.h"
/*
	getArray() : ���׽��� �Է¹޴´�. 
				 ���׽��� �Է¹��� ��, Term ��ü�� return ��Ų��.
*/
Term* IOManager::getArray(int& limit, int& count){
	/*
		�ʿ��� ���� ����
	*/
	float c;
	int e;
	// �ʱ� ��ü ����
	Term *term = new Term[limit];

	while (true){
		std::cin >> c >> e;
		if (count == limit)
			upSize(term, limit);
		term[count++] = Term(c, e);
		if (c == 0 || e == 0)
			break;
	}
	return term;
}
void IOManager::upSize(Term *term, int& MAX)
{
	Term *new_term = new Term[2 * MAX];
	for (int i = 0; i < MAX; i++)
		new_term[i] = term[i];
	delete[] term;
	term = new_term;
	MAX *= 2;
}