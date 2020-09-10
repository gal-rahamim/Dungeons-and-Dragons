#ifndef DRAGON_HPP
#define DRAGON_HPP

#include <memory>
#include "i_room.hpp"
#include "i_fightable.hpp"

namespace d_d {

class Dragon : public IFightable {
public:
    Dragon(const std::string& a_name, const std::shared_ptr<IRoom>& a_starting_pos, unsigned int a_life = 100, unsigned int a_money = 100, unsigned int a_attack = 12, unsigned int a_defense = 9, unsigned int a_respawn_sec = 20);
    virtual unsigned int GetDefense() const;
    virtual unsigned int GetAttack() const;
    virtual void Describe(std::string& a_out) const;
    virtual void Respawn();

private:
    const std::shared_ptr<IRoom> m_starting_pos;
    const unsigned int m_attack;
    const unsigned int m_defense;
    const unsigned int m_respawn_sec;
    const unsigned int m_starting_money;
};

} //d_d

#endif //DRAGON_HPP