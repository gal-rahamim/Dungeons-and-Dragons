#ifndef I_SWORD_HPP
#define I_SWORD_HPP

#include "i_object.hpp"

namespace d_d {

class ISword : public IObject {
public:
    ISword(const std::string& a_name, unsigned int a_strength, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec);
    virtual ~ISword();
    virtual void Describe(std::string& a_description) const = 0;
    unsigned int GetStrength() const;

private:
    unsigned int m_strength;
};

} //d_d

#endif //I_SWORD_HPP