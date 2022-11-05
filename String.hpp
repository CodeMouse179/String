//     +--------------------------------------------------------------------------------+
//     |                                  String v1.8.0                                 |
//     |  Introduction : System.String in C++                                           |
//     |  Modified date : 2022/11/5                                                     |
//     |  License : MIT                                                                 |
//     |  Source code : https://github.com/CodeMouse179/String                          |
//     |  Doc : https://github.com/CodeMouse179/String/blob/main/README.md              |
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
#define SYSTEM_STRING_VERSION_MINOR 8
#define SYSTEM_STRING_VERSION_PATCH 0
#define SYSTEM_STRING_VERSION (SYSTEM_STRING_VERSION_MAJOR << 16 | SYSTEM_STRING_VERSION_MINOR << 8 | SYSTEM_STRING_VERSION_PATCH)

//Windows Platform:
#ifdef _WIN32
#define SYSTEM_WINDOWS 1
#endif

//Linux Platform:
#ifdef __linux__
#define SYSTEM_LINUX 1
#endif

//Windows Headers:
#ifdef SYSTEM_WINDOWS
#include <Windows.h>
//Disable warnings for MSVC++ 20:
#ifdef _MSC_VER
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif
#endif

//Linux Headers:
#ifdef SYSTEM_LINUX
#include <locale> //std::wstring_convert
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
#else
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
#include <string> //std::string, std::wstring, std::basic_string
#include <algorithm> //std::equal
#include <cctype> //std::tolower
#include <sstream> //std::basic_ostringstream
#include <vector> //std::vector
#include <codecvt> //wstring_convert, codecvt_utf8, codecvt_utf16, codecvt_utf8_utf16

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
#else
#define StringT StringA
#endif

//std::string
#define __S(s) s
#define S(s) __S(s)

//std::wstring
#define __W(s) L##s
#define W(s) __W(s)

//std::u8string(C++20)
#ifdef SYSTEM_CXX_20
#define __U8(s) StringA::U8stringToString(u8##s)
#define U8(s) __U8(s)
#else
#define __U8(s) u8##s
#define U8(s) __U8(s)
#endif

//std::u16string
#define __U16(s) u##s
#define U16(s) __U16(s)

//std::u32string
#define __U32(s) U##s
#define U32(s) __U32(s)

//Windows:wchar_t, Linux:char
#ifdef SYSTEM_WINDOWS
#define T(s) W(s)
#else
#define T(s) s
#endif

//Windows:char/char8_t(C++20), Linux:char
#ifdef SYSTEM_WINDOWS
#define T8(s) U8(s)
#else
#define T8(s) s
#endif

//Specifies the execution character set used for string and character literals.
#ifdef SYSTEM_STRING_SET_UTF8
#ifdef SYSTEM_WINDOWS
#pragma execution_character_set("utf-8")
#endif
#endif

namespace System
{
    //generic types:
#ifdef SYSTEM_WINDOWS
    typedef std::wstring tstring;
    typedef wchar_t tchar;
#else
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
        UTF8 = 65001,   //CP_UTF8(Windows)
    };

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
                    if (std::tolower(s[i]) != std::tolower(value[j])) return false;
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
                    if (std::tolower(a[i]) != std::tolower(b[i])) return false;
                }
                return true;
#else
                return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                    [](T _a, T _b)
                    {
                        return std::tolower(_a) == std::tolower(_b);
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

        static int IndexOf(const std::basic_string<T>& s, T value)
        {
            return s.find(value);
        }

        static int LastIndexOf(const std::basic_string<T>& s, const std::basic_string<T>& value)
        {
            return s.find_last_of(value);
        }

        static int LastIndexOf(const std::basic_string<T>& s, T value)
        {
            return s.find_last_of(value);
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

#ifndef SYSTEM_STRING_ONLY
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
                    if (std::tolower(s[i]) != std::tolower(value[i])) return false;
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
            for (const auto& item : s) lower += std::tolower(item);
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

        static std::basic_string<T> ToUpper(const std::basic_string<T>& s)
        {
            std::basic_string<T> lower;
            for (const auto& item : s) lower += std::toupper(item);
            return lower;
        }

        static T ToUpper(T c)
        {
            return std::toupper(c);
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
    public: //extra convert function 1:
        static tstring StringToWstring(const std::string& s, StringEncoding encoding)
        {
#ifdef SYSTEM_WINDOWS
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

        static std::string WstringToString(const tstring& s, StringEncoding encoding)
        {
#ifdef SYSTEM_WINDOWS
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

    public: //extra convert function 2:
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

        static std::u16string To_UTF16(const std::string& s)
        {
            std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conv;
            return conv.from_bytes(s);
        }

        static std::u16string To_UTF16(const std::u32string& s)
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

    public: //extra convert function 3:
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

    public: //extra convert function 4:
        static std::string ConvertString(const std::string& s, StringEncoding sourceEncoding, StringEncoding targetEncoding)
        {
            return String::WstringToString(String::StringToWstring(s, sourceEncoding), targetEncoding);
        }
#endif

#ifndef SYSTEM_STRING_ONLY
    public: //extra support:
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
                        unsigned char otherByte = s[index];
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
                else return charCount;
                //Calculate:
                for (int j = 1; j < length; j++)
                {
                    int index = i + j;
                    if (index < s.size())
                    {
                        unsigned char otherByte = s[index];
                        if ((otherByte & 0xC0) != 0x80) return charCount;
                        codePoint = (codePoint << 6) | (otherByte & 0x3F);
                    }
                }
                i += (length - 1);
                charCount++;
                //Check CodePoint:
                if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
                    return charCount;
                if (codePoint >= 0x0000 && codePoint <= 0x007F && length == 1)
                    continue;
                if (codePoint >= 0x0080 && codePoint <= 0x07FF && length == 2)
                    continue;
                if (codePoint >= 0x0800 && codePoint <= 0xFFFF && length == 3)
                    continue;
                if (codePoint >= 0x10000 && codePoint <= 0x10FFFF && length == 4)
                    continue;
                return charCount;
            }
            return charCount;
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
            std::size_t openBracket = s.find('{');
            if (openBracket == std::string::npos) return;
            std::size_t closeBracket = s.find('}', openBracket + 1);
            if (closeBracket == std::string::npos) return;
            boss << s.substr(0, openBracket) << value;
            s = s.substr(closeBracket + 1);
        }
    };
}

#endif