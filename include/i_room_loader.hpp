#ifndef I_ROOM_LOADER_HPP
#define I_ROOM_LOADER_HPP

#include "i_room.hpp"

namespace d_d {

class IRoomLoader {
public:
    virtual ~IRoomLoader();
    virtual void Load(const std::string& a_filename, std::vector<std::shared_ptr<IRoom>>& a_rooms) const = 0;
};

inline IRoomLoader::~IRoomLoader(){}

} //d_d

#endif //I_ROOM_LOADER_HPP