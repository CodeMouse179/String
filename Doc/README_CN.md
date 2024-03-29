# String 1.35.0 CN

[英文](https://github.com/CodeMouse179/String/blob/main/README.md)

[参考](https://github.com/CodeMouse179/String/blob/main/Doc/README.md)

System.String的C++实现

平台 : Windows, Linux, macOS

C++最低要求版本 : C++ 11

### 介绍

String.hpp是用C++实现的System.String(C#)，目的是为C++程序员提供方便可靠的字符串操作函数。

通过操作std::basic_string从而支持多种字符类型：char，wchar_t，char8_t，char16_t，char32_t。

String.hpp通过单个头文件的形式分发，它使用起来非常简单：

1. 将String.hpp复制到你的项目中

2. #include "String.hpp"

### 编译并运行示例

Windows：用VisualStudio打开String.sln，点击本地Windows调试器即可

Linux：cmake . && make && ./ss

### 宏

头文件宏:

    SYSTEM_STRING_HPP

    SYSTEM_STRING_VERSION_MAJOR

    SYSTEM_STRING_VERSION_MINOR

    SYSTEM_STRING_VERSION_PATCH

    SYSTEM_STRING_VERSION

    SYSTEM_STRING_VERSION_STRING

平台宏:

    SYSTEM_WINDOWS

    SYSTEM_LINUX

    SYSTEM_MACOS

    SYSTEM_POSIX(Linux, macOS)

语言宏:

    SYSTEM_CXX

    SYSTEM_CXX_11

    SYSTEM_CXX_14

    SYSTEM_CXX_17

    SYSTEM_CXX_20

你可以在引用String.hpp之前定义以下宏:

    SYSTEM_STRING_ONLY(禁用额外函数)

    SYSTEM_STRING_SET_UTF8(将运行时字符集设置为utf-8，仅在Windows平台生效)

    SYSTEM_STRING_CONSOLE(启用控制台函数)

### String API 教程

引用String.hpp:

``` cpp
#include "String.hpp"
using namespace System; //可选项
```

String::Format示例:

``` cpp
//output: a:2:3
std::string format1 = StringA::Format("{0}:{1}:{2}", (char)97, 2, 3);

//output: 97:2:3
std::string format2 = StringA::Format("{0}:{1}:{2}", 97, 2, 3);
```

String::Split示例:

``` cpp
//vector values:1,2,3
std::vector<std::string> split1 = StringA::Split("1 2 3", ' ');
```

### 控制台 API 教程

启用控制台函数支持:

``` cpp
#define SYSTEM_STRING_CONSOLE
#include "String.hpp"
using namespace System; //可选项
```

### 示例1

``` cpp
//（可选项）仅对Windows生效，让运行时字符串以UTF-8格式编码
#define SYSTEM_STRING_SET_UTF8
#include "String.hpp"
int main()
{
    //获得String.hpp当前版本：
    int major = SYSTEM_STRING_VERSION_MAJOR;
    int minor = SYSTEM_STRING_VERSION_MINOR;
    int patch = SYSTEM_STRING_VERSION_PATCH;

    //获得char类型组成的空字符串：
    std::string empty = System::String<char>::Empty();
    //通过使用StringA宏，获得char类型组成的空字符串：
    std::string emtpyA = StringA::Empty();

    //获得wchar_t类型组成的空字符串：
    std::wstring empty2 = System::String<wchar_t>::Empty();
    //通过使用StringW宏，获得wchar_t类型组成的空字符串：
    std::wstring empty2W = StringW::Empty();

    //获得char16_t类型组成的空字符串：
    std::u16string empty3 = System::String<char16_t>::Empty();
    //通过使用StringU16宏，获得char16_t类型组成的空字符串：
    std::u16string empty3U16 = StringU16::Empty();

    //获得char32_t类型组成的空字符串：
    std::u32string empty4 = System::String<char32_t>::Empty();
    //通过使用StringU32宏，获得char32_t类型组成的空字符串：
    std::u32string empty4U32 = StringU32::Empty();

    return 0;
}
```

### 示例2

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