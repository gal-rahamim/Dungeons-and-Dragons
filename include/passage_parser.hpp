#ifndef PASSAGE_PARSER_HPP
#define PASSAGE_PARSER_HPP

#include "i_passage_parser.hpp"

namespace d_d {

class PassageParser : public IPassageParser {
public:
    virtual bool Parse(const std::string& a_line
                     , std::pair<std::string, IRoom::Direction>& a_p1
                     , std::pair<std::string, IRoom::Direction>& a_p2
                     , IPassage::DoorState& a_ds
                     , IPassage::LockState& a_ls
                     , std::shared_ptr<Key>& a_key) const;
};

} //d_d

#endif //PASSAGE_PARSER_HPP