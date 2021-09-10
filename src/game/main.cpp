#include "game.hpp"
#include "map_loader.hpp"
#include "passage_parser.hpp"
#include "passage_loader.hpp"
#include "dragon_parser.hpp"
#include "dragon_loader.hpp"
#include "object_parser.hpp"
#include "object_loader.hpp"
#include "room_parser.hpp"
#include "room_loader.hpp"

int main(int argc, char** argv)
{
    auto pp = std::make_shared<d_d::PassageParser>();
    auto rp = std::make_shared<d_d::RoomParser>();
    auto dp = std::make_shared<d_d::DragonParser>();
    auto op = std::make_shared<d_d::ObjectParser>();
    auto pl = std::make_shared<d_d::PassageLoader>(pp);
    auto rl = std::make_shared<d_d::RoomLoader>(rp);
    auto dl = std::make_shared<d_d::DragonLoader>(dp);
    auto ol = std::make_shared<d_d::ObjectLoader>(op);
    auto ml = std::make_shared<d_d::MapLoader>(rl, pl, dl, ol);

    d_d::Game game(ml);
    game.Start();

    return 0;
}