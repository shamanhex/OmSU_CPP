#include <iostream>

struct Point
{
    int x;
    int y;
    bool isVisible;
};

class ListItem
{
private:
    void* lpValue = NULL;
    ListItem* lpNext = NULL;

public:
    ListItem(const ListItem& lpItem)
    {
        lpValue = lpItem.lpValue;
        lpNext = lpItem.lpNext;
    }

    ListItem(const void* lpValue)
    {
        lpValue = lpValue;
    }

    void* getValue()
    {
        return this->lpValue;
    }

    void setValue(const void* lpValue)
    {
        this->lpValue = (void*) lpValue;
    }

    ListItem* getNext()
    {
        return this->lpNext;
    }

    void setNext(const ListItem* lpNext)
    {
        this->lpNext = (ListItem*) lpNext;
    }              
};

class List
{
private:
    ListItem* lpFirstItem;
    int count;

public:
    List()
    {
        lpFirstItem = NULL;
        count = 0;
    }

    ~List()
    {
        ListItem* lpCurItem = this->lpFirstItem;
        while (lpCurItem != NULL)
        {
            ListItem* lpNextItem = lpCurItem->getNext();
            delete lpCurItem;
            lpCurItem = lpNextItem;
        }
    }

    int Count()
    {
        return count;
    };

    void Add(const void* lpValue)
    {
        ListItem* lpNewItem = new ListItem(lpValue);

        if (this->lpFirstItem == NULL)
        {
            this->lpFirstItem = lpNewItem;
        }
        else
        {
            ListItem* lpLastItem = this->lpFirstItem;
            while (lpLastItem->getNext() != NULL)
            {
                lpLastItem = lpLastItem->getNext();
            }
            lpLastItem->setNext(lpNewItem);
        }
        count++;  
    }
};

int main()
{
    int x = 10;
    List list;     
    list.Add(&x);
    list.Add(&x);
    std::cout << "Item number " << list.Count() << "\n";
}
