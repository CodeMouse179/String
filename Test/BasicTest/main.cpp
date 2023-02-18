#define SYSTEM_STRING_CONSOLE
#ifdef _MSC_VER
#include "String.hpp"
#else
#include "../../String.hpp"
#endif
using namespace System;
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
        usleep(sec * 1000 * 1000);
    }
    return 0;
}