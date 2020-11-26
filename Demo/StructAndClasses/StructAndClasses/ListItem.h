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