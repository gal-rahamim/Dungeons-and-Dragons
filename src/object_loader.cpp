#include <fstream>
#include "object_loader.hpp"
#include "sword.hpp"
#include "shield.hpp"
#include "key.hpp"

namespace d_d {

ObjectLoader::ObjectLoader(const std::shared_ptr<IObjectParser>& a_parser)
: m_parser(a_parser)
{}

void ObjectLoader::Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const
{
    std::ifstream file(a_filename);
    std::string line;
    while(std::getline(file, line)) {
        std::string room_name, object_type, object_name, out;
        unsigned int power, respawn_sec;
        if(m_parser->Parse(line, room_name, object_type, object_name, power, respawn_sec)) {
            auto r = a_rooms.find(room_name);
            if(r == a_rooms.end()) {
                continue;
            }
            std::shared_ptr<IObject> object;
            if(object_type == "sword") {
                object = std::make_shared<Sword>(object_name, power, r->second, respawn_sec);
            }
            else if(object_type == "shield") {
                object = std::make_shared<Shield>(object_name, r->second, respawn_sec, power);
            }
            else if(object_type == "key") {
                object = std::make_shared<Key>(object_name, r->second, respawn_sec);
            }
            else {
                continue;
            }
            
            r->second->PlaceObject(object, out);
        }
    }
    file.close();    
}

} //d_d