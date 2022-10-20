#include "String.hpp"
int main()
{
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
    std::string subStr1 = StringA::Substring("ABCDEFG", 1);
    std::string subStr2 = StringA::Substring("ABCDEFG", 0, 2);
    std::string lower = StringA::ToLower("ABCDEFG");
    std::string upper = StringA::ToUpper("abcdefg");
    std::string trimStr = StringA::Trim("111", '1');
    std::string trimStr1 = StringA::TrimEnd(" ABC ", ' ');
    std::string trimStr2 = StringA::TrimStart(" ABC ", ' ');
    System::tstring wstr1 = StringA::StringToWstring("你好世界", System::StringEncoding::ANSI);
    System::tstring wstr2 = StringA::StringToWstring(U8("你好世界"), System::StringEncoding::UTF8);
    std::string str1 = StringA::WstringToString(T("你好世界"), System::StringEncoding::ANSI);
    std::string str2temp = StringA::WstringToString(T("你好世界"), System::StringEncoding::UTF8);
    System::u8str str2 = StringA::StringToU8string(str2temp);
    return 0;
}