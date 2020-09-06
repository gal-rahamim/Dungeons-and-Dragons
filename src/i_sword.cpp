#include "i_sword.hpp"

namespace d_d {

ISword::ISword(const std::string& a_name, int a_strength)
: IObject(a_name)
, m_strength(a_strength)
{
}

int ISword::GetStrength() const
{
    return m_strength;
}


} //d_d