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
    a_description = "------This is " + Name() + "------\nIn this room there are " + std::to_string(m_objects.size()) + " objects"
                    + ", " + std::to_string(m_passages.size()) + " passages and " + std::to_string(m_players.size()) + " creatures";
    a_description += "\n---Objects---";
    std::for_each(m_objects.begin(), m_objects.end(), [&](auto obj)
    {
        std::string objDescription;
        obj.second->Describe(objDescription);
        a_description += "\n" + objDescription;
    });
    a_description += "\n---Creatures---";
    std::for_each(m_players.begin(), m_players.end(), [&](auto obj)
    {
        std::string fightable_desc;
        obj.second->Describe(fightable_desc);
        a_description += "\n------\n" + fightable_desc;
    });
}

void Room::GetObject(const std::string& a_objectName, std::shared_ptr<IObject>& a_obj, std::string& a_output)
{
    auto res = m_objects.find(a_objectName);
    if(res == m_objects.end()) {
        a_output = "No such object was found";
        a_obj = nullptr;
        return;
    }
    else {
        a_obj = res->second;
        res->second->Respawn();
        m_objects.erase(a_objectName);
        a_output = res->second->Name() + " Obtained";
        return;
    }
}

void Room::AddPassage(const std::pair<Direction, std::shared_ptr<IPassage>>& a_passage)
{
    m_passages.insert(a_passage);
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

void Room::PlaceObjects(const std::vector<IObject::ObjectPtr>& a_objects, std::string& a_output)
{
    std::for_each(a_objects.begin(), a_objects.end(), [&](auto obj)
    {
        m_objects.insert(std::make_pair(obj->Name(), obj));
    });
}

void Room::Enter(const std::shared_ptr<IFightable>& a_player)
{
    m_players.insert(std::make_pair(a_player->Name(), a_player));
}

void Room::Exit(const std::string& a_playerName, std::shared_ptr<IFightable>& a_playerPtr)
{
    auto res = m_players.find(a_playerName);
    if(res == m_players.end()) {
        return;
    }
    a_playerPtr = res->second;
    m_players.erase(a_playerName);
}

void Room::GetFightable(const std::string& a_fightableName, std::shared_ptr<IFightable>& a_fightable) const
{
    auto res = m_players.find(a_fightableName);
    a_fightable = res == m_players.end() ? nullptr : res->second;
}

} //d_d