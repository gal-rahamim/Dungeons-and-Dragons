#ifndef I_TCP_CLIENT_HPP
#define I_TCP_CLIENT_HPP

#include <string>

namespace d_d {

class ITCPClient {
public: 
    virtual ~ITCPClient() = default;
    virtual void Connect() = 0;
    virtual void Start() = 0;
};

} //d_d

#endif //I_TCP_CLIENT_HPP