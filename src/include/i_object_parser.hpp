#ifndef I_OBJECT_PARSER_HPP
#define I_OBJECT_PARSER_HPP

#include <string>

namespace d_d {

class IObjectParser {
public:
    virtual ~IObjectParser() = default;
    virtual bool Parse(const std::string& a_line
                     , std::string& a_room_name
                     , std::string& a_object_type
                     , std::string& a_object_name
                     , unsigned int& a_power
                     , unsigned int& a_respawn_sec) const = 0;
};

} //d_d

#endif //I_OBJECT_PARSER_HPP