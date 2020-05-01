//
//
//

#pragma once

#include <string>

class FizzBuzz
{
    // ---- Constructor ----
public:

    FizzBuzz(int _target);

    // ---- Methods ----
public:

    void DoWork();

    bool IsComplete() { return m_complete; }

	// ---- Variables ----
private:

    int m_countTarget = 0;

    bool m_complete = false;
    
    std::string m_buffer = "";
};

