#pragma once

#include "ListItem.h"
#include <iostream>

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

 

template <class T>
List<T>::List()
{
    lpFirstItem = NULL;
    count = 0;
}

template <class T>
List<T>::~List()
{
    ListItem<T>* lpCurItem = this->lpFirstItem;
    while (lpCurItem != NULL)
    {
        ListItem<T>* lpNextItem = lpCurItem->getNext();
        delete lpCurItem;
        lpCurItem = lpNextItem;
    }
    this->lpFirstItem = NULL;
}

template <class T>
int List<T>::Count()
{
    return count;
}

template <class T>
void List<T>::Add(const T* lpValue)
{
    ListItem<T>* lpNewItem = new ListItem<T>(lpValue);

    if (this->lpFirstItem == NULL)
    {
        this->lpFirstItem = lpNewItem;
    }
    else
    {
        ListItem<T>* lpLastItem = this->lpFirstItem;
        while (lpLastItem->getNext() != NULL)
        {
            lpLastItem = lpLastItem->getNext();
        }
        lpLastItem->setNext(lpNewItem);
    }
    count++;
}

template <class T>
void List<T>::DeleteLast()
{
    if (this->lpFirstItem != NULL)
    {
        ListItem<T>* lpPrevItem = NULL;
        ListItem<T>* lpLastItem = this->lpFirstItem;
        while (lpLastItem->getNext() != NULL)
        {
            lpPrevItem = lpLastItem;
            lpLastItem = lpLastItem->getNext();
        }
        lpPrevItem->setNext(NULL);
        delete lpLastItem;
    }
}

template <class T>
T* List<T>::GetItemByIndex(int index)
{
    ListItem<T>* lpCurItem = this->lpFirstItem;
    for (int i = 0; i < index; i++)
    {
        if (lpCurItem == NULL)
        {
            return NULL;
        }
        lpCurItem = lpCurItem->getNext();
    }
    return lpCurItem->getValue();
}

template <class T>
List<T>* List<T>::operator += (const T* item)
{
    this->Add(item);
    return this;
}

template <class T>
List<T>* List<T>::operator << (const T* item)
{
    this->Add(item);
    return this;
}

template <class T>
T* List<T>::operator[] (int index)
{
    return this->GetItemByIndex(index);
}