#ifndef PASSAGE_HPP
#define PASSAGE_HPP

#include "i_passage.hpp"
#include "common.hpp"
#include "key.hpp"

namespace d_d {

class Passage : public IPassage {
public:
    Passage(const std::shared_ptr<IRoom>& a_room1, const std::shared_ptr<IRoom>& a_room2
        , DoorState a_door_state = DOOR_STATE_NODOOR, LockState a_lock_state = LOCK_STATE_NOLOCK
        , const std::shared_ptr<Key>& a_key = std::make_shared<Key>());

    virtual void Describe(std::string& a_description) const;
    virtual bool Pass(const std::shared_ptr<IRoom>& a_from, std::shared_ptr<IRoom>& a_to, std::string& a_output) const;
    virtual bool Lock(const std::shared_ptr<Key>& a_key, std::string& a_output);
    virtual bool UnLock(const std::shared_ptr<Key>& a_key, std::string& a_output);
    virtual bool Open(std::string& a_output);
    virtual bool Close(std::string& a_output);

private:
    std::shared_ptr<IRoom> m_room1;
    std::shared_ptr<IRoom> m_room2;
    std::shared_ptr<Key> m_key;
    DoorState m_door_state;
    LockState m_lock_state;
};

} //d_d

#endif //PASSAGE_HPP