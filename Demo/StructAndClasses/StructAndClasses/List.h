#pragma once

#include "ListItem.h"

template <class T>
class List
{
private:
    ListItem<T>* lpFirstItem;
    int count;

public:
    List();

    ~List();

    int Count();

    void Add(const T* lpValue);

    void DeleteLast();

    T* GetItemByIndex(int index);

    List* operator += (const T* item);

    List* operator << (const T* item);

    T* operator[] (int index);
};