#ifndef BOOST_TCP_CLIENT_HPP
#define BOOST_TCP_CLIENT_HPP

#include <boost/asio.hpp>
#include <thread>
#include <memory>
// #include "i_tcp_client.hpp"

namespace io = boost::asio;
using tcp = io::ip::tcp;
using error_code = boost::system::error_code;

namespace d_d {

class BoostTCPClient {
public:
    BoostTCPClient(const std::string& a_ip = "127.0.0.1", size_t a_port = 2222); 
    ~BoostTCPClient();

    void Connect();
    void Write();
    void Read();

private:
    void read_done(error_code a_error, std::size_t a_bytes_read);
    void send_done(error_code a_error, std::size_t a_bytes_read);

private:
    std::string m_ip;
    size_t m_port;
    io::io_context m_io_context;
    tcp::socket m_sock;
    std::thread m_read_thread;
    std::thread m_write_thread;
    io::streambuf m_in_packet;
    std::string m_out_massage;
};

} //d_d

#endif //BOOST_TCP_CLIENT_HPP