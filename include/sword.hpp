#ifndef SWORD_HPP
#define SWORD_HPP

#include "i_object.hpp"

namespace d_d {

class Sword : public IObject {
public:
    Sword(std::string a_name, int a_strength);
    virtual void Describe(std::string& a_description) const;
    int GetStrength() const;

private:
    int m_strength;
};

} //d_d

#endif //SWORD_HPP