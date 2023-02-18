# Changelog

## History

### 1.30.0

Release Date : 2023/2/18

Added : String::ConsoleSendCommand(function), String::InitConsole(function), String::DeinitConsole(function), String::SetCursorPosition(function)

### 1.29.0

Release Date : 2023/2/2

Added : SYSTEM_POSIX(macro), String::WindowWidth(function), String::WindowHeight(function)

### 1.28.2

Release Date : 2023/1/31

Fixed : #ifdef SYSTEM_STRING_CONSOLE => #if defined(SYSTEM_STRING_CONSOLE) && !defined(SYSTEM_STRING_ONLY)

### 1.28.1

Release Date : 2023/1/29

Fixed : add #include cstring on Linux, strlen => std::strlen

### 1.28.0

Release Date : 2023/1/28

Added : SYSTEM_MACOS(macro), add macOS Headers

Changed : #ifdef SYSTEM_LINUX => #if defined(SYSTEM_LINUX) || defined(SYSTEM_MACOS)

### 1.27.0

Release Date : 2023/1/15

Added : String::ToBoolean(function), String::ToInt32(function), String::ToString(overload function)

### 1.26.3

Release Date : 2022/12/11

Changed : rename StringComparison => System::StringComparison in code

### 1.26.2

Release Date : 2022/12/11

Desc : rename 1.26.1-emergency repair patch 1 => 1.26.2

### 1.26.1-emergency repair patch 1

Release Date : 2022/12/11

Added : BuiltInConsole::oldInput(field), BuiltInConsole::ResetInput(function)

Changed : add BuiltInConsole::Init Linux support, String::KeyAvailable, String::ReadKey

### 1.26.1

Release Date : 2022/12/11

Added : #include sys/ioctl.h

Changed : impl String::KeyAvailable

### 1.26.0-emergency repair patch 3

Release Date : 2022/12/11

Fixed : fix String::ReadKey Linux support

### 1.26.0-emergency repair patch 2

Release Date : 2022/12/11

Fixed : fix String::ReadKey Linux support

### 1.26.0-emergency repair patch 1

Release Date : 2022/12/11

Fixed : fix String::ReadKey Linux support

### 1.26.0-emergency repair

Release Date : 2022/12/11

Fixed : fix String::ReadKey Linux support

### 1.26.0

Release Date : 2022/12/11

Added : SYSTEM_CXX(macro), #include termio.h, String::KeyAvailable

Changed : add String::ReadKey Linux support

### 1.25.1

Release Date : 2022/12/10

Changed : String::ReadKey

Fixed : add BuiltInConsoleKey::BuiltInConsoleKey, fix String::ReadLineEx bug

### 1.25.0

Release Date : 2022/12/10

Added : BuiltInConsole::TempChar(field), BuiltInConsole::NoProblem(function), System::BuiltInConsoleKey(struct), System::color(typedef), String::ReadKey(function), String::ReadLineEx(function)

Changed : define SYSTEM_STRING_CONSOLE macro to enable console functions, String::ReadLine, String::Write, String::WriteLine

### 1.24.0

Release Date : 2022/12/9

Added : String::UTF32ToUTF32String(function), String::IsValidUTF32String(function), String::UTF32StringCharCount(function), String::UTF32StringToCharArray(function)

### 1.23.0

Release Date : 2022/12/4

Added : String::StringToWstring2(function), String::WstringToString2(function)

### 1.22.0

Release Date : 2022/11/27

Added : String::IndexOf(overload function), String::LastIndexOf(overload function), String::Replace(overload function), String::Trim(overload function), String::TrimEnd(overload function), String::TrimStart(overload function)

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

Added : #include unistd.h, String::WstringToU16string(function), String::U16stringToWstring(function), String::To_Wstring(overload function)

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

Added : SYSTEM_STRING_VERSION_MAJOR(macro), SYSTEM_STRING_VERSION_MINOR(macro), SYSTEM_STRING_VERSION_PATCH(macro)

Changed : SYSTEM_STRING_ONLY macro normally works now

### 0.20.1

Release Date : 2022/10/23

Changed : #define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS only when _MSC_VER is enabled

### 0.20.0

Release Date : 2022/10/23

Added : String::EndsWith(function), String::StartsWith(function)

### 0.19.1

Release Date : 2022/10/23

Changed : String::Clone, String::FormatHelper

### 0.19.0

Release Date : 2022/10/23

Added : SYSTEM_CXX_11(macro), SYSTEM_CXX_14(macro), SYSTEM_CXX_17(macro)

Changed : String::Equals

### 0.18.0

Release Date : 2022/10/23

Added : S(macro), W(macro), String::To_String(function), String::To_Wstring(function)

### 0.17.2

Release Date : 2022/10/23

Fixed : String::To_UTF16, String::To_UTF32

### 0.17.1

Release Date : 2022/10/23

Added : add #include locale on Linux

### 0.17.0

Release Date : 2022/10/23

Added : _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS(macro), add #include codecvt, String::To_UTF8(function), String::To_UTF16(function), String::To_UTF32(function)

### 0.16.0

Release Date : 2022/10/22

Added : U16(macro), U32(macro)

### 0.15.0

Release Date : 2022/10/21

Added : SYSTEM_CXX_20(macro), U8(macro), u8str(typedef), u8char(typedef), String::StringToU8string(function), String::U8stringToString(function)

### 0.14.0

Release Date : 2022/10/20

Added : SYSTEM_WINDOWS(macro), SYSTEM_LINUX(macro), add #include Windows.h, System::StringEncoding(enum class), String::StringToWstring(function), String::WstringToString(function)

Changed : #ifdef _WIN32 => #ifdef SYSTEM_WINDOWS

### 0.13.0

Release Date : 2022/10/18

Added : String::IndexOf(function), String::LastIndexOf(function)

### 0.12.0

Release Date : 2022/10/18

Added : String::Substring(function)

### 0.11.0

Release Date : 2022/10/18

Added : String::Trim(function), String::TrimEnd(function), String::TrimStart(function)

### 0.10.1

Release Date : 2022/10/18

Changed : String::GetHashCode

### 0.10.0

Release Date : 2022/10/18

Added : String::Compare(function), String::Contains(function), String::ToLower(function)

### 0.9.0

Release Date : 2022/10/18

Added : String::Slice(function)

### 0.8.0

Release Date : 2022/10/18

Added : String::Split(function)

### 0.7.0

Release Date : 2022/10/18

Added : String::GetHashCode(function)

Changed : System::StringComparison, String::Equals

### 0.6.0

Release Date : 2022/10/18

Added : String::ConcatHelper(private function), String::Concat(function)

### 0.5.0

Release Date : 2022/10/18

Added : #include vector, String::Concat(function)

### 0.4.0

Release Date : 2022/10/18

Added : #include sstream, String::FormatHelper(private function), String::Format(function)

### 0.3.1

Release Date : 2022/10/17

Fixed : add #include algorithm, #include cctype

### 0.3.0

Release Date : 2022/10/17

Added : System::StringComparison(enum class), String::Clone(function), String::Equals(function)

### 0.2.0

Release Date : 2022/10/17

Added : T(macro)

### 0.1.0

Release Date : 2022/10/17

Added : String.hpp