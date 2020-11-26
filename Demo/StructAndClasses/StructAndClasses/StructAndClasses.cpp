#include <iostream>  
#include "MultipleInheritanceExample.h"
#include "List.h"

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
  

int main()
{
    List<MyPoint> PointsList;
    PointsList.Add(new MyPoint(10, 100));
    PointsList.Add(new MyPoint(20, 200));
    PointsList.Add(new MyPoint(30, 300));

    //PointsList += new MyPoint(10, 10);
    //PointsList << new MyPoint(10, 10);

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