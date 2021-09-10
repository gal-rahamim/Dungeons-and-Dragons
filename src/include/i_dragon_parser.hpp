#ifndef I_DRAGON_PARSER_HPP
#define I_DRAGON_PARSER_HPP

#include "i_room.hpp"

namespace d_d {

class IDragonParser {
public:
    virtual ~IDragonParser() = default;
    virtual bool Parse(const std::string& a_line
                     , std::string& a_room_name
                     , std::string& a_dragon_name
                     , unsigned int& a_life
                     , unsigned int& a_money
                     , unsigned int& a_attack
                     , unsigned int& a_defense
                     , unsigned int& a_respawn_sec) const = 0;
};

} //d_d

#endif //I_DRAGON_PARSER_HPP