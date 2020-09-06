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
    a_description = "This is " + Name() + "\nIn this room there are " + std::to_string(m_objects.size()) + " objects"
                    + " and " + std::to_string(m_passages.size()) + " passages";
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

void Room::PlaceObject(const IObject::ObjectPtr& a_object, std::string& a_output)
{
    if(!a_object) {
        a_output = "No object to be placed";
        return;
    }
    m_objects.insert(std::make_pair(a_object->Name(), a_object));
    a_output = a_object->Name() + " has been placed in the room";
}
//void Enter(std::shared_ptr<Player> a_player);
//std::shared_ptr<IRoom> Exit(std::shared_ptr<Player> a_player, std::shared_ptr<IPassage> a_passage);

} //d_d