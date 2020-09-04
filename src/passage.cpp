#include <cassert>
#include "passage.hpp"

namespace d_d {

Passage::Passage(std::shared_ptr<IRoom> a_room1, std::shared_ptr<IRoom> a_room2
    , DoorState a_door_state, LockState a_lock_state, const Key& a_key)
: IPassage(a_room1, a_room2)
, m_door_state(a_door_state)
, m_lock_state(a_lock_state)
, m_key(a_key)
{
    assert(m_door_state == DOOR_STATE_OPEN && m_lock_state != LOCK_STATE_LOCKED);
    assert(m_door_state == DOOR_STATE_NODOOR && m_lock_state == LOCK_STATE_NOLOCK);
}

void Passage::Describe(std::string& a_description) const
{
    a_description = "This passage connects between " + GetRoom1()->Name() + "and " + GetRoom2()->Name() + "\n";
    a_description += m_door_state != DOOR_STATE_NODOOR ? m_door_state == DOOR_STATE_CLOSED ? "The door is closed\n" : "The door is open\n" : "Passage is clear\n";
    a_description += m_lock_state != LOCK_STATE_NOLOCK ? m_lock_state == LOCK_STATE_LOCKED ? "The door is locked\n" : "The door is not locked\n" : "";
}

void Passage::Pass(std::shared_ptr<IRoom> a_from, std::shared_ptr<IRoom> a_to, std::string& a_output) const
{
    assert(a_from && a_to);
    if(m_door_state == DOOR_STATE_CLOSED){
        a_output = "Can't pass the door is closed\n";
        a_to = nullptr;
        return;
    }
    a_to = a_from == GetRoom1() ? GetRoom2() : GetRoom1();
    a_output = "Passing from " + a_from->Name() + "to " + a_to->Name() + "\n";
}

void Passage::Lock(const Key& a_key, std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door\n";
        return;
    }
    if(m_door_state == DOOR_STATE_OPEN) {
        a_output = "Can't lock an open door\n";
        return;
    }
    if(m_lock_state == LOCK_STATE_LOCKED) {
        a_output = "Door is already locked\n";
        return;
    }
    if(m_lock_state == LOCK_STATE_NOLOCK) {
        a_output = "This door as no lock\n";
        return;
    }
    if(m_key == a_key) {
        m_lock_state == LOCK_STATE_LOCKED;
        a_output = "You have locked the door\n";
        return;
    }
    else {
        a_output = "Wrong Key, can't lock the door\n";
        return;
    }
}

void Passage::UnLock(const Key& a_key, std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door\n";
        return;
    }
    if(m_door_state == DOOR_STATE_OPEN) {
        a_output = "Can't unlock an open door\n";
        return;
    }
    if(m_lock_state == LOCK_STATE_UNLOCKED) {
        a_output = "Door is already unlocked\n";
        return;
    }
    if(m_lock_state == LOCK_STATE_NOLOCK) {
        a_output = "This door as no lock\n";
        return;
    }
    if(m_key == a_key) {
        m_lock_state == LOCK_STATE_UNLOCKED;
        a_output = "You have unlocked the door\n";
        return;
    }
    else {
        a_output = "Wrong Key, can't unlock the door\n";
        return;
    }
}

void Passage::Open(std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door\n";
        return;
    }
    if(m_door_state == DOOR_STATE_OPEN) {
        a_output = "The door is already open\n";
        return;
    }
    if(m_lock_state == LOCK_STATE_LOCKED) {
        a_output = "Can't open, door is locked\n";
        return;
    }
    else {
        m_door_state = DOOR_STATE_OPEN;
        a_output = "You have opened the door\n";
        return;
    }
}
void Passage::Close(std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door\n";
        return;
    }
    if(m_door_state == DOOR_STATE_CLOSED) {
        a_output = "The door is already closed\n";
        return;
    }
    else {
        m_door_state = DOOR_STATE_CLOSED;
        a_output = "You have closed the door\n";
        return;
    }
}

} //d_d