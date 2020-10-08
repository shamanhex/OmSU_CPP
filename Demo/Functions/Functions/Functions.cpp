// Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print(const int *x, const int *y)
{
    std::cout << "Hello World!\n";
    int z = *x + *y;
    std::cout << "Sum: " << z << "\n";
}

const char* GetLocalizedUserMessage(const char* lpszEnText, int local)
{
    //... Translate
    if (local > 10 /*local not found*/)
    {
        return 0;
    }
    else
    {
        return "All is OK";
    }
}

int GetLocalizedUserMessage(const char* lpszEnText, int local, char** lpszResult)
{
    //...
    if (local > 10 /*Error*/)
    {
        *lpszResult = 0;
        return -1;
    }
    else
    {
        *lpszResult = (char*) "All is OK";
        return 0;
    }
}

int main()
{
    int x = 10;
    int y = 20;

    print(&x, &y);

    std::cout << "x: " << x << "\n";
    std::cout << "y: " << y << "\n";

    char* lpszResult = new char[100];
    int errCode = GetLocalizedUserMessage("OK?", 1033, &lpszResult);
    if (errCode != 0)
    {
        
        std::cout << "ERROR translation.";
    }

}
