#ifndef BOOST_TCP_SERVER_HXX
#define BOOST_TCP_SERVER_HXX

#include "boost_tcp_server.hpp"

namespace d_d {

template<typename ConnectionHandler>
BoostTcpServer<ConnectionHandler>::BoostTcpServer(size_t a_thread_count, size_t a_port)
: m_num_of_threads(a_thread_count)
, m_io_context()
, m_acceptor(m_io_context, tcp::endpoint(tcp::v4(), a_port))
{}

// template<typename ConnectionHandler>
// BoostTcpServer<ConnectionHandler>::~BoostTcpServer()
// {
//     for(size_t i = 0 ; i < m_num_of_threads ; ++i) {
//         m_thread_pool[i].join();
//     }
// }

template<typename ConnectionHandler>
template<typename Arg1, typename Arg2>
void BoostTcpServer<ConnectionHandler>::StartServer(const Arg1& a_arg1, const Arg2& a_arg2)
{
    m_socket.emplace(m_io_context);

    m_acceptor.async_accept(*m_socket, [&](error_code error)
    {
        if(!error){
            auto handler = std::make_shared<ConnectionHandler>(std::move(*m_socket), a_arg1, a_arg2);
            handler->Start();
        }
        handleNewConnection(a_arg1, a_arg2);
    });

    for(size_t i = 0 ; i < m_num_of_threads ; ++i) {
        m_thread_pool.emplace_back([=]{m_io_context.run();});
    }                                   

    for(size_t i = 0 ; i < m_num_of_threads ; ++i) {
        if(m_thread_pool[i].joinable()) {            
            m_thread_pool[i].join();
        }
    }
}

template<typename ConnectionHandler>
template<typename Arg1, typename Arg2>
void BoostTcpServer<ConnectionHandler>::handleNewConnection(const Arg1& a_arg1, const Arg2& a_arg2)
{
    m_socket.emplace(m_io_context);
    m_acceptor.async_accept(*m_socket, [&](error_code error)
    {
        if(!error){
            auto handler = std::make_shared<ConnectionHandler>(std::move(*m_socket), a_arg1, a_arg2);
            handler->Start();
        }
        handleNewConnection(a_arg1, a_arg2);
    });

}

} //d_d

#endif //BOOST_TCP_SERVER_HXX
