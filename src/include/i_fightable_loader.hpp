#ifndef I_FIGHTABLE_LOADER_HPP
#define I_FIGHTABLE_LOADER_HPP

#include <unordered_map>
#include "i_room.hpp"

namespace d_d {

class IFightableLoader {
public:
    virtual ~IFightableLoader() = default;
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const = 0;
};

} //d_d

#endif //I_FIGHTABLE_LOADER_HPP