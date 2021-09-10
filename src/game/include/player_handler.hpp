#ifndef PLAYER_HANDLER_HPP
#define PLAYER_HANDLER_HPP

#include <memory>
#include <boost/asio.hpp>
#include "i_room.hpp"
#include "i_player.hpp"
#include "mt_unordered_map.hpp"

namespace io = boost::asio;
using tcp = io::ip::tcp;
using error_code = boost::system::error_code;

namespace d_d {

class PlayerHandler : public std::enable_shared_from_this<PlayerHandler> {
public:
    PlayerHandler(tcp::socket&& a_socket, const std::shared_ptr<IRoom>& a_start_room, const std::shared_ptr<MTUnorderedMap<std::string, std::shared_ptr<PlayerHandler>>>& a_players);
    ~PlayerHandler();
    
    tcp::socket& Socket();
    void Start();

private:
    void read_name();
    void read_name_done(error_code a_error, std::size_t a_bytes_read);
    void read_command();
    void read_command_done(error_code a_error, std::size_t a_bytes_read);
    void send(const std::string& a_msg);
    void send_done(error_code a_error, std::size_t a_bytes_read);

private:
    static const std::unordered_map<std::string, std::string> s_dict;

private:
    tcp::socket m_socket;
    std::shared_ptr<IRoom> m_start_room;
    std::shared_ptr<IPlayer> m_player;
    io::streambuf m_in_packet;
    std::shared_ptr<MTUnorderedMap<std::string, std::shared_ptr<PlayerHandler>>> m_players;
    std::string m_name;
};

} //d_d

#endif //PLAYER_HANDLER_HPP