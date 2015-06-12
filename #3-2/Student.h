#pragma once

#include <string>

using namespace std;

class Student
{
public:
	Student(int stdN, string name):stdN(stdN), name(name){}

private:
	int stdN;
	string name;
};

