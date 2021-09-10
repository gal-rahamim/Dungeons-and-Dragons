#include "dragon_parser.hpp"

namespace d_d {

// dragon line in file should look like:
//    1      2     3  4   5  6  7
// "Drogo,room b,100,150,12,8,20"

//1. dragon's name
//2. position in map
//3. life juice
//4. treasure upon slaying
//5. attack force
//6. defense force
//7. time in sec before respawning after death.

bool DragonParser::Parse(const std::string& a_line
                        , std::string& a_room_name
                        , std::string& a_dragon_name
                        , unsigned int& a_life
                        , unsigned int& a_money
                        , unsigned int& a_attack
                        , unsigned int& a_defense
                        , unsigned int& a_respawn_sec) const
{
    size_t start_pos = 0;
    size_t end_pos = a_line.find_first_of(',');
    if(start_pos == end_pos) {
        return false;
    }
    a_dragon_name = a_line.substr(start_pos, end_pos - start_pos);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    a_room_name = a_line.substr(start_pos, end_pos - start_pos);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    std::string num = a_line.substr(start_pos, end_pos - start_pos);
    try {
        a_life = std::stoul(num);
    }
    catch(std::exception) {
        return false;
    }
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    num = a_line.substr(start_pos, end_pos - start_pos);
    try {
        a_money = std::stoul(num);
    }
    catch(std::exception) {
        return false;
    }
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    num = a_line.substr(start_pos, end_pos - start_pos);
    try {
        a_attack = std::stoul(num);
    }
    catch(std::exception) {
        return false;
    }
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    num = a_line.substr(start_pos, end_pos - start_pos);
    try {
        a_defense = std::stoul(num);
    }
    catch(std::exception) {
        return false;
    }
    start_pos = end_pos + 1;
    num = a_line.substr(start_pos);
    try {
        a_respawn_sec = std::stoul(num);
    }
    catch(std::exception) {
        return false;
    }
    return true;
}         

} //d_d