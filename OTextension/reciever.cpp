/*
 * @Author: your name
 * @Date: 2021-10-20 12:49:11
 * @LastEditTime: 2021-10-20 13:03:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/reciever.cpp
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include "PrimeGroup.hpp"

#define PORT  7000
#define BUFFER_SIZE 1024
#define IP "10.176.34.170"
 
int main()
{
    ///定义sockfd
    int sock_cli = socket(AF_INET,SOCK_STREAM, 0);
 
    ///定义sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);  //服务器端口
    servaddr.sin_addr.s_addr = inet_addr(IP);  //服务器ip，inet_addr用于IPv4的IP转换（十进制转换为二进制）
    //127.0.0.1是本地预留地址
    //连接服务器，成功返回0，错误返回-1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }
 
    char sendbuf[BUFFER_SIZE];
    char recvbuf[BUFFER_SIZE];
 
    PrimeGroup p;
    p.initC();
    srand(time[0]);
    int k = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶)
    vector<int64> PK;
    PK.push_back(p.cyc_group[k+1]);//获得PK[0]，即为g的k次方
    PK.push_back(p.divide(p.c,PK[0]));//获得PK[1]
    srand(time[0]);
    string PKrandom = toString(PK[rand()%2]);//随机选取一个进行传输
    sendbuf = PKrandom;
    send(sock_cli, sendbuf, strlen(PKrandom), 0);
    recv(sock_cli, recvbuf, sizeof(recvbuf),0); ///接收
    close(sock_cli);
    return 0;
}