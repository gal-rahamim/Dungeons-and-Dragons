#include <algorithm>
#include "room.hpp"
#include "i_player.hpp"

namespace d_d {

Room::Room(std::string a_name)
: IRoom(a_name)
, m_objects()
, m_passages()
, m_players()
{   
}

void Room::InitRoom(const std::vector<IObject::ObjectPtr>& a_objects,
                    const std::vector<std::pair<Direction, std::shared_ptr<IPassage> > >& a_passages)
{
    std::for_each(a_passages.begin(), a_passages.end(), [&](auto psg)
    {
        m_passages.insert(psg);
    });
    std::for_each(a_objects.begin(), a_objects.end(), [&](auto obj)
    {
        m_objects.insert(std::make_pair(obj->Name(), obj));
    });
}

void Room::Move(Direction a_direction, std::shared_ptr<IPassage>& a_passage)
{
    auto res = m_passages.find(a_direction);
    if(res == m_passages.end()) {
        a_passage = nullptr;
        return;
    }
    a_passage = res->second;
}

void Room::Describe(std::string& a_description) const
{
    a_description = "This is " + Name() + "\nIn this room there are " + std::to_string(m_objects.size()) + " objects"
                    + ", " + std::to_string(m_passages.size()) + " passages and " + std::to_string(m_players.size()) + " players";
    std::for_each(m_objects.begin(), m_objects.end(), [&](auto obj)
    {
        std::string objDescription;
        obj.second->Describe(objDescription);
        a_description += "\n" + objDescription;
    });
    std::for_each(m_players.begin(), m_players.end(), [&](auto obj)
    {
        a_description += "\n" + obj.second->Name();
    });
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

void Room::Enter(const std::shared_ptr<IPlayer>& a_player)
{
    m_players.insert(std::make_pair(a_player->Name(), a_player));
}

std::shared_ptr<IPlayer> Room::Exit(const std::string& a_playerName)
{
    auto res = m_players.find(a_playerName)->second;
    m_players.erase(a_playerName);
    return res;
}

} //d_d