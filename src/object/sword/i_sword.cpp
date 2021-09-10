#include "i_sword.hpp"

namespace d_d {

ISword::ISword(const std::string& a_name, unsigned int a_strength, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec)
: IObject(a_name, a_start_pos, a_respawn_sec)
, m_strength(a_strength)
{
}

unsigned int ISword::GetStrength() const
{
    return m_strength;
}

} //d_d