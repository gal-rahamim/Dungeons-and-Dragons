#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <unordered_map>
#include "i_room.hpp"
#include "common.hpp"

namespace d_d {

class Room : public IRoom, advcpp::UnCopyable {
public:
    Room(std::string a_name);

    virtual void InitRoom(const std::vector<IObject::ObjectPtr>& a_objects, const std::vector<std::shared_ptr<IPassage>>& a_passages);

    virtual void Describe(std::string& a_description) const;
    virtual std::shared_ptr<IObject> GetObject(const std::string& a_objectName, std::string& a_output);
    virtual void PlaceObject(const IObject::ObjectPtr& a_object, std::string& a_output);
    // virtual void Enter(std::shared_ptr<Player> a_player);
    // virtual std::shared_ptr<IRoom> Exit(std::shared_ptr<Player> a_player, std::shared_ptr<IPassage> a_passage);
    // virtual std::string Name() const;

private:
    // std::string m_name;
    std::unordered_multimap<std::string, IObject::ObjectPtr> m_objects;
    std::vector<std::shared_ptr<IPassage>> m_passages;
};

} //d_d

#endif //ROOM_HPP