#include "i_shield.hpp"

namespace d_d {

IShield::IShield(const std::string& a_name, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec, unsigned int a_defense)
: IObject(a_name, a_start_pos, a_respawn_sec)
, m_defense(a_defense) 
{}

unsigned int IShield::GetDefense() const
{
    return m_defense;
}

} //d_d