#include "String.hpp"
int main()
{
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
    bool endWith1 = StringA::EndsWith("ABCDEFG", "EFg");
    bool endWith2 = StringA::EndsWith("ABCDEFG", "EFg", System::StringComparison::IgnoreCase);
    bool eq1 = StringA::Equals("abc", "ABC");
    bool eq2 = StringA::Equals("abc", "ABC", System::StringComparison::IgnoreCase);
    std::string format = StringA::Format("{0} name is {1}.", "My", "ABC");
    int hash = StringA::GetHashCode("ABC123");
    int hash1 = StringA::GetHashCode("ABC123", System::StringComparison::IgnoreCase);
    int hash2 = StringA::GetHashCode("abc123", System::StringComparison::IgnoreCase);
    int index1 = StringA::IndexOf("123456", "3");
    int index2 = StringA::IndexOf("123456", '3');
    int index3 = StringA::LastIndexOf("654321", "1");
    int index4 = StringA::LastIndexOf("654321", "1");
    std::string slice1 = StringA::Slice("123", 1);
    std::string slice2 = StringA::Slice("123", -1);
    std::string slice3 = StringA::Slice("123", 0, 2);
    std::string slice4 = StringA::Slice("123", 0, -1);
    std::string slice5 = StringA::Slice("123", 0, 0);
    auto vector = StringA::Split("A B C 1 2 3", " ");
    bool startsWith1 = StringA::StartsWith("ABCDEFG", "ABc");
    bool startsWith2 = StringA::StartsWith("ABCDEFG", "ABc", System::StringComparison::IgnoreCase);
    std::string subStr1 = StringA::Substring("ABCDEFG", 1);
    std::string subStr2 = StringA::Substring("ABCDEFG", 0, 2);
    std::string lower = StringA::ToLower("ABCDEFG");
    std::string upper = StringA::ToUpper("abcdefg");
    std::string trimStr = StringA::Trim("111", '1');
    std::wstring _trimStr = StringW::Trim(W(" 你好世界 "));
    std::string trimStr1 = StringA::TrimEnd(" ABC ", ' ');
    std::wstring _trimStr1 = StringW::TrimEnd(W(" 你好世界 "));
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
    std::u16string us1 = StringA::To_UTF16(U8("你好世界"));
    std::u16string us2 = StringA::To_UTF16(U32("你好世界"));
    std::u32string Us1 = StringA::To_UTF32(U8("你好世界"));
    std::u32string Us2 = StringA::To_UTF32(U16("你好世界"));
    std::string utf8_str = StringA::To_String(W("你好世界"));
    std::wstring wide_str1 = StringA::To_Wstring(utf8_str);
    std::wstring wide_str2 = StringA::To_Wstring(U8("你好世界"));
    bool isUTF8_1 = StringA::IsValidUTF8(U8("你好世界"));
    bool isUTF8_2 = StringA::IsValidUTF8("你好世界");
    int charCount = StringA::UTF8CharCount(U8("你好世界ABC123"));
    auto zxcxz = StringA::ConvertString(U8("你好世界"), System::StringEncoding::UTF8, (System::StringEncoding)950);
    auto xczzz = StringA::StringToWstring(zxcxz, (System::StringEncoding)950);
    return 0;
}