#ifndef I_SHIELD_HPP
#define I_SHIELD_HPP

#include "i_object.hpp"

namespace d_d {

class IShield : public IObject {
public:
    IShield(const std::string& a_name, unsigned int a_defense = 0);
    virtual ~IShield();
    virtual void Describe(std::string& a_description) const = 0;
    unsigned int GetDefense() const;

private:
    unsigned int m_defense;
};

inline IShield::IShield(const std::string& a_name, unsigned int a_defense)
: IObject(a_name)
, m_defense(a_defense) 
{}

inline IShield::~IShield(){}

inline unsigned int IShield::GetDefense() const
{
    return m_defense;
}

} //d_d

#endif //I_SHIELD_HPP