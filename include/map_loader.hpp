#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include "i_map_loader.hpp"
#include "i_room_loader.hpp"
#include "i_passage_loader.hpp"
#include "i_fightable_loader.hpp"
// #include "i_object_loader.hpp"

namespace d_d {

class MapLoader : public IMapLoader {
public:
    MapLoader(const std::shared_ptr<IRoomLoader>& a_room_loader
            , const std::shared_ptr<IPassageLoader>& a_passage_loader
            , const std::shared_ptr<IFightableLoader>& a_fightable_loader/*
            , const std::shared_ptr<IObjectLoader>& a_object_loader*/);
    virtual void Load(std::vector<std::shared_ptr<IRoom> >& a_rooms) const;

private:
    std::shared_ptr<IRoomLoader> m_room_loader;
    std::shared_ptr<IPassageLoader> m_passage_loader;
    std::shared_ptr<IFightableLoader> m_fightable_loader;
    // std::shared_ptr<IObjectLoader> m_object_loader;
    
};

} //d_d

#endif //MAP_LOADER_HPP