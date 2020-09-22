#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <unordered_map>
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
    Player(const std::string& a_name, const std::shared_ptr<IRoom>& a_startingPosition, unsigned int a_starting_life = 42, unsigned int a_starting_money = 0);
    ~Player();
    virtual unsigned int GetDefense() const;
    virtual unsigned int GetAttack() const;
    virtual void Respawn();
    virtual void Forward(std::string& a_out);
    virtual void Backward(std::string& a_out);
    virtual void TurnRight(std::string& a_out);
    virtual void TurnLeft(std::string& a_out);
    virtual void Take(const std::string& a_objectName, std::string& a_out);
    virtual void Fight(const std::string& a_name, std::string& a_out);
    virtual void Describe(std::string& a_out) const;
    virtual void Open(std::string& a_out) const;
    virtual void Close(std::string& a_out) const;
    virtual void Lock(std::string& a_out) const;
    virtual void UnLock(std::string& a_out) const;
    virtual void Where(std::string& a_out) const;
    virtual void Look(std::string& a_out) const;
    virtual void Call(const std::string& a_method, std::string& a_out);
    virtual void Call(const std::string& a_method, const std::string& a_arg, std::string& a_out);

private:
    typedef void (Player::*MF_ONE_ARG)(std::string&);
    typedef void (Player::*MF_ONE_ARG_CONST)(std::string&) const;
    typedef void (Player::*MF_TWO_ARG)(const std::string&, std::string&);
    static std::unordered_map<std::string, MF_ONE_ARG> s_mf_dict_one_arg;
    static std::unordered_map<std::string, MF_ONE_ARG_CONST> s_mf_dict_one_arg_const;
    static std::unordered_map<std::string, MF_TWO_ARG> s_mf_dict_two_arg;

private:
    std::shared_ptr<IRoom> m_location;
    std::shared_ptr<ISword> m_sword;
    std::shared_ptr<IShield> m_shield;
    std::vector<std::shared_ptr<Key> > m_keys;
    IRoom::Direction m_direction;

    const std::shared_ptr<IRoom> m_starting_position;
    const std::shared_ptr<ISword> m_starting_sword;
    const unsigned int m_starting_life;
    const unsigned int m_starting_money;
};

} //d_d

#endif //PLAYER_HPP