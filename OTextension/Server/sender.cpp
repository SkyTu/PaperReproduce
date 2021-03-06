/*
 * @Author: your name
 * @Date: 2021-10-20 12:49:11
 * @LastEditTime: 2021-11-10 10:17:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/reciever.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <string>
#include <vector>
#include "../PrimeGroup.hpp"
#include "cryptopp/shake.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/filters.h"
#include "cryptopp/files.h"
#include "cryptopp/hex.h"
#define addr "10.176.34.170" 
#define MAXLINK 1024
#define BUFFSIZE 1024
#define DEFAULT_PORT 16555


int sockfd, connfd;    // 定义服务端套接字和客户端套接字

void stopServerRunning(int p)
{
    close(sockfd);
    printf("Close Server\n");
    exit(0);
}
int main()
{
    struct sockaddr_in servaddr;    // 用于存放ip和端口的结构
    char buff[BUFFSIZE];    // 用于收发数据
    // 对应伪代码中的sockfd = socket();
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        printf("Create socket error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    // END
    // 对应伪代码中的bind(sockfd, ip::port和一些配置);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(DEFAULT_PORT);
    if (-1 == bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)))
    {
        printf("Bind error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    // END
    // 对应伪代码中的listen(sockfd);    
    if (-1 == listen(sockfd, MAXLINK))
    {
        printf("Listen error(%d): %s\n", errno, strerror(errno));
        return -1;
    }
    // END
    printf("Listening...\n");
    while (true)
    {
        signal(SIGINT, stopServerRunning);    // 这句用于在输入Ctrl+C的时候关闭服务器
        // 对应伪代码中的connfd = accept(sockfd);
        connfd = accept(sockfd, NULL, NULL);
        if (-1 == connfd)
        {
            printf("Accept error(%d): %s\n", errno, strerror(errno));
            return -1;
        }

        //变量声明
        PrimeGroup p;
        int64 c;
        //生成随机数C
        p.initC();
        int64 gr0 = 0;
        int64 gr1 = 0;
        std::string hashval0;
        std::string hashval1;
        std::vector<int64> PK;
            
        srand(time(0));
        int k = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶)
        PK.push_back(p.cyc_group[k+1]);//获得PK[0]，即为g的k次方
        PK.push_back(p.divide(p.c,PK[0]));//获得PK[1]
        c = p.c;
        bzero(buff, sizeof(buff));
        strcpy(buff, std::to_string(c).c_str());
        send(connfd, buff, strlen(buff), 0);
        printf("Send: c = %s\n", buff);

        bzero(buff, sizeof(buff));
        strcpy(buff, std::to_string(PK[0]).c_str());
        send(connfd, buff, strlen(buff), 0);
        printf("Send: PK[0] = %s\n", buff);
        
        bzero(buff, sizeof(buff));
        recv(connfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: %s\n", buff);
    	gr0 = atol(buff);

        bzero(buff, sizeof(buff));
        recv(connfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: %s\n", buff);
        gr1 = atol(buff);
                       
        bzero(buff, sizeof(buff));
        recv(connfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: %s\n", buff);
        hashval0 = buff;
        
        bzero(buff, sizeof(buff));
        recv(connfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: %s\n", buff);
        hashval1 = buff;

        
    }
    close(connfd);
    // END
    return 0;
}          

/*
TODO List
1. 代码太冗余
2. 传输数据的hex encoding而后进行xor
*/