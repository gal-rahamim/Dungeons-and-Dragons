#include "key.hpp"

namespace d_d {

Key::Key(const std::shared_ptr<IRoom>& a_start_pos, const std::string& a_name, unsigned int a_respawn_sec)
: IObject(a_name, a_start_pos, a_respawn_sec)
{}

bool Key::operator==(const Key& a_other) const
{
    return Name() == a_other.Name();
}

void Key::Describe(std::string& a_description) const
{
    a_description = "Key name: " + Name();
}

} //d_d
