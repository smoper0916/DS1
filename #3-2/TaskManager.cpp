#include "TaskManager.h"

TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::perform(Chain& stdList){
	showMenu();
	while (true){
		cout << "���ϴ� ����� �����ϼ��� : ";
		int answer = Keyboard<int>().getInput();
		if (answer == EXIT)
			return;
		processMenu(answer, stdList);
	}
}
void TaskManager::processMenu(int menuCode, Chain& stdList){
	switch (menuCode)
	{
	case INPUT:
		processInput(stdList);
		break;
	case DELETE:
		processDelete(stdList);
		break;
	case PRINT:
		stdList.printData();
		break;
	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}
void TaskManager::showMenu(){
	cout << "==========================================" << endl;
	cout << "(1) �� �л� �Է�" << endl;
	cout << "(2) �л� ����" << endl;
	cout << "(3) �й� ������ ��ü ���" << endl;
	cout << "(4) ����" << endl;
	cout << "==========================================" << endl;
}
void TaskManager::loadingFunction(IOHandler& io, Chain& stdList){
	io.load(stdList);
}
void TaskManager::processInput(Chain& stdList){
	int stdN; string name;
	cout << "���ϴ� �й��� �̸��� �Է��ϼ���. : ";
	cin >> stdN >> name;

	Student s(stdN, name);
	ChainNode* bigNode = stdList.getBig(s);
	if (bigNode)
		stdList.insertNode(bigNode, s);
	else
		stdList.insertNode(s);

	cout << "ó���� �Ϸ�Ǿ����ϴ�." << endl;
}
void TaskManager::processDelete(Chain& stdList){
	int stdN;
	cout << "�й��� �Է��ϼ���. : ";
	cin >> stdN;

	stdList.deleteNode(stdN);

	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
}