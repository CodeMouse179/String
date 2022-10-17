#include "String.hpp"
int main()
{
    System::tstring s = StringT::Empty();
    std::string clone = StringA::Clone("ABC123");
    bool eq1 = StringA::Equals("abc", "ABC");
    bool eq2 = StringA::Equals("abc", "ABC", System::StringComparison::IgnoreCase);
    return 0;
}