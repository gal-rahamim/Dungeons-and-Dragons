#include "room_parser.hpp"

namespace d_d {

bool RoomParser::Parse(const std::string& a_line, std::string& a_room_name) const
{
    a_room_name = a_line;
    return true;
}

} //d_d