// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef unsigned char BYTE;
typedef struct
{
    int x;          //4 байта
    int y;          //4 байта
    bool isEnabled; //1 байт
    char Symbol;    //1 байт
    char Symbol1;    //1 байт
    char Symbol2;    //1 байт   
    char Symbol3;    //1 байт
} _POINT;           //Сумма: 10 байт

int main()
{
    _POINT point0, point, point2;
    point.x = 10;
    point.y = 100;
    std::cout << "Size of _POINT in bytes " << sizeof(_POINT) << "\n";

    std::cout << "Address of point0          " << &point0 << "\n";
    std::cout << "Address of point           " << &point << "\n";
    std::cout << "Address of point.x         " << &point.x << "\n";
    std::cout << "Address of point.y         " << &point.y << "\n";
    std::cout << "Address of point.isEnabled " << &point.isEnabled << "\n";
    std::cout << "Address of point.Symbol    " << (int*) &point.Symbol << "\n";
    std::cout << "Address of point.Symbol1   " << (int*) &point.Symbol1 << "\n";
    std::cout << "Address of point.Symbol2   " << (int*) &point.Symbol2 << "\n";
    std::cout << "Address of point2          " << &point2 << "\n";
}