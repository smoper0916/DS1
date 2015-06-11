#include "IOHandler.h"

void IOHandler::save(Student object){
	ofstream os(fileName);
	os << object << endl;
	os.close();
}
void IOHandler::load(Chain& stdList){
	Student* ob = new Student();
	Student& object = *ob;
	ifstream is(fileName);
	if (is.fail())
		throw "File Open�� �����߽��ϴ�.";
	while (true){
		is >> object;
		if (is.eof())
			break;

		ChainNode* bigNode = stdList.getBig(object);
		if (bigNode)
			stdList.insertData(bigNode->getData(), object);
		else
			stdList.insertData(object);
	}
	is.close();
}