#ifndef KEY_HPP
#define KEY_HPP

#include <string>

namespace d_d {

class Key {
public:
    Key();
    Key(const std::string& a_name);

    bool operator==(const Key& a_other) const;
private:
    std::string m_name;
};

inline Key::Key()
: m_name("")
{}

inline Key::Key(const std::string& a_name)
: m_name(a_name)
{}

inline bool Key::operator==(const Key& a_other) const
{
    return m_name == a_other.m_name;
}

} //d_d

#endif //KEY_HPP