#pragma once

#include <iostream>
#include "Keyboard.h"
#include "Chain.h"
#include "Student.h"
#include "IOHandler.h"

using namespace std;
enum{ NONE, INPUT, DELETE, PRINT, EXIT};

typedef int CODE;

class TaskManager
{
public:
	TaskManager();
	~TaskManager();

	void perform(Chain&);
	void processMenu(int, Chain&);
	void showMenu();
	void loadingFunction(IOHandler&, Chain&);
private:
	void processInput(Chain&);
	void processDelete(Chain&);
};
