// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <future>
#include "FizzBuzz.h"

std::chrono::nanoseconds DoWork();
std::chrono::nanoseconds DoAsyncWork();

static const int s_target = 1000000;
static const int s_numCounters = 500;

//static std::chrono::high_resolution_clock stopWatch;

int main()
{
    std::cout << "Do work.\n";
    auto timeTaken = DoWork();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeTaken);

    std::cout << "Do work async.\n";
    auto timeTakenAsync = DoAsyncWork();
    auto asyncMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeTakenAsync);

    std::cout << "C++ Results: \n";
    std::cout << "Sync: Time Taken: " << milliseconds.count() / 1000 << "s " << milliseconds.count() % 1000 << "ms\n";
    std::cout << "Async: Time Taken: " << asyncMilliseconds.count() / 1000 << "s " << asyncMilliseconds.count() % 1000 << "ms\n";

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

struct FizzBuzzFuture
{
    FizzBuzz* fizzbuzzer = 0;
    std::future<void> future;
};

std::chrono::nanoseconds DoAsyncWork()
{
    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<FizzBuzzFuture> fizzbuzzers(s_numCounters);
    for (int index = 0; index < s_numCounters; ++index)
    {
        fizzbuzzers[index].fizzbuzzer = new FizzBuzz(s_target);
    }

    for (int index = 0; index < s_numCounters; ++index)
    {
        fizzbuzzers[index].future = std::async(std::launch::async, &FizzBuzz::DoWork, fizzbuzzers[index].fizzbuzzer);        
    }

    bool allComplete = false;
    while (!allComplete)
    {
        allComplete = true;
        for (int index = 0; index < s_numCounters; ++index)
        {
            if (!(fizzbuzzers[index].fizzbuzzer->IsComplete()))
            {
                allComplete = false;
                break;
            }
        }
        std::cout << '.';
    }

    for (int index = 0; index < s_numCounters; ++index)
    {
        delete fizzbuzzers[index].fizzbuzzer;
    }

    std::cout << std::endl;

    auto endTime = std::chrono::high_resolution_clock::now();
    auto timeDiff = endTime - startTime;

    return timeDiff;
}