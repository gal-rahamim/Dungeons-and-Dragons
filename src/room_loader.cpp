#include <fstream>
#include "room_loader.hpp"

namespace d_d {

RoomLoader::RoomLoader(const std::shared_ptr<IRoomParser>& a_parser)
: m_parser(a_parser)
{}

void RoomLoader::Load(const std::string& a_filename, std::vector<std::shared_ptr<IRoom>>& a_rooms) const
{
    std::ifstream file(a_filename);
    std::string line;
    while(std::getline(file, line)) {
        std::shared_ptr<IRoom> room;
        if(m_parser->Parse(line, room)) {
            a_rooms.push_back(room);
        }
    }
    file.close();
}

} //d_d