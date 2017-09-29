#include "socket.hpp"
#include "sockmat.hpp"
#include <cv.hpp>
#include <iostream>
using namespace cv;

int main()
{
    Socket cli;
    cli.CreateAddr("127.0.0.1",8888);
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
            //if(i == 23)
            //{
            //    for(int j = 0;j < i;++j)
            //    {    
                    imshow("test",image);
                    waitKey(11);
                //}
            //    i == -1;
           // }
           // i++;
        }
    }
    return 0;
}
