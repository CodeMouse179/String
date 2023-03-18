// BasicTest of String.hpp
// Programmer : CodeMouse179
// Platform : Windows, Linux, macOS

#define SYSTEM_STRING_CONSOLE
#include "String.hpp"
using namespace System;

static const float sec = 0.05f;

void wait(float second)
{
#ifdef SYSTEM_WINDOWS
    Sleep(second * 1000);
#endif
#ifdef SYSTEM_POSIX
    usleep(second * 1000 * 1000);
#endif
}

int console_readkey_tutorial()
{
    Console::WriteLine(U8("console_readkey_tutorial START (press Q to quit)"), 155, 75, 185);
    while (true)
    {
        //TODO:解决macOS平台按键一次，输出两次的问题。
        if (Console::KeyAvailable())
        {
           BuiltInConsoleKey key = Console::ReadKey();
           if (StringA::ToLower(key.CodePoint) == 'q') break;
        }
        wait(sec);
    }
    Console::WriteLine(U8("\nconsole_readkey_tutorial START"), 155, 75, 185);
    return 0;
}

int main()
{
    Console::WriteLine(U8("BasicTest START"), 255, 25, 135);
    console_readkey_tutorial();
    Console::WriteLine(U8("BasicTest END"), 255, 25, 135);
    return 0;
}