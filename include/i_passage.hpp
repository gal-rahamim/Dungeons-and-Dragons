#ifndef I_PASSAGE_HPP
#define I_PASSAGE_HPP

#include <memory>

namespace d_d {

class IPassage {
public:
    IPassage(std::shared_ptr<IRoom> a_room1, std::shared_ptr<IRoom> a_room2);
    virtual ~IPassage();
    virtual void Describe(std::string& a_description) const = 0;
    virtual void Pass(std::shared_ptr<IRoom> a_from, std::shared_ptr<IRoom> a_to, std::string& a_output) const = 0;

protected:
    std::shared_ptr<IRoom> GetRoom1() const;
    std::shared_ptr<IRoom> GetRoom2() const;

private:
    std::shared_ptr<IRoom> m_room1;
    std::shared_ptr<IRoom> m_room2;

};

inline IPassage::IPassage(std::shared_ptr<IRoom> a_room1, std::shared_ptr<IRoom> a_room2)
: m_room1(a_room1)
, m_room2(a_room2)
{
}

inline IPassage::~IPassage() {}

inline std::shared_ptr<IRoom> IPassage::GetRoom1() const
{
    return m_room1;
}

inline std::shared_ptr<IRoom> IPassage::GetRoom2() const
{
    return m_room2;
}

} //d_d

#endif //I_PASSAGE_HPP