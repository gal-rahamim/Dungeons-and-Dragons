#include <algorithm>
#include "room.hpp"

namespace d_d {

Room::Room(std::string a_name)
: IRoom(a_name)
, m_objects()
, m_passages()
{
    
}

void Room::InitRoom(const std::vector<IObject::ObjectPtr>& a_objects, const std::vector<std::shared_ptr<IPassage>>& a_passages)
{
    m_passages = a_passages;
    std::for_each(a_objects.begin(), a_objects.end(), [&](auto obj)
    {
        m_objects.insert(std::make_pair(obj->Name(), obj));
    });
}

void Room::Describe(std::string& a_description) const
{

}

std::shared_ptr<IObject> Room::GetObject(const std::string& a_objectName, std::string& a_output)
{
    auto res = m_objects.find(a_objectName);
    if(res == m_objects.end()) {
        a_output = "No such object was found";
        return nullptr;
    }
    else {
        m_objects.erase(a_objectName);
        a_output = res->second->Name() + " Obtained";
        return res->second;
    }
}

void Room::PlaceObject(IObject::ObjectPtr a_object, std::string& a_output)
{

}
//void Enter(std::shared_ptr<Player> a_player);
//std::shared_ptr<IRoom> Exit(std::shared_ptr<Player> a_player, std::shared_ptr<IPassage> a_passage);
// std::string Room::Name() const
// {
//     return m_name;
// }

} //d_d