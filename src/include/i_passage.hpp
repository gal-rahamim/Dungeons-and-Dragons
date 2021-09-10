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
    enum LockState {
        LOCK_STATE_LOCKED,
        LOCK_STATE_UNLOCKED,
        LOCK_STATE_NOLOCK
    };

    enum DoorState {
        DOOR_STATE_CLOSED,
        DOOR_STATE_OPEN,
        DOOR_STATE_NODOOR
    };
    
public:
    virtual ~IPassage() = default;
    virtual void Describe(std::string& a_description) const = 0;
    virtual bool Pass(const std::shared_ptr<IRoom>& a_from, std::shared_ptr<IRoom>& a_to, std::string& a_output) const = 0;
    virtual bool Lock(const std::shared_ptr<Key>& a_key, std::string& a_output) = 0;
    virtual bool UnLock(const std::shared_ptr<Key>& a_key, std::string& a_output) = 0;
    virtual bool Open(std::string& a_output) = 0;
    virtual bool Close(std::string& a_output) = 0;
};

} //d_d

#endif //I_PASSAGE_HPP