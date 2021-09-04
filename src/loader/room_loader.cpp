#include <fstream>
#include "room_loader.hpp"
#include "room.hpp"

namespace d_d {

RoomLoader::RoomLoader(const std::shared_ptr<IRoomParser>& a_parser)
: m_parser(a_parser)
{}

void RoomLoader::Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom> >& a_rooms) const
{
    std::ifstream file(a_filename);
    std::string line;
    while(std::getline(file, line)) {
        std::string room_name;
        if(m_parser->Parse(line, room_name)) {
            a_rooms.insert(std::make_pair(room_name, std::make_shared<Room>(room_name)));
        }
    }
    file.close();
}

} //d_d