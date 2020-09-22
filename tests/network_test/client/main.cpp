#include "game_player.hpp"
#include "boost_tcp_client.hpp"

using namespace std;
using namespace d_d;

int main()
{
    BoostTCPClient client;
    client.Connect();

    return 0;
}
