#include "passage_parser.hpp"

namespace d_d {

// passage line in file should look like:
// "room a,room b,north,south,dc,dl,key name"
// "room a,room b,north,south,dc"
// "room a,room b,north,south"

//1. "room a" & "room b" -> names of rooms where this passage is connecting.
//2. "north" & "south" -> indicate where in the rooms the passage is located respectivly.  
//3. "dc"/"do"/"nd" -> indicate door status: door closed, door open, no door respectivly.
//4. "dl"/"du"/"nl" -> indicate lock status: door locked, door unlocked, no lock respectivly.
//5. "key name" -> key name to generate
// 3 + 4 + 5 could be left empty for default

static bool directionFromStr(const std::string& a_direction, IRoom::Direction& a_dir)
{
    if(a_direction == "north") {
        a_dir = IRoom::NORTH;
        return true;
    }
    if(a_direction == "south") {
        a_dir = IRoom::SOUTH;
        return true;
    }
    if(a_direction == "east") {
        a_dir = IRoom::EAST;
        return true;
    }
    if(a_direction == "west") {
        a_dir = IRoom::WEST;
        return true;
    }
    return false;
}

static bool doorStateFromStr(const std::string& a_direction, IPassage::DoorState& a_ds)
{
    if(a_direction == "dc") {
        a_ds = IPassage::DOOR_STATE_CLOSED;
        return true;
    }
    if(a_direction == "do") {
        a_ds = IPassage::DOOR_STATE_OPEN;
        return true;
    }
    if(a_direction == "nd") {
        a_ds = IPassage::DOOR_STATE_NODOOR;
        return true;
    }
    return false;
}

static bool lockStateFromStr(const std::string& a_direction, IPassage::LockState& a_ls)
{
    if(a_direction == "dl") {
        a_ls = IPassage::LOCK_STATE_LOCKED;
        return true;
    }
    if(a_direction == "du") {
        a_ls = IPassage::LOCK_STATE_UNLOCKED;
        return true;
    }
    if(a_direction == "nl") {
        a_ls = IPassage::LOCK_STATE_NOLOCK;
        return true;
    }
    return false;
}

bool PassageParser::Parse(const std::string& a_line
                        , std::pair<std::string, IRoom::Direction>& a_p1
                        , std::pair<std::string, IRoom::Direction>& a_p2
                        , IPassage::DoorState& a_ds
                        , IPassage::LockState& a_ls
                        , std::shared_ptr<Key>& a_key) const
{
    size_t start_pos = 0;
    size_t end_pos = a_line.find_first_of(',');
    if(start_pos == end_pos) {
        return false;
    }
    std::string r1_name = a_line.substr(start_pos, end_pos - start_pos);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    std::string r2_name = a_line.substr(start_pos, end_pos - start_pos);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(start_pos >= end_pos) {
        return false;
    }
    IRoom::Direction r1_direction;
    if(!directionFromStr(a_line.substr(start_pos, end_pos - start_pos), r1_direction)) {
        return false;
    }
    a_p1 = std::make_pair(r1_name, r1_direction);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    IRoom::Direction r2_direction;
    if(end_pos == std::string::npos) {
        if(!directionFromStr(a_line.substr(start_pos), r2_direction)) {
            return false;
        }
        a_p2 = std::make_pair(r2_name, r2_direction);
        a_ds = IPassage::DOOR_STATE_NODOOR;
        a_ls = IPassage::LOCK_STATE_NOLOCK;
        a_key = std::make_shared<Key>();
        return true;
    }
    else if(start_pos >= end_pos) {
        return false;
    }
    if(!directionFromStr(a_line.substr(start_pos, end_pos - start_pos), r2_direction)) {
        return false;
    }
    a_p2 = std::make_pair(r2_name, r2_direction);
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(end_pos == std::string::npos) {
        if(!doorStateFromStr(a_line.substr(start_pos), a_ds)) {
            return false;
        }
        a_ls = IPassage::LOCK_STATE_NOLOCK;
        a_key = std::make_shared<Key>();
        return true;
    }
    else if(start_pos >= end_pos) {
        return false;
    }
    if(!doorStateFromStr(a_line.substr(start_pos, end_pos - start_pos), a_ds)) {
            return false;
    }
    start_pos = end_pos + 1;
    end_pos = a_line.find_first_of(',', start_pos);
    if(end_pos == std::string::npos) {
        if(!lockStateFromStr(a_line.substr(start_pos), a_ls)) {
            return false;
        }
        a_key = std::make_shared<Key>();
        return true;
    }
    else if(start_pos >= end_pos) {
        return false;
    }
    if(!lockStateFromStr(a_line.substr(start_pos, end_pos - start_pos), a_ls)) {
            return false;
    }
    start_pos = end_pos + 1;
    a_key = std::make_shared<Key>(a_line.substr(start_pos));
    return true;
}         

} //d_d