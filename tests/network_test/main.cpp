#include "map_loader.hpp"
#include "room_parser.hpp"
#include "passage_parser.hpp"
#include "room_loader.hpp"
#include "passage_loader.hpp"
#include "dragon_loader.hpp"
#include "dragon_parser.hpp"
#include "object_loader.hpp"
#include "object_parser.hpp"
#include "game.hpp"

using namespace std;
using namespace d_d;

int main()
{
    shared_ptr<IPassageParser> pp = make_shared<PassageParser>();
    shared_ptr<IRoomParser> rp = make_shared<RoomParser>();
    shared_ptr<IDragonParser> dp = make_shared<DragonParser>();
    shared_ptr<IObjectParser> op = make_shared<ObjectParser>();
    shared_ptr<IPassageLoader> pl = make_shared<PassageLoader>(pp);
    shared_ptr<IRoomLoader> rl = make_shared<RoomLoader>(rp);
    shared_ptr<IFightableLoader> dl = make_shared<DragonLoader>(dp);
    shared_ptr<IObjectLoader> ol = make_shared<ObjectLoader>(op);
    shared_ptr<IMapLoader> ml = make_shared<MapLoader>(rl, pl, dl, ol);
    Game g(ml);
    g.Start();

    return 0;
}
