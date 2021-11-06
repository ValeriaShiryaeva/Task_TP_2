#include <iostream>
#include"SetOfStacks.h"
#include"Stack.h"
#include"Plate.h"
using namespace std;

SetOfStacks setofstacks;

void menu();
void print_menu();
int input_number();
int main()
{
	setlocale(LC_ALL, "rus");
	menu();
}

void menu() {
	cout << "Задайте максимально колличество тарелок в стопке. ";
	int max_lenght = input_number();
	while (1) {
		print_menu();
		int punkt_menu = input_number();
		if (punkt_menu <= 6 && punkt_menu >= 0) {
			switch (punkt_menu)
			{
			case 1:
				setofstacks.creat_SetOfStacks(max_lenght);
				break;
			case 2:
				if (setofstacks.getLength() != 0)
					setofstacks.delete_plate();
				else
					cout << "На столе нет сторок с тарелками" << endl;
				break;
			case 3:
				setofstacks.output_to_console();
				break;
			case 0:
				exit(0);
			}
		}
		else
			cout << "Введен не верный пункт меню. " << endl;
	}
}

void print_menu()
{
	cout << "Выберете пункт меню:" << endl;
	cout << "	1. Добавить тарелку в стопку " << endl;
	cout << "	2. Удалить тарелку из стопки" << endl;
	cout << "	3. Вывсти стопки тарелок на экран" << endl;
	cout << "	0. Выход из программы" << endl;
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << "Введите: " << endl;
		cin >> number_s;
		if (number_s.find_first_not_of("0123456789", 0) == string::npos)
		{
			int number = stoi(number_s);
			return number;
		}
		else
			cout << "Введено не верное значение. Повторите ввод." << endl;
	}
}