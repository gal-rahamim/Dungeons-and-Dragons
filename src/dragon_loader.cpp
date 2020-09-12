#include <fstream>
#include "dragon_loader.hpp"
#include "dragon.hpp"

namespace d_d {

DragonLoader::DragonLoader(const std::shared_ptr<IDragonParser>& a_parser)
: m_parser(a_parser)
{}

void DragonLoader::Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const
{
    std::ifstream file(a_filename);
    std::string line;
    while(std::getline(file, line)) {
        std::string room_name, dragon_name;
        unsigned int life, money, attack, defense, respawn_sec;
        if(m_parser->Parse(line, room_name, dragon_name, life, money, attack, defense, respawn_sec)) {
            auto r = a_rooms.find(room_name);
            if(r == a_rooms.end()) {
                continue;
            }
            std::shared_ptr<IFightable> dragon = std::make_shared<Dragon>(dragon_name, r->second, life, money, attack, defense, respawn_sec);
            r->second->Enter(dragon);
        }
    }
    file.close();
}

} //d_d