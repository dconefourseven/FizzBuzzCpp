// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "FizzBuzz.h"

std::chrono::nanoseconds DoWork();
std::chrono::nanoseconds DoAsyncWork();

static const int s_target = 100000;
static const int s_numCounters = 200;

//static std::chrono::high_resolution_clock stopWatch;

int main()
{
    std::cout << "Do work.\n";
    auto timeTaken = DoWork();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeTaken);
    std::cout << "Do work complete. Time taken: " << milliseconds.count() / 1000 << "s " << milliseconds.count() % 1000 << "ms\n";

    std::cout << "Do work async.\n";
    auto timeTakenAsync = DoAsyncWork();    
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeTaken);
    std::cout << "Do async work complete. Time taken: " << milliseconds.count() / 1000 << "s " << milliseconds.count() % 1000 << "ms\n";

    system("pause");
}

std::chrono::nanoseconds DoWork()
{
    auto startTime = std::chrono::high_resolution_clock::now();

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

    auto endTime = std::chrono::high_resolution_clock::now();
    auto timeDiff = endTime - startTime;

    return timeDiff;
}

std::chrono::nanoseconds DoAsyncWork()
{
    auto startTime = std::chrono::high_resolution_clock::now();

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
        std::cout << '.';
    }

    for (auto fb : fizzbuzzers)
    {
        delete fb;
    }

    std::cout << std::endl;

    auto endTime = std::chrono::high_resolution_clock::now();
    auto timeDiff = endTime - startTime;

    return timeDiff;
}