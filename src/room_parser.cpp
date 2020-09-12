#include "room_parser.hpp"
#include "room.hpp"

namespace d_d {

bool RoomParser::Parse(const std::string& a_line, std::shared_ptr<IRoom>& a_room) const
{
    a_room = std::make_shared<Room>(a_line);
    return true;
}

} //d_d