//     +--------------------------------------------------------------------------------+
//     |                                  String v1.23.0                                |
//     |  Introduction : System.String in C++                                           |
//     |  Modified Date : 2022/12/4                                                     |
//     |  License : MIT                                                                 |
//     |  Source Code : https://github.com/CodeMouse179/String                          |
//     |  Readme : https://github.com/CodeMouse179/String/blob/main/README.md           |
//     |                                                                                |
//     |                             Designer : CodeMouse179                            |
//     |  Email : codemouse179@gmail.com                                                |
//     |  Github : https://github.com/CodeMouse179                                      |
//     |  Bilibili : https://space.bilibili.com/3461577785215838                        |
//     +--------------------------------------------------------------------------------+

#ifndef SYSTEM_STRING_HPP
#define SYSTEM_STRING_HPP

//Versioning refer to Semantic Versioning 2.0.0 : https://semver.org/

#define SYSTEM_STRING_VERSION_MAJOR 1
#define SYSTEM_STRING_VERSION_MINOR 23
#define SYSTEM_STRING_VERSION_PATCH 0
#define SYSTEM_STRING_VERSION (SYSTEM_STRING_VERSION_MAJOR << 16 | SYSTEM_STRING_VERSION_MINOR << 8 | SYSTEM_STRING_VERSION_PATCH)
#define SYSTEM_STRING_VERSION_STRING "1.23.0"

//Windows Platform:
#ifdef _WIN32
#define SYSTEM_WINDOWS 1
#endif
#ifdef WIN32
#define SYSTEM_WINDOWS 1
#endif

//Linux Platform:
#ifdef __linux__
#define SYSTEM_LINUX 1
#endif

//Windows Headers:
#ifdef SYSTEM_WINDOWS
//Enable UNICODE:
#ifndef UNICODE
#define UNICODE
#endif
//Enable _UNICODE:
#ifndef _UNICODE
#define _UNICODE
#endif
#include <Windows.h>
//Disable warnings for MSVC++ 20:
#ifdef _MSC_VER
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif
#endif

//Linux Headers:
#ifdef SYSTEM_LINUX
#include <locale>       //std::wstring_convert
#include <unistd.h>     //read, write, STDIN_FILENO, STDOUT_FILENO
#endif

//CXX version define:
#ifdef SYSTEM_WINDOWS
#if (_MSVC_LANG >= 201103L)
#define SYSTEM_CXX_11 1
#endif
#if (_MSVC_LANG >= 201402L)
#define SYSTEM_CXX_14 1
#endif
#if (_MSVC_LANG >= 201703L)
#define SYSTEM_CXX_17 1
#endif
#endif
#ifdef SYSTEM_LINUX
#if (__cplusplus >= 201103L)
#define SYSTEM_CXX_11 1
#endif
#if (__cplusplus >= 201402L)
#define SYSTEM_CXX_14 1
#endif
#if (__cplusplus >= 201703L)
#define SYSTEM_CXX_17 1
#endif
#endif

#ifdef __cpp_char8_t
#define SYSTEM_CXX_20 1
#endif

#ifdef __SYSTEM_STRING_ONLY
#define SYSTEM_STRING_ONLY
#endif

//C++ Headers:
#include <string>       //std::string, std::wstring, std::basic_string
#include <algorithm>    //std::equal
#include <cctype>       //std::tolower
#include <sstream>      //std::basic_ostringstream
#include <vector>       //std::vector
#include <codecvt>      //wstring_convert, codecvt_utf8, codecvt_utf16, codecvt_utf8_utf16

//Ordinary character System::String class
#define StringA System::String<char>
//Wide-character System::String class
#define StringW System::String<wchar_t>
//UTF-8 character System::String class
#ifdef SYSTEM_CXX_20
#define StringU8 System::String<char8_t>
#else
#define StringU8 System::String<char>
#endif
//UTF-16 character System::String class
#define StringU16 System::String<char16_t>
//UTF-32 character System::String class
#define StringU32 System::String<char32_t>

//Generic System::String class
#ifdef SYSTEM_WINDOWS
#define StringT StringW
#endif
#ifdef SYSTEM_LINUX
#define StringT StringA
#endif

//std::string(Windows Default:ANSI Encoding, Linux Default:UTF-8 Encoding)
#define __S(s) s
#define S(s) __S(s)

//std::wstring
#define __W(s) L##s
#define W(s) __W(s)

//char/char8_t
#ifdef SYSTEM_WINDOWS
#define __U8c(c) u8##c
#define U8c(c) __U8c(c)
#endif
#ifdef SYSTEM_LINUX
//g++ cannot compile u8'c' normally in C++14, requires C++17 or above
#ifdef SYSTEM_CXX_17
#define __U8c(c) u8##c
#define U8c(c) __U8c(c)
#else
#define __U8c(c) c
#define U8c(c) __U8c(c)
#endif
#endif

//const char* str(UTF-8 Encoding)
#ifdef SYSTEM_CXX_20
#define __U8s(s) (reinterpret_cast<const char*>(u8##s))
#define U8s(s) __U8s(s)
#else
#define __U8s(s) u8##s
#define U8s(s) __U8s(s)
#endif

//std::string(UTF-8 Encoding)
#ifdef SYSTEM_CXX_20
#define __U8(s) StringA::U8stringToString(u8##s)
#define U8(s) __U8(s)
#else
#define __U8(s) u8##s
#define U8(s) __U8(s)
#endif

//std::u8string(C++20)
#define __U8S(s) u8##s
#define U8S(s) __U8S(s)

//std::u16string
#define __U16(s) u##s
#define U16(s) __U16(s)

//std::u32string
#define __U32(s) U##s
#define U32(s) __U32(s)

//Windows:wchar_t, Linux:char
#ifdef SYSTEM_WINDOWS
#define T(s) W(s)
#endif
#ifdef SYSTEM_LINUX
#define T(s) s
#endif

//Windows:char/char8_t(C++20), Linux:char
#ifdef SYSTEM_WINDOWS
#define T8(s) U8(s)
#endif
#ifdef SYSTEM_LINUX
#define T8(s) s
#endif

//Specifies the execution character set used for string and character literals.
#ifdef SYSTEM_STRING_SET_UTF8
#ifdef SYSTEM_WINDOWS
#pragma execution_character_set("utf-8")
#endif
#endif

#ifndef TRUE_STRING
#define TRUE_STRING "True"
#endif

#ifndef FALSE_STRING
#define FALSE_STRING "False"
#endif

#ifndef SYSTEM_STRING_INPUT_BUFFER_SIZE
#define SYSTEM_STRING_INPUT_BUFFER_SIZE 1024
#endif

#ifdef SYSTEM_STRING_CONSOLE
#define ESC "\033"   //00011011 = 033 = 27 = 0x1b
#endif

namespace System
{
    //generic types:
#ifdef SYSTEM_WINDOWS
    typedef std::wstring tstring;
    typedef wchar_t tchar;
#endif
#ifdef SYSTEM_LINUX
    typedef std::string tstring;
    typedef char tchar;
#endif

    //CXX20 u8string:
#ifdef SYSTEM_CXX_20
    typedef std::u8string u8str;
    typedef char8_t u8char;
#else
    typedef std::string u8str;
    typedef char u8char;
#endif

    enum class StringComparison
    {
        None = 0,
        IgnoreCase = 10,
    };

    //See:https://learn.microsoft.com/en-us/windows/win32/intl/code-page-identifiers
    enum class StringEncoding
    {
        ANSI = 0,       //CP_ACP(Windows)
        UTF16LE = 1200,
        UTF16BE = 1201,
        UTF32LE = 12000,
        UTF32BE = 12001,
        ASCII = 20127,
        UTF8 = 65001,   //CP_UTF8(Windows)
    };

    struct UnicodeChar
    {
    public:
        int bytes;
        unsigned int codePoint;

        UnicodeChar()
        {
            this->bytes = 0;
            this->codePoint = 0;
        }

        UnicodeChar(int bytes, unsigned int codePoint)
        {
            this->bytes = bytes;
            this->codePoint = codePoint;
        }
    };

    typedef UnicodeChar ASCIIChar;
    typedef UnicodeChar UTF8Char;
    typedef UnicodeChar UTF16Char;
    typedef UnicodeChar UTF32Char;

#ifdef SYSTEM_STRING_CONSOLE
    //Singleton class
    class BuiltInConsole
    {
    private:
        BuiltInConsole()
        {
        }

    private:
        bool inited = false;
        bool success = false;

    public:
        void Init()
        {
            if (!this->inited) this->inited = true;
#ifdef SYSTEM_WINDOWS
            //Get Output Handle:
            HANDLE stdOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            if (stdOutputHandle == INVALID_HANDLE_VALUE) return;

            //Get Console Mode:
            DWORD outputMode;
            BOOL get_output_success = GetConsoleMode(stdOutputHandle, &outputMode);
            if (!get_output_success) return;

            //Turn on ENABLE_VIRTUAL_TERMINAL_PROCESSING flag:
            outputMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

            //Set Console Mode:
            BOOL set_output_success = SetConsoleMode(stdOutputHandle, outputMode);
            if (!set_output_success) return;

            //Get Console Mode again and check if ENABLE_VIRTUAL_TERMINAL_PROCESSING flag is enabled:
            get_output_success = GetConsoleMode(stdOutputHandle, &outputMode);
            if (!get_output_success) return;

            //Set success:
            this->success = (outputMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
#ifdef SYSTEM_LINUX
            this->success = true;
#endif
        }

        bool IsInited()
        {
            return this->inited;
        }

        bool Success()
        {
            return this->success;
        }

    public:
        static BuiltInConsole& Instance()
        {
            static BuiltInConsole instance;
            return instance;
        }
    };
#endif

    template<typename T>
    class String
    {
    private:
        //static class
        String()
        {
        }

    public:
        static std::basic_string<T> Empty()
        {
            return std::basic_string<T>();
        }

    public:
        static std::basic_string<T> Clone(const std::basic_string<T>& s)
        {
            std::basic_string<T> instance = s;
            return instance;
        }

        static int Compare(const std::basic_string<T>& strA, const std::basic_string<T>& strB)
        {
            return strA.compare(strB);
        }

        static int Compare(const std::basic_string<T>& strA, const std::basic_string<T>& strB, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::Compare(String::ToLower(strA), String::ToLower(strB));
            }
            else
            {
                return String::Compare(strA, strB);
            }
        }

        static std::basic_string<T> Concat(const std::basic_string<T>& str0, const std::basic_string<T>& str1)
        {
            return str0 + str1;
        }

        static std::basic_string<T> Concat(const std::vector<std::basic_string<T>>& values)
        {
            std::basic_string<T> str;
            for (const auto& item : values) str += item;
            return str;
        }

        template<typename... Types>
        static std::basic_string<T> Concat(Types... args)
        {
            std::basic_ostringstream<T> boss;
#ifdef SYSTEM_CXX_17
            (String::ConcatHelper(boss, args), ...); //C++17
#else
            int arr[] = { (String::ConcatHelper(boss, args), 0)... }; //C++11
#endif
            return boss.str();
        }

        static bool Contains(const std::basic_string<T>& s, const std::basic_string<T>& value)
        {
            return s.find(value) != std::string::npos;
        }

        static bool Contains(const std::basic_string<T>& s, const std::basic_string<T>& value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::Contains(String::ToLower(s), String::ToLower(value));
            }
            else
            {
                return String::Contains(s, value);
            }
        }

        static std::basic_string<T> Copy(const std::basic_string<T>& str)
        {
            std::basic_string<T> instance = str;
            return instance;
        }

        static bool EndsWith(const std::basic_string<T>& s, const std::basic_string<T>& value)
        {
            if (value.size() > s.size()) return false;
            for (int i = s.size() - value.size(), j = 0; j < value.size(); i++, j++)
            {
                if (s[i] != value[j]) return false;
            }
            return true;
        }

        static bool EndsWith(const std::basic_string<T>& s, const std::basic_string<T>& value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                if (value.size() > s.size()) return false;
                for (int i = s.size() - value.size(), j = 0; j < value.size(); i++, j++)
                {
                    if (String::ToLower(s[i]) != String::ToLower(value[j])) return false;
                }
                return true;
            }
            else
            {
                return String::EndsWith(s, value);
            }
        }

        static bool Equals(const std::basic_string<T>& a, const std::basic_string<T>& b)
        {
            return a.compare(b) == 0;
        }

        static bool Equals(const std::basic_string<T>& a, const std::basic_string<T>& b, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
#ifndef SYSTEM_CXX_14
                if (a.length() != b.length()) return false;
                for (int i = 0; i < a.size(); i++)
                {
                    if (String::ToLower(a[i]) != String::ToLower(b[i])) return false;
                }
                return true;
#else
                return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                    [](T _a, T _b)
                    {
                        return String::ToLower(_a) == String::ToLower(_b);
                    }
                );
#endif
            }
            else
            {
                return String::Equals(a, b);
            }
        }

        template<typename... Types>
        static std::basic_string<T> Format(const std::basic_string<T>& format, Types... args)
        {
            std::basic_ostringstream<T> boss;
            std::basic_string<T> clone = String::Clone(format);
#ifdef SYSTEM_CXX_17
            (String::FormatHelper(boss, clone, args), ...); //C++17
#else
            int arr[] = { (String::FormatHelper(boss, clone, args), 0)... }; //C++11
#endif
            boss << clone;
            return boss.str();
        }

        static int GetHashCode(const std::basic_string<T>& s)
        {
            const unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
            unsigned int hash = 0;
            for (int i = 0; i < s.size(); i++)
            {
                hash = hash * seed + s[i];
            }
            return (hash & 0x7FFFFFFF);
        }

        static int GetHashCode(const std::basic_string<T>& s, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::GetHashCode(String::ToLower(s));
            }
            else
            {
                return String::GetHashCode(s);
            }
        }

        static int GetTypeCode()
        {
            return 18;
        }

        static int IndexOf(const std::basic_string<T>& s, const std::basic_string<T>& value)
        {
            return s.find(value);
        }

        static int IndexOf(const std::basic_string<T>& s, const std::basic_string<T>& value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::IndexOf(String::ToLower(s), String::ToLower(value));
            }
            else
            {
                return String::IndexOf(s, value);
            }
        }

        static int IndexOf(const std::basic_string<T>& s, T value)
        {
            return s.find(value);
        }

        static int IndexOf(const std::basic_string<T>& s, T value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::IndexOf(String::ToLower(s), String::ToLower(value));
            }
            else
            {
                return String::IndexOf(s, value);
            }
        }

        static std::basic_string<T> Insert(const std::basic_string<T>& s, int startIndex, const std::basic_string<T>& value)
        {
            if (startIndex < 0 || startIndex > s.size()) return s;
            if (startIndex == s.size()) return s + value;
            std::basic_string<T> part1 = String::Substring(s, 0, startIndex);
            std::basic_string<T> part2 = String::Substring(s, startIndex);
            return part1 + value + part2;
        }

        static std::basic_string<T> Join(const std::basic_string<T>& separator, const std::vector<std::basic_string<T>>& values)
        {
            std::basic_string<T> str;
            for (int i = 0; i < values.size(); i++)
            {
                if (i < values.size() - 1)
                    str += (values[i] + separator);
                else
                    str += values[i];
            }
            return str;
        }

        static std::basic_string<T> Join(T separator, const std::vector<std::basic_string<T>>& values)
        {
            return String::Join(String::ToString(separator), values);
        }

        static int LastIndexOf(const std::basic_string<T>& s, const std::basic_string<T>& value)
        {
            return s.find_last_of(value);
        }

        static int LastIndexOf(const std::basic_string<T>& s, const std::basic_string<T>& value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::LastIndexOf(String::ToLower(s), String::ToLower(value));
            }
            else
            {
                return String::LastIndexOf(s, value);
            }
        }

        static int LastIndexOf(const std::basic_string<T>& s, T value)
        {
            return s.find_last_of(value);
        }

        static int LastIndexOf(const std::basic_string<T>& s, T value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                return String::LastIndexOf(String::ToLower(s), String::ToLower(value));
            }
            else
            {
                return String::LastIndexOf(s, value);
            }
        }

        static std::basic_string<T> Remove(const std::basic_string<T>& s, int startIndex)
        {
            if (startIndex <= 0) return String::Empty();
            if (startIndex >= s.size()) return s;
            std::basic_string<T> str;
            for (int i = 0; i < startIndex; i++)
            {
                str += s[i];
            }
            return str;
        }

        static std::basic_string<T> Remove(const std::basic_string<T>& s, int startIndex, int count)
        {
            if (startIndex <= 0) return String::Empty();
            if (startIndex >= s.size()) return s;
            if (count == 0) return s;
            if (startIndex + count > s.size()) return s;
            std::basic_string<T> str;
            for (int i = 0; i < s.size(); i++)
            {
                if (i >= startIndex && i < startIndex + count) continue;
                str += s[i];
            }
            return str;
        }

        static std::basic_string<T> Replace(const std::basic_string<T>& s, const std::basic_string<T>& oldValue, const std::basic_string<T>& newValue)
        {
            if (oldValue.empty()) return s;
            std::basic_string<T> str = s;
            size_t pos = 0;
            while ((pos = str.find(oldValue, pos)) != std::string::npos)
            {
                str.replace(pos, oldValue.size(), newValue);
                pos += newValue.size();
            }
            return str;
        }

        static std::basic_string<T> Replace(const std::basic_string<T>& s, const std::basic_string<T>& oldValue, const std::basic_string<T>& newValue, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                if (oldValue.empty()) return s;
                std::basic_string<T> str = s;
                size_t pos = 0;
                while ((pos = String::ToLower(str).find(String::ToLower(oldValue), pos)) != std::string::npos)
                {
                    str.replace(pos, oldValue.size(), newValue);
                    pos += newValue.size();
                }
                return str;
            }
            else
            {
                return String::Replace(s, oldValue, newValue);
            }
        }

        static std::basic_string<T> Replace(const std::basic_string<T>& s, T oldValue, T newValue)
        {
            std::basic_string<T> str;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == oldValue)
                {
                    if (newValue != 0) str += newValue;
                }
                else str += s[i];
            }
            return str;
        }

        static std::basic_string<T> Replace(const std::basic_string<T>& s, T oldValue, T newValue, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                std::basic_string<T> str;
                for (int i = 0; i < s.size(); i++)
                {
                    if (String::ToLower(s[i]) == String::ToLower(oldValue))
                    {
                        if (newValue != 0) str += newValue;
                    }
                    else str += s[i];
                }
                return str;
            }
            else
            {
                return String::Replace(s, oldValue, newValue);
            }
        }

#ifndef SYSTEM_STRING_ONLY
        static std::string Reverse(const std::string& s)
        {
            if (String::IsValidUTF8(s))
            {
                return String::To_UTF8(String::Reverse(String::To_UTF32(s)));
            }
            else
            {
#ifdef SYSTEM_WINDOWS
                std::wstring wstr = String::StringToWstring(s, StringEncoding::ANSI);
                return String::WstringToString(String::Reverse(wstr), StringEncoding::ANSI);
#endif
#ifdef SYSTEM_LINUX
                std::string str;
                for (int i = s.size() - 1; i >= 0; i--)
                {
                    str += s[i];
                }
                return str;
#endif
            }
        }

        static std::wstring Reverse(const std::wstring& s)
        {
            std::u32string u32str = String::Reverse(String::To_UTF32(s));
            return String::To_Wstring(String::To_UTF8(u32str));
        }

#ifdef SYSTEM_CXX_20
        static std::u8string Reverse(const std::u8string& s)
        {
            std::string str_utf8 = String::U8stringToString(s);
            std::string str = String::To_UTF8(String::Reverse(String::To_UTF32(str_utf8)));
            return String::StringToU8string(str);
        }
#endif

        static std::u16string Reverse(const std::u16string& s)
        {
            return String::To_UTF16(String::Reverse(String::To_UTF32(s)));
        }

        static std::u32string Reverse(const std::u32string& s)
        {
            std::u32string str;
            for (int i = s.size() - 1; i >= 0; i--)
            {
                str += s[i];
            }
            return str;
        }

        static std::basic_string<T> Slice(const std::basic_string<T>& s)
        {
            return s;
        }

        static std::basic_string<T> Slice(const std::basic_string<T>& s, int start)
        {
            std::basic_string<T> slice;
            if (start < 0) start += s.size();
            for (int i = start; i < s.size(); i++)
            {
                slice += s[i];
            }
            return slice;
        }

        static std::basic_string<T> Slice(const std::basic_string<T>& s, int start, int end)
        {
            std::basic_string<T> slice;
            if (start < 0) start += s.size();
            if (end < 0) end += s.size();
            for (int i = start; i < end; i++)
            {
                slice += s[i];
            }
            return slice;
        }
#endif

        static std::vector<std::basic_string<T>> Split(const std::basic_string<T>& s, const std::basic_string<T>& separator)
        {
            std::vector<std::basic_string<T>> strings;
            if (separator.empty())
            {
                strings.push_back(s);
                return strings;
            }
            size_t pos;
            std::basic_string<T> rest = s;
            while ((pos = rest.find(separator)) != std::string::npos)
            {
                strings.push_back(rest.substr(0, pos));
                rest.erase(0, pos + separator.size());
            }
            if (!rest.empty())
            {
                strings.push_back(rest);
            }
            return strings;
        }

        static std::vector<std::basic_string<T>> Split(const std::basic_string<T>& s, T separator)
        {
            return String::Split(s, String::ToString(separator));
        }

        static bool StartsWith(const std::basic_string<T>& s, const std::basic_string<T>& value)
        {
            if (value.size() > s.size()) return false;
            for (int i = 0; i < value.size(); i++)
            {
                if (s[i] != value[i]) return false;
            }
            return true;
        }

        static bool StartsWith(const std::basic_string<T>& s, const std::basic_string<T>& value, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                if (value.size() > s.size()) return false;
                for (int i = 0; i < value.size(); i++)
                {
                    if (String::ToLower(s[i]) != String::ToLower(value[i])) return false;
                }
                return true;
            }
            else
            {
                return String::StartsWith(s, value);
            }
        }

        static std::basic_string<T> Substring(const std::basic_string<T>& s, int startIndex)
        {
            return s.substr(startIndex);
        }

        static std::basic_string<T> Substring(const std::basic_string<T>& s, int startIndex, int length)
        {
            return s.substr(startIndex, length);
        }

        static std::vector<T> ToCharArray(const std::basic_string<T>& s)
        {
            std::vector<T> charArray;
            for (int i = 0; i < s.size(); i++)
            {
                charArray.push_back(s[i]);
            }
            return charArray;
        }

        static std::vector<T> ToCharArray(const std::basic_string<T>& s, int startIndex, int length)
        {
            std::vector<T> charArray;
            int endIndex = startIndex + length;
            if (endIndex > s.size()) return charArray;
            for (int i = startIndex; i < endIndex; i++)
            {
                charArray.push_back(s[i]);
            }
            return charArray;
        }

        static std::basic_string<T> ToLower(const std::basic_string<T>& s)
        {
            std::basic_string<T> lower;
            for (const auto& item : s) lower += String::ToLower(item);
            return lower;
        }

        static T ToLower(T c)
        {
            return std::tolower(c);
        }

        static std::basic_string<T> ToString(const std::basic_string<T>& s)
        {
            return s;
        }

        static std::basic_string<T> ToString(T c)
        {
            std::basic_string<T> s;
            s.push_back(c);
            return s;
        }

        static std::basic_string<T> ToString(int value)
        {
            std::basic_ostringstream<T> boss;
            boss << value;
            return boss.str();
        }

        template<typename Type>
        static std::basic_string<T> ToString(Type value)
        {
            std::basic_ostringstream<T> boss;
            boss << value;
            return boss.str();
        }

        static std::basic_string<T> ToUpper(const std::basic_string<T>& s)
        {
            std::basic_string<T> lower;
            for (const auto& item : s) lower += String::ToUpper(item);
            return lower;
        }

        static T ToUpper(T c)
        {
            return std::toupper(c);
        }

        //注意:trimString仅应该存放单个字符
        static std::basic_string<T> Trim(const std::basic_string<T>& s, const std::basic_string<T>& trimString)
        {
            size_t indexOfFirstNonTrimChar = s.find_first_not_of(trimString);
            if (indexOfFirstNonTrimChar == std::string::npos) return String::Empty();
            size_t indexOfLastNonTrimChar = s.find_last_not_of(trimString);
            return s.substr(indexOfFirstNonTrimChar, indexOfLastNonTrimChar - indexOfFirstNonTrimChar + 1);
        }

        static std::basic_string<T> Trim(const std::basic_string<T>& s, T trimChar)
        {
            size_t indexOfFirstNonTrimChar = s.find_first_not_of(trimChar);
            if (indexOfFirstNonTrimChar == std::string::npos) return String::Empty();
            size_t indexOfLastNonTrimChar = s.find_last_not_of(trimChar);
            return s.substr(indexOfFirstNonTrimChar, indexOfLastNonTrimChar - indexOfFirstNonTrimChar + 1);
        }

        static std::basic_string<T> Trim(const std::basic_string<T>& s)
        {
            return String::Trim(s, (T)' ');
        }

        //注意:trimString仅应该存放单个字符
        static std::basic_string<T> TrimEnd(const std::basic_string<T>& s, const std::basic_string<T>& trimString)
        {
            size_t indexOfLastNonTrimChar = s.find_last_not_of(trimString);
            if (indexOfLastNonTrimChar == std::string::npos) return String::Empty();
            return s.substr(0, indexOfLastNonTrimChar + 1);
        }

        static std::basic_string<T> TrimEnd(const std::basic_string<T>& s, T trimChar)
        {
            size_t indexOfLastNonTrimChar = s.find_last_not_of(trimChar);
            if (indexOfLastNonTrimChar == std::string::npos) return String::Empty();
            return s.substr(0, indexOfLastNonTrimChar + 1);
        }

        static std::basic_string<T> TrimEnd(const std::basic_string<T>& s)
        {
            return String::TrimEnd(s, (T)' ');
        }

        //注意:trimString仅应该存放单个字符
        static std::basic_string<T> TrimStart(const std::basic_string<T>& s, const std::basic_string<T>& trimString)
        {
            size_t indexOfFirstNonTrimChar = s.find_first_not_of(trimString);
            if (indexOfFirstNonTrimChar == std::string::npos) return String::Empty();
            return s.substr(indexOfFirstNonTrimChar);
        }

        static std::basic_string<T> TrimStart(const std::basic_string<T>& s, T trimChar)
        {
            size_t indexOfFirstNonTrimChar = s.find_first_not_of(trimChar);
            if (indexOfFirstNonTrimChar == std::string::npos) return String::Empty();
            return s.substr(indexOfFirstNonTrimChar);
        }

        static std::basic_string<T> TrimStart(const std::basic_string<T>& s)
        {
            return String::TrimStart(s, (T)' ');
        }

#ifndef SYSTEM_STRING_ONLY
    public: //Extra Convert Function 1:
        static System::tstring StringToWstring(const std::string& s, StringEncoding encoding)
        {
#ifdef SYSTEM_WINDOWS
            if (s.empty()) return std::wstring();
            std::wstring result;
            int len = MultiByteToWideChar((UINT)encoding, 0, s.c_str(), -1, NULL, 0);
            if (len == 0) return result;
            wchar_t* wstr = new wchar_t[len];
            if (wstr == nullptr) return result;
            int ret = MultiByteToWideChar((UINT)encoding, 0, s.c_str(), -1, wstr, len);
            if (ret == 0)
            {
                delete[] wstr;
                return result;
            }
            result = wstr;
            delete[] wstr;
            return result;
#endif
#ifdef SYSTEM_LINUX
            return s;
#endif
        }

        static std::string WstringToString(const System::tstring& s, StringEncoding encoding)
        {
#ifdef SYSTEM_WINDOWS
            if (s.empty()) return std::string();
            std::string result;
            int len = WideCharToMultiByte((UINT)encoding, 0, s.c_str(), -1, NULL, 0, NULL, NULL);
            if (len == 0) return result;
            char* str = new char[len];
            if (str == nullptr) return result;
            int ret = WideCharToMultiByte((UINT)encoding, 0, s.c_str(), -1, str, len, NULL, NULL);
            if (ret == 0)
            {
                delete[] str;
                return result;
            }
            result = str;
            delete[] str;
            return result;
#endif
#ifdef SYSTEM_LINUX
            return s;
#endif
        }

        //receive utf-8/ansi string
        static System::tstring StringToWstring2(const std::string& s)
        {
#ifdef SYSTEM_WINDOWS
            std::wstring result;
            if (String::IsValidUTF8(s))
            {
                result = String::StringToWstring(s, StringEncoding::UTF8);
            }
            else
            {
                result = String::StringToWstring(s, StringEncoding::ANSI);
            }
            return result;
#endif
#ifdef SYSTEM_LINUX
            return s;
#endif
        }

        //return utf-8 string
        static std::string WstringToString2(const System::tstring& s)
        {
#ifdef SYSTEM_WINDOWS
            return String::WstringToString(s, StringEncoding::UTF8);
#endif
#ifdef SYSTEM_LINUX
            return s;
#endif
        }

        //receive utf-8 string
        static std::wstring StringToWstring(const std::string& s)
        {
            return String::To_Wstring(s);
        }

        //return utf-8 string
        static std::string WstringToString(const std::wstring& s)
        {
            return String::To_String(s);
        }

        static u8str StringToU8string(const std::string& s)
        {
#ifdef SYSTEM_CXX_20
            return u8str(reinterpret_cast<const u8char*>(s.c_str()));
#else
            return s;
#endif
        }

        static std::string U8stringToString(const u8str& s)
        {
#ifdef SYSTEM_CXX_20
            return std::string(reinterpret_cast<const char*>(s.c_str()));
#else
            return s;
#endif
        }

        static std::u16string WstringToU16string(const std::wstring& s)
        {
#ifdef SYSTEM_WINDOWS
            std::u16string str(reinterpret_cast<const char16_t*>(s.c_str()));
            return str;
#endif
#ifdef SYSTEM_LINUX
            return String::To_UTF16(s);
#endif
        }

        static std::wstring U16stringToWstring(const std::u16string& s)
        {
#ifdef SYSTEM_WINDOWS
            std::wstring str(reinterpret_cast<const wchar_t*>(s.c_str()));
            return str;
#endif
#ifdef SYSTEM_LINUX
            return String::To_Wstring(s);
#endif
        }

        static std::u32string WstringToU32string(const std::wstring& s)
        {
#ifdef SYSTEM_WINDOWS
            return String::To_UTF32(s);
#endif
#ifdef SYSTEM_LINUX
            std::u32string str(reinterpret_cast<const char32_t*>(s.c_str()));
            return str;
#endif
        }

        static std::wstring U32stringToWstring(const std::u32string& s)
        {
#ifdef SYSTEM_WINDOWS
            return String::To_Wstring(s);
#endif
#ifdef SYSTEM_LINUX
            std::wstring str(reinterpret_cast<const wchar_t*>(s.c_str()));
            return str;
#endif
        }

    public: //Extra Convert Function 2:
        static std::string To_UTF8(const std::u16string& s)
        {
            std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv;
            return conv.to_bytes(s);
        }

        static std::string To_UTF8(const std::u32string& s)
        {
            std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
            return conv.to_bytes(s);
        }

        static std::string To_UTF8(const std::wstring& s)
        {
            return String::To_String(s);
        }

        static std::u16string To_UTF16(const std::string& s)
        {
            std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv;
            return conv.from_bytes(s);
        }

        static std::u16string To_UTF16(const std::u32string& s)
        {
            return To_UTF16(To_UTF8(s));
        }

        static std::u16string To_UTF16(const std::wstring& s)
        {
            return To_UTF16(To_UTF8(s));
        }

        static std::u32string To_UTF32(const std::string& s)
        {
            std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
            return conv.from_bytes(s);
        }

        static std::u32string To_UTF32(const std::u16string& s)
        {
            return To_UTF32(To_UTF8(s));
        }

        static std::u32string To_UTF32(const std::wstring& s)
        {
            return To_UTF32(To_UTF8(s));
        }

    public: //Extra Convert Function 3:
        //return utf-8 string
        static std::string To_String(const std::wstring& s)
        {
            std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
            return conv.to_bytes(s);
        }

        //receive utf-8 string
        static std::wstring To_Wstring(const std::string& s)
        {
            std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
            return conv.from_bytes(s);
        }

        static std::wstring To_Wstring(const std::u16string& s)
        {
            return String::To_Wstring(String::To_UTF8(s));
        }

        static std::wstring To_Wstring(const std::u32string& s)
        {
            return String::To_Wstring(String::To_UTF8(s));
        }

    public: //Extra Convert Function 4:
        static std::string ConvertString(const std::string& s, StringEncoding sourceEncoding, StringEncoding targetEncoding)
        {
            return String::WstringToString(String::StringToWstring(s, sourceEncoding), targetEncoding);
        }
#endif

#ifndef SYSTEM_STRING_ONLY
    public: //Extra Util 1:
        static bool IsValidASCII(const std::string& s)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (static_cast<unsigned char>(s[i]) > 127) return false;
            }
            return true;
        }

        //return 0 if failed.
        static int ASCIICharCount(const std::string& s)
        {
            if (String::IsValidASCII(s)) return s.size();
            return 0;
        }

        static std::vector<ASCIIChar> ASCIIToCharArray(const std::string& s)
        {
            std::vector<ASCIIChar> charArray;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned char item = static_cast<unsigned char>(s[i]);
                if (item > 127) return std::vector<ASCIIChar>();
                charArray.push_back(ASCIIChar(1, item));
            }
            return charArray;
        }

        static std::string CodePointToASCII(const std::vector<ASCIIChar>& codePoints)
        {
            std::string str;
            for (int i = 0; i < codePoints.size(); i++)
            {
                if (static_cast<unsigned char>(codePoints[i].codePoint) > 127) return std::string();
                str += codePoints[i].codePoint;
            }
            return str;
        }

        static bool IsValidUTF32(const std::u32string& s)
        {
            for (int i = 0; i < s.size(); i++)
            {
                int codePoint = (int)s[i];
                if (codePoint < 0 || codePoint > 0x10FFFF) return false;
            }
            return true;
        }

        static int UTF32CharCount(const std::u32string& s)
        {
            if (String::IsValidUTF32(s)) return s.size();
            return 0;
        }

        static std::vector<UTF32Char> UTF32ToCharArray(const std::u32string& s)
        {
            std::vector<UTF32Char> charArray;
            for (int i = 0; i < s.size(); i++)
            {
                int codePoint = (int)s[i];
                if (codePoint < 0 || codePoint > 0x10FFFF) return std::vector<UTF32Char>();
                charArray.push_back(UTF32Char(4, (unsigned int)codePoint));
            }
            return charArray;
        }

        static std::u32string CodePointToUTF32(const std::vector<UTF32Char>& codePoints)
        {
            std::u32string str;
            for (int i = 0; i < codePoints.size(); i++)
            {
                if (codePoints[i].codePoint < 0 || codePoints[i].codePoint>0x10FFFF) return std::u32string();
                str += codePoints[i].codePoint;
            }
            return str;
        }

        static bool IsValidUTF8(const std::string& s)
        {
            for (int i = 0; i < s.size(); i++)
            {
                unsigned char firstByte = (unsigned char)s[i];
                unsigned int codePoint = 0;
                int length = 0;
                //Check Byte 1:
                if ((firstByte & 0x80) == 0x00) // U+0000 to U+007F
                {
                    codePoint = (firstByte & 0x7F);
                    length = 1;
                }
                else if ((firstByte & 0xE0) == 0xC0) // U+0080 to U+07FF
                {
                    codePoint = (firstByte & 0x1F);
                    length = 2;
                }
                else if ((firstByte & 0xF0) == 0xE0) // U+0800 to U+FFFF
                {
                    codePoint = (firstByte & 0x0F);
                    length = 3;
                }
                else if ((firstByte & 0xF8) == 0xF0) // U+10000 to U+10FFFF
                {
                    codePoint = (firstByte & 0x07);
                    length = 4;
                }
                else return false;
                //Calculate:
                for (int j = 1; j < length; j++)
                {
                    int index = i + j;
                    if (index < s.size())
                    {
                        unsigned char otherByte = (unsigned char)s[index];
                        if ((otherByte & 0xC0) != 0x80) return false;
                        codePoint = (codePoint << 6) | (otherByte & 0x3F);
                    }
                }
                i += (length - 1);
                //Check CodePoint:
                if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
                    return false;
                if (codePoint >= 0x0000 && codePoint <= 0x007F && length == 1)
                    continue;
                if (codePoint >= 0x0080 && codePoint <= 0x07FF && length == 2)
                    continue;
                if (codePoint >= 0x0800 && codePoint <= 0xFFFF && length == 3)
                    continue;
                if (codePoint >= 0x10000 && codePoint <= 0x10FFFF && length == 4)
                    continue;
                return false;
            }
            return true;
        }

#ifdef SYSTEM_CXX_20
        static bool IsValidUTF8(const std::u8string& s)
        {
            return String::IsValidUTF8(String::U8stringToString(s));
        }
#endif

        //return 0 if failed.
        static int UTF8CharCount(const std::string& s)
        {
            int charCount = 0;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned char firstByte = (unsigned char)s[i];
                unsigned int codePoint = 0;
                int length = 0;
                //Check Byte 1:
                if ((firstByte & 0x80) == 0x00) // U+0000 to U+007F
                {
                    codePoint = (firstByte & 0x7F);
                    length = 1;
                }
                else if ((firstByte & 0xE0) == 0xC0) // U+0080 to U+07FF
                {
                    codePoint = (firstByte & 0x1F);
                    length = 2;
                }
                else if ((firstByte & 0xF0) == 0xE0) // U+0800 to U+FFFF
                {
                    codePoint = (firstByte & 0x0F);
                    length = 3;
                }
                else if ((firstByte & 0xF8) == 0xF0) // U+10000 to U+10FFFF
                {
                    codePoint = (firstByte & 0x07);
                    length = 4;
                }
                else return 0;
                //Calculate:
                for (int j = 1; j < length; j++)
                {
                    int index = i + j;
                    if (index < s.size())
                    {
                        unsigned char otherByte = (unsigned char)s[index];
                        if ((otherByte & 0xC0) != 0x80) return 0;
                        codePoint = (codePoint << 6) | (otherByte & 0x3F);
                    }
                }
                i += (length - 1);
                charCount++;
                //Check CodePoint:
                if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
                    return 0;
                if (codePoint >= 0x0000 && codePoint <= 0x007F && length == 1)
                    continue;
                if (codePoint >= 0x0080 && codePoint <= 0x07FF && length == 2)
                    continue;
                if (codePoint >= 0x0800 && codePoint <= 0xFFFF && length == 3)
                    continue;
                if (codePoint >= 0x10000 && codePoint <= 0x10FFFF && length == 4)
                    continue;
                return 0;
            }
            return charCount;
        }

#ifdef SYSTEM_CXX_20
        static int UTF8CharCount(const std::u8string& s)
        {
            return String::UTF8CharCount(String::U8stringToString(s));
        }
#endif

        static std::vector<UTF8Char> UTF8ToCharArray(const std::string& s)
        {
            std::vector<UTF8Char> charArray;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned char firstByte = (unsigned char)s[i];
                unsigned int codePoint = 0;
                int length = 0;
                //Check Byte 1:
                if ((firstByte & 0x80) == 0x00) // U+0000 to U+007F
                {
                    codePoint = (firstByte & 0x7F);
                    length = 1;
                }
                else if ((firstByte & 0xE0) == 0xC0) // U+0080 to U+07FF
                {
                    codePoint = (firstByte & 0x1F);
                    length = 2;
                }
                else if ((firstByte & 0xF0) == 0xE0) // U+0800 to U+FFFF
                {
                    codePoint = (firstByte & 0x0F);
                    length = 3;
                }
                else if ((firstByte & 0xF8) == 0xF0) // U+10000 to U+10FFFF
                {
                    codePoint = (firstByte & 0x07);
                    length = 4;
                }
                else return std::vector<UTF8Char>();
                //Calculate:
                for (int j = 1; j < length; j++)
                {
                    int index = i + j;
                    if (index < s.size())
                    {
                        unsigned char otherByte = (unsigned char)s[index];
                        if ((otherByte & 0xC0) != 0x80) return std::vector<UTF8Char>();
                        codePoint = (codePoint << 6) | (otherByte & 0x3F);
                    }
                }
                i += (length - 1);
                charArray.push_back(UTF8Char(length, codePoint));
                //Check CodePoint:
                if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
                    return std::vector<UTF8Char>();
                if (codePoint >= 0x0000 && codePoint <= 0x007F && length == 1)
                    continue;
                if (codePoint >= 0x0080 && codePoint <= 0x07FF && length == 2)
                    continue;
                if (codePoint >= 0x0800 && codePoint <= 0xFFFF && length == 3)
                    continue;
                if (codePoint >= 0x10000 && codePoint <= 0x10FFFF && length == 4)
                    continue;
                return std::vector<UTF8Char>();
            }
            return charArray;
        }

#ifdef SYSTEM_CXX_20
        static std::vector<UTF8Char> UTF8ToCharArray(const std::u8string& s)
        {
            return String::UTF8ToCharArray(String::U8stringToString(s));
        }
#endif

        static std::string CodePointToUTF8(int codePoint)
        {
            //Check CodePoint:
            if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
                return std::string();
            //Check CodePoint:
            if (codePoint < 0 || codePoint > 0x10FFFF)
                return std::string();
            //Assemble Bytes:
            std::string str;
            if (codePoint >= 0x0000 && codePoint <= 0x007F)
            {
                char firstByte = (codePoint & 0x7F);
                str.push_back(firstByte);
            }
            if (codePoint >= 0x0080 && codePoint <= 0x07FF)
            {
                char firstByte = 0xC0 | ((codePoint >> 6) & 0x1F);
                char secondByte = 0x80 | (codePoint & 0x3F);
                str.push_back(firstByte);
                str.push_back(secondByte);
            }
            if (codePoint >= 0x0800 && codePoint <= 0xFFFF)
            {
                char firstByte = 0xE0 | ((codePoint >> 12) & 0x0F);
                char secondByte = 0x80 | ((codePoint >> 6) & 0x3F);
                char thirdByte = 0x80 | (codePoint & 0x3F);
                str.push_back(firstByte);
                str.push_back(secondByte);
                str.push_back(thirdByte);
            }
            if (codePoint >= 0x10000 && codePoint <= 0x10FFFF)
            {
                char firstByte = 0xF0 | ((codePoint >> 18) & 0x07);
                char secondByte = 0x80 | ((codePoint >> 12) & 0x3F);
                char thirdByte = 0x80 | ((codePoint >> 6) & 0x3F);
                char fourthByte = 0x80 | (codePoint & 0x3F);
                str.push_back(firstByte);
                str.push_back(secondByte);
                str.push_back(thirdByte);
                str.push_back(fourthByte);
            }
            return str;
        }

        static std::string CodePointToUTF8(const std::vector<int>& codePoints)
        {
            std::string str;
            for (int i = 0; i < codePoints.size(); i++)
            {
                str += CodePointToUTF8(codePoints[i]);
            }
            return str;
        }

        static std::string CodePointToUTF8(const std::u32string& s)
        {
            std::string str;
            for (int i = 0; i < s.size(); i++)
            {
                str += CodePointToUTF8((int)s[i]);
            }
            return str;
        }

        static std::string CodePointToUTF8(const std::vector<UTF8Char>& codePoints)
        {
            std::string str;
            for (int i = 0; i < codePoints.size(); i++)
            {
                str += CodePointToUTF8(codePoints[i].codePoint);
            }
            return str;
        }

        static bool IsValidUTF16(const System::tstring& s)
        {
#ifdef SYSTEM_WINDOWS
            return true;
#endif
#ifdef SYSTEM_LINUX
            return String::IsValidUTF16String(s);
#endif
        }

        static bool IsValidUTF16(const std::u16string& s)
        {
            return true;
        }

        static int UTF16CharCount(const System::tstring& s)
        {
#ifdef SYSTEM_WINDOWS
            int charCount = 0;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned short firstTwoByte = (unsigned short)s[i];
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index = i + 1;
                    if (index < s.size())
                    {
                        unsigned short secondTwoByte = (unsigned short)s[index];
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        charCount++;
                        i++;
                    }
                }
                else
                {
                    charCount++;
                }
            }
            return charCount;
#endif
#ifdef SYSTEM_LINUX
            return String::UTF16StringCharCount(s);
#endif
        }

        static int UTF16CharCount(const std::u16string& s)
        {
#ifdef SYSTEM_WINDOWS
            std::wstring str(reinterpret_cast<const wchar_t*>(s.c_str()));
            return String::UTF16CharCount(str);
#endif
#ifdef SYSTEM_LINUX
            int charCount = 0;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned short firstTwoByte = (unsigned short)s[i];
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index = i + 1;
                    if (index < s.size())
                    {
                        unsigned short secondTwoByte = (unsigned short)s[index];
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        charCount++;
                        i++;
                    }
                }
                else
                {
                    charCount++;
                }
            }
            return charCount;
#endif
        }

        static std::vector<UTF16Char> UTF16ToCharArray(const System::tstring& s)
        {
#ifdef SYSTEM_WINDOWS
            std::vector<UTF16Char> charArray;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned short firstTwoByte = (unsigned short)s[i];
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index = i + 1;
                    if (index < s.size())
                    {
                        unsigned short secondTwoByte = (unsigned short)s[index];
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        charArray.push_back(UTF16Char(4, codePoint));
                        i++;
                    }
                }
                else
                {
                    charArray.push_back(UTF16Char(2, firstTwoByte));
                }
            }
            return charArray;
#endif
#ifdef SYSTEM_LINUX
            return String::UTF16StringToCharArray(s);
#endif
        }

        static std::vector<UTF16Char> UTF16ToCharArray(const std::u16string& s)
        {
#ifdef SYSTEM_WINDOWS
            std::wstring str(reinterpret_cast<const wchar_t*>(s.c_str()));
            return String::UTF16ToCharArray(str);
#endif
#ifdef SYSTEM_LINUX
            std::vector<UTF16Char> charArray;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned short firstTwoByte = (unsigned short)s[i];
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index = i + 1;
                    if (index < s.size())
                    {
                        unsigned short secondTwoByte = (unsigned short)s[index];
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        charArray.push_back(UTF16Char(4, codePoint));
                        i++;
                    }
                }
                else
                {
                    charArray.push_back(UTF16Char(2, firstTwoByte));
                }
            }
            return charArray;
#endif
        }

        static std::u16string CodePointToUTF16(int codePoint)
        {
            //Check CodePoint:
            if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
                return std::u16string();
            //Check CodePoint:
            if (codePoint < 0 || codePoint > 0x10FFFF)
                return std::u16string();
            //Assemble Bytes:
            std::u16string str;
            if (codePoint >= 0 && codePoint <= 0xFFFF)
            {
                char16_t firstTwoByte = (char16_t)codePoint;
                str.push_back(firstTwoByte);
            }
            else
            {
                int u = codePoint - 0x10000;
                char16_t firstTwoByte = 0xD800 + ((u >> 10) & 0x3FF);
                char16_t secondTwoByte = 0xDC00 + (u & 0x3FF);
                str.push_back(firstTwoByte);
                str.push_back(secondTwoByte);
            }
            return str;
        }

        static std::u16string CodePointToUTF16(const std::vector<int>& codePoints)
        {
            std::u16string str;
            for (int i = 0; i < codePoints.size(); i++)
            {
                str += CodePointToUTF16(codePoints[i]);
            }
            return str;
        }

        static std::u16string CodePointToUTF16(const std::u32string& s)
        {
            std::u16string str;
            for (int i = 0; i < s.size(); i++)
            {
                str += CodePointToUTF16((int)s[i]);
            }
            return str;
        }

        static std::u16string CodePointToUTF16(const std::vector<UTF16Char>& codePoints)
        {
            std::u16string str;
            for (int i = 0; i < codePoints.size(); i++)
            {
                str += CodePointToUTF16(codePoints[i].codePoint);
            }
            return str;
        }
#endif

#ifndef SYSTEM_STRING_ONLY
    public: //Extra Util 2:
        static std::string UTF16ToUTF16String(const std::u16string& s)
        {
            std::string str;
            for (int i = 0; i < s.size(); i++)
            {
                unsigned short twoByte = s[i];
                str += ((twoByte >> 8) & 0xFF);
                str += (twoByte & 0xFF);
            }
            return str;
        }

        static bool IsValidUTF16String(const std::string& s)
        {
            if (s.size() < 2) return false;
            if (s.size() % 2 != 0)  return false;
            for (int i = 0; i < s.size(); i += 2)
            {
                unsigned short firstByte = (unsigned short)s[i];                        //char => ushort
                unsigned short secondByte = (unsigned short)s[i + 1];                   //char => ushort
                unsigned short firstTwoByte = ((firstByte << 8) | secondByte);          //combine
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index1 = i + 2;
                    int index2 = i + 3;
                    if (index1 < s.size() && index2 < s.size())
                    {
                        unsigned short thirdByte = (unsigned short)s[index1];           //char => ushort
                        unsigned short fourthByte = (unsigned short)s[index2];          //char => ushort
                        unsigned short secondTwoByte = ((thirdByte << 8) | fourthByte); //combine
                        //combine codePoint:
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        i += 2;
                    }
                    else //error: missing next part
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        static int UTF16StringCharCount(const std::string& s)
        {
            if (s.size() < 2) return 0;
            if (s.size() % 2 != 0)  return 0;
            int charCount = 0;
            for (int i = 0; i < s.size(); i += 2)
            {
                unsigned short firstByte = (unsigned short)s[i];                        //char => ushort
                unsigned short secondByte = (unsigned short)s[i + 1];                   //char => ushort
                unsigned short firstTwoByte = ((firstByte << 8) | secondByte);          //combine
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index1 = i + 2;
                    int index2 = i + 3;
                    if (index1 < s.size() && index2 < s.size())
                    {
                        unsigned short thirdByte = (unsigned short)s[index1];           //char => ushort
                        unsigned short fourthByte = (unsigned short)s[index2];          //char => ushort
                        unsigned short secondTwoByte = ((thirdByte << 8) | fourthByte); //combine
                        //combine codePoint:
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        charCount++;
                        i += 2;
                    }
                    else //error: missing next part
                    {
                        return 0;
                    }
                }
                else
                {
                    charCount++;
                }
            }
            return charCount;
        }

        static std::vector<UTF16Char> UTF16StringToCharArray(const std::string& s)
        {
            if (s.size() < 2) return std::vector<UTF16Char>();
            if (s.size() % 2 != 0)  return std::vector<UTF16Char>();
            std::vector<UTF16Char> charArray;
            for (int i = 0; i < s.size(); i += 2)
            {
                unsigned short firstByte = (unsigned short)s[i];                        //char => ushort
                unsigned short secondByte = (unsigned short)s[i + 1];                   //char => ushort
                unsigned short firstTwoByte = ((firstByte << 8) | secondByte);          //combine
                if (firstTwoByte >= 0xD800 && firstTwoByte < 0xDC00)
                {
                    int index1 = i + 2;
                    int index2 = i + 3;
                    if (index1 < s.size() && index2 < s.size())
                    {
                        unsigned short thirdByte = (unsigned short)s[index1];           //char => ushort
                        unsigned short fourthByte = (unsigned short)s[index2];          //char => ushort
                        unsigned short secondTwoByte = ((thirdByte << 8) | fourthByte); //combine
                        //combine codePoint:
                        unsigned int codePoint = ((firstTwoByte & 0x3FF) << 10) + (secondTwoByte & 0x3FF) + 0x10000;
                        charArray.push_back(UTF16Char(4, codePoint));
                        i += 2;
                    }
                    else //error: missing next part
                    {
                        return std::vector<UTF16Char>();
                    }
                }
                else
                {
                    charArray.push_back(UTF16Char(2, firstTwoByte));
                }
            }
            return charArray;
        }
#endif

#ifndef SYSTEM_STRING_ONLY
    public: //Extra Function 1:
        static std::basic_string<T> GetTrueString()
        {
            std::basic_string<T> s;
            std::string str = TRUE_STRING;
            for (int i = 0; i < str.size(); i++)
            {
                s.push_back((T)str[i]);
            }
            return s;
        }

        static std::basic_string<T> GetFalseString()
        {
            std::basic_string<T> s;
            std::string str = FALSE_STRING;
            for (int i = 0; i < str.size(); i++)
            {
                s.push_back((T)str[i]);
            }
            return s;
        }

        static bool IsNumeric(const std::basic_string<T>& s)
        {
            if (s.empty()) return false;
            for (int i = 0; i < s.size(); i++)
            {
                //'0' = 48, '9' = 57
                if (s[i] < (T)'0' || s[i] > (T)'9')
                {
                    return false;
                }
            }
            return true;
        }

        static bool IsEmptyOrWhiteSpace(const std::basic_string<T>& s)
        {
            if (s.empty()) return true;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != (T)' ') return false;
            }
            return true;
        }
#endif

#ifndef SYSTEM_STRING_ONLY
    public: //Console Function 1:
        //return code point of next read character.
        static int Read()
        {
            std::string s = String::ReadLine();
            auto arr = String::UTF8ToCharArray(s);
            if (arr.size() > 0)
                return arr[0].codePoint;
            else
                return -1;
        }

        //return UTF-8 string.
        static std::string ReadLine()
        {
            std::string str;
#ifdef SYSTEM_WINDOWS
            HANDLE stdInputHandle = GetStdHandle(STD_INPUT_HANDLE);
            if (stdInputHandle == INVALID_HANDLE_VALUE) return str;
            DWORD read;
#if SYSTEM_STRING_INPUT_BUFFER_SIZE >= 1024
            const int bufferSize = SYSTEM_STRING_INPUT_BUFFER_SIZE;
#else
            const int bufferSize = 1024;    //minimum size
#endif
            wchar_t buffer[bufferSize + 1]; //bufferSize + 1 because we need '\0' at end of this string.
            buffer[bufferSize] = 0;         //add '\0' at the end.
            BOOL success = ReadConsoleW(stdInputHandle, buffer, bufferSize, &read, NULL);
            if (success)
            {
                if (read >= 2)
                    buffer[read - 2] = 0;   //remove \r\n (NewLine in Windows)
                str = String::WstringToString(std::wstring(buffer), System::StringEncoding::UTF8);
            }
#endif
#ifdef SYSTEM_LINUX
#if SYSTEM_STRING_INPUT_BUFFER_SIZE >= 2048
            const int bufferSize = SYSTEM_STRING_INPUT_BUFFER_SIZE;
#else
            const int bufferSize = 2048;    //minimum size
#endif
            char buffer[bufferSize + 1];    //bufferSize + 1 because we need '\0' at end of this string.
            buffer[bufferSize] = 0;         //add '\0' at the end.
            ssize_t ret = read(STDIN_FILENO, buffer, bufferSize);
            if (ret != -1)
            {
                if (ret >= 1)
                    buffer[ret - 1] = 0;    //remove \n (NewLine in Linux)
                str = buffer;
            }
#endif
            return str;
        }

        //std::string must be UTF-8 Encoding.
        static bool Write(const std::string& s)
        {
            if (!String::IsValidUTF8(s))
            {
                return false;
            }
#ifdef SYSTEM_WINDOWS
            HANDLE stdOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            if (stdOutputHandle == INVALID_HANDLE_VALUE) return false;
            DWORD written;
            std::wstring str = String::StringToWstring(s, StringEncoding::UTF8);
            BOOL success = WriteConsoleW(stdOutputHandle, str.c_str(), str.size(), &written, NULL);
            return success;
#endif
#ifdef SYSTEM_LINUX
            ssize_t ret = write(STDOUT_FILENO, s.c_str(), s.size());
            return ret != -1;
#endif
            return false;
        }

        //std::string must be UTF-8 Encoding.
        static bool WriteLine(const std::string& s)
        {
            return String::Write(s + U8("\n"));
        }

    public: //Extension Console Function 1:
        static bool Write(const std::string& s, unsigned char r, unsigned char g, unsigned char b)
        {
#ifdef SYSTEM_STRING_CONSOLE
            if (!BuiltInConsole::Instance().IsInited())
            {
                BuiltInConsole::Instance().Init();
            }
            if (BuiltInConsole::Instance().Success())
            {
                std::string format1 = StringA::Format(U8("{0}[{1};{2};{3};{4};{5}m"), U8(ESC), 38, 2, (int)r, (int)g, (int)b);
                std::string format2 = StringA::Format(U8("{0}[{1}m"), U8(ESC), 0);
                return StringA::Write(format1 + s + format2);
            }
            else
            {
                return StringA::Write(s);
            }
#else
            return StringA::Write(s);
#endif
        }

        static bool Write(const std::string& s,
            unsigned char r1, unsigned char g1, unsigned char b1,
            unsigned char r2, unsigned char g2, unsigned char b2)
        {
#ifdef SYSTEM_STRING_CONSOLE
            if (!BuiltInConsole::Instance().IsInited())
            {
                BuiltInConsole::Instance().Init();
            }
            if (BuiltInConsole::Instance().Success())
            {
                std::string format1 = StringA::Format(U8("{0}[{1};{2};{3};{4};{5}m"), U8(ESC), 38, 2, (int)r1, (int)g1, (int)b1);
                std::string format2 = StringA::Format(U8("{0}[{1};{2};{3};{4};{5}m"), U8(ESC), 48, 2, (int)r2, (int)g2, (int)b2);
                std::string format3 = StringA::Format(U8("{0}[{1}m"), U8(ESC), 0);
                return StringA::Write(format1 + format2 + s + format3);
            }
            else
            {
                return StringA::Write(s);
            }
#else
            return StringA::Write(s);
#endif
        }

        static bool WriteLine(const std::string& s, unsigned char r, unsigned char g, unsigned char b)
        {
            return String::Write(s + U8("\n"), r, g, b);
        }

        static bool WriteLine(const std::string& s,
            unsigned char r1, unsigned char g1, unsigned char b1,
            unsigned char r2, unsigned char g2, unsigned char b2)
        {
            return String::Write(s + U8("\n"), r1, g1, b1, r2, g2, b2);
        }
#endif

    private:
        template<typename Type>
        static void ConcatHelper(std::basic_ostringstream<T>& boss, const Type& value)
        {
            boss << value;
        }

        template<typename Type>
        static void FormatHelper(std::basic_ostringstream<T>& boss, std::basic_string<T>& s, const Type& value)
        {
            std::size_t openBracket = s.find((T)'{');
            if (openBracket == std::string::npos) return;
            std::size_t closeBracket = s.find((T)'}', openBracket + 1);
            if (closeBracket == std::string::npos) return;
            boss << s.substr(0, openBracket) << value;
            s = s.substr(closeBracket + 1);
        }
    };
}

#endif