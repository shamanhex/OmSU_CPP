#include "Stack.h"

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