#pragma once
#include <cv.hpp>

class SockMat
{
public:
    SockMat();
    bool Transmit(cv::Mat& image,int sendfd);
    cv::Mat Receive(int recvfd);
private:

};