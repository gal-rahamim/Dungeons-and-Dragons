#ifndef PASSAGE_LOADER_HPP
#define PASSAGE_LOADER_HPP

#include "i_passage_loader.hpp"
#include "i_passage_parser.hpp"

namespace d_d {

class PassageLoader : public IPassageLoader {
public:
    PassageLoader(const std::shared_ptr<IPassageParser>& a_parser);
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const;

private:
    std::shared_ptr<IPassageParser> m_parser;
};


} //d_d

#endif //PASSAGE_LOADER_HPP