#ifndef SWORD_HPP
#define SWORD_HPP

#include "i_sword.hpp"

namespace d_d {

class Sword : public ISword {
public:
    Sword(const std::string& a_name, int a_strength);
    virtual void Describe(std::string& a_description) const;
};

inline Sword::Sword(const std::string& a_name, int a_strength)
: ISword(a_name, a_strength)
{}

inline void Sword::Describe(std::string& a_description) const
{
    a_description = Name() + " sword\n" + "Strength = " + std::to_string(GetStrength()); 
}

} //d_d

#endif //SWORD_HPP