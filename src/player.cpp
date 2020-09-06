#include "player.hpp"
#include "sword.hpp"

namespace d_d {

Player::Player(const std::string& a_name, const std::shared_ptr<IRoom>& a_startingPosition)
: m_name(a_name)
, m_location(a_startingPosition)
, m_sword(new Sword("niddle", 4))
// m_shield;
, m_keys()
, m_direction(IRoom::NORTH)
, m_life(42)
, m_money(0)
{
}

static std::string directionToString(IRoom::Direction a_direction)
{
    std::string ret;
    switch (a_direction)
    {
    case IRoom::NORTH :
        ret = "North";
        break;
    case IRoom::SOUTH :
        ret = "South";
        break;
    case IRoom::EAST :
        ret = "East";
        break;
    case IRoom::WEST :
        ret = "West";
        break;
    default:
        break;
    }

    return ret;
}

static void reverseDirection(IRoom::Direction& a_direction)
{
    switch (a_direction)
    {
    case IRoom::NORTH :
        a_direction =  IRoom::SOUTH;
        return;
    case IRoom::SOUTH :
        a_direction = IRoom::NORTH;
        return;
    case IRoom::EAST :
        a_direction = IRoom::WEST;
        return;
    case IRoom::WEST :
        a_direction = IRoom::EAST;
        return;
    default:
        break;
    }    
}

static void right90(IRoom::Direction& a_direction)
{
    switch (a_direction)
    {
    case IRoom::NORTH :
        a_direction = IRoom::EAST;
        return;
    case IRoom::SOUTH :
        a_direction = IRoom::WEST;
        return;
    case IRoom::EAST :
        a_direction = IRoom::SOUTH;
        return;
    case IRoom::WEST :
        a_direction = IRoom::NORTH;
        return;
    default:
        break;
    }    
}

static void left90(IRoom::Direction& a_direction)
{
    switch (a_direction)
    {
    case IRoom::NORTH :
        a_direction = IRoom::WEST;
        return;
    case IRoom::SOUTH :
        a_direction = IRoom::EAST;
        return;
    case IRoom::EAST :
        a_direction = IRoom::NORTH;
        return;
    case IRoom::WEST :
        a_direction = IRoom::SOUTH;
        return;
    default:
        break;
    }    
}

void Player::Forward(std::string& a_out)
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(!passage) {
        a_out = "Can't move " + directionToString(m_direction) + " reached a wall";
        return;
    }
    std::shared_ptr<IRoom> destRoom;
    if(passage->Pass(m_location, destRoom, a_out)) {
        destRoom->Enter(m_location->Exit(m_name));
        m_location = destRoom;
        return;
    }
    return;
}

void Player::Backward(std::string& a_out)
{
    reverseDirection(m_direction);
    Forward(a_out);
    reverseDirection(m_direction);
}

void Player::TurnRight(std::string& a_out)
{
    right90(m_direction);
    a_out = "You are now facing: " + directionToString(m_direction);
}

void Player::TurnLeft(std::string& a_out)
{
    left90(m_direction);
    a_out = "You are now facing: " + directionToString(m_direction);
}

void Player::Take(const std::string& a_objectName, std::string& a_out)
{
    std::string getOutput;
    auto obj = m_location->GetObject(a_objectName, getOutput);
    if(!obj) {
        a_out = getOutput;
        return;
    }
    std::shared_ptr<ISword> sword = std::dynamic_pointer_cast<ISword>(obj);
    if(sword) {
        a_out = "Swithing swords:\n" + getOutput + "\n";
        std::string placeOutput;
        m_location->PlaceObject(m_sword, placeOutput);
        a_out += placeOutput;
        m_sword = sword;
        return;
    }
    std::shared_ptr<Key> key = std::dynamic_pointer_cast<Key>(obj);
    if(key) {
        a_out = getOutput + "\nInserting key to chain";
        m_keys.push_back(key);
        return;
    }
}

void Player::Fight(const std::string& a_name, std::string& a_out)
{

}

void Player::Describe(std::string& a_out)
{
    std::string swordDescription;
    m_sword->Describe(swordDescription);
    a_out = Name() + ":\nLife: " + std::to_string(m_life) + "\nMoney: " + std::to_string(m_money) + "\nSword:\n" + swordDescription;
}

void Player::Open(std::string& a_out)
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(passage) {
        passage->Open(a_out);
        return;
    }
    a_out = "You have reached a wall";
}

void Player::Close(std::string& a_out)
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(passage) {
        passage->Close(a_out);
        return;
    }
    a_out = "You have reached a wall";
}

void Player::Lock(std::string& a_out)
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(passage) {
        for(size_t i = 0 ; i < m_keys.size() ; ++i) {
            if(passage->Lock(m_keys[i], a_out)) {
                break;
            }
        }
        return;
    }
    a_out = "You have reached a wall";    
}

void Player::UnLock(std::string& a_out)
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(passage) {
        for(size_t i = 0 ; i < m_keys.size() ; ++i) {
            if(passage->UnLock(m_keys[i], a_out)) {
                break;
            }
        }
        return;
    }
    a_out = "You have reached a wall";    
}

void Player::Where(std::string& a_out)
{
    a_out = m_location->Name();
}

void Player::Look(std::string& a_out)
{
    m_location->Describe(a_out);
}

const std::string& Player::Name() const
{
    return m_name;
}

} //d_d