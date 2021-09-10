#ifndef LOCKER_HPP
#define LOCKER_HPP

#include <mutex>
#include "common.hpp"

namespace d_d {

class Locker :  private advcpp::UnCopyable {
public:
    Locker(std::mutex& a_lock);
    ~Locker();

private:
    std::mutex& m_lock;
};

inline Locker::Locker(std::mutex& a_lock) 
: m_lock(a_lock)
{
    m_lock.lock();
}

inline Locker::~Locker()
{
    m_lock.unlock();
}

} //d_d

#endif //LOCKER_HPP