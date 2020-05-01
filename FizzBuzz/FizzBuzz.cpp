//
//
//

#include "FizzBuzz.h"
#include <future>

FizzBuzz::FizzBuzz(int _target)
	: m_countTarget(_target)
{

}

void FizzBuzz::DoWork()
{
    m_buffer = "";
    m_buffer += "Begin FizzBuzz!\n";
    m_complete = false;

    int index = 1;
    while (index <= m_countTarget)
    {
        if (((index % 3) == 0) && ((index % 5) == 0))
        {
            m_buffer += "FizzBuzz\n";
        }
        else if ((index % 3) == 0)
        {
            m_buffer += "Fizz\n";
        }
        else if ((index % 5) == 0)
        {
            m_buffer += "Buzz\n";
        }
        else
        {
            char intbuff[10];
            memset(intbuff, 0, 10);
            snprintf(intbuff, 10, "%d\n", index);
            m_buffer += intbuff;
        }

        ++index;
    }

    m_buffer += "End FizzBuzz!\n";
    m_complete = true;
}

void FizzBuzz::DoAsyncWork()
{
    m_buffer = "";
    m_buffer += "Begin FizzBuzz!\n";
    m_complete = false;

    std::future<void> task = std::async(std::launch::async, [&]() {
        int index = 1;
        while (index <= m_countTarget)
        {
            if (((index % 3) == 0) && ((index % 5) == 0))
            {
                m_buffer += "FizzBuzz\n";
            }
            else if ((index % 3) == 0)
            {
                m_buffer += "Fizz\n";
            }
            else if ((index % 5) == 0)
            {
                m_buffer += "Buzz\n";
            }
            else
            {
                char intbuff[10];
                memset(intbuff, 0, 10);
                snprintf(intbuff, 10, "%d\n", index);
                m_buffer += intbuff;
            }

            ++index;
        }
        });

    task.wait();

    m_buffer += "End FizzBuzz!\n";
    m_complete = true;
}