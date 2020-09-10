#include <cassert>
#include "i_fightable.hpp"

namespace d_d {

const unsigned int IFightable::MAX_MONEY = 1000;
const unsigned int IFightable::MAX_LIFE = 142;

IFightable::IFightable(const std::string& a_name, unsigned int a_life, unsigned int a_money)
: m_life(a_life)
, m_money(a_money)
, m_name(a_name)
{
    assert(m_life <= MAX_LIFE);
    assert(m_money <= MAX_MONEY);
}

IFightable::~IFightable(){}

unsigned int IFightable::GetLife() const
{
    return m_life;
}

unsigned int IFightable::GetMoney() const
{
    return m_money;
}

void IFightable::SetLife(unsigned int a_newLife)
{
    m_life = a_newLife;
}

void IFightable::SetMoney(unsigned int a_newMoney)
{
    m_money = a_newMoney;
}

void IFightable::AddMoney(unsigned int a_money)
{
    m_money = std::min(a_money+m_money, MAX_MONEY);
}

void IFightable::ReduceMoney(unsigned int a_money)
{
    m_money = std::max(m_money - a_money, (unsigned int)0);
}

std::string IFightable::Name() const
{
    return m_name;
}

void IFightable::AddLife(unsigned int a_life)
{
    m_life = std::min(a_life + m_life, MAX_LIFE);
}

void IFightable::ReduceLife(unsigned int a_life)
{
    m_life = a_life > m_life ? 0 : m_life - a_life;
}

} //d_d
