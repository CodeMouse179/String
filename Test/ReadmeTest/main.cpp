#define SYSTEM_STRING_CONSOLE
#include "String.hpp"
using namespace System;

int main()
{
    //String::Format 1:
    std::string version = StringA::Format("String {0}.{1}.{2}",
        SYSTEM_STRING_VERSION_MAJOR, SYSTEM_STRING_VERSION_MINOR, SYSTEM_STRING_VERSION_PATCH);
    Console::WriteLine(version, 255, 45, 145);

    //String::Format 2:
    std::string format = StringA::Format("My name is {0}, I am {1} years old.", "Nora", 20);
    Console::WriteLine(format);

    //String::Split:
    auto split = StringA::Split("Maomao and Shushu", " ");
    for (int i = 0; i < split.size(); i++)
    {
        if (i == split.size() - 1)
            Console::Write(split[i] + "\n");
        else
            Console::Write(split[i] + "    ");
    }

    //String::To_UTF8:
    std::string utf8_string = StringA::To_UTF8(L"你好世界😄");
    Console::WriteLine(utf8_string);

    //String::UTF8CharCount:
    int charCount = StringA::UTF8CharCount(U8("你好世界😄"));
    Console::WriteLine(StringA::Format("char count : {0}", charCount));

    return 0;
}