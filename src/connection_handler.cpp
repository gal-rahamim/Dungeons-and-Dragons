#include "connection_handler.hpp"

namespace d_d {

ConnectionHandler::ConnectionHandler(boost::asio::io_service& a_io_service)
: m_sock(a_io_service)
, m_strand(a_io_service)
{}

ConnectionHandler::~ConnectionHandler()
{
    m_sock.close();
}

ConnectionHandler::ConHandlerPtr ConnectionHandler::GetPointer(boost::asio::io_service& a_io_service)
{
    return ConHandlerPtr(new ConnectionHandler(a_io_service));
}

tcp::socket& ConnectionHandler::GetSocket()
{
    return m_sock;
}

bool ConnectionHandler::Read()
{
    if(!m_sock.is_open()) {
        return false;
    }
    m_sock.async_read_some(boost::asio::buffer(m_buffer), m_strand.wrap(boost::bind(&ConnectionHandler::handle, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)));
    return true;
}

void ConnectionHandler::GetData(std::string& a_str) const
{
    a_str = m_buffer;
}

// bool ConnectionHandler::Read(ConHandlerPtr& a_self, std::string& a_str)
// {
//     a_self = shared_from_this();
//     return Read(a_str);
// }

void ConnectionHandler::handle(const boost::system::error_code& err, size_t bytes_transferred)
{
    if(err) {
        std::cerr << "error: " << err.message() << std::endl;
        m_sock.close();
    }
}

bool ConnectionHandler::Write(const std::string& a_str)
{
    if(!m_sock.is_open()) {
        return false;
    }
    m_sock.async_write_some(boost::asio::buffer(a_str), m_strand.wrap(boost::bind(&ConnectionHandler::handle, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)));
    return true;
}

} //d_d