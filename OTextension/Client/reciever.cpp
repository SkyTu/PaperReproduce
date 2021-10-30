/*
 * @Author: your name
 * @Date: 2021-10-20 09:52:47
 * @LastEditTime: 2021-10-30 16:23:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/Client/reciever.cpp
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <vector>
#include "../PrimeGroup.hpp"
#define BUFFSIZE 2048
#define SERVER_IP  "10.176.34.170"    // 指定服务端的IP，记得修改为你的服务端所在的ip
#define SERVER_PORT 16555            // 指定服务端的port

int main()
{
    struct sockaddr_in servaddr;
    char buff[BUFFSIZE];
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sockfd)
    {
        printf("Create socket error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr);
    servaddr.sin_port = htons(SERVER_PORT);
    if (-1 == connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)))
    {
        printf("Connect error(%d): %s\n", errno, strerror(errno));
        return -1;
    }

    //变量声明
    int64 c;
    std::vector<int64> PK;
    PrimeGroup p;
    srand(time(0));
    int64 r0 = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶);
    int64 r1 = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶);

    while(true){
        recv(sockfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: c = %s\n", buff);
        c = (int64) buff;
        //清空缓冲区
        bzero(buff, sizeof(buff));
        recv(sockfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: PK0 = %s\n", buff);

        bzero(buff, sizeof(buff));
        recv(sockfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: %s\n", buff);

        PK[0] = (int64) buff;
        PK[1] = p.divide(c,PK[0]);

        bzero(buff, sizeof(buff));
        strcpy(buff, std::to_string(p.pow(p.generator, r0)).c_str());
        send(sockfd, buff, BUFFSIZE - 1, 0);       
        printf("Send: value = %s\n", buff);
    }
    close(sockfd);
    return 0;
}