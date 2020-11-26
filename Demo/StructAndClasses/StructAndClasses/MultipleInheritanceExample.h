#pragma once

class Person
{
public:
    char* lpszName;

    Person();

    ~Person();

    void PrintName();
};

class Student : public Person
{
public:
    Student();

    ~Student();
};

class Doctor : public Person
{
public:
    Doctor();

    ~Doctor();
};

class StudentDoctor : public Student, public Doctor
{
public:
    StudentDoctor();

    ~StudentDoctor();
};