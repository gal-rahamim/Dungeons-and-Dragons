#ifndef OBJECT_PARSER_HPP
#define OBJECT_PARSER_HPP

#include "i_object_parser.hpp"

namespace d_d {

class ObjectParser : public IObjectParser {
public:
    virtual bool Parse(const std::string& a_line
                     , std::string& a_room_name
                     , std::string& a_object_type
                     , std::string& a_object_name
                     , unsigned int& a_power
                     , unsigned int& a_respawn_sec) const;
};

} //d_d

#endif //OBJECT_PARSER_HPP