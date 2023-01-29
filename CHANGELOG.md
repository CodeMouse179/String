# Changelog

## History

### 1.21.1-little change

Release Date : 2022/11/27

Fixed : U8c on Linux

### 1.21.1

Release Date : 2022/11/27

Added : U8c(macro)

Changed : std::tolower => String::ToLower, std::toupper => String::ToUpper

### 1.21.0

Release Date : 2022/11/26

Added : U8s(macro)

### 1.20.1

Release Date : 2022/11/22

Changed : String::StringToWstring, String::WstringToString

### 1.20.0

Release Date : 2022/11/20

Added : System::UTF32Char(typedef), String::StringToWstring(overload function), String::WstringToString(overload function), String::WstringToU32string(function), String::U32stringToWstring(function), String::CodePointToASCII(function), String::IsValidUTF32(function), String::UTF32CharCount(function), String::UTF32ToCharArray(function), String::CodePointToUTF32(function)

### 1.19.0

Release Date : 2022/11/20

Added : String::CodePointToUTF8(overload function), String::CodePointToUTF16(overload function), String::UTF16ToUTF16String(function), String::IsValidUTF16String(function), String::UTF16StringCharCount(function), String::UTF16StringToCharArray(function)

Changed : #else => #ifdef SYSTEM_LINUX, String::StringToWstring, String::WstringToString, add String::IsValidUTF16 Linux support, add String::UTF16CharCount Linux support, add StringUTF16ToCharArray Linux support

### 1.18.0

Release Date : 2022/11/18

Added : String::CodePointToUTF16(function)

Changed : BuiltInConsole::Init, String::Write

Fixed : String::CodePointToUTF8

### 1.17.1

Release Date : 2022/11/17

Fixed : String::Write bug

### 1.17.0

Release Date : 2022/11/17

Added : ESC(macro), System::BuiltInConsole(class), String::CodePointToUTF8(function), String::Write(overload function), String::WriteLine(overload function)

Changed : String::WriteLine

### 1.16.1

Release Date : 2022/11/16

Changed : String::IsValidUTF16, String::UTF16ToCharArray

### 1.16.0

Release Date : 2022/11/15

Added : #include <unistd.h>, String::WstringToU16string(function), String::U16stringToWstring(function), String::To_Wstring(overload function)

Changed : add String::ReadLine Linux support, add String::Write Linux support

### 1.15.0

Release Date : 2022/11/15

Added : SYSTEM_STRING_INPUT_BUFFER_SIZE(macro), String::Read(function), String::ReadLine(function), String::Write(function), String::WriteLine(function)

### 1.14.0

Release Date : 2022/11/14

Added : #ifdef WIN32, UNICODE(macro), _UNICODE(macro), String::IsNumeric(function), String::IsEmptyOrWhiteSpace(function)

### 1.13.1

Release Date : 2022/11/13

Added : String::ToString(overload function)

### 1.13.0

Release Date : 2022/11/12

Added : TRUE_STRING(macro), FALSE_STRING(macro), String::Join(function), String::Split(overload function), String::GetTrueString(function), String::GetFalseString(function)

Changed : System::StringEncoding

Fixed : String::Split bug

### 1.12.0

Release Date : 2022/11/12

Added : System::ASCIIChar(typedef), System::UTF8Char(typedef), System::UTF16Char(typedef), String::ASCIICharCount(function), String::ASCIIToCharArray(function), String::IsValidUTF8(overload function), String::UTF8CharCount(overload function), String::UTF8ToCharArray(overload function), String::IsValidUTF16(function), String::UTF16CharCount(function), String::UTF16ToCharArray(function)

Changed : rename System::UTF8Char => System::UnicodeChar

### 1.11.1

Release Date : 2022/11/11

Changed : String::Reverse

### 1.11.0

Release Date : 2022/11/10

Added : U8S(macro), String::Reverse(function)

### 1.10.0

Release Date : 2022/11/9

Added : System::UTF8Char(struct), String::To_UTF8(overload function), String::To_UTF16(overload function), String::To_UTF32(overload function), String::UTF8ToCharArray(function)

Changed : String::IsValidUTF8, String::UTF8CharCount

### 1.9.1

Release Date : 2022/11/8

Fixed : String::UTF8CharCount

### 1.9.0

Release Date : 2022/11/7

Added : SYSTEM_STRING_VERSION_STRING(macro), String::Insert(function), String::Reverse(function), String::IsValidASCII(function)

Changed : String::FormatHelper

### 1.8.0

Release Date : 2022/11/5

Added : String::Remove(function), String::ToLower(overload function), String::ToUpper(overload function)

Changed : SYSTEM_WINDOWS = 1, SYSTEM_LINUX = 1, SYSTEM_CXX_11 = 1, SYSTEM_CXX_14 = 1, SYSTEM_CXX_17 = 1, SYSTEM_CXX_20 = 1

### 1.7.0

Release Date : 2022/11/5

Added : String::Copy(function), String::GetTypeCode(function), String::ToString(overload function)

### 1.6.0

Release Date : 2022/11/5

Added : String::Replace(function), String::ToCharArray(function), String::ToString(function)

Changed : make String::String static

### 1.5.1

Release Date : 2022/11/5

Added : StringU8(macro), StringU16(macro), StringU32(macro)

### 1.5.0

Release Date : 2022/11/1

Added : String::ConvertString(function)

### 1.4.0

Release Date : 2022/10/28

Added : String::UTF8CharCount(function)

Fixed : String::IsValidUTF8

### 1.3.4

Release Date : 2022/10/28

Fixed : #if SYSTEM_CXX_17 => #ifdef SYSTEM_CXX_17 in String::Concat, String::Format

### 1.3.3

Release Date : 2022/10/28

Fixed : SYSTEM_CXX_11, SYSTEM_CXX_14, SYSTEM_CXX_17

### 1.3.2

Release Date : 2022/10/28

Added : SYSTEM_STRING_SET_UTF8(macro)

### 1.3.1

Release Date : 2022/10/28

Added : SYSTEM_STRING_VERSION(macro)

### 1.3.0

Release Date : 2022/10/27

Added : String::Trim(overload function), String::TrimEnd(overload function), String::TrimStart(overload function)

Changed : String::Equals, make String::IsValidUTF8 to public function.

### 1.2.0

Release Date : 2022/10/27

Added : T8(macro)

### 1.1.0

Release Date : 2022/10/27

Added : String::IsValidUTF8(function)

### 1.0.1

Release Date : 2022/10/26

Added : __SYSTEM_STRING_ONLY(macro)

### 1.0.0

Release Date : 2022/10/26

First release!