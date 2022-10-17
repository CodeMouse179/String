#ifndef SYSTEM_STRING_HPP
#define SYSTEM_STRING_HPP

#include <string> //std::string, std::wstring, std::basic_string
#include <algorithm> //std::equal
#include <cctype> //std::tolower
#include <sstream> //std::basic_ostringstream
#include <vector> //std::vector

//ascii System::String class
#define StringA System::String<char>
//wide-char System::String class
#define StringW System::String<wchar_t>

//generic System::String class
#ifdef _WIN32
#define StringT StringW
#else
#define StringT StringA
#endif

//generic macros:
#ifdef _WIN32
#define __T(s) L##s
#define T(s) __T(s)
#else
#define T(s) s
#endif

namespace System
{
    //generic types:
#ifdef _WIN32
    typedef std::wstring tstring;
    typedef wchar_t tchar;
#else
    typedef std::string tstring;
    typedef char tchar;
#endif

    enum class StringComparison
    {
        IgnoreCase = 10,
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

    private:
        template<typename Type>
        static void ConcatHelper(std::basic_ostringstream<T>& boss, const Type& value)
        {
            boss << value;
        }

    public:
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

        static bool Equals(const std::basic_string<T>& a, const std::basic_string<T>& b)
        {
            return a.compare(b) == 0;
        }

        static bool Equals(const std::basic_string<T>& a, const std::basic_string<T>& b, StringComparison comparisonType)
        {
            if (comparisonType == StringComparison::IgnoreCase)
            {
                if (a.length() != b.length()) return false;
                return std::equal(a.begin(), a.end(), b.begin(),
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

    private:
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

    public:
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
    };
}

#endif