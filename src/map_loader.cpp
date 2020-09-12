#include <algorithm>
#include "map_loader.hpp"

namespace d_d {

MapLoader::MapLoader(const std::shared_ptr<IRoomLoader>& a_room_loader
                    , const std::shared_ptr<IPassageLoader>& a_passage_loader
                    , const std::shared_ptr<IFightableLoader>& a_fightable_loader/*
                    , const std::shared_ptr<IObjectLoader>& a_object_loader*/)
: m_room_loader(a_room_loader)
, m_passage_loader(a_passage_loader)
, m_fightable_loader(a_fightable_loader)
{    
}

void MapLoader::Load(std::vector<std::shared_ptr<IRoom> >& a_rooms) const
{
    m_room_loader->Load("rooms.log", a_rooms);
    std::unordered_map<std::string, std::shared_ptr<IRoom>> room_map;
    std::for_each(a_rooms.begin(), a_rooms.end(), [&](auto obj)
    {
        room_map.insert(std::make_pair(obj->Name(), obj));
    });
    m_passage_loader->Load("passages.log", room_map);
    m_fightable_loader->Load("dragons.log", room_map);
}

} //d_d