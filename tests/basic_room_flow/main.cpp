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
    vector<IPassage::PassagePtr> passages({shared_ptr<Passage>(new Passage(r1, r2)),
                                                shared_ptr<Passage>(new Passage(r1, r3))});                                        
    r1->InitRoom(swords, passages);
    string out;
    r1->GetObject("blade", out);
    cout << out << endl;                                 
    return 0;
}
