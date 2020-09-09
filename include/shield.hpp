#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "i_shield.hpp"

namespace d_d {

class Shield : public IShield {
public:
    Shield(const std::string& a_name, int a_strength);
    virtual void Describe(std::string& a_description) const;
};

} //d_d

#endif //SHIELD_HPP