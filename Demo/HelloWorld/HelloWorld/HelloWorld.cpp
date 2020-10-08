// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int x = 0;
    if (x == 0)
    {
        printf("Hello World!\n");
    }
    return 0;
}

void connectToDB(char* connectionString)
{
    if (connectionString == NULL)
    {
        printf("ОШИБКА: Введена пустая строка подключения");
        return;
    }
    //Код подключения к БД
}
