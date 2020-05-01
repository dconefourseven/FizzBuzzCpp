//
//
//

#include "FizzBuzz.h"
#include <future>

FizzBuzz::FizzBuzz(int _target)
	: m_countTarget(_target)
{

}

#define countof(array) (sizeof(array) / sizeof(array[0]))
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
            // Potential for a bug here if the target exceeds 9999999999
            char intbuff[_MAX_U64TOSTR_BASE2_COUNT];
            memset(intbuff, 0, countof(intbuff));
            _itoa_s(index, intbuff, countof(intbuff), 10);
            m_buffer += intbuff;
            m_buffer += '\n';
        }

        ++index;
    }

    m_buffer += "End FizzBuzz!\n";
    m_complete = true;
}