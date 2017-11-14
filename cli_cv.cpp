#include "socket.hpp"
#include "sockmat.hpp"
#include <cv.hpp>
#include <iostream>
using namespace cv;

int main()
{
    Socket cli;
    cli.CreateAddr("192.168.0.106",8888);
    cli.Connect();
    int recvfd = cli.Getfd();
    char buf[3];

    while(1)
    {
        if(recv(recvfd,buf,sizeof(buf),0) <= 0)
        {
            perror("recv failed cli1:");
            exit(1);
        }
        send(recvfd,"OK",2,0);
        Mat image;
        SockMat recvmat;
        while(1)
        {
            
           image = recvmat.Receive(recvfd);
           imshow("test",image);
           waitKey(11);
        }
    }
    return 0;
}
