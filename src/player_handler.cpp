#include <boost/bind.hpp>
#include <iostream>
#include "player_handler.hpp"
#include "player.hpp"

namespace d_d {

const std::unordered_map<std::string, std::string> PlayerHandler::s_dict({{"forward", "Forward"}
                                                         ,{"walk", "Forward"}
                                                         ,{"g", "Forward"}
                                                         ,{"go", "Forward"}
                                                         ,{"backwards", "Backward"}
                                                         ,{"b", "Backward"}
                                                         ,{"back", "Backward"}
                                                         ,{"left", "TurnLeft"}
                                                         ,{"l", "TurnLeft"}
                                                         ,{"right", "TurnRight"}
                                                         ,{"r", "TurnRight"}
                                                         ,{"Take", "Take"}
                                                         ,{"get", "Take"}
                                                         ,{"pick", "Take"}
                                                         ,{"open", "Open"}
                                                         ,{"o", "Open"}
                                                         ,{"close", "Close"}
                                                         ,{"unlock", "UnLock"}
                                                         ,{"lock", "Lock"}
                                                         ,{"look", "Look"}
                                                         ,{"where", "Where"}
                                                         ,{"me", "Describe"}
                                                         ,{"myself", "Describe"}
                                                         ,{"self", "Describe"}});

PlayerHandler::PlayerHandler(tcp::socket&& a_socket, const std::shared_ptr<IRoom>& a_start_room, const std::shared_ptr<MTUnorderedMap<std::string, bool>>& a_players)
: m_socket(std::move(a_socket))
, m_start_room(a_start_room)
, m_players(a_players)
{}

PlayerHandler::~PlayerHandler()
{
    error_code error;
    m_socket.close(error);
    if(m_player) {
        m_players->Remove(m_player->Name());
    }
}

tcp::socket& PlayerHandler::Socket()
{
    return m_socket;
}

void PlayerHandler::Start()
{
    send("Welcome\nPlease enter your name:\n~");
    read_name();
}

void PlayerHandler::read_name()
{
    if(!m_socket.is_open()) {
        return;
    }
    io::async_read_until(m_socket, m_in_packet, '~', [self = shared_from_this()] (error_code error, std::size_t bytes_transferred)
    {
        self->read_name_done(error, bytes_transferred);
    });
}

void PlayerHandler::read_name_done(error_code a_error, std::size_t a_bytes_read)
{
    if(a_error) {
        std::cout << "Read name error: " << a_error.message() << ", " << a_bytes_read << " bytes read" <<std::endl;
        m_socket.close(a_error);
        return;
    }
    std::istream stream(&m_in_packet);
    std::string name;
    stream >> name;
    name.pop_back();
    m_in_packet.consume(a_bytes_read);
    std::cout << name << std::endl;
    if(name == "" || m_players->IsExist(name)) {
        send("Illigal name, please try again\n~");
        read_name();
    }
    else {
        m_players->Insert(std::make_pair(name, true));
        m_player = std::make_shared<Player>(name, m_start_room);
        send("Welcome " + name + "\n~");
        read_command();
    }
}

void PlayerHandler::read_command()
{
    if(!m_socket.is_open()) {
        return;
    }
    io::async_read_until(m_socket, m_in_packet, '~', [self = shared_from_this()] (error_code error, std::size_t bytes_transferred)
    {
        self->read_command_done(error, bytes_transferred);
    });
}

static void splitTwoWords(const std::string& a_input, std::string& a_cmd, std::string& a_arg)
{
    size_t space = a_input.find_first_of(' ');
    if(space == std::string::npos) {
        a_cmd = a_input;
        a_arg = "";
        return;
    }
    a_cmd = a_input.substr(0,space);
    a_arg = a_input.substr(space + 1);
}

void PlayerHandler::read_command_done(error_code a_error, std::size_t a_bytes_read)
{
    if(a_error) {
        std::cout << "Read command error: " << a_error.message() << ", " << a_bytes_read << " bytes read" <<std::endl;
        m_socket.close(a_error);
        return;
    }
    std::stringstream stream;
    stream << std::istream(&m_in_packet).rdbuf();
    std::string input(stream.str()), command, arg;
    input.pop_back();
    m_in_packet.consume(m_in_packet.size());
    splitTwoWords(input, command, arg);
    auto res = s_dict.find(command);
    if(res == s_dict.end()) {
        send("Unknown command: " + command + ", please try again\n~");
    }
    else {
        std::string out;
        if(arg == "") {
            m_player->Call(res->second, out);
        }
        else {
            m_player->Call(res->second, arg, out);
        }
        send(out + "~");
    }
    read_command();
}

void PlayerHandler::send(const std::string& a_msg)
{
    if(!m_socket.is_open()) {
        return;
    }
    // error_code error;
    // io::write(m_socket, io::buffer(a_msg), error);
    // if(error){
    //     std::cout << "send failed: " << error.message() << std::endl;
    // }
    io::async_write(m_socket, io::buffer(a_msg), [self = shared_from_this()] (error_code error, std::size_t bytes_transferred)
    {
        self->send_done(error, bytes_transferred);
    });
}

void PlayerHandler::send_done(error_code a_error, std::size_t a_bytes_read)
{
    if(a_error) {
        std::cout << a_error.message() << std::endl;
        m_socket.close(a_error);
        return;
    }
    std::cout << "sent " << a_bytes_read << " bytes" << std::endl;
}

} //d_d