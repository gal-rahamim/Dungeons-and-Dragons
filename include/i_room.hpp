#ifndef I_ROOM_HPP
#define I_ROOM_HPP

#include <string>
#include <vector>
#include <memory>
#include "i_object.hpp"

namespace d_d {

class IPassage;
class IFightable;

class IRoom {
public:
    typedef std::shared_ptr<IRoom> RoomPtr;
    enum Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

public:
    IRoom(const std::string& a_name);
    virtual ~IRoom();

    virtual void InitRoom(const std::vector<IObject::ObjectPtr>& a_objects,
                         const std::vector<std::pair<Direction, std::shared_ptr<IPassage> > >& a_passages) = 0;
    virtual void Describe(std::string& a_description) const = 0;
    virtual void AddPassage(const std::pair<Direction, std::shared_ptr<IPassage>>& a_passage) = 0;
    virtual void GetObject(const std::string& a_objectName, std::shared_ptr<IObject>& a_obj, std::string& a_output) = 0;
    virtual void PlaceObject(const IObject::ObjectPtr& a_object, std::string& a_output) = 0;
    virtual void PlaceObjects(const std::vector<IObject::ObjectPtr>& a_objects, std::string& a_output) = 0;
    virtual void Move(Direction a_direction, std::shared_ptr<IPassage>& a_passage) = 0;
    virtual void Enter(const std::shared_ptr<IFightable>& a_player) = 0;
    virtual void Exit(const std::string& a_playerName, std::shared_ptr<IFightable>& a_playerPtr) = 0;
    virtual void GetFightable(const std::string& a_fightableName, std::shared_ptr<IFightable>& a_fightable) const = 0;
    const std::string& Name() const;

private:
    std::string m_name;
};

inline IRoom::IRoom(const std::string& a_name)
: m_name(a_name)
{}

inline IRoom::~IRoom(){}


inline const std::string& IRoom::Name() const
{
    return m_name;
}


} //d_d

#endif //I_ROOM_HPP