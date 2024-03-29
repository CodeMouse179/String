﻿// Example of String.hpp
// Programmer : CodeMouse179
// Platform : Windows, Linux, macOS

#define SYSTEM_STRING_CONSOLE
#include "String.hpp"   //System.String in C++
#include <assert.h>     //assert
#include <string.h>     //strcpy_s
#include <iostream>     //std::cin, std::cout, std::wcout
#include <locale.h>     //setlocale(ONLY FOR TUTORIAL, NEVER USE SETLOCALE IN ANY WHERE!!!)

void write(const std::string& s)
{
    std::cout << s;
}

void write_line()
{
    std::cout << "\n";
}

void write_line(const std::string& s)
{
    std::cout << s << "\n";
}

void wait(float second)
{
#ifdef SYSTEM_WINDOWS
    Sleep(second * 1000);
#endif
#ifdef SYSTEM_POSIX
    usleep(second * 1000 * 1000);
#endif
}

int format_tutorial()
{
    //output: a:2:3
    std::string format1 = StringA::Format("{0}:{1}:{2}", (char)97, 2, 3);
    //output: 97:2:3
    std::string format2 = StringA::Format("{0}:{1}:{2}", 97, 2, 3);
    return 0;
}

int split_tutorial()
{
    //vector values:1,2,3
    std::vector<std::string> split1 = StringA::Split("1 2 3", ' ');
    return 0;
}

int str_to_wstr_tutorial()
{
    System::tstring ts = StringA::StringToWstring("----- 你好世界 -----", System::StringEncoding::ANSI);
#ifdef SYSTEM_WINDOWS
    setlocale(LC_ALL, ""); //This is required in Windows if you will invoke std::wcout
    std::wcout << ts << L"\n";
#endif
#ifdef SYSTEM_LINUX
    std::cout << ts << "\n";
#endif
    return 0;
}

int wstr_to_str_tutorial()
{
    std::string s = StringA::WstringToString(T("----- 世界你好 -----"), System::StringEncoding::ANSI);
    std::cout << s << "\n"; //Output ANSI Encoding string by default
    return 0;
}

int readline_ex_tutorial()
{
    Console::WriteLine(U8("readline_ex_tutorial started."), 179, 116, 69);
    StringA::WriteLine(U8("请输入你的名字(Please input your name):"));
    std::string readLineExString1 = StringA::ReadLineEx();
    StringA::WriteLine(U8("你好!") + readLineExString1);
    //System::tstring readLineExTstring1 = StringA::StringToWstring(readLineExString1, System::StringEncoding::UTF8);
    Console::WriteLine(U8("readline_ex_tutorial finished."), 179, 116, 69);
    return 0;
}

int key_available_tutorial()
{
    StringA::WriteLine(U8("key_available_tutorial enter."));
    const float sec = 0.05f;
    while (true)
    {
        if (StringA::KeyAvailable())
        {
            System::BuiltInConsoleKey key = StringA::ReadKey();
            if (key.CodePoint == 'q' || key.CodePoint == 'Q')
            {
                break;
            }
        }
        wait(sec);
    }
    return 0;
}

int get_window_size()
{
    int width = StringA::WindowWidth();
    int height = StringA::WindowHeight();
    StringA::WriteLine(U8("Terminal window width:") + StringA::ToString(width));
    StringA::WriteLine(U8("Terminal window height:") + StringA::ToString(height));
    return 0;
}

int init_deinit_console()
{
    StringA::InitConsole();
    StringA::SetCursorPosition(4, 2);
    StringA::WriteLine(U8("Hello World!"));
    StringA::WriteLine(U8("press Enter continue..."));
    StringA::ReadLine();
    StringA::DeinitConsole();
    return 0;
}

int key_available_test()
{
    while (true)
    {
        if (StringA::KeyAvailable())
        {
            std::string line;
            std::cin >> line;
            std::cout << "Hello\n" << line;
        }
        wait(0.1f);
    }
    return 0;
}

int readme_example()
{
    return 0;
}

int console_example()
{
    Console::InitConsole();
    Console::SetCursorPosition(4, 2);
    Console::WriteLine(U8("Console Example:"));
    Console::WriteLineU8(U8("你好世界😄"));
    Console::WriteLine(1);
    Console::ReadLine();
    Console::DeinitConsole();
    return 0;
}

int system_string_example()
{
    Console::WriteLine(U8("system_string_example starts!"), 198, 251, 19);
    System::string str;
    std::string test = "test";
    System::string a = test;        // impl constructor2
    test = a;                       // impl implicit convert
    Console::WriteLine(a);          // impl operator <<
    Console::WriteLine(a.Length()); // length of System::string
    char ch = a[0];                 // impl operator []
    Console::WriteLine(ch);
    System::string b = a.Clone();   // clone
    a = "a";                        // impl constructor3
    Console::WriteLine(b);
    int compare = a.CompareTo(b);
    Console::WriteLine(StringA::Format("compare : {}", compare));
    bool contains1 = a.Contains('A', System::StringComparison::None);
    bool contains2 = a.Contains('A', System::StringComparison::IgnoreCase);
    Console::WriteLine(contains1);
    Console::WriteLine(contains2);
    bool ends_with1 = a.EndsWith('a');
    bool ends_with2 = a.EndsWith('A');
    bool ends_with3 = a.EndsWith('a', System::StringComparison::IgnoreCase);
    bool ends_with4 = a.EndsWith('A', System::StringComparison::IgnoreCase);
    bool ends_with5 = a.EndsWith("a");
    bool ends_with6 = a.EndsWith("A");
    bool ends_with7 = a.EndsWith("a", System::StringComparison::IgnoreCase);
    bool ends_with8 = a.EndsWith("A", System::StringComparison::IgnoreCase);
    bool eq1 = a.Equals("a");
    bool eq2 = a.Equals("A");
    bool eq3 = a.Equals("a", System::StringComparison::IgnoreCase);
    bool eq4 = a.Equals("A", System::StringComparison::IgnoreCase);
    System::string hash_string1 = "abcdefg";
    System::string hash_string2 = "ABCDEFG";
    int hash1 = hash_string1.GetHashCode();
    int hash2 = hash_string2.GetHashCode();
    int hash3 = hash_string1.GetHashCode(System::StringComparison::IgnoreCase);
    int hash4 = hash_string2.GetHashCode(System::StringComparison::IgnoreCase);
    bool starts_with1 = a.StartsWith('a');
    bool starts_with2 = a.StartsWith('A');
    bool starts_with3 = a.StartsWith('a', System::StringComparison::IgnoreCase);
    bool starts_with4 = a.StartsWith('A', System::StringComparison::IgnoreCase);
    bool starts_with5 = a.StartsWith("a");
    bool starts_with6 = a.StartsWith("A");
    bool starts_with7 = a.StartsWith("a", System::StringComparison::IgnoreCase);
    bool starts_with8 = a.StartsWith("A", System::StringComparison::IgnoreCase);
    Console::WriteLine(U8("system_string_example ends!"), 198, 251, 19);
    return 0;
}

int system_string_copy_to_example()
{
    using namespace System;
    string a = TEXT("nihao");
    char buffer[20] { 0 };
    a.CopyTo(0, buffer, 0, a.Length());
    Console::WriteLine(buffer, 255, 0, 0);
    return 0;
}

int main()
{
    //CopyTo:
    system_string_copy_to_example();

    std::string __string__ = System::format<char>("Hello, {}", "World!");
    write_line(__string__);

    //system string example:
    system_string_example();
    return 0;

    //TEXT:
    std::string text = TEXT("你好世界😄😄");
    Console::WriteLine(text);

    //Intro:
    Console::WriteLine(U8("String.hpp ") + std::string(U8(SYSTEM_STRING_VERSION_STRING)), 255, 45, 145);

    //console example:
    console_example();

    //key_available_tutorial();
    //return 0;

    //tutorials:
    //int r0 = init_deinit_console();

    int readme_example_result = readme_example();

    int r1 = format_tutorial();

    int r2 = split_tutorial();

    int r3 = str_to_wstr_tutorial();

    int r4 = wstr_to_str_tutorial();

    //U8c Test:
    char u8c = U8c('a');
#ifdef SYSTEM_CXX_20
    char8_t u8cc = U8c('b');
#endif

    //String Equals Testing:
    std::string ansi_latin = "ABCD";
    std::string utf8_latin = U8("ABCD");
    bool latin_equals1 = StringA::Equals(ansi_latin, utf8_latin);

    std::string ansi_chinese = "你好世界";
    std::string utf8_chinese = U8("你好世界");
    std::string ansi_utf8_chinese = StringA::ConvertString(ansi_chinese, System::StringEncoding::ANSI, System::StringEncoding::UTF8);
    std::string wide_char_utf8_chinese = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    bool chinese_equals1 = StringA::Equals(ansi_chinese, utf8_chinese);
    bool chinese_equals2 = StringA::Equals(ansi_utf8_chinese, utf8_chinese);
    bool chinese_equals3 = StringA::Equals(wide_char_utf8_chinese, utf8_chinese);

    //测试修改不同字符串的字符:
    const char* utf8ConstBuf = U8s("你好世界");
    char utf8Buf[100] = { 0 };
#ifdef SYSTEM_WINDOWS
    strcpy_s(utf8Buf, U8s("你好世界"));          //使用C语言的方式给字符串数组赋值
#else
    strcpy(utf8Buf, U8s("你好世界"));            //使用C语言的方式给字符串数组赋值
#endif
    utf8Buf[0] = 'a';                           //修改UTF-8字符串, 修改之后字符串已经损坏，不可读取
    wchar_t buf[10] = L"你好世界";               //L"你好世界"
    buf[0] = L'a';                              //L"a好世界"

    //不同字符串的遍历与转换:
    std::u32string nihaoshijieU32 = U"ABCD你好世界!";
    std::wstring nihaoshijieW;
    for (int i = 0; i < nihaoshijieU32.size(); i++)
    {
        nihaoshijieW.push_back((wchar_t)nihaoshijieU32[i]);
    }
    std::string nihaoshijieU8 = StringA::To_UTF8(nihaoshijieW);
    StringA::WriteLine(nihaoshijieU8, 255, 140, 0);

    //char, wchar_t, char16_t, char32_t Testing:
    //不同类型的char储存ASCII以外的字符时，只要不发生数值越界，其值相同。
    //注意：不要使用char类型储存ASCII字符以外的文字。

    char ascii1 = 'a';           //value:97
    wchar_t ascii2 = L'a';       //value:97
    char16_t ascii3 = u'a';      //value:97
    char32_t ascii4 = U'a';      //value:97
    int asciiInt1 = 97;          //value:97

    assert(ascii1 == ascii2);    //OK!
    assert(ascii2 == ascii3);    //OK!
    assert(ascii3 == ascii4);    //OK!
    assert(ascii4 == asciiInt1); //OK!

#ifndef SYSTEM_MACOS
    char ch1 = '你';             //data value overflow!
#endif

    wchar_t ch2 = L'你';         //Unicode value:20320
    char16_t ch3 = u'你';        //Unicode value:20320
    char32_t ch4 = U'你';        //Unicode value:20320
    int ni1 = 20320;             //value:20320

    //assert(ch1 == ch2);       //assert error!
    assert(ch2 == ch3);         //OK!
    assert(ch3 == ch4);         //OK!
    assert(ch4 == ni1);         //OK!

#ifndef SYSTEM_MACOS
    char _ch1 = '🧐';            //data value overflow!
#endif

    wchar_t _ch2 = L'🧐';        //data value overflow!
    //char16_t _ch3 = u'🧐';     //compile error!
    char32_t _ch4 = U'🧐';       //Unicode value:129488
    int wen1 = 129488;           //value:129488

    //assert(_ch1 == _ch2);     //assert error!
#ifdef SYSTEM_LINUX
    assert(_ch2 == _ch4);       //Windows assert error, Linux OK!
#endif
    assert(_ch4 == wen1);       //OK!

    //获得char类型组成的空字符串：
    std::string empty = System::String<char>::Empty;
    //通过使用StringA宏，获得char类型组成的空字符串：
    std::string emtpyA = StringA::Empty;

    //获得wchar_t类型组成的空字符串：
    std::wstring empty2 = System::String<wchar_t>::Empty;
    //通过使用StringW宏，获得wchar_t类型组成的空字符串：
    std::wstring empty2W = StringW::Empty;

    //获得char16_t类型组成的空字符串：
    std::u16string empty3 = System::String<char16_t>::Empty;
    //通过使用StringU16宏，获得char16_t类型组成的空字符串：
    std::u16string empty3U16 = StringU16::Empty;

    //获得char32_t类型组成的空字符串：
    std::u32string empty4 = System::String<char32_t>::Empty;
    //通过使用StringU32宏，获得char32_t类型组成的空字符串：
    std::u32string empty4U32 = StringU32::Empty;

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

    int version_major = SYSTEM_STRING_VERSION_MAJOR;
    int version_minor = SYSTEM_STRING_VERSION_MINOR;
    int version_patch = SYSTEM_STRING_VERSION_PATCH;
    int version = SYSTEM_STRING_VERSION;
    std::string version_string = U8(SYSTEM_STRING_VERSION_STRING);
    StringA::WriteLine(U8("String.hpp version_major:") + StringA::ToString(version_major));
    StringA::WriteLine(U8("String.hpp version_minor:") + StringA::ToString(version_minor));
    StringA::WriteLine(U8("String.hpp version_patch:") + StringA::ToString(version_patch));
    StringA::WriteLine(U8("String.hpp version:") + StringA::ToString(version));
    StringA::WriteLine(U8("String.hpp version_string:") + version_string);
    System::tstring s = StringT::Empty;
    char string_chars = StringA::Chars("ABCDEFG", 5);
    int string_length = StringA::Length("ABCDEFG");
    StringA::WriteLine(U8("string_chars:") + StringA::ToString(string_chars));
    StringA::WriteLine(U8("string_length:") + StringA::ToString(string_length));
    std::string clone = StringA::Clone("ABC123");
    int compare = StringA::Compare("a1", "1a");
    int compare2 = StringA::Compare("A1", "a1", System::StringComparison::IgnoreCase);
    int compare3 = StringA::Compare("A1", "a1", true);
    StringA::WriteLine(U8("compare3:") + StringA::ToString(compare3));
    std::string con = StringA::Concat("ABC", "123");
    std::vector<std::string> values;
    values.push_back("A1");
    values.push_back("B2");
    values.push_back("C3");
    std::string con2 = StringA::Concat(values);
    std::string con3 = StringA::Concat("A1", "B2", "C3", "D4", "E5", "F6", "G7");
    bool contains = StringA::Contains("ABC123", "C12");
    bool contains2 = StringA::Contains("ABC123", "c12", System::StringComparison::IgnoreCase);
    bool contains3 = StringA::Contains("ABC123", 'a');
    bool contains4 = StringA::Contains("ABC123", 'a', System::StringComparison::IgnoreCase);
    std::string copy = StringA::Copy("ABCD你好呀");
    bool endWith1 = StringA::EndsWith("ABCDEFG", "EFg");
    bool endWith2 = StringA::EndsWith("ABCDEFG", "EFg", System::StringComparison::IgnoreCase);
    bool endWith3 = StringA::EndsWith("ABCDEFG", 'g');
    bool endWith4 = StringA::EndsWith("ABCDEFG", 'g', System::StringComparison::IgnoreCase);
    bool eq1 = StringA::Equals("abc", "ABC");
    bool eq2 = StringA::Equals("abc", "ABC", System::StringComparison::IgnoreCase);
    std::string format = StringA::Format("{0} name is {1}.", "My", "ABC");
    std::string format2 = StringA::Format("");
    int hash = StringA::GetHashCode("ABC123");
    int hash1 = StringA::GetHashCode("ABC123", System::StringComparison::IgnoreCase);
    int hash2 = StringA::GetHashCode("abc123", System::StringComparison::IgnoreCase);
    int typeCode = StringA::GetTypeCode();
    int index1 = StringA::IndexOf("123456", "3");
    int index2 = StringA::IndexOf("123456", '3');
    int index11 = StringA::IndexOf("ABCDEFG", "d", System::StringComparison::IgnoreCase);
    int index111 = StringA::IndexOf("ABCDEFG", "d", System::StringComparison::None);
    int index22 = StringA::IndexOf("ABCDEFG", 'd', System::StringComparison::IgnoreCase);
    int index222 = StringA::IndexOf("ABCDEFG", 'd', System::StringComparison::None);
    std::vector<char> anyOf1 = { 'E', 'F', 'G' };
    int indexOfAny1 = StringA::IndexOfAny("ABCDEFG", anyOf1);
    std::string insert_str1 = StringA::Insert("ABCDEFG", 4, "OPQ");
    std::string insert_str2 = StringA::Insert("ABCDEFG", 4, 'Q');
    bool isNullOrEmpty = StringA::IsNullOrEmpty("");
    bool isNullOrWhiteSpace = StringA::IsNullOrWhiteSpace("  ");
    StringA::WriteLine(U8("isNullOrEmpty:") + StringA::ToString(isNullOrEmpty));
    StringA::WriteLine(U8("isNullOrWhiteSpace:") + StringA::ToString(isNullOrWhiteSpace));
    std::string join_str1 = StringA::Join(" ", { "A", "B", "C", "D" });
    std::string join_str2 = StringA::Join(' ', { "A", "B", "C", "D" });
    std::string join_str3 = StringA::Join("B", "M", 1);
    std::string join_str4 = StringA::Join('B', 'M', 2);
    Console::WriteLine("Join str:" + join_str3);
    Console::WriteLine("Join chr:" + join_str4);
    int index3 = StringA::LastIndexOf("654321", "1");
    int index4 = StringA::LastIndexOf("654321", '1');
    int index33 = StringA::LastIndexOf("ABCDEFG", "b", System::StringComparison::IgnoreCase);
    int index333 = StringA::LastIndexOf("ABCDEFG", "b", System::StringComparison::None);
    int index44 = StringA::LastIndexOf("ABCDEFG", 'b', System::StringComparison::IgnoreCase);
    int index444 = StringA::LastIndexOf("ABCDEFG", 'b', System::StringComparison::None);
    std::vector<char> anyOf2 = { 'E', 'F', 'G' };
    int lastIndexOfAny1 = StringA::LastIndexOfAny("ABCDEFG", anyOf2);
    //pad left:
    std::string padLeft1 = StringA::PadLeft("1", 10, 'a');
    StringA::WriteLine(U8("padLeft1 :") + padLeft1);
    //pad right:
    std::string padRight1 = StringA::PadRight("1", 10, 'a');
    StringA::WriteLine(U8("padRight1:") + padRight1);
    std::string remove1 = StringA::Remove("ABCDEFG", 2);
    std::string remove2 = StringA::Remove("ABCDEFG", 2, 3);
    std::string replace1 = StringA::Replace("ABCD", "C", "");
    std::string replace2 = StringA::Replace("ABCD", 'C', 0);
    std::string replace3 = StringA::Replace("ABCD", "c", "", System::StringComparison::IgnoreCase);
    std::string replace4 = StringA::Replace("ABCD", "c", "", System::StringComparison::None);
    std::string replace33 = StringA::Replace("ABCD", 'c', 0, System::StringComparison::IgnoreCase);
    std::string replace44 = StringA::Replace("ABCD", 'c', 0, System::StringComparison::None);
    std::string replaceLineEndings1 = StringA::ReplaceLineEndings("nihao, shijie\n!!!\n你好世界\n!!!");
    std::string replaceLineEndings2 = StringA::ReplaceLineEndings("nihao, shijie\r\n!!!\r\n你好世界\r\n!!!");
    auto reversed_stra = StringA::Reverse(U8("你好世界"));
    auto reversed_stra2w = StringA::StringToWstring(reversed_stra, System::StringEncoding::UTF8);
    auto reversed_stra2 = StringA::Reverse(S("你好世界ABCD"));
    auto reversed_stra22w = StringA::StringToWstring(reversed_stra2, System::StringEncoding::ANSI);
    auto reversed_strw = StringA::Reverse(W("你好世界"));
#ifdef SYSTEM_CXX_20
    auto reversed_stru8 = StringA::Reverse(U8S("你好世界"));
#endif
    auto reversed_stru16 = StringA::Reverse(U16("你好世界"));
    auto reversed_stru32 = StringA::Reverse(U32("你好世界"));
    std::string slice1 = StringA::Slice("123", 1);
    std::string slice2 = StringA::Slice("123", -1);
    std::string slice3 = StringA::Slice("123", 0, 2);
    std::string slice4 = StringA::Slice("123", 0, -1);
    std::string slice5 = StringA::Slice("123", 0, 0);
    auto vector1 = StringA::Split("A B C 1 2 3", " ");
    auto vector2 = StringA::Split("A B C 1 2 3", "");
    auto vector3 = StringA::Split("A B C 1 2 3", ' ');
    bool startsWith1 = StringA::StartsWith("ABCDEFG", "ABc");
    bool startsWith2 = StringA::StartsWith("ABCDEFG", "ABc", System::StringComparison::IgnoreCase);
    std::string subStr1 = StringA::Substring("ABCDEFG", 1);
    std::string subStr2 = StringA::Substring("ABCDEFG", 0, 2);
    bool toBoolean1 = StringA::ToBoolean("True");
    bool toBoolean2 = StringA::ToBoolean("true", System::StringComparison::IgnoreCase);
    std::vector<char> charArray1 = StringA::ToCharArray("ABCDEFG");
    std::vector<char> charArray2 = StringA::ToCharArray("ABCDEFG", 5, 2);
    int toInt32_1 = StringU32::ToInt32(U32("65001"));
    std::string lower = StringA::ToLower("ABCDEFG");
    auto to_lower = StringU32::ToLower(U32('N'));
    std::string to_string1 = StringA::ToString("你好世界");
#ifndef SYSTEM_MACOS
    std::string to_string2 = StringA::ToString('你');
#endif
    std::wstring to_string3 = StringW::ToString(W('你'));
    std::string to_string4 = StringA::ToString(999);
    auto to_string5 = StringW::ToString(false);
    std::string upper = StringA::ToUpper("abcdefg");
    auto to_upper = StringU32::ToUpper(U32('n'));
    std::string trimStrS1 = StringA::Trim("你好世界你", "你");
    std::string trimStr = StringA::Trim("111", '1');
    std::wstring _trimStr = StringW::Trim(W(" 你好世界 "));
    std::string trimStrS2 = StringA::TrimEnd("你好世界你", "你");
    std::string trimStr1 = StringA::TrimEnd(" ABC ", ' ');
    std::wstring _trimStr1 = StringW::TrimEnd(W(" 你好世界 "));
    std::string trimStrS3 = StringA::TrimStart("你好世界你", "你");
    std::string trimStr2 = StringA::TrimStart(" ABC ", ' ');
    std::wstring _trimStr2 = StringW::TrimStart(W(" 你好世界 "));
    System::tstring wstr1 = StringA::StringToWstring("你好世界", System::StringEncoding::ANSI);
    System::tstring wstr2 = StringA::StringToWstring(U8("你好世界"), System::StringEncoding::UTF8);
    std::string str1 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ANSI);
    std::string str2temp = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    System::tstring wstr3 = StringA::StringToWstring2("你好世界😄");
    System::tstring wstr4 = StringA::StringToWstring2(U8("你好世界😄"));
    std::string str3 = StringA::WstringToString2(T("你好世界😄"));
    System::tstring wstr5 = StringA::StringToWstring2(str3);
    System::u8str str2 = StringA::StringToU8string(str2temp);
    std::u16string u16 = U16("你好世界");
    std::u32string u32 = U32("你好世界");
    std::string s1 = StringA::To_UTF8(U16("你好世界"));
    std::string s2 = StringA::To_UTF8(U32("你好世界"));
    std::string s3 = StringA::To_UTF8(W("你好世界"));
    std::u16string us1 = StringA::To_UTF16(U8("你好世界"));
    std::u16string us2 = StringA::To_UTF16(U32("你好世界"));
    std::u16string us3 = StringA::To_UTF16(W("你好世界"));
    std::u32string Us1 = StringA::To_UTF32(U8("你好世界"));
    std::u32string Us2 = StringA::To_UTF32(U16("你好世界"));
    std::u32string Us3 = StringA::To_UTF32(W("你好世界"));
    std::string utf8_str = StringA::To_String(W("你好世界"));
    std::wstring wide_str1 = StringA::To_Wstring(utf8_str);
    std::wstring wide_str2 = StringA::To_Wstring(U8("你好世界"));

    auto zxcxz = StringA::ConvertString(U8("你好世界"), System::StringEncoding::UTF8, (System::StringEncoding)950);
    auto xczzz = StringA::StringToWstring(zxcxz, (System::StringEncoding)950);

    //Extra Util 1:
    bool IsValidASCII1 = StringA::IsValidASCII(S("ABCD"));
    bool IsValidASCII2 = StringA::IsValidASCII(S("你好世界"));

    int ASCIICharCount1 = StringA::ASCIICharCount(S("ABCD"));
    int ASCIICharCount2 = StringA::ASCIICharCount(S("你好世界"));

    auto ASCIIToCharArray1 = StringA::ASCIIToCharArray(S("ABCD"));
    auto ASCIIToCharArray2 = StringA::ASCIIToCharArray(S("你好世界"));

    std::string codePointToASCII1 = StringA::CodePointToASCII(ASCIIToCharArray1);
    std::string codePointToASCII2 = StringA::CodePointToASCII(ASCIIToCharArray2);

    bool isUTF8_1 = StringA::IsValidUTF8(U8("你好世界"));
    bool isUTF8_2 = StringA::IsValidUTF8(S("你好世界"));

    int charCount1 = StringA::UTF8CharCount(U8("你好世界ABC123"));
    int charCount2 = StringA::UTF8CharCount(S("你好世界ABC123"));

    //UTF-8 Emoji Test:
    auto utf8CharArray_Vector = StringA::UTF8ToCharArray(U8("😄🙅🦠🤢")); //128516,128581,129440,129314

    auto utf8CharArray1 = StringA::UTF8ToCharArray(U8("你好世界"));
#ifdef SYSTEM_CXX_20
    auto utf8CharArray2 = StringA::UTF8ToCharArray(U8S("你好世界"));
#endif

    std::string codePointToUTF8String1 = StringA::CodePointToUTF8(U32('😄'));
    auto ca = StringA::UTF8ToCharArray(codePointToUTF8String1);
    std::vector<int> codePoints{ U32('😄') };
    std::string codePointToUTF8String2 = StringA::CodePointToUTF8(codePoints);
    std::string codePointToUTF8String3 = StringA::CodePointToUTF8(U32("你好世界"));
    std::string codePointANSIString1 = StringA::ConvertString(codePointToUTF8String3, System::StringEncoding::UTF8, System::StringEncoding::ANSI);

    std::string codePointToUTF8String4 = StringA::CodePointToUTF8(utf8CharArray1);

    bool IsValidUTF16_1 = StringA::IsValidUTF16(T("你好世界"));
    bool IsValidUTF16_2 = StringA::IsValidUTF16(U16("你好世界"));

    int UTF16CharCount_1 = StringA::UTF16CharCount(T("你好世界😄"));
    int UTF16CharCount_2 = StringA::UTF16CharCount(U16("你好世界😄"));

    std::u32string utf32TestChar = U32("你好世界😄");
    auto utf16CharArray1 = StringA::UTF16ToCharArray(T("你好世界😄"));
    auto utf16CharArray2 = StringA::UTF16ToCharArray(U16("你好世界😄"));

    std::u16string codePointToUTF16_1 = StringA::CodePointToUTF16(U32("你好世界"));
    auto charArray = StringA::UTF16ToCharArray(codePointToUTF16_1);
    std::u32string utf32_str1 = StringA::To_UTF32(codePointToUTF16_1);

    std::u16string codePointToUTF16_2 = StringA::CodePointToUTF16(utf16CharArray1);

    //Extra Util 2:
    std::string UTF16String1 = StringA::UTF16ToUTF16String(U16("你好世界"));
    bool IsValidUTF16String1 = StringA::IsValidUTF16String(UTF16String1);
    int UTF16StringCharCount1 = StringA::UTF16StringCharCount(UTF16String1);
    auto UTF16StringToCharArray1 = StringA::UTF16StringToCharArray(UTF16String1);

    //Extra Util 3:
    std::string UTF32String1 = StringA::UTF32ToUTF32String(U32("你好世界"));
    bool IsValidUTF32String1 = StringA::IsValidUTF32String(UTF32String1);
    int UTF32StringCharCount1 = StringA::UTF32StringCharCount(UTF32String1);
    auto UTF32StringToCharArray1 = StringA::UTF32StringToCharArray(UTF32String1);
    std::u32string codePointToUTF321 = StringA::CodePointToUTF32(UTF32StringToCharArray1);

    //Extra Function 1:

    std::string trueStringA = StringA::GetTrueString();
    std::string falseStringA = StringA::GetFalseString();

    std::wstring trueStringW = StringW::GetTrueString();
    std::wstring falseStringW = StringW::GetFalseString();

    std::u16string trueStringU16 = StringU16::GetTrueString();
    std::u16string falseStringU16 = StringU16::GetFalseString();

    std::u32string trueStringU32 = StringU32::GetTrueString();
    std::u32string falseStringU32 = StringU32::GetFalseString();

    bool isNumeric1 = StringA::IsNumeric("123");
    bool isNumeric2 = StringA::IsNumeric("123a");

    bool isEmptyOrWhiteSpace1 = StringA::IsEmptyOrWhiteSpace("   ");
    bool isEmptyOrWhiteSpace2 = StringA::IsEmptyOrWhiteSpace("");
    bool isEmptyOrWhiteSpace3 = StringA::IsEmptyOrWhiteSpace("ABCD");

    void* void2int_void = (void*)22;
    int void2int_result = StringA::Void2Int(void2int_void);
    Console::WriteLine(U8("我今年") + StringA::ToString(void2int_result) + U8("岁"), 169, 119, 197);

    bool number_is_palindrome1 = StringA::IsPalindrome(12321);
    bool number_is_palindrome2 = StringA::IsPalindrome(1);
    bool number_is_palindrome3 = StringA::IsPalindrome(-1);
    bool string_is_palindrome1 = StringA::IsPalindrome("12321");
    bool string_is_palindrome2 = StringA::IsPalindrome("1");
    bool string_is_palindrome3 = StringA::IsPalindrome("");

    int string_to_int1 = StringA::StringTo<int>("123");
    int string_to_bool1 = StringA::StringTo("TRUE", true);
    //int string_to_bool2 = StringA::StringTo("TRUE", false);   //Cause exception here.
    int string_to_bool3 = StringA::StringTo("True", false);
    //int string_to_bool4 = StringA::StringTo("XXX", true);     //Cause exception here.

    //Russian Test:
    //Output:здравствуйте, Expected output:ЗДРАВСТВУЙТЕ
    //TODO:Implement a language-independent ToUpper function
    //不依赖C++提供的函数:toupper与tolower
    std::u32string upperRussian = StringU32::ToUpper(U32("здравствуйте"));

    //Linux Test 1:
    std::wstring linuxTestWstring1 = StringA::StringToWstring(U8("Linux, 你好!"));
    std::string linuxTestString1 = StringA::WstringToString(linuxTestWstring1);
    StringA::WriteLine(linuxTestString1, 0, 255, 0);

    //Linux Test 2:
    std::u32string linuxTestU32string1 = StringA::WstringToU32string(W("Linux, 你还好吗?"));
    std::wstring linuxTestWstring2 = StringA::U32stringToWstring(linuxTestU32string1);
    std::string linuxTestString2 = StringA::WstringToString(linuxTestWstring2);
    StringA::WriteLine(linuxTestString2, 133, 133, 192);

    //StringToWstring/WstringToString Testing:
    //Output:"你好世界"
    std::string errorTest_1 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ANSI);
    //Output:"????"
    std::string errorTest_2 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ASCII);
    //Output:"浣犲ソ涓栫晫"
    std::string errorTest_3 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    //Output:""
    std::string errorTest_4 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF16LE);
    //Output:""
    std::string errorTest_5 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF16BE);
    //Output:""
    std::string errorTest_6 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF32LE);
    //Output:""
    std::string errorTest_7 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF32BE);

    //Emoji Test:
    StringA::WriteLine(U8("😄😄😄😆😆😆"));

    //Get terminal window size:
    get_window_size();

    //Tutorial:
    readline_ex_tutorial();

    //Tutorial:
    //key_available_tutorial();

    //Console Function 1:
    StringA::WriteLine(U8("你好世界!"), 255, 0, 0);
    bool writeSuccess1 = StringA::WriteLine(U8("Please Input Something:"), 255, 255, 255);
    std::string readLine = StringA::ReadLine();
    bool writeSuccess2 = StringA::WriteLine(readLine, 255, 255, 255);
    int readChar = StringA::Read();

    return 0;
}