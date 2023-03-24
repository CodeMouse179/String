# String 1.43.0

[README - 中文](https://github.com/CodeMouse179/String/blob/main/Doc/README_CN.md)

[README - русский](https://github.com/CodeMouse179/String/blob/main/Doc/README_RU.md)

[README - türkçe](https://github.com/CodeMouse179/String/blob/main/Doc/README_TR.md)

## System.String in C++

License : MIT

Platform : Windows, Linux, macOS

C++ Required Version : C++ 11

API Family : [System](https://github.com/CodeMouse179/System)

## Introduction

String.hpp is a System.String (C#) implemented in C++.

The purpose is to provide C++ programmers with convenient and reliable string manipulation functions.

It supports multiple character types by manipulating std::basic_string: char, wchar_t, char8_t, char16_t , char32_t.

## Inspiration

[C# System.String](https://learn.microsoft.com/en-us/dotnet/api/system.string?view=net-8.0)

## Installation

String.hpp is distributed as a single header file so it's easy to install, just follow 2 steps:

1. Copy String.hpp into your project

2. #include "String.hpp"

## Compile and Run Example

Windows : Open String.sln with VisualStudio and click Windows Debugger

Linux, macOS : cmake . && make && ./ss

## Documentation

[Documentation](https://github.com/CodeMouse179/String/blob/main/Doc/README.md)

## Tutorial

``` cpp
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
```

## API Family

* [System](https://github.com/CodeMouse179/System)

* [System.String](https://github.com/CodeMouse179/String)