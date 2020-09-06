#ifndef KEY_HPP
#define KEY_HPP

#include <string>
#include "i_object.hpp"

namespace d_d {

class Key : public IObject {
public:
    Key(const std::string& a_name = "");
    virtual void Describe(std::string& a_description) const;
    bool operator==(const Key& a_other) const;
};

inline Key::Key(const std::string& a_name)
: IObject(a_name)
{}

inline bool Key::operator==(const Key& a_other) const
{
    return Name() == a_other.Name();
}

inline void Key::Describe(std::string& a_description) const
{
    a_description = "Key name: " + Name();
}

} //d_d

#endif //KEY_HPP