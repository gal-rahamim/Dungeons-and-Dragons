#ifndef I_SWORD_HPP
#define I_SWORD_HPP

#include "i_object.hpp"

namespace d_d {

class ISword : public IObject {
public:
    ISword(const std::string&, unsigned int a_strength);
    virtual ~ISword();
    virtual void Describe(std::string& a_description) const = 0;
    unsigned int GetStrength() const;

private:
    unsigned int m_strength;
};

inline ISword::ISword(const std::string& a_name, unsigned int a_strength)
: IObject(a_name)
, m_strength(a_strength)
{
}

inline ISword::~ISword(){}

inline unsigned int ISword::GetStrength() const
{
    return m_strength;
}

} //d_d

#endif //I_SWORD_HPP