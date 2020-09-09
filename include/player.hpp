#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "i_player.hpp"
#include "i_room.hpp"
#include "i_sword.hpp"
#include "i_passage.hpp"
#include "i_shield.hpp"
#include "common.hpp"
#include "key.hpp"

namespace d_d {

class Player : public IPlayer, advcpp::UnCopyable {
public:
    Player(const std::string& a_name, const std::shared_ptr<IRoom>& a_startingPosition, unsigned int a_life = 42, unsigned int a_money = 0);
    virtual unsigned int GetDefense() const;
    virtual unsigned int GetAttack() const;
    virtual void Respawn();
    virtual void Forward(std::string& a_out);
    virtual void Backward(std::string& a_out);
    virtual void TurnRight(std::string& a_out);
    virtual void TurnLeft(std::string& a_out);
    virtual void Take(const std::string& a_objectName, std::string& a_out);
    virtual void Fight(const std::string& a_name, std::string& a_out);
    virtual void Describe(std::string& a_out);
    virtual void Open(std::string& a_out);
    virtual void Close(std::string& a_out);
    virtual void Lock(std::string& a_out);
    virtual void UnLock(std::string& a_out);
    virtual void Where(std::string& a_out);
    virtual void Look(std::string& a_out);
    virtual const std::string& Name() const;

private:
    std::string m_name;
    std::shared_ptr<IRoom> m_location;
    std::shared_ptr<ISword> m_sword;
    std::shared_ptr<IShield> m_shield;
    std::vector<std::shared_ptr<Key> > m_keys;
    IRoom::Direction m_direction;
};

} //d_d

#endif //PLAYER_HPP