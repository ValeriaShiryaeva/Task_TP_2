#include "Stack.h"

Stack::Stack(const Stack& S){
    size = 0;
    stack_ptr = nullptr;
    if (S.size != 0)
        add(S.stack_ptr);
}

void Stack::add(Plate* p) {
    if (nullptr != p->getPrevPtr())
        add(p->getPrevPtr());
    push(p);
}

Stack::~Stack() {
    while(size != 0)
        pop();
}

void Stack::push(Plate* plate) {
    Plate* p = new Plate;
    p->setColorPlate(plate->getColorPlate());
    p->setPrevPtr(stack_ptr);
    stack_ptr = p;
    size++;
}

string Stack::pop() {
    if (size == 0) 
        cout << "Стопка терелок пуста" << endl;
    else
    {
        string _color_plate = stack_ptr->getColorPlate();
        stack_ptr = stack_ptr->getPrevPtr();
        size--;
        return _color_plate;
    }      
}

void Stack::print() {
    Plate* ptr = stack_ptr;
    for (int i = 0; i < size; i++)
    {
        cout << stack_ptr->getColorPlate() << endl;
        stack_ptr = stack_ptr->getPrevPtr();
    }
    stack_ptr = ptr;
}




