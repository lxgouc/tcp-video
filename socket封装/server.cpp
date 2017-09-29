#include "socket.hpp"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>


int main()
{
    Socket ser;
    ser.CreateAddr("127.0.0.1",8080);
    if(!ser.Bind())
    {
        exit(1);
    }
    ser.Listen();
    int fd = ser.Accept();
    char buff[128] = {0};
    recv(fd,buff,127,0);
    std::cout<<buff<<std::endl;
}