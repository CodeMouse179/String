#include "string_extension.h"
#include <iostream>

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

int main()
{
    std::string str1 = System::format<char>("Hello, {}", "World!");
    write_line(str1);
    return 0;
}