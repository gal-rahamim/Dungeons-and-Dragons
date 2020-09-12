#ifndef I_ROOM_PARSER_HPP
#define I_ROOM_PARSER_HPP

#include "i_room.hpp"

namespace d_d {

class IRoomParser {
public:
    virtual ~IRoomParser();
    virtual bool Parse(const std::string& a_line, std::shared_ptr<IRoom>& a_room) const = 0;

};

inline IRoomParser::~IRoomParser(){}

} //d_d

#endif //I_ROOM_PARSER_HPP