//#include <iostream>
#include "IOManager.h"
//#include "Term.h"
/*
	getArray() : 다항식을 입력받는다. 
				 다항식을 입력받은 뒤, Term 객체로 return 시킨다.
*/
Term* IOManager::getArray(int& limit, int& count){
	/*
		필요한 변수 선언
	*/
	float c;
	int e;
	// 초기 객체 생성
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