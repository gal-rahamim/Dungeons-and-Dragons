#ifndef I_PLAYER_HPP
#define I_PLAYER_HPP

#include <string>

namespace d_d {

class IPlayer {
public:
    virtual ~IPlayer();
    virtual void Forward(std::string& a_out) = 0;
    virtual void Backward(std::string& a_out) = 0;
    virtual void TurnRight(std::string& a_out) = 0;
    virtual void TurnLeft(std::string& a_out) = 0;
    virtual void Take(const std::string& a_objectName, std::string& a_out) = 0;
    virtual void Fight(const std::string& a_name, std::string& a_out) = 0;
    virtual void Describe(std::string& a_out) = 0;
    virtual void Open(std::string& a_out) = 0;
    virtual void Close(std::string& a_out) = 0;
    virtual void Lock(std::string& a_out) = 0;
    virtual void UnLock(std::string& a_out) = 0;
    virtual const std::string& Name() const = 0;
};

} //d_d

#endif //I_PLAYER_HPP