#ifndef I_OBJECT_HPP
#define I_OBJECT_HPP

#include <string>
#include <memory>

namespace d_d {

class IObject {
public:
    typedef std::shared_ptr<IObject> ObjectPtr;

public:
    IObject(const std::string& a_name);
    virtual ~IObject();
    virtual void Describe(std::string& a_description) const = 0;
    const std::string& Name() const;

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