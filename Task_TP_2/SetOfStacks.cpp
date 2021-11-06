#include "SetOfStacks.h"

string input_keyboard();

SetOfStacks::SetOfStacks() :length(0), data(nullptr) {}

SetOfStacks::SetOfStacks(const SetOfStacks& SOS) {
    data = new Stack[SOS.length];
    length = SOS.length;
    for (int i = 0; i < SOS.length; i++)
        data[i] = SOS.data[i];
}

SetOfStacks::~SetOfStacks() {
    delete[] data;
    data = nullptr;
    length = 0;
}

Stack& SetOfStacks::operator[](int index) {
    if (index >= 0 && index < length)
        return data[index];
}

SetOfStacks& SetOfStacks::operator=(const SetOfStacks& keeper)
{
    if (this == &keeper)
        return *this;
    delete[] data;
    data = new Stack[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
    return *this;
}

void SetOfStacks::creat_SetOfStacks(int max_lenght) {
    Plate* P = new Plate;
    P->setColorPlate(input_keyboard());
    if (length != 0)
    {
        if(data[length-1].getSize() < max_lenght)
                data[length - 1].push(P);
        else
        {
             Stack S;
             S.push(P);
             memory_allocation_SetOfStacks(S);
        }
    }
    else
    {
        Stack S;
        S.push(P);
        memory_allocation_SetOfStacks(S);
    }
    
}

void SetOfStacks::memory_allocation_SetOfStacks(Stack& S) {
    Stack* tmp = data;
    length++;
    data = new Stack[length];
    for (int i = 0; i < length-1; i++)
            data[i] = tmp[i];
    data[length-1] = S;
}

void SetOfStacks::delete_plate() {
    if (data[length - 1].getSize() != 0)
    {
        data[length - 1].pop();
        if (data[length - 1].getSize() == 0)
        {
            Stack* S = new Stack[length - 1];
            length--;
            for (int i = 0; i < length; i++)
                S[i] = data[i];
            data = S;
        }
    }
}

void SetOfStacks::output_to_console() {
    if (length == 0) {
        cout << "На столе нет ни одной стопки тарелок" << endl << endl;
    }
    else {
        cout << "Количество стопок на столе: " << length << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Стопка " << i + 1 << endl;
            cout << "Количество тарелок в стопке: " << data[i].getSize() << endl;
                data[i].print();
        }
    }
    cout << endl;
}

string input_keyboard() {
    string s;
    cout << "Введите цвет тарелки" << endl;
    getline(cin, s);
    while (1) {
        getline(cin, s);
        if (s.find_first_not_of("qwertyuiopasdfghjklzxcvbnmWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
            return s;
        else
            cout << "Введен неверный цвет тарелки, повторите ввод." << endl;
    }
    cout << endl;
}