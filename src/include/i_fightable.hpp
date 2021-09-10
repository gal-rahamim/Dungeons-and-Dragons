#ifndef I_FIGHTABLE_HPP
#define I_FIGHTABLE_HPP

#include <string>

namespace d_d {

class IFightable {
public:
    IFightable(const std::string& a_name, unsigned int a_life, unsigned int a_money);
    virtual ~IFightable() = default;
    virtual unsigned int GetDefense() const = 0;
    virtual unsigned int GetAttack() const = 0;
    virtual void Describe(std::string& a_out) const = 0;
    virtual void Respawn() = 0;

    unsigned int GetLife() const;
    unsigned int GetMoney() const;
    void SetLife(unsigned int a_newLife);
    void SetMoney(unsigned int a_newMoney);
    void AddMoney(unsigned int a_money);
    void ReduceMoney(unsigned int a_money);
    void AddLife(unsigned int a_life);
    void ReduceLife(unsigned int a_life);
    std::string Name() const;

private:
    static const unsigned int MAX_LIFE;
    static const unsigned int MAX_MONEY;

private:
    unsigned int m_life; 
    unsigned int m_money; 
    std::string m_name;
};

} //d_d

#endif //I_FIGHTABLE_HPP