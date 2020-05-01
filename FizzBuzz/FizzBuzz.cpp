//
//
//

#include "FizzBuzz.h"
#include <iostream>

FizzBuzz::FizzBuzz(int _target)
	: m_countTarget(_target)
{

}

void FizzBuzz::DoWork()
{
    //m_buffer = "";
    std::cout << "Begin FizzBuzz!\n";
    //m_complete = false;

    int index = 1;
    while (index <= m_countTarget)
    {
        if (((index % 3) == 0) && ((index % 5) == 0))
        {
            std::cout << "FizzBuzz\n";
        }
        else if ((index % 3) == 0)
        {
            std::cout << "Fizz\n";
        }
        else if ((index % 5) == 0)
        {
            std::cout << "Buzz\n";
        }
        else
        {
            char intbuff[10];
            memset(intbuff, 0, 10);
            snprintf(intbuff, 10, "%d\n", index);
            std::cout << intbuff;
        }

        ++index;
    }

    std::cout << "End FizzBuzz!\n";
    //m_complete = true;
}

void FizzBuzz::DoAsyncWork()
{

}