# String

[英文](https://github.com/CodeMouse179/String/blob/main/README.md)

System.String的C++实现

版本 : 1.5.0

平台 : Windows, Linux, macOS(未测试)

C++最低版本要求 : C++11

### 介绍

String.hpp是用C++实现的System.String(C#)，目的是为C++程序员提供方便可靠的字符串操作函数，通过操作std::basic_string从而支持多种字符类型：char，wchar_t，char8_t，char16_t，char32_t。

String.hpp通过单个头文件的形式分发，它使用起来非常简单：

1. 将String.hpp复制到你的项目中

2. #include "String.hpp"

### 示例

``` cpp
    //String::Format, output:Anna is your Wife.
    std::string format_str = System::String<char>::Format("{0} is your {1}.", "Anna", "Wife");

    //String::StringToWstring, output:L"Hello World"(on Windows) or "Hello World"(on Linux)
    System::tstring hello_world = System::String<char>::StringToWstring(U8("Hello World"), System::StringEncoding::UTF8);
    
    //String::WstringToString, output:"Hello World"
    std::string hello_world2 = System::String<char>::WstringToString(T("Hello World"), System::StringEncoding::UTF8);
    
    //String::IsValidUTF8, output:true
    bool is_utf8_str = System::String<char>::IsValidUTF8(U8("你好世界"));

```