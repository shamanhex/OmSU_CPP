#include <iostream>

struct Point
{
    int x;
    int y;
    bool isVisible;
};

class MyPoint
{
public:
    int X;
    int Y;

    MyPoint(int x, int y)
    {
        this->X = x;
        this->Y = y;
    };
};

template <class T>
class ListItem
{
private:
    T* lpValue = NULL;
    ListItem* lpNext = NULL;

public:
    ListItem(const ListItem* lpItem)
    {
        lpValue = lpItem.lpValue;
        lpNext = lpItem.lpNext;
    }

    ListItem(const T* lpValue)
    {
        this->lpValue = (T*) lpValue;
    }

    T* getValue() 
    {
        return this->lpValue;
    }

    void setValue(const T* lpValue)
    {
        this->lpValue = lpValue;
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

template <class T>
class List
{
private:
    ListItem<T>* lpFirstItem;
    int count;

public:
    List()
    {
        lpFirstItem = NULL;
        count = 0;
    }

    ~List()
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

    int Count()
    {
        return count;
    }

    void Add(const T* lpValue)
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

    void DeleteLast()
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

    T* GetItemByIndex(int index)
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

    List* operator += (const T* item)
    {
        this->Add(item);
        return this;
    }

    List* operator << (const T* item)
    {
        this->Add(item);
        return this;
    }

    T* operator[] (int index)
    {
        return this->GetItemByIndex(index);
    }
};

template <class T>
class Stack : private List<T>
{
public:
    Stack()
    {
    }

    void Push(T* item)
    {
        this->Add(item);
    }

    T* Pull()
    {
        T* value = this->GetItemByIndex(this->Count() - 1);
        this->DeleteLast();
        return value;
    }
};

class Person
{
public:
    char* lpszName;

    Person()
    {
        lpszName = NULL;
        if (lpszName == NULL)
        {
            std::cout << "Create Persone() -> allocate memory for Name\n";
            lpszName = new char[500];
        }
        std::cout << "Create Persone()\n";
    }

    ~Person()
    {
        std::cout << "Delete Persone()\n";
        if (lpszName != NULL)
        {
            std::cout << "Delete Persone() -> free memory for Name\n";
            delete lpszName;
            lpszName = NULL;
        }
    }

    void PrintName()
    {
        std::cout << "Name: " << this->lpszName << "\n";
    }

};

class Student : public Person
{
public:
    Student()
    {
        sprintf_s(lpszName, 500, "Student");
        std::cout << "Create Student()\n";
    }

    ~Student()
    {
        std::cout << "Delete Student()\n";
    }
};

class Doctor : public Person
{
public:
    Doctor()
    {
        sprintf_s(lpszName, 500, "Doctor");
        std::cout << "Create Doctor()\n";
    }

    ~Doctor()
    {
        std::cout << "Delete Doctor()\n";
    }
};

class StudentDoctor : public Student, public Doctor
{
public:
    StudentDoctor()
    {
        std::cout << "Create StudentDoctor()\n";
    }

    ~StudentDoctor()
    {
        std::cout << "Delete StudentDoctor()\n";
    }
};

int main()
{
    List<MyPoint> PointsList;
    PointsList.Add(new MyPoint(10, 100));
    PointsList.Add(new MyPoint(20, 200));
    PointsList.Add(new MyPoint(30, 300));

    PointsList += new MyPoint(10, 10);
    PointsList << new MyPoint(10, 10);

    MyPoint* p = PointsList.GetItemByIndex(0);
    p = PointsList[0];

    std::cout << "Item number " << PointsList.Count() << "\n";
    std::cout << "Item[0] = {X = " << p->X << "; Y = " << p->Y << "}\n";

    std::cout << "\n";
    std::cout << "\n";

    Student* stud = new Student();
    stud->PrintName();
    delete stud;

    std::cout << "\n";

    Doctor* doc = new Doctor();
    doc->PrintName();
    delete doc;

    std::cout << "\n";

    StudentDoctor* x = new StudentDoctor();
    ((Doctor*) x)->PrintName();
    delete x;

}
