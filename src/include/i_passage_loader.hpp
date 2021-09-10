#ifndef I_PASSAGE_LOADER_HPP
#define I_PASSAGE_LOADER_HPP

#include <unordered_map>
#include "i_room.hpp"

namespace d_d {

class IPassageLoader {
public:
    virtual ~IPassageLoader();
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const = 0;
};

inline IPassageLoader::~IPassageLoader(){}

} //d_d

#endif //I_PASSAGE_LOADER_HPP