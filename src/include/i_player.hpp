#ifndef I_PLAYER_HPP
#define I_PLAYER_HPP

#include <string>
#include "i_fightable.hpp"

namespace d_d {

class IPlayer : public IFightable {
public:
    IPlayer(const std::string& a_name, unsigned int a_life, unsigned int a_money);
    virtual ~IPlayer() = default;
    virtual unsigned int GetDefense() const = 0;
    virtual unsigned int GetAttack() const = 0;
    virtual void Respawn() = 0;
    virtual void Forward(std::string& a_out) = 0;
    virtual void Backward(std::string& a_out) = 0;
    virtual void TurnRight(std::string& a_out) = 0;
    virtual void TurnLeft(std::string& a_out) = 0;
    virtual void Take(const std::string& a_objectName, std::string& a_out) = 0;
    virtual void Fight(const std::string& a_name, std::string& a_out) = 0;
    virtual void Describe(std::string& a_out) const = 0;
    virtual void Open(std::string& a_out) const = 0;
    virtual void Close(std::string& a_out) const = 0;
    virtual void Lock(std::string& a_out) const = 0;
    virtual void UnLock(std::string& a_out) const = 0;
    virtual void Where(std::string& a_out) const = 0;
    virtual void Look(std::string& a_out) const = 0;
    virtual void Call(const std::string& a_method, std::string& a_out) = 0;
    virtual void Call(const std::string& a_method, const std::string& a_arg, std::string& a_out) = 0;
};

inline IPlayer::IPlayer(const std::string& a_name, unsigned int a_life, unsigned int a_money)
: IFightable(a_name, a_life, a_money)
{}

} //d_d

#endif //I_PLAYER_HPP