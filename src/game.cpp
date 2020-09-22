#include "game.hpp"
#include "boost_tcp_server.hpp"

namespace d_d {

Game::Game(const std::shared_ptr<IMapLoader>& a_map_loader)
: m_map_loader(a_map_loader)
, m_map()
, m_players(std::make_shared<MTUnorderedMap<std::string, std::shared_ptr<PlayerHandler>>>())
, m_tcp_server(std::make_shared<BoostTcpServer<PlayerHandler>>(3))
{
    m_map_loader->Load(m_map);
}

void Game::Start()
{
    auto res = m_map.find("room a");
    if(res != m_map.end()) {
        m_tcp_server->StartServer(res->second, m_players);
    }
}

} //d_d