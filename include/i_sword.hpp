#ifndef I_SWORD_HPP
#define I_SWORD_HPP

#include "i_object.hpp"

namespace d_d {

class ISword : public IObject {
public:
    ISword(const std::string&, int a_strength);
    virtual void Describe(std::string& a_description) const = 0;
    int GetStrength() const;

private:
    int m_strength;
};

} //d_d

#endif //I_SWORD_HPP