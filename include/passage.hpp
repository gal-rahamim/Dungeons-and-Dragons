#ifndef PASSAGE_HPP
#define PASSAGE_HPP

#include "i_passage.hpp"
#include "common.hpp"
#include "key.hpp"

namespace d_d {

class Passage : public IPassage {
public:
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
    Passage(const std::shared_ptr<IRoom>& a_room1, const std::shared_ptr<IRoom>& a_room2
        , DoorState a_door_state = DOOR_STATE_NODOOR, LockState a_lock_state = LOCK_STATE_NOLOCK
        , const Key& a_key = Key());

    virtual void Describe(std::string& a_description) const;
    virtual bool Pass(const std::shared_ptr<IRoom>& a_from, std::shared_ptr<IRoom>& a_to, std::string& a_output) const;
    virtual bool Lock(const Key& a_key, std::string& a_output);
    virtual bool UnLock(const Key& a_key, std::string& a_output);
    virtual bool Open(std::string& a_output);
    virtual bool Close(std::string& a_output);

private:
    std::shared_ptr<IRoom> m_room1;
    std::shared_ptr<IRoom> m_room2;
    Key m_key;
    DoorState m_door_state;
    LockState m_lock_state;
};

} //d_d

#endif //PASSAGE_HPP