#pragma once
#include <iostream>
#include <string>
#include"Plate.h"
using namespace std;

class Stack
{
private:
	Plate* stack_ptr;
	int size;
public:
	Stack() : stack_ptr(nullptr), size(0) {}
	~Stack();
	Plate* getStackPtr() { return stack_ptr; }
	int getSize() { return size; }

	void push(Plate*);
	string pop();
	void print();
};

