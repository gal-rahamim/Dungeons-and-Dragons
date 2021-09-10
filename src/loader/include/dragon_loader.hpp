#ifndef DRAGON_LOADER_HPP
#define DRAGON_LOADER_HPP

#include "i_fightable_loader.hpp"
#include "i_dragon_parser.hpp"

namespace d_d {

class DragonLoader : public IFightableLoader {
public:
    DragonLoader(const std::shared_ptr<IDragonParser>& a_parser);
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const;

private:
    std::shared_ptr<IDragonParser> m_parser;
};

} //d_d

#endif //DRAGON_LOADER_HPP