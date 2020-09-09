#ifndef SWORD_HPP
#define SWORD_HPP

#include "i_sword.hpp"

namespace d_d {

class Sword : public ISword {
public:
    Sword(const std::string& a_name, unsigned int a_strength);
    virtual void Describe(std::string& a_description) const;
};

} //d_d

#endif //SWORD_HPP