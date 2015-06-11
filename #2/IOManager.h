#ifndef _IOMANAGER_H_
#define _IOMANAGER_H_
//#include <fstream>

#include "Polynomial.h"
class IOManager
{

public:
	Term* getArray(int&,int&);
	void upSize(Term*, int&);
	
};
#endif