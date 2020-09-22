#ifndef I_OBJECT_HPP
#define I_OBJECT_HPP

#include <string>
#include <memory>
#include <thread>

namespace d_d {

class IRoom;

class IObject : public std::enable_shared_from_this<IObject> {
public:
    typedef std::shared_ptr<IObject> ObjectPtr;

public:
    IObject(const std::string& a_name, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec = 20);
    virtual ~IObject();
    virtual void Describe(std::string& a_description) const = 0;
    void Respawn();
    const std::string& Name() const;

private:
    std::string m_name;
    const std::shared_ptr<IRoom> m_start_pos;
    std::shared_ptr<std::thread> m_wait_respawn;
    unsigned int m_respawn_sec;
};

} //d_d

#endif //I_OBJECT_HPPs