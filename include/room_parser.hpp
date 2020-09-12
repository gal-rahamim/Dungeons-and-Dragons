#ifndef ROOM_PARSER_HPP
#define ROOM_PARSER_HPP

#include "i_room_parser.hpp"

namespace d_d {

class RoomParser : public IRoomParser {
public:
    virtual bool Parse(const std::string& a_line, std::shared_ptr<IRoom>& a_room) const;

};

} //d_d

#endif //ROOM_PARSER_HPP