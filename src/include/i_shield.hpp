#ifndef I_SHIELD_HPP
#define I_SHIELD_HPP

#include "i_object.hpp"

namespace d_d {

class IShield : public IObject {
public:
    IShield(const std::string& a_name, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec, unsigned int a_defense = 0);
    virtual ~IShield() = default;
    virtual void Describe(std::string& a_description) const = 0;
    unsigned int GetDefense() const;

private:
    unsigned int m_defense;
};

} //d_d

#endif //I_SHIELD_HPP