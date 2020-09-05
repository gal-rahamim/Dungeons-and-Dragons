#include "sword.hpp"

namespace d_d {

Sword::Sword(std::string a_name, int a_strength)
: IObject(a_name)
, m_strength(a_strength)
{
}

void Sword::Describe(std::string& a_description) const
{
    a_description = Name() + " sword\n" + "Strength = " + std::to_string(m_strength); 
}

int Sword::GetStrength() const
{
    return m_strength;
}


} //d_d