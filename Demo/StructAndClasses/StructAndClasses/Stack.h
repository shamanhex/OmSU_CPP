#pragma once
#include "List.h"

template <class T>
class Stack : private List<T>
{
public:
    Stack();

    void Push(T* item);

    T* Pull();
};

template <class T>
Stack<T>::Stack()
{
}

template <class T>
void Stack<T>::Push(T* item)
{
    this->Add(item);
}

template <class T>
T* Stack<T>::Pull()
{
    T* value = this->GetItemByIndex(this->Count() - 1);
    this->DeleteLast();
    return value;
}