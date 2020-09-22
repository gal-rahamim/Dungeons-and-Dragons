#ifndef MT_UNORDERED_MAP_HXX
#define MT_UNORDERED_MAP_HXX

#include "mt_unordered_map.hpp"
#include "locker.hpp"

namespace d_d {
template<typename Key, typename Data>
void MTUnorderedMap<Key, Data>::Insert(const std::pair<Key, Data>& a_item)
{
    Locker guard(m_lock);
    m_set.insert(a_item);
}

template<typename Key, typename Data>
void MTUnorderedMap<Key, Data>::Remove(const Key& a_to_remove)
{
    Locker guard(m_lock);
    m_set.erase(a_to_remove);
}

template<typename Key, typename Data>
bool MTUnorderedMap<Key, Data>::IsExist(const Key& a_to_find) const
{
    Locker guard(m_lock);
    auto res = m_set.find(a_to_find);
    return res == m_set.end() ? false : true;
}

template<typename Key, typename Data>
MTUnorderedMap<Key, Data>::operator bool() const
{
    return true;
}

} //d_d

#endif //MT_UNORDERED_MAP_HXX