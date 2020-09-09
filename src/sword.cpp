#include "sword.hpp"

namespace d_d {

Sword::Sword(const std::string& a_name, unsigned int a_strength)
: ISword(a_name, a_strength)
{}

void Sword::Describe(std::string& a_description) const
{
    a_description = Name() + " sword\n" + "Strength = " + std::to_string(GetStrength()); 
}


} //d_d