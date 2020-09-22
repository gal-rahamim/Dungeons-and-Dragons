#ifndef MT_UNORDERED_MAP_HXX
#define MT_UNORDERED_MAP_HXX

#include "mt_unordered_map.hpp"
#include "locker.hpp"

namespace d_d {
template<typename Key, typename Data>
void MTUnorderedMap<Key, Data>::Insert(const std::pair<Key, Data>& a_item)
{
    Locker guard(m_lock);
    m_map.insert(a_item);
}

template<typename Key, typename Data>
void MTUnorderedMap<Key, Data>::Remove(const Key& a_to_remove)
{
    Locker guard(m_lock);
    m_map.erase(a_to_remove);
}

template<typename Key, typename Data>
bool MTUnorderedMap<Key, Data>::IsExist(const Key& a_to_find) const
{
    Locker guard(m_lock);
    auto res = m_map.find(a_to_find);
    return res == m_map.end() ? false : true;
}

template<typename Key, typename Data>
MTUnorderedMap<Key, Data>::operator bool() const
{
    return true;
}

template<typename Key, typename Data>
template<typename Function>
void MTUnorderedMap<Key, Data>::ForEach(Function a_fn) const
{
    Locker guard(m_lock);
    for(auto i : m_map) {
        a_fn(i);
    }
}

} //d_d

#endif //MT_UNORDERED_MAP_HXX