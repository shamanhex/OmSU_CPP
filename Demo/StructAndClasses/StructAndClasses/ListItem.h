#pragma once

template <class T>
class ListItem
{
private:
    T* lpValue = NULL;
    ListItem* lpNext = NULL;

public:
    ListItem(const ListItem* lpItem);

    ListItem(const T* lpValue);

    T* getValue();

    void setValue(const T* lpValue);

    ListItem* getNext();

    void setNext(const ListItem* lpNext);
};

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