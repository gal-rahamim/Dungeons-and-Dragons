#include <iostream>
#include <unistd.h>
#include "i_room.hpp"
#include "room.hpp"
#include "passage.hpp"
#include "key.hpp"
#include "i_sword.hpp"
#include "sword.hpp"
#include "player.hpp"
#include "dragon.hpp"

using namespace std;
using namespace d_d;

int main()
{
    shared_ptr<Room> r1(new Room("room a"));
    shared_ptr<Room> r2(new Room("room b"));
    shared_ptr<Room> r3(new Room("room c"));
    shared_ptr<Key> k(new Key("cool key", r1));
    vector<IObject::ObjectPtr> r1_objects({shared_ptr<Sword>(new Sword("blade", 4, r1, 20))
                                        , shared_ptr<Sword>(new Sword("cutycut", 6, r1, 20)), k});
    vector<IObject::ObjectPtr> r2_objects({shared_ptr<Sword>(new Sword("Slayer", 9, r2, 20))});                                        
    shared_ptr<Passage> p1_2(new Passage(r1, r2, Passage::DOOR_STATE_CLOSED, Passage::LOCK_STATE_LOCKED, k));
    shared_ptr<Passage> p1_3(new Passage(r1, r3, Passage::DOOR_STATE_CLOSED));
    vector<pair<Room::Direction, IPassage::PassagePtr> > r1_passages({make_pair(Room::NORTH,p1_2), make_pair(Room::SOUTH,p1_3)});                                        
    vector<pair<Room::Direction, IPassage::PassagePtr> > r2_passages({make_pair(Room::SOUTH,p1_2)});                                        
    vector<pair<Room::Direction, IPassage::PassagePtr> > r3_passages({make_pair(Room::NORTH,p1_3)});                                        
    r1->InitRoom(r1_objects, r1_passages);
    r2->InitRoom(r2_objects, r2_passages);
    r3->InitRoom(vector<IObject::ObjectPtr>(), r3_passages);

    string out;
    shared_ptr<Dragon> drogo = make_shared<Dragon>("Drogo", r3);
    r3->Enter(drogo);
    shared_ptr<Player> gal = make_shared<Player>("Gal", r1);
    r1->Enter(gal);
    gal->TurnLeft(out);
    cout << out << endl;
    gal->TurnLeft(out);
    cout << out << endl;
    gal->Open(out);
    cout << out << endl;
    gal->Forward(out);
    cout << out << endl;
    gal->Look(out);
    cout << out << endl;
    gal->ReduceLife(41);
    gal->Fight("Drogo", out);
    cout << out << endl;
    gal->Describe(out);
    cout << out << endl;
    gal->Forward(out);
    cout << out << endl;
    gal->Look(out);
    cout << out << endl;
    drogo->ReduceLife(99);
    drogo->Describe(out);
    cout << out << endl;
    gal->Fight("Drogo", out);
    cout << out << endl;
    gal->Look(out);
    cout << out << endl;
    sleep(21);
    gal->Look(out);
    cout << out << endl;

    return 0;
}
