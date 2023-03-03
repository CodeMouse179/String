#define SYSTEM_STRING_CONSOLE
#ifdef _MSC_VER
#include "String.hpp"
#else
#include "../../String.hpp"
#endif
using namespace System;

void wait(float second)
{
#ifdef SYSTEM_WINDOWS
    Sleep(second * 1000);
#endif
#ifdef SYSTEM_POSIX
    usleep(second * 1000 * 1000);
#endif
}

int main()
{
    StringA::WriteLine(U8("BasicTest"));
    StringA::WriteLine(U8("BasicTest"), 255, 25, 135);
    const float sec = 0.05f;
    while (true)
    {
        if (StringA::KeyAvailable())
        {
            BuiltInConsoleKey key = StringA::ReadKey();
            if (key.CodePoint == 'a')
            {
                break;
            }
        }
        wait(sec);
    }
    return 0;
}