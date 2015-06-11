#ifndef _TERM_H_
#define _TERM_H_
#include <fstream>
//class Polynomial;
class Term
{
	friend class Polynomial;
	friend std::ostream& operator<<(std::ostream& os, Polynomial& p);
private:
	float coef;
	int exp;
public:
	Term(){ Term(0, 0); }
	inline Term(float coef, int exp){ this->coef = coef; this->exp = exp; }
};
#endif