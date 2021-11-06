#pragma once
#include <iostream>
#include <string>
#include"Stack.h"
using namespace std;

class SetOfStacks
{
private:
	Stack* data;
	int length;
public:
	SetOfStacks();
	SetOfStacks(const SetOfStacks&);
	~SetOfStacks();

	SetOfStacks& operator=(const SetOfStacks&);
	Stack& operator[](int);

	void setLength(int _length) { length = _length; }
	int getLength() { return length; }

	void creat_SetOfStacks(int);
	void memory_allocation_SetOfStacks(Stack&);
	void delete_plate();
	void output_to_console();
};

