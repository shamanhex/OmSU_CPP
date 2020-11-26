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