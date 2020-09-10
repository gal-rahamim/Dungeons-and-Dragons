#include <chrono> 
#include "i_object.hpp"
#include "i_room.hpp"

namespace d_d {

void waitNsecAndThenRespawn(std::shared_ptr<IObject> a_obj, const std::shared_ptr<IRoom>& a_location, unsigned int a_sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(a_sec));
    if(a_location){
        std::string out;
        a_location->PlaceObject(a_obj, out);
    }
}

IObject::IObject(const std::string& a_name, const std::shared_ptr<IRoom>& a_start_pos, unsigned int a_respawn_sec)
: m_name(a_name)
, m_start_pos(a_start_pos)
, m_wait_respawn()
, m_respawn_sec(a_respawn_sec)
{
}

IObject::~IObject() 
{
    m_wait_respawn->join();
}

void IObject::Respawn(std::shared_ptr<IObject>& a_self)
{
    m_wait_respawn = std::make_shared<std::thread>(waitNsecAndThenRespawn, a_self, std::ref(m_start_pos), m_respawn_sec);
}

const std::string& IObject::Name() const
{
    return m_name;
}

} //d_d