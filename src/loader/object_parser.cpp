#include "object_parser.hpp"

namespace d_d {

// object line in file should look like:
//    1      2        3      4  5
// "sword,room b,shiny sword,6,20

//1. object type (sword/shield/key)
//2. position in map
//3. objects name
//4. objects power (irellevant for key)
//5. respawn in sec (0 for no respawn)

bool ObjectParser::Parse(const std::string& a_line
                     , std::string& a_room_name
                     , std::string& a_object_type
                     , std::string& a_object_name
                     , unsigned int& a_power
                     , unsigned int& a_respawn_sec) const
{
    size_t start_pos = 0;
    size_t end_pos = a_line.find_first_of(',');
    if(start_pos == end_pos) {
        return false;
    }
    a_object_type = a_line.substr(start_pos, end_pos - start_pos);
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
    a_object_name = a_line.substr(start_pos, end_pos - start_pos);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    std::string num = a_line.substr(start_pos, end_pos - start_pos);
    try {
        a_power = std::stoul(num);
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