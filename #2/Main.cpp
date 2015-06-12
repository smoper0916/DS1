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

	int pTerms = 0; int p2Terms = 0;
	Chain x = p.getChain(); Chain y = p2.getChain();
	for (ChainNode* n = x.begin(); n != x.end(); n = n->getNext(), pTerms++);
	for (ChainNode* n = y.begin(); n != y.end(); n = n->getNext(), p2Terms++);

	if (pTerms == 0 || p2Terms == 0)
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

	int terms = 0;
	int i = 0;
	Chain x = p.getChain();
	for (ChainNode* n = x.begin(); n != x.end(); n = n->getNext(), terms++);
	for (ChainNode* n = x.begin(); n != x.end(); n = n->getNext(), i++)
	{
		if (n->getData().coef != 0)
		{
			if (n->getData().coef != 1)
				result += parseString(n->getData().coef);
			else if (n->getData().coef == -1)
				result += "-";

			if (n->getData().exp == 1)
				result += "x";
			else if (n->getData().exp != 0)
				result += "x^" + parseString(n->getData().exp);
		}
		if (i != terms - 1)
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