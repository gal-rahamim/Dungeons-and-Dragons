#ifndef I_PASSAGE_HPP
#define I_PASSAGE_HPP

#include <memory>
// #include "i_room.hpp"


namespace d_d {

class IRoom;

class IPassage {
public:
    typedef std::shared_ptr<IPassage> PassagePtr;

public:
    virtual ~IPassage();
    virtual void Describe(std::string& a_description) const = 0;
    virtual void Pass(const std::shared_ptr<IRoom>& a_from, std::shared_ptr<IRoom>& a_to, std::string& a_output) const = 0;

};

inline IPassage::~IPassage(){}

} //d_d

#endif //I_PASSAGE_HPP