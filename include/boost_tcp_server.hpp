#ifndef BOOST_TCP_SERVER_HPP
#define BOOST_TCP_SERVER_HPP

#include <vector>
#include <memory>
#include <thread>
#include <optional>
#include <boost/asio.hpp>

namespace io = boost::asio;
using tcp = io::ip::tcp;
using error_code = boost::system::error_code;

namespace d_d {

template<typename ConnectionHandler>
class BoostTcpServer {
public:
    using shared_handler = std::shared_ptr<ConnectionHandler>;

public:
    BoostTcpServer(size_t a_thread_count = 1, size_t a_port = 2222);
    // ~BoostTcpServer();

    template<typename Arg1, typename Arg2>
    void StartServer(const Arg1& a_arg1 = nullptr, const Arg2& a_arg2 = nullptr);

private:
    template<typename Arg1, typename Arg2>
    void handleNewConnection(const Arg1& a_arg1, const Arg2& a_arg2);

private:
    size_t m_num_of_threads;
    std::vector<std::thread> m_thread_pool;
    io::io_context m_io_context;
    tcp::acceptor m_acceptor;
    std::optional<tcp::socket> m_socket;
};

} //d_d

#include "inl/boost_tcp_server.hxx"

#endif //BOOST_TCP_SERVER_HPP