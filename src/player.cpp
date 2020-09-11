#include <random>
#include "player.hpp"
#include "sword.hpp"

namespace d_d {

Player::Player(const std::string& a_name, const std::shared_ptr<IRoom>& a_startingPosition, unsigned int a_starting_life, unsigned int a_starting_money)
: IPlayer(a_name, a_starting_life, a_starting_money)
, m_location(a_startingPosition)
, m_sword(new Sword("niddle", 4, a_startingPosition, 20))
, m_shield()
, m_keys()
, m_direction(IRoom::NORTH)
, m_starting_position(a_startingPosition)
, m_starting_sword(m_sword)
, m_starting_life(a_starting_life)
, m_starting_money(a_starting_money)
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
        std::shared_ptr<IFightable> me;
        m_location->Exit(Name(), me);
        destRoom->Enter(me);
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
        a_out = "Switching swords:\n" + getOutput + "\n";
        std::string placeOutput;
        m_location->PlaceObject(m_sword, placeOutput);
        a_out += placeOutput;
        m_sword = sword;
        return;
    }
    std::shared_ptr<IShield> shield = std::dynamic_pointer_cast<IShield>(obj);
    if(shield) {
        if(m_shield) {
            a_out = "Switching shields:\n" + getOutput + "\n";
            std::string placeOutput;
            m_location->PlaceObject(m_shield, placeOutput);
            a_out += placeOutput;
        }
        m_shield = shield;
        return;
    }
    std::shared_ptr<Key> key = std::dynamic_pointer_cast<Key>(obj);
    if(key) {
        a_out = getOutput + "\nInserting key to chain";
        m_keys.push_back(key);
        return;
    }
}

unsigned int Player::GetDefense() const
{
    return m_shield ? m_shield->GetDefense() : 0;
}

unsigned int Player::GetAttack() const
{
    return m_sword ? m_sword->GetStrength() : 0;
}

void Player::Fight(const std::string& a_name, std::string& a_out)
{
    std::shared_ptr<IFightable> target;
    m_location->GetFightable(a_name, target);
    if(!target) {
        a_out = "No such victim was found in the room";
        return;
    }
    unsigned int alpha = std::min((unsigned int)0, GetAttack() - target->GetDefense());
    unsigned int beta = std::min((unsigned int)0, target->GetAttack()/3 - GetDefense());
    std::uniform_int_distribution<int> alphaRange(alpha, alpha*2 + 10);
    std::uniform_int_distribution<int> betaRange(beta, beta*1.2 + 4);
    std::random_device rd;
    alpha = alphaRange(rd);
    beta = betaRange(rd);
    ReduceLife(alpha);
    target->ReduceLife(beta);
    a_out = "A hit was made!\nYou'r damage: " + std::to_string(alpha) + ", current life: " + std::to_string(GetLife())
            + "\nOpponent damage: " + std::to_string(beta) + ", opponent current life: " + std::to_string(target->GetLife());
    if(target->GetLife() == 0) {
        unsigned int shinyMoney = target->GetMoney();
        AddMoney(shinyMoney);
        a_out += "\nYou've killed " + target->Name() + "\nYou've got " + std::to_string(shinyMoney) + " new coins!";
        target->Respawn();
    }
    if(GetLife() == 0) {
        target->AddMoney(GetMoney());
        a_out += "\nYou've died :(\nRespawning..";
        Respawn();
    }
}

void Player::Respawn()
{
    std::string out;
    std::vector<std::shared_ptr<IObject> > dropping_objects(m_keys.begin(),m_keys.end());
    if(m_sword) {
        dropping_objects.push_back(m_sword);
        m_sword = m_starting_sword;
    }
    if(m_shield) {
        dropping_objects.push_back(m_shield);
        m_shield = nullptr;
    }
    m_location->PlaceObjects(dropping_objects, out);
    SetLife(m_starting_life);
    SetMoney(m_starting_money);
    std::shared_ptr<IFightable> me;
    m_location->Exit(Name(), me);
    m_location = m_starting_position;
    m_location->Enter(me);
}

void Player::Describe(std::string& a_out) const
{
    std::string swordDescription;
    m_sword->Describe(swordDescription);
    a_out = Name() + ":\nLife: " + std::to_string(GetLife()) + "\nMoney: " + std::to_string(GetMoney()) + "\nSword:\n" + swordDescription;
}

void Player::Open(std::string& a_out) const
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(passage) {
        passage->Open(a_out);
        return;
    }
    a_out = "You have reached a wall";
}

void Player::Close(std::string& a_out) const
{
    std::shared_ptr<IPassage> passage;
    m_location->Move(m_direction, passage);
    if(passage) {
        passage->Close(a_out);
        return;
    }
    a_out = "You have reached a wall";
}

void Player::Lock(std::string& a_out) const
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

void Player::UnLock(std::string& a_out) const
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

void Player::Where(std::string& a_out) const
{
    a_out = m_location->Name();
}

void Player::Look(std::string& a_out) const
{
    m_location->Describe(a_out);
}

} //d_d