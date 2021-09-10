#include "sword.hpp"

namespace d_d {

Sword::Sword(const std::string& a_name, unsigned int a_strength, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec)
: ISword(a_name, a_strength, a_start_pos, a_respawn_sec)
{}

void Sword::Describe(std::string& a_description) const
{
    a_description = "Sword: '" + Name() + "', Strength = " + std::to_string(GetStrength()); 
}


} //d_d