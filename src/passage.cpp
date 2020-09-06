#include <cassert>
#include "passage.hpp"
#include "i_room.hpp"
namespace d_d {

Passage::Passage(const std::shared_ptr<IRoom>& a_room1, const std::shared_ptr<IRoom>& a_room2
    , DoorState a_door_state, LockState a_lock_state, const Key& a_key)
: m_room1(a_room1)
, m_room2(a_room2)
, m_key(a_key)
, m_door_state(a_door_state)
, m_lock_state(a_lock_state)
{
    assert(!(m_door_state != DOOR_STATE_CLOSED && m_lock_state == LOCK_STATE_LOCKED));
    assert(!(m_door_state == DOOR_STATE_NODOOR && m_lock_state != LOCK_STATE_NOLOCK));
}

void Passage::Describe(std::string& a_description) const
{
    a_description = "This passage connects between " + m_room1->Name() + " and " + m_room2->Name();
    a_description += m_door_state != DOOR_STATE_NODOOR ? m_door_state == DOOR_STATE_CLOSED ? "\nThe door is closed" : "\nThe door is open" : "\nPassage is clear";
    a_description += m_lock_state != LOCK_STATE_NOLOCK ? m_lock_state == LOCK_STATE_LOCKED ? "\nThe door is locked" : "\nThe door is not locked" : "";
}

void Passage::Pass(const std::shared_ptr<IRoom>& a_from, std::shared_ptr<IRoom>& a_to, std::string& a_output) const
{
    assert(a_from);
    if(m_door_state == DOOR_STATE_CLOSED){
        a_output = "Can't pass the door is closed";
        a_to = nullptr;
        return;
    }
    a_to = a_from == m_room1 ? m_room2 : m_room1;
    a_output = "Passing from " + a_from->Name() + " to " + a_to->Name();
}

void Passage::Lock(const Key& a_key, std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door";
        return;
    }
    if(m_door_state == DOOR_STATE_OPEN) {
        a_output = "Can't lock an open door";
        return;
    }
    if(m_lock_state == LOCK_STATE_LOCKED) {
        a_output = "Door is already locked";
        return;
    }
    if(m_lock_state == LOCK_STATE_NOLOCK) {
        a_output = "This door as no lock";
        return;
    }
    if(m_key == a_key) {
        m_lock_state = LOCK_STATE_LOCKED;
        a_output = "You have locked the door";
        return;
    }
    else {
        a_output = "Wrong Key, can't lock the door";
        return;
    }
}

void Passage::UnLock(const Key& a_key, std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door";
        return;
    }
    if(m_door_state == DOOR_STATE_OPEN) {
        a_output = "Can't unlock an open door";
        return;
    }
    if(m_lock_state == LOCK_STATE_UNLOCKED) {
        a_output = "Door is already unlocked";
        return;
    }
    if(m_lock_state == LOCK_STATE_NOLOCK) {
        a_output = "This door as no lock";
        return;
    }
    if(m_key == a_key) {
        m_lock_state = LOCK_STATE_UNLOCKED;
        a_output = "You have unlocked the door";
        return;
    }
    else {
        a_output = "Wrong Key, can't unlock the door";
        return;
    }
}

void Passage::Open(std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door";
        return;
    }
    if(m_door_state == DOOR_STATE_OPEN) {
        a_output = "The door is already open";
        return;
    }
    if(m_lock_state == LOCK_STATE_LOCKED) {
        a_output = "Can't open, door is locked";
        return;
    }
    else {
        m_door_state = DOOR_STATE_OPEN;
        a_output = "You have opened the door";
        return;
    }
}
void Passage::Close(std::string& a_output)
{
    if(m_door_state == DOOR_STATE_NODOOR) {
        a_output = "This passage as no door";
        return;
    }
    if(m_door_state == DOOR_STATE_CLOSED) {
        a_output = "The door is already closed";
        return;
    }
    else {
        m_door_state = DOOR_STATE_CLOSED;
        a_output = "You have closed the door";
        return;
    }
}

} //d_d