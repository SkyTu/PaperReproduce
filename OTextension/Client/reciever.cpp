/*
 * @Author: your name
 * @Date: 2021-10-20 09:52:47
 * @LastEditTime: 2021-11-10 10:31:21
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
#include "cryptopp/shake.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/filters.h"
#include "cryptopp/files.h"
#include "cryptopp/hex.h"
#define BUFFSIZE 1024
#define SERVER_IP  "10.176.34.170"    // 指定服务端的IP，记得修改为你的服务端所在的ip
#define SERVER_PORT 16555            // 指定服务端的port
using namespace CryptoPP;
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
    int64 m0 = 1231984, m1 = 234235, c, tempval;
    std::vector<int64> PK;
    PrimeGroup p;//循环群
    srand(time(0));
    int64 r0 = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶);
    int64 r1 = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶);
    std::string hashval0;//用sha128进行加密
    std::string hashval1;
    std::string tempstr;
    std::string msg;
    std::string digest;
    HexEncoder encoder0(new StringSink(hashval0));
    HexEncoder encoder1(new StringSink(hashval1));
    //printf("Oblivious Transfer Begins! Please input the message you want to transport\n");
    //std::cin>>m0;
    //std::cin>>m1;
    while(true){
        //开始传输数据
        recv(sockfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: c = %s\n", buff);
        c = atol(buff);
        //清空缓冲区
        bzero(buff, sizeof(buff));
        recv(sockfd, buff, BUFFSIZE - 1, 0);
        printf("Recv: PK0 = %s\n", buff);

        PK.push_back(atol(buff));
        PK.push_back(p.divide(c,PK[0]));
        std::cout<<"PK[0] = "<<PK[0]<<";PK[1] = "<<PK[1]<<std::endl;

        bzero(buff, sizeof(buff));
        strcpy(buff, std::to_string(p.cyc_group[r0]).c_str());
        send(sockfd, buff, strlen(buff), 0);       
        printf("Send: value = %s\n", buff);
        
        bzero(buff, sizeof(buff));
        strcpy(buff, std::to_string(p.cyc_group[r1]).c_str());
        send(sockfd, buff, strlen(buff), 0);   
        printf("Send: value = %s\n", buff);

        msg = std::to_string(m0^(p.pow(PK[0],r0)));
        SHAKE128 hash;
        hash.Update((const byte*)msg.data(), msg.size());
        digest.resize(hash.DigestSize());
        hash.Final((byte*)&hashval0[0]);
        StringSource(digest, true, new Redirector(encoder0));
        //获得hashval，异或传递消息
        tempstr = "0x";
        tempstr += hashval0.substr(hashval0.size()-17,16); 
        sscanf(tempstr.c_str() , "%lx", &tempval);
        tempval ^= m0;
        hashval0 = hashval0.substr(0,hashval0.size()-16) + std::to_string(tempval);
        bzero(buff, sizeof(buff));
        strcpy(buff, hashval0.c_str());
        send(sockfd, buff, strlen(buff), 0);   
        printf("Send: hashval = %s\n", buff);
        
        hash.Update((const byte*)msg.data(), msg.size());
        digest.resize(hash.DigestSize());
        hash.Final((byte*)&hashval1[0]);
        StringSource(digest, true, new Redirector(encoder1));
        //获得hashval，异或传递消息
        tempstr = "0x";
        tempstr += hashval1.substr(hashval1.size()-17,16); 
        sscanf(tempstr.c_str() , "%lx", &tempval);
        tempval ^= m1;
        hashval1 = hashval1.substr(0,hashval1.size()-16) + std::to_string(tempval);
        bzero(buff, sizeof(buff));
        strcpy(buff, hashval1.c_str());
        send(sockfd, buff, strlen(buff), 0);   
        printf("Send: hashval = %s\n", buff);

    }
    close(sockfd);
    return 0;
}