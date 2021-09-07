#ifndef I_TCP_CLIENT_HPP
#define I_TCP_CLIENT_HPP

#include <string>

namespace d_d {

class ITCPClient {
public: 
    virtual ~ITCPClient() = default;
    virtual void Connect() = 0;
    virtual void Write(const std::string& a_msg) = 0;
    virtual void Read(std::string& a_msg) = 0;
};

} //d_d

#endif //I_TCP_CLIENT_HPP