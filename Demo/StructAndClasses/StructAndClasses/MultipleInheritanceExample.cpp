#include <iostream>
#include "MultipleInheritanceExample.h"

Person::Person()
{
    lpszName = NULL;
    if (lpszName == NULL)
    {
        std::cout << "Create Persone() -> allocate memory for Name\n";
        lpszName = new char[500];
    }
    std::cout << "Create Persone()\n";
}

Person::~Person()
{
    std::cout << "Delete Persone()\n";
    if (lpszName != NULL)
    {
        std::cout << "Delete Persone() -> free memory for Name\n";
        delete lpszName;
        lpszName = NULL;
    }
}

void Person::PrintName()
{
    std::cout << "Name: " << this->lpszName << "\n";
}

Student::Student()
{
    sprintf_s(lpszName, 500, "Student");
    std::cout << "Create Student()\n";
}

Student::~Student()
{
    std::cout << "Delete Student()\n";
}

Doctor::Doctor()
{
    sprintf_s(lpszName, 500, "Doctor");
    std::cout << "Create Doctor()\n";
}

Doctor::~Doctor()
{
    std::cout << "Delete Doctor()\n";
}

StudentDoctor::StudentDoctor()
{
    std::cout << "Create StudentDoctor()\n";
}

StudentDoctor::~StudentDoctor()
{
    std::cout << "Delete StudentDoctor()\n";
}