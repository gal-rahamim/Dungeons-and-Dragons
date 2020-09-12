#ifndef I_MAP_LOADER_HPP
#define I_MAP_LOADER_HPP

#include <vector>
#include <memory>
#include <i_room.hpp>

namespace d_d {

class IMapLoader {
public:
    virtual ~IMapLoader();
    virtual void Load(std::vector<std::shared_ptr<IRoom> >& a_rooms) const = 0;

};

inline IMapLoader::~IMapLoader() {}

} //d_d

#endif //I_MAP_LOADER_HPP