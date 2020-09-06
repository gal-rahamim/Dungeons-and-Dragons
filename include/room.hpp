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

    virtual void InitRoom(const std::vector<IObject::ObjectPtr>& a_objects,
                         const std::vector<std::pair<Direction, std::shared_ptr<IPassage> > >& a_passages);

    virtual void Describe(std::string& a_description) const;
    virtual std::shared_ptr<IObject> GetObject(const std::string& a_objectName, std::string& a_output);
    virtual void PlaceObject(const IObject::ObjectPtr& a_object, std::string& a_output);
    virtual void Move(Direction a_direction, std::shared_ptr<IPassage>& a_passage);
    virtual void Enter(const std::shared_ptr<IPlayer>& a_player);
    virtual std::shared_ptr<IPlayer> Exit(const std::string& a_playerName);

private:
    std::unordered_multimap<std::string, IObject::ObjectPtr> m_objects;
    std::unordered_multimap<Direction, std::shared_ptr<IPassage> > m_passages;
    std::unordered_map<std::string, std::shared_ptr<IPlayer> > m_players;
};

} //d_d

#endif //ROOM_HPP