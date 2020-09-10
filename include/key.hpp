#ifndef KEY_HPP
#define KEY_HPP

#include <string>
#include "i_object.hpp"

namespace d_d {

class Key : public IObject {
public:
    Key(const std::shared_ptr<IRoom>& a_start_pos = nullptr, const std::string& a_name = "", unsigned int a_respawn_sec = 20);
    virtual void Describe(std::string& a_description) const;
    bool operator==(const Key& a_other) const;
};

} //d_d

#endif //KEY_HPP