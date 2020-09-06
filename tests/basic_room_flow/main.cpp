#include <iostream>
#include "i_room.hpp"
#include "room.hpp"
#include "passage.hpp"
#include "key.hpp"
#include "sword.hpp"

using namespace std;
using namespace d_d;

int main()
{
    vector<IObject::ObjectPtr> swords({shared_ptr<Sword>(new Sword("blade", 4))
                                        , shared_ptr<Sword>(new Sword("cutycut", 6))});
    shared_ptr<Room> r1(new Room("room a"));
    shared_ptr<Room> r2(new Room("room b"));
    shared_ptr<Room> r3(new Room("room c"));
    Key k("cool key");
    shared_ptr<Passage> p1(new Passage(r1, r2, Passage::DOOR_STATE_CLOSED, Passage::LOCK_STATE_LOCKED, k));
    vector<IPassage::PassagePtr> passages({p1, shared_ptr<Passage>(new Passage(r1, r3))});                                        
    r1->InitRoom(swords, passages);
    string out;
    r1->Describe(out);
    cout << out << endl;   
    shared_ptr<IObject> s = r1->GetObject("blade", out);
    cout << out << endl;        
    r1->GetObject("blade", out);                         
    cout << out << endl;        
    p1->Describe(out);
    cout << out << endl;        
    p1->UnLock(Key(), out);
    cout << out << endl;   
    p1->UnLock(k, out);
    cout << out << endl;   
    p1->UnLock(k, out);
    cout << out << endl; 
    shared_ptr<IRoom> newRoom;  
    p1->Pass(r1, newRoom, out);
    cout << out << endl;  
    p1->Open(out);
    cout << out << endl;   
    p1->Pass(r1, newRoom, out);
    cout << out << endl;  
    newRoom->PlaceObject(s, out);
    cout << out << endl;  
    newRoom->Describe(out);
    cout << out << endl;  
    return 0;
}
