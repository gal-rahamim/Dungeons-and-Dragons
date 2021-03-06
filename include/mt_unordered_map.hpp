#ifndef MT_UNORDERED_MAP_HPP
#define MT_UNORDERED_MAP_HPP

#include <unordered_map>
#include <mutex>

namespace d_d {

template<typename Key, typename Data>
class MTUnorderedMap {
public:
    void Insert(const std::pair<Key, Data>& a_item);
    void Remove(const Key& a_to_remove);
    bool IsExist(const Key& a_to_find) const;
    template<typename Function>
    void ForEach(Function a_fn) const;
    void Find(const Key& a_to_find, Data& a_found_object) const;
    operator bool() const;

private:
    std::unordered_map<Key, Data> m_map;
    mutable std::mutex m_lock;

};

} //d_d

#include "inl/mt_unordered_map.hxx"

#endif //MT_UNORDERED_MAP_HPP