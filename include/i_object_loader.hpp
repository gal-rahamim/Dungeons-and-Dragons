#ifndef I_OBJECT_LOADER_HPP
#define I_OBJECT_LOADER_HPP

#include <unordered_map>
#include "i_room.hpp"

namespace d_d {

class IObjectLoader {
public:
    virtual ~IObjectLoader();
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const = 0;
};

inline IObjectLoader::~IObjectLoader(){}

} //d_d

#endif //I_OBJECT_LOADER_HPP