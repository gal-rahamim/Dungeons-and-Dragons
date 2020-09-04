#ifndef I_OBJECT_HPP
#define I_OBJECT_HPP

#include <string>

namespace d_d {

class IObject {
public:
    IObject(const std::string& a_name);
    virtual ~IObject();
    virtual void Describe(std::string& a_description) = 0;

private:
    std::string m_name;
};

inline IObject::IObject(const std::string& a_name)
: m_name(a_name)
{
}

inline IObject::~IObject() {}

} //d_d

#endif //I_OBJECT_HPPs