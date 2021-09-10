#ifndef ROOM_LOADER_HPP
#define ROOM_LOADER_HPP

#include "i_room_loader.hpp"
#include "i_room_parser.hpp"

namespace d_d {

class RoomLoader : public IRoomLoader {
public:
    RoomLoader(const std::shared_ptr<IRoomParser>& a_parser);
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom> >& a_rooms) const;

private:
    std::shared_ptr<IRoomParser> m_parser;
};


} //d_d

#endif //ROOM_LOADER_HPP