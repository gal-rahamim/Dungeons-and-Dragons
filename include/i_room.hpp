#ifndef I_ROOM_HPP
#define I_ROOM_HPP

#include <string>
#include <vector>
#include <memory>
#include "i_object.hpp"

namespace d_d {

class IPassage;
class IPlayer;

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
    virtual std::shared_ptr<IObject> GetObject(const std::string& a_objectName, std::string& a_output) = 0;
    virtual void PlaceObject(const IObject::ObjectPtr& a_object, std::string& a_output) = 0;
    virtual void Move(Direction a_direction, std::shared_ptr<IPassage>& a_passage) = 0;
    virtual void Enter(const std::shared_ptr<IPlayer>& a_player) = 0;
    virtual std::shared_ptr<IPlayer> Exit(const std::string& a_playerName) = 0;
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