#define SYSTEM_STRING_CONSOLE
#include "String.hpp"
#include <assert.h> //assert
#include <string.h> //strcpy_s

int format_tutorial()
{
    //output: a:2:3
    std::string format1 = StringA::Format("{0}:{1}:{2}", (char)97, 2, 3);
    //output: 97:2:3
    std::string format2 = StringA::Format("{0}:{1}:{2}", 97, 2, 3);
    return 0;
}

int split_tutorial()
{
    //vector values:1,2,3
    std::vector<std::string> split1 = StringA::Split("1 2 3", ' ');
    return 0;
}

int main()
{
    //tutorials:
    int r1 = format_tutorial();

    int r2 = split_tutorial();

    //U8c Test:
    char u8c = U8c('a');
#ifdef SYSTEM_CXX_20
    char8_t u8cc = U8c('b');
#endif

    //String Equals Testing:
    std::string ansi_latin = "ABCD";
    std::string utf8_latin = U8("ABCD");
    bool latin_equals1 = StringA::Equals(ansi_latin, utf8_latin);

    std::string ansi_chinese = "你好世界";
    std::string utf8_chinese = U8("你好世界");
    std::string ansi_utf8_chinese = StringA::ConvertString(ansi_chinese, System::StringEncoding::ANSI, System::StringEncoding::UTF8);
    std::string wide_char_utf8_chinese = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    bool chinese_equals1 = StringA::Equals(ansi_chinese, utf8_chinese);
    bool chinese_equals2 = StringA::Equals(ansi_utf8_chinese, utf8_chinese);
    bool chinese_equals3 = StringA::Equals(wide_char_utf8_chinese, utf8_chinese);

    //测试修改不同字符串的字符:
    const char* utf8ConstBuf = U8s("你好世界");
    char utf8Buf[100] = { 0 };
#ifdef SYSTEM_WINDOWS
    strcpy_s(utf8Buf, U8s("你好世界"));          //使用C语言的方式给字符串数组赋值
#else
    strcpy(utf8Buf, U8s("你好世界"));            //使用C语言的方式给字符串数组赋值
#endif
    utf8Buf[0] = 'a';                           //修改UTF-8字符串, 修改之后字符串已经损坏，不可读取
    wchar_t buf[10] = L"你好世界";               //L"你好世界"
    buf[0] = L'a';                              //L"a好世界"

    //不同字符串的遍历与转换:
    std::u32string nihaoshijieU32 = U"ABCD你好世界!";
    std::wstring nihaoshijieW;
    for (int i = 0; i < nihaoshijieU32.size(); i++)
    {
        nihaoshijieW.push_back((wchar_t)nihaoshijieU32[i]);
    }
    std::string nihaoshijieU8 = StringA::To_UTF8(nihaoshijieW);
    StringA::WriteLine(nihaoshijieU8, 255, 140, 0);

    //char, wchar_t, char16_t, char32_t Testing:
    //不同类型的char储存ASCII以外的字符时，只要不发生数值越界，其值相同。
    //注意：不要使用char类型储存ASCII字符以外的文字。

    char ascii1 = 'a';           //value:97
    wchar_t ascii2 = L'a';       //value:97
    char16_t ascii3 = u'a';      //value:97
    char32_t ascii4 = U'a';      //value:97
    int asciiInt1 = 97;          //value:97

    assert(ascii1 == ascii2);    //OK!
    assert(ascii2 == ascii3);    //OK!
    assert(ascii3 == ascii4);    //OK!
    assert(ascii4 == asciiInt1); //OK!

    char ch1 = '你';             //data value overflow!
    wchar_t ch2 = L'你';         //Unicode value:20320
    char16_t ch3 = u'你';        //Unicode value:20320
    char32_t ch4 = U'你';        //Unicode value:20320
    int ni1 = 20320;             //value:20320

    //assert(ch1 == ch2);       //assert error!
    assert(ch2 == ch3);         //OK!
    assert(ch3 == ch4);         //OK!
    assert(ch4 == ni1);         //OK!

    char _ch1 = '🧐';            //data value overflow!
    wchar_t _ch2 = L'🧐';        //data value overflow!
    //char16_t _ch3 = u'🧐';     //compile error!
    char32_t _ch4 = U'🧐';       //Unicode value:129488
    int wen1 = 129488;           //value:129488

    //assert(_ch1 == _ch2);     //assert error!
#ifdef SYSTEM_LINUX
    assert(_ch2 == _ch4);       //Windows assert error, Linux OK!
#endif
    assert(_ch4 == wen1);       //OK!

    //获得char类型组成的空字符串：
    std::string empty = System::String<char>::Empty();
    //通过使用StringA宏，获得char类型组成的空字符串：
    std::string emtpyA = StringA::Empty();

    //获得wchar_t类型组成的空字符串：
    std::wstring empty2 = System::String<wchar_t>::Empty();
    //通过使用StringW宏，获得wchar_t类型组成的空字符串：
    std::wstring empty2W = StringW::Empty();

    //获得char16_t类型组成的空字符串：
    std::u16string empty3 = System::String<char16_t>::Empty();
    //通过使用StringU16宏，获得char16_t类型组成的空字符串：
    std::u16string empty3U16 = StringU16::Empty();

    //获得char32_t类型组成的空字符串：
    std::u32string empty4 = System::String<char32_t>::Empty();
    //通过使用StringU32宏，获得char32_t类型组成的空字符串：
    std::u32string empty4U32 = StringU32::Empty();

    //String::Format, output:"Anna is your Wife."
    std::string format_str = System::String<char>::Format("{0} is your {1}.", "Anna", "Wife");

    //String::StringToWstring, output:L"Hello World"(on Windows) or "Hello World"(on Linux)
    System::tstring hello_world = System::String<char>::StringToWstring(U8("Hello World"), System::StringEncoding::UTF8);

    //String::WstringToString, output:"Hello World"
    std::string hello_world2 = System::String<char>::WstringToString(T("Hello World"), System::StringEncoding::UTF8);

    //String::IsValidUTF8, output:true
    bool is_utf8_str = System::String<char>::IsValidUTF8(U8("你好世界"));

    //String::UTF8CharCount, output:7
    int count = System::String<char>::UTF8CharCount(U8("你好世界123"));

    int version = SYSTEM_STRING_VERSION;
    System::tstring s = StringT::Empty();
    std::string clone = StringA::Clone("ABC123");
    int compare = StringA::Compare("a1", "1a");
    int compare2 = StringA::Compare("A1", "a1", System::StringComparison::IgnoreCase);
    std::string con = StringA::Concat("ABC", "123");
    std::vector<std::string> values;
    values.push_back("A1");
    values.push_back("B2");
    values.push_back("C3");
    std::string con2 = StringA::Concat(values);
    std::string con3 = StringA::Concat("A1", "B2", "C3", "D4", "E5", "F6", "G7");
    bool contains = StringA::Contains("ABC123", "C12");
    bool contains2 = StringA::Contains("ABC123", "c12", System::StringComparison::IgnoreCase);
    std::string copy = StringA::Copy("ABCD你好呀");
    bool endWith1 = StringA::EndsWith("ABCDEFG", "EFg");
    bool endWith2 = StringA::EndsWith("ABCDEFG", "EFg", System::StringComparison::IgnoreCase);
    bool eq1 = StringA::Equals("abc", "ABC");
    bool eq2 = StringA::Equals("abc", "ABC", System::StringComparison::IgnoreCase);
    std::string format = StringA::Format("{0} name is {1}.", "My", "ABC");
    int hash = StringA::GetHashCode("ABC123");
    int hash1 = StringA::GetHashCode("ABC123", System::StringComparison::IgnoreCase);
    int hash2 = StringA::GetHashCode("abc123", System::StringComparison::IgnoreCase);
    int typeCode = StringA::GetTypeCode();
    int index1 = StringA::IndexOf("123456", "3");
    int index2 = StringA::IndexOf("123456", '3');
    int index11 = StringA::IndexOf("ABCDEFG", "d", System::StringComparison::IgnoreCase);
    int index111 = StringA::IndexOf("ABCDEFG", "d", System::StringComparison::None);
    int index22 = StringA::IndexOf("ABCDEFG", 'd', System::StringComparison::IgnoreCase);
    int index222 = StringA::IndexOf("ABCDEFG", 'd', System::StringComparison::None);
    std::string insert_str = StringA::Insert("ABCDEFG", 4, "OPQ");
    std::string join_str1 = StringA::Join(" ", { "A", "B", "C", "D" });
    std::string join_str2 = StringA::Join(' ', { "A", "B", "C", "D" });
    int index3 = StringA::LastIndexOf("654321", "1");
    int index4 = StringA::LastIndexOf("654321", '1');
    int index33 = StringA::LastIndexOf("ABCDEFG", "b", System::StringComparison::IgnoreCase);
    int index333 = StringA::LastIndexOf("ABCDEFG", "b", System::StringComparison::None);
    int index44 = StringA::LastIndexOf("ABCDEFG", 'b', System::StringComparison::IgnoreCase);
    int index444 = StringA::LastIndexOf("ABCDEFG", 'b', System::StringComparison::None);
    std::string remove1 = StringA::Remove("ABCDEFG", 2);
    std::string remove2 = StringA::Remove("ABCDEFG", 2, 3);
    std::string replace1 = StringA::Replace("ABCD", "C", "");
    std::string replace2 = StringA::Replace("ABCD", 'C', 0);
    std::string replace3 = StringA::Replace("ABCD", "c", "", System::StringComparison::IgnoreCase);
    std::string replace4 = StringA::Replace("ABCD", "c", "", System::StringComparison::None);
    std::string replace33 = StringA::Replace("ABCD", 'c', 0, System::StringComparison::IgnoreCase);
    std::string replace44 = StringA::Replace("ABCD", 'c', 0, System::StringComparison::None);
    auto reversed_stra = StringA::Reverse(U8("你好世界"));
    auto reversed_stra2w = StringA::StringToWstring(reversed_stra, System::StringEncoding::UTF8);
    auto reversed_stra2 = StringA::Reverse(S("你好世界ABCD"));
    auto reversed_stra22w = StringA::StringToWstring(reversed_stra2, System::StringEncoding::ANSI);
    auto reversed_strw = StringA::Reverse(W("你好世界"));
#ifdef SYSTEM_CXX_20
    auto reversed_stru8 = StringA::Reverse(U8S("你好世界"));
#endif
    auto reversed_stru16 = StringA::Reverse(U16("你好世界"));
    auto reversed_stru32 = StringA::Reverse(U32("你好世界"));
    std::string slice1 = StringA::Slice("123", 1);
    std::string slice2 = StringA::Slice("123", -1);
    std::string slice3 = StringA::Slice("123", 0, 2);
    std::string slice4 = StringA::Slice("123", 0, -1);
    std::string slice5 = StringA::Slice("123", 0, 0);
    auto vector1 = StringA::Split("A B C 1 2 3", " ");
    auto vector2 = StringA::Split("A B C 1 2 3", "");
    auto vector3 = StringA::Split("A B C 1 2 3", ' ');
    bool startsWith1 = StringA::StartsWith("ABCDEFG", "ABc");
    bool startsWith2 = StringA::StartsWith("ABCDEFG", "ABc", System::StringComparison::IgnoreCase);
    std::string subStr1 = StringA::Substring("ABCDEFG", 1);
    std::string subStr2 = StringA::Substring("ABCDEFG", 0, 2);
    std::vector<char> charArray1 = StringA::ToCharArray("ABCDEFG");
    std::vector<char> charArray2 = StringA::ToCharArray("ABCDEFG", 5, 2);
    std::string lower = StringA::ToLower("ABCDEFG");
    auto to_lower = StringU32::ToLower(U32('N'));
    std::string to_string1 = StringA::ToString("你好世界");
    std::string to_string2 = StringA::ToString('你');
    std::wstring to_string3 = StringW::ToString(W('你'));
    std::string to_string4 = StringA::ToString(999);
    std::string upper = StringA::ToUpper("abcdefg");
    auto to_upper = StringU32::ToUpper(U32('n'));
    std::string trimStrS1 = StringA::Trim("你好世界你", "你");
    std::string trimStr = StringA::Trim("111", '1');
    std::wstring _trimStr = StringW::Trim(W(" 你好世界 "));
    std::string trimStrS2 = StringA::TrimEnd("你好世界你", "你");
    std::string trimStr1 = StringA::TrimEnd(" ABC ", ' ');
    std::wstring _trimStr1 = StringW::TrimEnd(W(" 你好世界 "));
    std::string trimStrS3 = StringA::TrimStart("你好世界你", "你");
    std::string trimStr2 = StringA::TrimStart(" ABC ", ' ');
    std::wstring _trimStr2 = StringW::TrimStart(W(" 你好世界 "));
    System::tstring wstr1 = StringA::StringToWstring("你好世界", System::StringEncoding::ANSI);
    System::tstring wstr2 = StringA::StringToWstring(U8("你好世界"), System::StringEncoding::UTF8);
    std::string str1 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ANSI);
    std::string str2temp = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    System::u8str str2 = StringA::StringToU8string(str2temp);
    std::u16string u16 = U16("你好世界");
    std::u32string u32 = U32("你好世界");
    std::string s1 = StringA::To_UTF8(U16("你好世界"));
    std::string s2 = StringA::To_UTF8(U32("你好世界"));
    std::string s3 = StringA::To_UTF8(W("你好世界"));
    std::u16string us1 = StringA::To_UTF16(U8("你好世界"));
    std::u16string us2 = StringA::To_UTF16(U32("你好世界"));
    std::u16string us3 = StringA::To_UTF16(W("你好世界"));
    std::u32string Us1 = StringA::To_UTF32(U8("你好世界"));
    std::u32string Us2 = StringA::To_UTF32(U16("你好世界"));
    std::u32string Us3 = StringA::To_UTF32(W("你好世界"));
    std::string utf8_str = StringA::To_String(W("你好世界"));
    std::wstring wide_str1 = StringA::To_Wstring(utf8_str);
    std::wstring wide_str2 = StringA::To_Wstring(U8("你好世界"));

    auto zxcxz = StringA::ConvertString(U8("你好世界"), System::StringEncoding::UTF8, (System::StringEncoding)950);
    auto xczzz = StringA::StringToWstring(zxcxz, (System::StringEncoding)950);

    //Extra Util 1:
    bool IsValidASCII1 = StringA::IsValidASCII(S("ABCD"));
    bool IsValidASCII2 = StringA::IsValidASCII(S("你好世界"));

    int ASCIICharCount1 = StringA::ASCIICharCount(S("ABCD"));
    int ASCIICharCount2 = StringA::ASCIICharCount(S("你好世界"));

    auto ASCIIToCharArray1 = StringA::ASCIIToCharArray(S("ABCD"));
    auto ASCIIToCharArray2 = StringA::ASCIIToCharArray(S("你好世界"));

    std::string codePointToASCII1 = StringA::CodePointToASCII(ASCIIToCharArray1);
    std::string codePointToASCII2 = StringA::CodePointToASCII(ASCIIToCharArray2);

    bool isUTF8_1 = StringA::IsValidUTF8(U8("你好世界"));
    bool isUTF8_2 = StringA::IsValidUTF8(S("你好世界"));

    int charCount1 = StringA::UTF8CharCount(U8("你好世界ABC123"));
    int charCount2 = StringA::UTF8CharCount(S("你好世界ABC123"));

    auto utf8CharArray1 = StringA::UTF8ToCharArray(U8("你好世界"));
#ifdef SYSTEM_CXX_20
    auto utf8CharArray2 = StringA::UTF8ToCharArray(U8S("你好世界"));
#endif

    std::string codePointToUTF8String1 = StringA::CodePointToUTF8(U32('😄'));
    auto ca = StringA::UTF8ToCharArray(codePointToUTF8String1);
    std::vector<int> codePoints{ U32('😄') };
    std::string codePointToUTF8String2 = StringA::CodePointToUTF8(codePoints);
    std::string codePointToUTF8String3 = StringA::CodePointToUTF8(U32("你好世界"));
    std::string codePointANSIString1 = StringA::ConvertString(codePointToUTF8String3, System::StringEncoding::UTF8, System::StringEncoding::ANSI);

    std::string codePointToUTF8String4 = StringA::CodePointToUTF8(utf8CharArray1);

    bool IsValidUTF16_1 = StringA::IsValidUTF16(T("你好世界"));
    bool IsValidUTF16_2 = StringA::IsValidUTF16(U16("你好世界"));

    int UTF16CharCount_1 = StringA::UTF16CharCount(T("你好世界😄"));
    int UTF16CharCount_2 = StringA::UTF16CharCount(U16("你好世界😄"));

    std::u32string utf32TestChar = U32("你好世界😄");
    auto utf16CharArray1 = StringA::UTF16ToCharArray(T("你好世界😄"));
    auto utf16CharArray2 = StringA::UTF16ToCharArray(U16("你好世界😄"));

    std::u16string codePointToUTF16_1 = StringA::CodePointToUTF16(U32("你好世界"));
    auto charArray = StringA::UTF16ToCharArray(codePointToUTF16_1);
    std::u32string utf32_str1 = StringA::To_UTF32(codePointToUTF16_1);

    std::u16string codePointToUTF16_2 = StringA::CodePointToUTF16(utf16CharArray1);

    //Extra Util 2:
    std::string UTF16String1 = StringA::UTF16ToUTF16String(U16("你好世界"));
    bool IsValidUTF16String1 = StringA::IsValidUTF16String(UTF16String1);
    int UTF16StringCharCount1 = StringA::UTF16StringCharCount(UTF16String1);
    auto UTF16StringToCharArray1 = StringA::UTF16StringToCharArray(UTF16String1);

    //Extra Function 1:

    std::string trueStringA = StringA::GetTrueString();
    std::string falseStringA = StringA::GetFalseString();

    std::wstring trueStringW = StringW::GetTrueString();
    std::wstring falseStringW = StringW::GetFalseString();

    std::u16string trueStringU16 = StringU16::GetTrueString();
    std::u16string falseStringU16 = StringU16::GetFalseString();

    std::u32string trueStringU32 = StringU32::GetTrueString();
    std::u32string falseStringU32 = StringU32::GetFalseString();

    bool isNumeric1 = StringA::IsNumeric("123");
    bool isNumeric2 = StringA::IsNumeric("123a");

    bool isEmptyOrWhiteSpace1 = StringA::IsEmptyOrWhiteSpace("   ");
    bool isEmptyOrWhiteSpace2 = StringA::IsEmptyOrWhiteSpace("");
    bool isEmptyOrWhiteSpace3 = StringA::IsEmptyOrWhiteSpace("ABCD");

    //Russian Test:
    //Output:здравствуйте, Expected output:ЗДРАВСТВУЙТЕ
    //TODO:Implement a language-independent ToUpper function
    //不依赖C++提供的函数:toupper与tolower
    std::u32string upperRussian = StringU32::ToUpper(U32("здравствуйте"));

    //Linux Test 1:
    std::wstring linuxTestWstring1 = StringA::StringToWstring(U8("Linux, 你好!"));
    std::string linuxTestString1 = StringA::WstringToString(linuxTestWstring1);
    StringA::WriteLine(linuxTestString1, 0, 255, 0);

    //Linux Test 2:
    std::u32string linuxTestU32string1 = StringA::WstringToU32string(W("Linux, 你还好吗?"));
    std::wstring linuxTestWstring2 = StringA::U32stringToWstring(linuxTestU32string1);
    std::string linuxTestString2 = StringA::WstringToString(linuxTestWstring2);
    StringA::WriteLine(linuxTestString2, 133, 133, 192);

    //StringToWstring/WstringToString Testing:
    //Output:"你好世界"
    std::string errorTest_1 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ANSI);
    //Output:"????"
    std::string errorTest_2 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ASCII);
    //Output:"浣犲ソ涓栫晫"
    std::string errorTest_3 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    //Output:""
    std::string errorTest_4 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF16LE);
    //Output:""
    std::string errorTest_5 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF16BE);
    //Output:""
    std::string errorTest_6 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF32LE);
    //Output:""
    std::string errorTest_7 = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF32BE);

    //Emoji Test:
    StringA::WriteLine(U8("😄😄😄😆😆😆"));

    //Console Function 1:
    StringA::WriteLine(U8("你好世界!"), 255, 0, 0);
    bool writeSuccess1 = StringA::WriteLine(U8("Please Input Something:"), 255, 255, 255);
    std::string readLine = StringA::ReadLine();
    bool writeSuccess2 = StringA::WriteLine(readLine, 255, 255, 255);
    int readChar = StringA::Read();

    return 0;
}