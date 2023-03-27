#ifndef STRING_EXTENSION_H
#define STRING_EXTENSION_H

#include <string>       //std::basic_string
#include <sstream>      //std::basic_ostringstream

#ifndef OPEN_BRACKET
#define OPEN_BRACKET '{'
#endif

#ifndef CLOSE_BRACKET
#define CLOSE_BRACKET '}'
#endif

namespace System
{
    template<typename CharType, typename Type>
    void format_helper(std::basic_ostringstream<CharType>& boss, std::basic_string<CharType>& s, const Type& value)
    {
        std::size_t openBracket = s.find((CharType)OPEN_BRACKET);
        if (openBracket == std::string::npos) return;
        std::size_t closeBracket = s.find((CharType)CLOSE_BRACKET, openBracket + 1);
        if (closeBracket == std::string::npos) return;
        boss << s.substr(0, openBracket) << value;
        s = s.substr(closeBracket + 1);
    }

    template<typename CharType>
    std::basic_string<CharType> format(const std::basic_string<CharType>& s)
    {
        return s;
    }

    template<typename CharType, typename... Types>
    std::basic_string<CharType> format(const std::basic_string<CharType>& s, Types... args)
    {
        std::basic_ostringstream<CharType> boss;
        std::basic_string<CharType> clone = s;
        int arr[] = { (format_helper(boss, clone, args), 0)... }; //C++ 11 and above
        boss << clone;
        return boss.str();
    }
}

#endif