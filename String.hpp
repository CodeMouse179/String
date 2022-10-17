#ifndef SYSTEM_STRING_HPP
#define SYSTEM_STRING_HPP

#include <string>

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

    template<typename T>
    class String
    {
    public:
        static std::basic_string<T> Empty()
        {
            return std::basic_string<T>();
        }
    };
}

#endif