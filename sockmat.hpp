#pragma once
#include <cv.hpp>

//typedef unsigned char uchar;

class SockMat
{
public:
    SockMat();
    bool Transmit(cv::Mat& image,int sendfd);
    cv::Mat Receive(int recvfd);
private:

};