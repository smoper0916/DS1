#include "Student.h"

bool Student::operator==(const Student s) const {
	return this->name == s.name && this->stdN == s.stdN;
}
bool Student::operator!=(const Student s) const {
	return !operator==(s);
}
bool Student::operator==(const int key) const {
	return this->stdN == key;
}
bool Student::operator!=(const int key) const {
	return !operator==(key);
}
bool Student::operator<(const Student s) const {
	return this->stdN < s.stdN;
}
ofstream& operator<<(ofstream& os, Student& s)
{
	os << s.stdN << " " << s.name;
	return os;
}
ifstream& operator>>(ifstream& is, Student& s)
{
	int stdN;
	string name;

	is >> stdN >> name;
	s.setStdN(stdN);
	s.setName(name);
	return is;
}
istream& operator>>(istream& is, Student& s)
{
	int stdN;
	string name;

	is >> stdN >> name;
	s.setStdN(stdN);
	s.setName(name);
	return is;
}
ostream& operator<<(ostream& os, Student& s)
{

	os << s.stdN << " " << s.name;
	return os;
}