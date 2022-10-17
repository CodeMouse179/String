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
    bool eq1 = StringA::Equals("abc", "ABC");
    bool eq2 = StringA::Equals("abc", "ABC", System::StringComparison::IgnoreCase);
    std::string format = StringA::Format("{0} name is {1}.", "My", "ABC");
    return 0;
}