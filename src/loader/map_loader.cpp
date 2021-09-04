#include <algorithm>
#include "map_loader.hpp"

namespace d_d {

MapLoader::MapLoader(const std::shared_ptr<IRoomLoader>& a_room_loader
                    , const std::shared_ptr<IPassageLoader>& a_passage_loader
                    , const std::shared_ptr<IFightableLoader>& a_fightable_loader
                    , const std::shared_ptr<IObjectLoader>& a_object_loader)
: m_room_loader(a_room_loader)
, m_passage_loader(a_passage_loader)
, m_fightable_loader(a_fightable_loader)
, m_object_loader(a_object_loader)
{    
}

void MapLoader::Load(std::unordered_map<std::string, std::shared_ptr<IRoom> >& a_rooms) const
{
    m_room_loader->Load("rooms.log", a_rooms);
    m_passage_loader->Load("passages.log", a_rooms);
    m_fightable_loader->Load("dragons.log", a_rooms);
    m_object_loader->Load("objects.log", a_rooms);
}

} //d_d