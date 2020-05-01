// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FizzBuzz.h"

size_t DoWork();
size_t DoAsyncWork();

int main()
{
    std::cout << "Do work.\n";

    DoWork();

    system("pause");
}

size_t DoWork()
{
    FizzBuzz* buzzer = new FizzBuzz(100);
    buzzer->DoWork();
    delete buzzer;

    return 0;
}