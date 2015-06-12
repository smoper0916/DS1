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
		cout << "원하는 기능을 선택하세요 : ";
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
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}
void TaskManager::showMenu(){
	cout << "==========================================" << endl;
	cout << "(1) 새 학생 입력" << endl;
	cout << "(2) 학생 삭제" << endl;
	cout << "(3) 학번 순으로 전체 출력" << endl;
	cout << "(4) 종료" << endl;
	cout << "==========================================" << endl;
}
void TaskManager::loadingFunction(IOHandler& io, Chain& stdList){
	io.load(stdList);
}
void TaskManager::processInput(Chain& stdList){
	int stdN; string name;
	cout << "원하는 학번과 이름을 입력하세요. : ";
	cin >> stdN >> name;

	Student s(stdN, name);
	ChainNode* bigNode = stdList.getBig(s);
	if (bigNode)
		stdList.insertNode(bigNode, s);
	else
		stdList.insertNode(s);

	cout << "처리가 완료되었습니다." << endl;
}
void TaskManager::processDelete(Chain& stdList){
	int stdN;
	cout << "학번을 입력하세요. : ";
	cin >> stdN;

	stdList.deleteNode(stdN);

	cout << "삭제가 완료되었습니다." << endl;
}