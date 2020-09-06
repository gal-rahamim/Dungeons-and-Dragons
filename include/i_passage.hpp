#ifndef I_PASSAGE_HPP
#define I_PASSAGE_HPP

#include <memory>
#include "key.hpp"
// #include "i_room.hpp"


namespace d_d {

class IRoom;

class IPassage {
public:
    typedef std::shared_ptr<IPassage> PassagePtr;

public:
    virtual ~IPassage();
    virtual void Describe(std::string& a_description) const = 0;
    virtual bool Pass(const std::shared_ptr<IRoom>& a_from, std::shared_ptr<IRoom>& a_to, std::string& a_output) const = 0;
    virtual bool Lock(const std::shared_ptr<Key>& a_key, std::string& a_output) = 0;
    virtual bool UnLock(const std::shared_ptr<Key>& a_key, std::string& a_output) = 0;
    virtual bool Open(std::string& a_output) = 0;
    virtual bool Close(std::string& a_output) = 0;
};

inline IPassage::~IPassage(){}

} //d_d

#endif //I_PASSAGE_HPP