#ifndef I_PASSAGE_PARSER_HPP
#define I_PASSAGE_PARSER_HPP

#include "i_room.hpp"
#include "i_passage.hpp"

namespace d_d {

class IPassageParser {
public:
    virtual ~IPassageParser() = default;
    virtual bool Parse(const std::string& a_line
                     , std::pair<std::string, IRoom::Direction>& a_p1
                     , std::pair<std::string, IRoom::Direction>& a_p2
                     , IPassage::DoorState& a_ds
                     , IPassage::LockState& a_ls
                     , std::shared_ptr<Key>& a_key) const = 0;
};

} //d_d

#endif //I_PASSAGE_PARSER_HPP