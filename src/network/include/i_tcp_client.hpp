#ifndef I_TCP_CLIENT_HPP
#define I_TCP_CLIENT_HPP

#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

namespace d_d {

class ITCPClient {
public: 
    virtual ~ITCPClient();
    virtual void Connect() = 0;
    virtual void Write(const std::string& a_msg) = 0;
    virtual void Read(std::string& a_msg) = 0;
};

inline ITCPClient::~ITCPClient(){}

} //d_d

#endif //I_TCP_CLIENT_HPP