#include "sockmat.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <strings.h>
#include <cv.hpp>
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;
typedef unsigned char uchar;

SockMat::SockMat()
{

}

bool SockMat::Transmit(cv::Mat& image,int sendfd)
{
    if(image.empty()) return false;
    //printf("%d\n",image.total());
    vector<uchar> buf;
    vector<int>param;
    param.push_back(CV_IMWRITE_JPEG_QUALITY);
    param.push_back(95);
    cv::imencode(".jpg",image,buf,param);
    vector<uchar>::size_type size=buf.size();
    if(send(sendfd,&size,sizeof(size),0)==-1)
    {
        perror("send size error!");
        return false;
    }
    if(send(sendfd,buf.data(),size,0) == -1)
    {
        perror("send error ser1:");
        return false;
    }
    return true;
}

cv::Mat SockMat::Receive(int recvfd)
{
    int len=0;
    vector<uchar>::size_type num;
    uchar buf[1000000];
    if((recv(recvfd,&num,sizeof(num),0))<0)
    {
        perror("recv num failed");
        exit(1);
    }
    cout<<"num"<<num<<endl;
    while(len<num)
    {
        if((len+=recv(recvfd,&buf[0+len],num-len,0))<0)
        {
            perror("recv failed cil2:");
            exit(1);
        }  
    }
    cout<<"len"<<len<<endl;
    vector<uchar>buff(buf,buf+len);
    cv::Mat image=cv::imdecode(buff,CV_LOAD_IMAGE_COLOR);
    //printf("%d\n",image.total());
    return image;
}


