/*
 * @Author: your name
 * @Date: 2021-10-20 12:49:11
 * @LastEditTime: 2021-10-21 14:31:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/reciever.cpp
 */
#include<iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include "../PrimeGroup.hpp"
#define addr "10.176.34.170" 
int main()
{
    int sockfd = -1;
 
    sockfd = socket( AF_INET, SOCK_STREAM, 0 );
    if ( -1 == sockfd ) {
        perror( "sock created" );
        exit( -1 );
    }
 
    struct sockaddr_in server;
    memset(&server,0,sizeof(struct sockaddr_in));
    server.sin_addr.s_addr = inet_addr(addr);
    server.sin_port = htons(7777);
    server.sin_family = AF_INET;
 
    int res = -1;
    res = connect( sockfd, (struct sockaddr*)&server, sizeof( server ) );
    if( -1 == res ){
        perror( "sock connect" );
        exit( -1 );
    }
 
    char sendBuf[1024] = { 0 };
    char recvBuf[1024] = { 0 };
    while(true) {
        printf("Oblivious Transfer Begins! Please input the message you want to transport\n");
        std::string m0, m1;
        std::cin>>m0;
        std::cin>>m1;
        
        PrimeGroup p;
        p.initC();
        srand(time(0));
        int k = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶)
        std::vector<int64> PK;
        PK.push_back(p.cyc_group[k+1]);//获得PK[0]，即为g的k次方
        PK.push_back(p.divide(p.c,PK[0]));//获得PK[1]
        
        std::string c = std::to_string(p.c);
        memset(sendBuf, 0, 1024);
        strcpy(sendBuf, c.c_str());
        
        send(sockfd, sendBuf, sizeof( sendBuf ),0);//传递随机数C
        std::cout<<sendBuf<<std::endl;
        srand(time(0));
        std::string PKrandom = std::to_string(PK[rand()%2]);//随机选取一个进行传输
        memset(sendBuf, 0, 1024);
        strcpy(sendBuf, PKrandom.c_str());
        std::cout<<sendBuf<<std::endl;
        
        send( sockfd, sendBuf, sizeof( sendBuf ),0);
        recv( sockfd, recvBuf, sizeof( recvBuf ),0);
        fputs( recvBuf, stdout );
        memset( sendBuf, 0, sizeof( sendBuf ) );
        memset( recvBuf, 0, sizeof( recvBuf ) );
    }
 
    close( sockfd );
 
    return 0;
}

    