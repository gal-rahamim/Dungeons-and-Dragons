#include <chrono> 
#include "dragon.hpp"
namespace d_d {

void waitNsecAndThenRespawn(std::shared_ptr<IFightable> a_dragon, const std::shared_ptr<IRoom>& a_location, unsigned int a_sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(a_sec));
    if(a_location){
        a_location->Enter(a_dragon);
    }
}

Dragon::Dragon(const std::string& a_name, const std::shared_ptr<IRoom>& a_starting_pos, unsigned int a_life, unsigned int a_money
                , unsigned int a_attack, unsigned int a_defense, unsigned int a_respawn_sec)
: IFightable(a_name, a_life, a_money)
, m_starting_pos(a_starting_pos)
, m_attack(a_attack)
, m_defense(a_defense)
, m_respawn_sec(a_respawn_sec)
, m_starting_money(a_money)
, m_respwan_wait_thread()
{}                

Dragon::~Dragon()
{
    m_respwan_wait_thread->join();
}

unsigned int Dragon::GetDefense() const
{
    return m_defense;
}

unsigned int Dragon::GetAttack() const
{
    return m_attack;
}

void Dragon::Describe(std::string& a_out) const
{
    a_out = Name() + " is a mighty fire breathing dragon!\nStats:\nLife: " + std::to_string(GetLife()) + ", Attack: " + std::to_string(m_attack) + ", Defense: " + std::to_string(m_defense) + "\nTreasure upon slaying: " + std::to_string(GetMoney());
}

void Dragon::Respawn()
{
    std::shared_ptr<IFightable> me;
    m_starting_pos->Exit(Name(), me);
    SetMoney(m_starting_money);
    m_respwan_wait_thread = std::make_shared<std::thread>(waitNsecAndThenRespawn, me, std::ref(m_starting_pos), m_respawn_sec);
}


} //d_d
