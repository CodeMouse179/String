#define SYSTEM_STRING_CONSOLE
#ifdef _MSC_VER
#include "String.hpp"
#else
#include "../../String.hpp"
#endif
using namespace System;
int main()
{
    StringA::WriteLine(U8("BasicTest"));
    return 0;
}