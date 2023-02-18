# String 1.30.0

[中文](https://github.com/CodeMouse179/String/blob/main/Doc/README_CN.md)

[Reference](https://github.com/CodeMouse179/String/blob/main/Doc/README.md)

System.String in C++

Platform : Windows, Linux, macOS

C++ Minimum required version : C++ 11

### Introduce

String.hpp is a System.String (C#) implemented in C++. The purpose is to provide C++ programmers with convenient and reliable string manipulation functions.

It supports multiple character types by manipulating std::basic_string: char, wchar_t, char8_t, char16_t , char32_t.

String.hpp is distributed as a single header file and it is very simple to use:

1. Copy String.hpp into your project

2. #include "String.hpp"

### Compile and Run Example

Windows : Open String.sln with VisualStudio and click Windows Debugger

Linux, macOS : cmake . && make && ./ss

### Macros

Header infomation macros:

    SYSTEM_STRING_HPP

    SYSTEM_STRING_VERSION_MAJOR

    SYSTEM_STRING_VERSION_MINOR

    SYSTEM_STRING_VERSION_PATCH

    SYSTEM_STRING_VERSION

    SYSTEM_STRING_VERSION_STRING

Platform macros:

    SYSTEM_WINDOWS

    SYSTEM_LINUX

    SYSTEM_MACOS

    SYSTEM_POSIX(Linux, macOS)

Language macros:

    SYSTEM_CXX

    SYSTEM_CXX_11

    SYSTEM_CXX_14

    SYSTEM_CXX_17

    SYSTEM_CXX_20

You can define these macros before include String.hpp:

    SYSTEM_STRING_ONLY(Disable extra functions)

    SYSTEM_STRING_SET_UTF8(Change execution character set to UTF8, only effects on Windows)

    SYSTEM_STRING_CONSOLE(Enable console functions)

### String API Tutorial

Include String.hpp:

``` cpp
#include "String.hpp"
using namespace System; //optional
```

String::Format example:

``` cpp
//output: a:2:3
std::string format1 = StringA::Format("{0}:{1}:{2}", (char)97, 2, 3);

//output: 97:2:3
std::string format2 = StringA::Format("{0}:{1}:{2}", 97, 2, 3);
```

String::Split example:

``` cpp
//vector values:1,2,3
std::vector<std::string> split1 = StringA::Split("1 2 3", ' ');
```

### Console API Tutorial

Enable console function support:

``` cpp
#define SYSTEM_STRING_CONSOLE
#include "String.hpp"
using namespace System; //optional
```

### Example 1

``` cpp
//(Optional) Only valid for Windows, let runtime strings be encoded in UTF-8 format
#define SYSTEM_STRING_SET_UTF8
#include "String.hpp"
int main()
{
    //Get the current version of String.hpp:
    int major = SYSTEM_STRING_VERSION_MAJOR;
    int minor = SYSTEM_STRING_VERSION_MINOR;
    int patch = SYSTEM_STRING_VERSION_PATCH;

    //Get an empty string of type char:
    std::string empty = System::String<char>::Empty();
    //Get an empty string of type char by using the StringA macro:
    std::string emtpyA = StringA::Empty();

    //Get an empty string of type wchar_t:
    std::wstring empty2 = System::String<wchar_t>::Empty();
    //Get an empty string of type wchar_t by using the StringW macro:
    std::wstring empty2W = StringW::Empty();

    //Get an empty string of type char16_t:
    std::u16string empty3 = System::String<char16_t>::Empty();
    //Get an empty string of type char16_t by using the StringU16 macro:
    std::u16string empty3U16 = StringU16::Empty();

    //Get an empty string of type char32_t:
    std::u32string empty4 = System::String<char32_t>::Empty();
    //Get an empty string of type char32_t by using the StringU32 macro:
    std::u32string empty4U32 = StringU32::Empty();

    return 0;
}
```

### Example 2

``` cpp
    //String::Format, output:"Anna is your Wife."
    std::string format_str = System::String<char>::Format("{0} is your {1}.", "Anna", "Wife");

    //String::StringToWstring, output:L"Hello World"(on Windows) or "Hello World"(on Linux)
    System::tstring hello_world = System::String<char>::StringToWstring(U8("Hello World"), System::StringEncoding::UTF8);
    
    //String::WstringToString, output:"Hello World"
    std::string hello_world2 = System::String<char>::WstringToString(T("Hello World"), System::StringEncoding::UTF8);
    
    //String::IsValidUTF8, output:true
    bool is_utf8_str = System::String<char>::IsValidUTF8(U8("你好世界"));

    //String::UTF8CharCount, output:7
    int count = System::String<char>::UTF8CharCount(U8("你好世界123"));

```