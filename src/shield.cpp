#include "shield.hpp"

namespace d_d {

Shield::Shield(const std::string& a_name, int a_strength)
: IShield(a_name, a_strength)
{}

void Shield::Describe(std::string& a_description) const
{
    a_description = Name() + " Shield\n" + "Defense = " + std::to_string(GetDefense()); 
}    

} //d_d