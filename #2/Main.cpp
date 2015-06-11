#include "Polynomial.h"
#include <string>
#include <sstream>

using namespace std;

std::ostream& operator<<(std::ostream&, Polynomial&);
string parseString(int);
string parseString(float);

int main()
{
	/*
		�ʿ��� ��ü, ���� ����
	*/
	Polynomial p, p2;
	/*
		�Է��� �޴´�.
	*/
	cout << "ù��° ���׽��� ���-���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)" << endl;
	p.getArray();

	cout << "�ι�° ���׽��� ���-���� ������ �Է��ϼ���.(������ 0���� �ԷµǸ� ����)" << endl;
	p2.getArray();
	if (p.getTerms() == 0 || p2.getTerms() == 0)
	{
		cout << "���� 0���Դϴ�. ���� �� �����ϴ�." << endl;
		return 0;
	}
	cout << "�� ���׽��� �� : " << p.getMultiply(p2) << endl;
	return 0;
}
std::ostream& operator<<(std::ostream& os, Polynomial& p)
{
	string result = "";
	for (int i = 0; i < p.terms; i++)
	{
		if (p.termLinkedList[i].coef != 0)
		{
			if (p.termLinkedList[i].coef != 1)
				result += parseString(p.termLinkedList[i].coef);
			else if (p.termLinkedList[i].coef == -1)
				result += "-";

			if (p.termLinkedList[i].exp == 1)
				result += "x";
			else if (p.termLinkedList[i].exp != 0)
				result += "x^" + parseString(p.termLinkedList[i].exp);
		}
		if (i != p.terms - 1)
			result += "+";
	}
	if (result[result.length() - 1] == '+')
		result[result.length() - 1] = ' ';
	cout << result << endl;
	return os;
}
string parseString(int x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}
string parseString(float x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}