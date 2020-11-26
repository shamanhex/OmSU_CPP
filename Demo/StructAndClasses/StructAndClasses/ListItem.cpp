#include "ListItem.h"

template <class T>
ListItem<T>::ListItem(const ListItem* lpItem)
{
    lpValue = lpItem.lpValue;
    lpNext = lpItem.lpNext;
}

template <class T>
ListItem<T>::ListItem(const T* lpValue)
{
    this->lpValue = (T*)lpValue;
}

template <class T>
T* ListItem<T>::getValue()
{
    return this->lpValue;
}

template <class T>
void ListItem<T>::setValue(const T* lpValue)
{
    this->lpValue = lpValue;
}

template <class T>
ListItem<T>* ListItem<T>::getNext()
{
    return this->lpNext;
}

template <class T>
void ListItem<T>::setNext(const ListItem* lpNext)
{
    this->lpNext = (ListItem*)lpNext;
}

