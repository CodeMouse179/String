#include "String.hpp"
int main()
{
    System::tstring s = StringT::Empty();
    std::string clone = StringA::Clone("ABC123");
    std::string con = StringA::Concat("ABC", "123");
    std::vector<std::string> values;
    values.push_back("A1");
    values.push_back("B2");
    values.push_back("C3");
    std::string con2 = StringA::Concat(values);
    std::string con3 = StringA::Concat("A1", "B2", "C3", "D4", "E5", "F6", "G7");
    bool eq1 = StringA::Equals("abc", "ABC");
    bool eq2 = StringA::Equals("abc", "ABC", System::StringComparison::IgnoreCase);
    std::string format = StringA::Format("{0} name is {1}.", "My", "ABC");
    int hash = StringA::GetHashCode("ABC123");
    int hash1 = StringA::GetHashCode("ABC123", System::StringComparison::IgnoreCase);
    int hash2 = StringA::GetHashCode("abc123", System::StringComparison::IgnoreCase);
    std::string slice1 = StringA::Slice("123", 1);
    std::string slice2 = StringA::Slice("123", -1);
    std::string slice3 = StringA::Slice("123", 0, 2);
    std::string slice4 = StringA::Slice("123", 0, -1);
    std::string slice5 = StringA::Slice("123", 0, 0);
    auto vector = StringA::Split("A B C 1 2 3", " ");
    return 0;
}