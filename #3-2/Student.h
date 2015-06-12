#pragma once
#include <string>
#include <fstream>

using namespace std;

class Student
{
	friend ofstream& operator<<(ofstream& os, Student& s);
	friend ifstream& operator>>(ifstream& is, Student& s);
	friend ostream& operator<<(ostream& os, Student& s);
	friend istream& operator>>(istream& is, Student& s);
public:
	Student() :stdN(-1), name("-----"){}
	Student(int stdN, string name){
		this->stdN = stdN;
		this->name = name;
	}
	~Student(){}

	void setName(string name){ this->name = name; }
	string getName(){ return name; }

	void setStdN(int stdN){ this->stdN = stdN; }
	int getStdN(){ return stdN; }

	bool operator==(const Student) const;
	bool operator!=(const Student) const;

	bool operator==(const int) const;
	bool operator!=(const int) const;

	bool operator<(const Student) const;
private:
	int stdN;
	string name;
};
