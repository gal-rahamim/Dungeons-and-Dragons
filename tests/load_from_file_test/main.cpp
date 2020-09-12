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
#include "map_loader.hpp"
#include "room_parser.hpp"
#include "passage_parser.hpp"
#include "room_loader.hpp"
#include "passage_loader.hpp"
#include "dragon_loader.hpp"
#include "dragon_parser.hpp"

using namespace std;
using namespace d_d;

int main()
{
    shared_ptr<IPassageParser> pp = make_shared<PassageParser>();
    shared_ptr<IRoomParser> rp = make_shared<RoomParser>();
    shared_ptr<IDragonParser> dp = make_shared<DragonParser>();
    shared_ptr<IPassageLoader> pl = make_shared<PassageLoader>(pp);
    shared_ptr<IRoomLoader> rl = make_shared<RoomLoader>(rp);
    shared_ptr<IFightableLoader> dl = make_shared<DragonLoader>(dp);
    MapLoader ml(rl, pl, dl);
    vector<shared_ptr<IRoom>> rooms;
    ml.Load(rooms);
    string out;
    rooms[0]->Describe(out);
    cout << out << endl;
    rooms[1]->Describe(out);
    cout << out << endl;
    rooms[2]->Describe(out);
    cout << out << endl;

    return 0;
}
