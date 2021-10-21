/*
 * @Author: your name
 * @Date: 2021-10-20 09:52:47
 * @LastEditTime: 2021-10-21 14:30:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/sender.cpp
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#define addr "10.176.34.170"
#include "../PrimeGroup.hpp" 
using namespace std;
#define MYPORT 3420
#define BACKLOG 10
 
int main()
{
    int sockfd = -1;
    int bindres = -1;
    int listenres = -1;
 
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sockfd){
        perror("sock created");
        exit(-1);
    }
 
    struct sockaddr_in server;
    memset(&server,0,sizeof(struct sockaddr_in));
    server.sin_addr.s_addr = inet_addr(addr);
    server.sin_port = htons(7777);
    server.sin_family = AF_INET;
 
    bindres = bind(sockfd,(struct sockaddr*)&server,sizeof(server));
 
    if(-1 == bindres){
        perror("sock bind");
        exit(-1);
    }
 
    listenres = listen(sockfd,10);
    if(-1 == listenres){
        perror("sock listen");
        exit(-1);
    }
 
    struct sockaddr_in peerServer;
    int acceptfd = -1;
    socklen_t len = sizeof(peerServer);
    acceptfd = accept(sockfd,(struct sockaddr *)&peerServer,&len);
    if(-1 == acceptfd){
        perror("sock accept");
        exit(-1);
    }
 
    char sendBuf[1024];
    char recvBuf[1024];
    while(1){
        memset(recvBuf,0,sizeof(recvBuf));
        int recvBytes = recv(acceptfd,recvBuf,sizeof(recvBuf),0);
        cout<<recvBytes;
        fputs(recvBuf,stdout);
        send(acceptfd,recvBuf,recvBytes,0);
    }
 
    close(acceptfd);
    close(sockfd);
 
    return 0;
}