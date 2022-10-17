#ifndef SYSTEM_STRING_HPP
#define SYSTEM_STRING_HPP

#include <string>

//ascii System::String class
#define StringA System::String<char>
//wide-char System::String class
#define StringW System::String<wchar_t>

//general System::String class
#ifdef _WIN32
#define StringT StringW
#else
#define StringT StringA
#endif

namespace System
{
//general types:
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