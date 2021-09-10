#ifndef CONNECTION_HANDLER_HPP
#define CONNECTION_HANDLER_HPP

// #include <memory>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost::asio;
using ip::tcp;

namespace d_d {

class ConnectionHandler : public boost::enable_shared_from_this<ConnectionHandler> {
public:
    typedef boost::shared_ptr<ConnectionHandler> ConHandlerPtr;

public:
    ConnectionHandler(boost::asio::io_service& a_io_service);
    ~ConnectionHandler();

    static ConHandlerPtr GetPointer(boost::asio::io_service& a_io_service);
    tcp::socket& GetSocket();
    // bool Read(ConHandlerPtr& a_self, std::string& a_str);
    bool Read();
    bool Write(const std::string& a_str);
    void GetData(std::string& a_str) const;

private:
    void handle(const boost::system::error_code& err, size_t bytes_transferred);

private:
    tcp::socket m_sock;
    strand<io_service> m_strand;
    enum{ m_maxBufffer = 256};
    char m_buffer[m_maxBufffer];
};

} //d_d

#endif //CONNECTION_HANDLER_HPP