#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include "i_map_loader.hpp"
#include "i_player.hpp"
#include "boost_tcp_server.hpp"
#include "player_handler.hpp"
#include "mt_unordered_map.hpp"

namespace d_d {

class Game {
public:
    Game(const std::shared_ptr<IMapLoader>& a_map_loader);
    void Start();

private:
    static const std::unordered_map<std::string, std::string> s_dict;

private:
    std::shared_ptr<IMapLoader> m_map_loader;
    std::unordered_map<std::string, std::shared_ptr<IRoom> > m_map;
    std::shared_ptr<MTUnorderedMap<std::string, std::shared_ptr<PlayerHandler>> > m_players;
    std::shared_ptr<BoostTcpServer<PlayerHandler> > m_tcp_server;
};

} //d_d

#endif //GAME_HPP