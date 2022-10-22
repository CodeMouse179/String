#ifndef SYSTEM_STRING_HPP
#define SYSTEM_STRING_HPP

//Platform macros:
#ifdef _WIN32
#define SYSTEM_WINDOWS
#endif

#ifdef __linux__
#define SYSTEM_LINUX
#endif

//Platform headers:
#ifdef SYSTEM_WINDOWS
#include <Windows.h>
#endif

#ifdef SYSTEM_LINUX
#include <locale> //std::wstring_convert
#endif

//CXX version define:
#ifdef __cpp_char8_t
#define SYSTEM_CXX_20
#endif

//disable warnings for MSVCXX(in C++20):
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

//C++ headers:
#include <string> //std::string, std::wstring, std::basic_string
#include <algorithm> //std::equal
#include <cctype> //std::tolower
#include <sstream> //std::basic_ostringstream
#include <vector> //std::vector
#include <codecvt> //wstring_convert, codecvt_utf8, codecvt_utf16, codecvt_utf8_utf16

//ascii System::String class
#define StringA System::String<char>
//wide-char System::String class
#define StringW System::String<wchar_t>

//generic System::String class
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

//std::u8string in CXX20:
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

//generic macros:
#ifdef SYSTEM_WINDOWS
#define T(s) W(s)
#else
#define T(s) s
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

    enum class StringEncoding
    {
        ANSI = 0,       //CP_ACP(windows)
        UTF8 = 65001,   //CP_UTF8(windows)
    };

    template<typename T>
    class String
    {
    public:
        static std::basic_string<T> Empty()
        {
            return std::basic_string<T>();
        }

    public:
        static std::basic_string<T> Clone(const std::basic_string<T>& str)
        {
            std::basic_string<T> instance = str;
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
#if SYSTEM_CXX_17
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

        static bool Equals(const std::basic_string<T>& a, const std::basic_string<T>& b)
        {
            return a.compare(b) == 0;
        }

        static bool Equals(const std::basic_string<T>& a, const std::basic_string<T>& b, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                if (a.length() != b.length()) return false;
                return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                    [](T _a, T _b)
                    {
                        return std::tolower(_a) == std::tolower(_b);
                    }
                );
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
#if SYSTEM_CXX_17
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

        static std::basic_string<T> Substring(const std::basic_string<T>& s, int startIndex)
        {
            return s.substr(startIndex);
        }

        static std::basic_string<T> Substring(const std::basic_string<T>& s, int startIndex, int length)
        {
            return s.substr(startIndex, length);
        }

        static std::basic_string<T> ToLower(const std::basic_string<T>& s)
        {
            std::basic_string<T> lower;
            for (const auto& item : s) lower += std::tolower(item);
            return lower;
        }

        static std::basic_string<T> ToUpper(const std::basic_string<T>& s)
        {
            std::basic_string<T> lower;
            for (const auto& item : s) lower += std::toupper(item);
            return lower;
        }

        static std::basic_string<T> Trim(const std::basic_string<T>& s, T trimChar)
        {
            size_t indexOfFirstNonTrimChar = s.find_first_not_of(trimChar);
            if (indexOfFirstNonTrimChar == std::string::npos) return String::Empty();
            size_t indexOfLastNonTrimChar = s.find_last_not_of(trimChar);
            return s.substr(indexOfFirstNonTrimChar, indexOfLastNonTrimChar - indexOfFirstNonTrimChar + 1);
        }

        static std::basic_string<T> TrimEnd(const std::basic_string<T>& s, T trimChar)
        {
            size_t indexOfLastNonTrimChar = s.find_last_not_of(trimChar);
            if (indexOfLastNonTrimChar == std::string::npos) return String::Empty();
            return s.substr(0, indexOfLastNonTrimChar + 1);
        }

        static std::basic_string<T> TrimStart(const std::basic_string<T>& s, T trimChar)
        {
            size_t indexOfFirstNonTrimChar = s.find_first_not_of(trimChar);
            if (indexOfFirstNonTrimChar == std::string::npos) return String::Empty();
            return s.substr(indexOfFirstNonTrimChar);
        }

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
        static std::string To_String(const std::wstring& s)
        {
            std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
            return conv.to_bytes(s);
        }

        static std::wstring To_Wstring(const std::string& s)
        {
            std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
            return conv.from_bytes(s);
        }

    private:
        template<typename Type>
        static void ConcatHelper(std::basic_ostringstream<T>& boss, const Type& value)
        {
            boss << value;
        }

        template<typename Type>
        static void FormatHelper(std::basic_ostringstream<T>& boss, std::basic_string<T>& bs, const Type& value)
        {
            std::size_t openBracket = bs.find('{');
            if (openBracket == std::string::npos) return;
            std::size_t closeBracket = bs.find('}', openBracket + 1);
            if (closeBracket == std::string::npos) return;
            boss << bs.substr(0, openBracket) << value;
            bs = bs.substr(closeBracket + 1);
        }
    };
}

#endif