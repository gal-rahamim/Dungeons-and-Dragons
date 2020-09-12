#include <fstream>
#include "passage_loader.hpp"
#include "passage.hpp"

namespace d_d {

PassageLoader::PassageLoader(const std::shared_ptr<IPassageParser>& a_parser)
: m_parser(a_parser)
{}

void PassageLoader::Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const
{
    std::ifstream file(a_filename);
    std::string line;
    while(std::getline(file, line)) {
        std::pair<std::string, IRoom::Direction> p1, p2;
        IPassage::DoorState ds;
        IPassage::LockState ls;
        std::shared_ptr<Key> k;
        if(m_parser->Parse(line, p1, p2, ds, ls, k)) {
            auto r1 = a_rooms.find(p1.first);
            auto r2 = a_rooms.find(p2.first);
            if(r1 == a_rooms.end() || r2 == a_rooms.end()) {
                continue;
            }
            std::shared_ptr<IPassage> passage = std::make_shared<Passage>(r1->second, r2->second, ds, ls, k);
            r1->second->AddPassage(std::make_pair(p1.second, passage));
            r2->second->AddPassage(std::make_pair(p2.second, passage));
        }
    }
    file.close();
}

} //d_d