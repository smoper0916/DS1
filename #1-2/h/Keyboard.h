#pragma once

template<typename T>
class Keyboard
{
public:
	Keyboard(){}

	T getInput(){
		cin >> data;
		return data;
	}

private:
	T data;
};