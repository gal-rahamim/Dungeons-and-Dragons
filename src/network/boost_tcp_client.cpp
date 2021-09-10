#include <iostream>
#include "boost_tcp_client.hpp"

#define BOOST_ASIO_NO_DEPRECATED

namespace d_d {

BoostTCPClient::BoostTCPClient(const std::string& a_ip, size_t a_port)
: m_ip(a_ip)
, m_port(a_port)
, m_io_context()
, m_sock(m_io_context)
{}

BoostTCPClient::~BoostTCPClient()
{
    m_read_thread.join();
    m_write_thread.join();
    error_code error;
    m_sock.close(error);
}

void BoostTCPClient::Connect()
{
    m_sock.connect(tcp::endpoint(io::ip::address::from_string(m_ip), m_port));
    std::cout << "Connected to server" << std::endl;
}

void BoostTCPClient::Start()
{
    read();
    m_read_thread = std::thread([this]{m_io_context.run();});
    write();
    m_write_thread = std::thread([this]{m_io_context.run();});
}

void BoostTCPClient::read_done(error_code a_error, std::size_t a_bytes_read)
{
    if(a_error) {
        std::cout << a_error.message() << std::endl;
        return;
    }
    std::stringstream stream;
    stream << std::istream(&m_in_packet).rdbuf();
    std::string msg(stream.str());
    msg.pop_back();
    m_in_packet.consume(a_bytes_read);
    std::cout << msg << std::endl;
    read();
}

void BoostTCPClient::write()
{
    std::getline(std::cin, m_out_massage);
    m_out_massage += '~';
    io::async_write(m_sock, io::buffer(m_out_massage), [this] (error_code error, std::size_t bytes_transferred)
    {
        send_done(error, bytes_transferred);
    });
}

void BoostTCPClient::send_done(error_code a_error, std::size_t a_bytes_read)
{
    if(a_error) {
        std::cout << a_error.message() << std::endl;
        return;
    }
    write();
}

void BoostTCPClient::read()
{
    io::async_read_until(m_sock, m_in_packet, '~', [this] (error_code error, std::size_t bytes_transferred)
    {
        read_done(error, bytes_transferred);
    });
}

} //d_d