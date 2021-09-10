#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <memory>
#include <thread>
#include <atomic>
#include "i_tcp_client.hpp"

namespace d_d {

class GamePlayer {
public:
    GamePlayer(ITCPClient& a_tcp_client);
    ~GamePlayer();
    void Play();

// private:
//     void openForRead();

private:
    ITCPClient& m_tcp_client;
    // std::shared_ptr<std::thread> m_always_read;
    // std::atomic<bool> m_game_status;
};

} //d_d

#endif //GAME_PLAYER_HPP