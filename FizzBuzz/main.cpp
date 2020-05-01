// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "FizzBuzz.h"

size_t DoWork();
size_t DoAsyncWork();

static const int s_target = 100000;
static const int s_numCounters = 20;

int main()
{
    std::cout << "Do work.\n";

    DoWork();
    DoAsyncWork();

    system("pause");
}

size_t DoWork()
{
    std::vector<FizzBuzz*> fizzbuzzers(s_numCounters);
    for (int index = 0; index < s_numCounters; ++index)
    {
        fizzbuzzers[index] = new FizzBuzz(s_target);
    }

    for (auto buzzer : fizzbuzzers)
    {
        buzzer->DoWork();
    }

    for (auto buzzer : fizzbuzzers)
    {
        delete buzzer;
    }

    return 0;
}

size_t DoAsyncWork()
{
    std::vector<FizzBuzz*> fizzbuzzers(s_numCounters);
    for (int index = 0; index < s_numCounters; ++index)
    {
        fizzbuzzers[index] = new FizzBuzz(s_target);
    }

    for (auto fb : fizzbuzzers)
    {
        fb->DoAsyncWork();
    }

    bool allComplete = false;
    while (!allComplete)
    {
        allComplete = true;
        for (auto fb : fizzbuzzers)
        {
            if (!(fb->IsComplete()))
            {
                allComplete = false;
                break;
            }
        }
    }

    for (auto fb : fizzbuzzers)
    {
        delete fb;
    }

    return 0;
}