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
    virtual void AddPassage(const std::pair<Direction, std::shared_ptr<IPassage>>& a_passage);
    virtual std::shared_ptr<IObject> GetObject(const std::string& a_objectName, std::string& a_output);
    virtual void PlaceObject(const IObject::ObjectPtr& a_object, std::string& a_output);
    virtual void PlaceObjects(const std::vector<IObject::ObjectPtr>& a_objects, std::string& a_output);
    virtual void Move(Direction a_direction, std::shared_ptr<IPassage>& a_passage);
    virtual void Enter(const std::shared_ptr<IFightable>& a_player);
    virtual void Exit(const std::string& a_playerName, std::shared_ptr<IFightable>& a_playerPtr);
    virtual void GetFightable(const std::string& a_fightableName, std::shared_ptr<IFightable>& a_fightable) const;

private:
    std::unordered_map<std::string, IObject::ObjectPtr> m_objects;
    std::unordered_map<Direction, std::shared_ptr<IPassage> > m_passages;
    std::unordered_map<std::string, std::shared_ptr<IFightable> > m_players;
};

} //d_d

#endif //ROOM_HPP