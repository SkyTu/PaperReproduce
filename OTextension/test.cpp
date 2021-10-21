/*
 * @Author: your name
 * @Date: 2021-10-21 12:37:38
 * @LastEditTime: 2021-10-21 14:12:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/test.cpp
 */
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include "PrimeGroup.hpp"


int main(){
    std::string s = "12483849012852";
    char sendBuf[1024] = { 0 };
    char recvBuf[1024] = { 0 };
    PrimeGroup p;
    p.initC();
    std::cout<<p.c;
    std::cout<<p.c;
    srand(time(0));
    int k = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶)
    std::vector<int64> PK;
    PK.push_back(p.cyc_group[k+1]);//获得PK[0]，即为g的k次方
    PK.push_back(p.divide(p.c,PK[0]));//获得PK[1]
    
    std::string c = std::to_string(p.c);
    memset(sendBuf, 0, 1024);
    strcpy(sendBuf, c.c_str());
    return 0;
}