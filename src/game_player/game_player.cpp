#include <iostream>
#include "game_player.hpp"

namespace d_d {

GamePlayer::GamePlayer(ITCPClient& a_tcp_client)
: m_tcp_client(a_tcp_client)
, m_always_read()
, m_game_status(true)
{
    a_tcp_client.Connect();
}

GamePlayer::~GamePlayer()
{
    m_always_read->join();
}

void GamePlayer::Play()
{
    m_always_read = std::make_shared<std::thread>(&GamePlayer::openForRead, this);
    std::string input;
    do{
        std::cin >> input;
        m_tcp_client.Write(input);
    }
    while(input != "q" && input != "quit" && input != "exit");
    m_game_status = false;
}

void GamePlayer::openForRead()
{
    std::string output;
    while(m_game_status) {
        m_tcp_client.Read(output);
        std::cout << output << std::endl;
    }
}

} //d_d