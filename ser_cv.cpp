#include "socket.hpp"
#include "sockmat.hpp"
#include <cv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Socket ser;
    ser.CreateAddr("192.168.1.107",8888);
    ser.Bind();
    ser.Listen();
    VideoCapture capture(0);
    if(!capture.isOpened()) exit(1);
    char str[3];
    while(1)
    {
        int clifd = ser.Accept();
        send(clifd,"ok",2,0);
        if(recv(clifd,str,2,0) <= 0)
        {
            perror("recv failed:");
            exit(1);
        }
        cout << "one client connected : " << str << std::endl;
        Mat frame;
        SockMat transmat;
        if (!capture.isOpened()) 
            return 0;
        while(1)
        {      
            capture >> frame;
            transmat.Transmit(frame,clifd);
        }
    }
    return 0;
}
