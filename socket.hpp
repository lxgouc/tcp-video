#pragma once
#include <netinet/in.h>
#include <arpa/inet.h>

class Socket
{
public:
    Socket();
    ~Socket();
    void CreateAddr(const char *ip,int port);
    int Getfd();
    bool Bind();
    bool Listen();
    int Accept();
    bool Connect();
private:
    int _sockfd;
    const char *_ip;
    int _port;
    struct sockaddr_in _socketaddr;
};


