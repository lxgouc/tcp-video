#include "socket.hpp"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
     Socket cli;
     cli.CreateAddr("127.0.0.1",8080);
     if(!cli.Connect())
     {
         exit(1);
     }
     int fd = cli.Getfd();
     char buff[128] = {"test socket\n"};
     send(fd,buff,127,0);
}