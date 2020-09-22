#include "shield.hpp"

namespace d_d {

Shield::Shield(const std::string& a_name, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec, unsigned int a_defense)
: IShield(a_name, a_start_pos, a_respawn_sec, a_defense)
{}

void Shield::Describe(std::string& a_description) const
{
    a_description = Name() + " Shield\n" + "Defense = " + std::to_string(GetDefense()); 
}    

} //d_d