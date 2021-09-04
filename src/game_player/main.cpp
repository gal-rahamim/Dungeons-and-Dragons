#include "game_player.hpp"
#include  "boost_tcp_client.hpp"

int main(int argc, char** argv)
{
    d_d::BoostTCPClient client;
    d_d::GamePlayer player(client);
    player.Play();

    return 0;
}