#ifndef DRAGON_PARSER_HPP
#define DRAGON_PARSER_HPP

#include "i_dragon_parser.hpp"

namespace d_d {

class DragonParser : public IDragonParser {
public:
    virtual bool Parse(const std::string& a_line
                     , std::string& a_room_name
                     , std::string& a_dragon_name
                     , unsigned int& a_life
                     , unsigned int& a_money
                     , unsigned int& a_attack
                     , unsigned int& a_defense
                     , unsigned int& a_respawn_sec) const;
};

} //d_d

#endif //DRAGON_PARSER_HPP