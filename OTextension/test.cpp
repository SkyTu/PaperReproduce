/*
 * @Author: your name
 * @Date: 2021-11-05 23:58:18
 * @LastEditTime: 2021-11-10 10:07:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/test.cpp
 */
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <typeinfo>
#include "PrimeGroup.hpp"
#include "../../cppSourceCode/cryptopp/shake.h"
#include "../../cppSourceCode/cryptopp/cryptlib.h"
#include "../../cppSourceCode/cryptopp/filters.h"
#include "cryptopp/files.h"
#include "cryptopp/hex.h"
int main(){
    std::string s = "12483849012852";
    char sendBuf[1024] = { 0 };
    char recvBuf[1024] = { 0 };
    PrimeGroup p;
    p.initC();
    std::cout<<"c = "<<p.c<<std::endl;
    srand(time(0));
    int k = rand()%p.cyc_group.size()+1;//生成随机数1<=k<=q(q为循环群的阶)
    std::vector<int64> PK;
    PK.push_back(p.cyc_group[k+1]);//获得PK[0]，即为g的k次方
    PK.push_back(p.divide(p.c,PK[0]));//获得PK[1]
    std::cout<<"PK[0] = "<<std::to_string(PK[0])<<std::endl;
    std::cout<<"PK[1] = "<<std::to_string(PK[1])<<std::endl;
    std::string c = std::to_string(p.c);
    std::cout<<"PK[1]*PK[0] = "<<p.multiply(PK[0],PK[1])<<std::endl;
    memset(sendBuf, 0, 1024);
    strcpy(sendBuf, c.c_str());
    srand(time(0));
    int64 r0 = (rand()%p.cyc_group.size())+1;//生成随机数1<=k<=q(q为循环群的阶);
    std::cout<<std::to_string(p.cyc_group[60]).c_str()<<std::endl;
    std::cout<<atol(std::to_string(p.cyc_group[60]).c_str())<<std::endl;
    
    char temp[1024] = "120920422342\0";
    PK[0] = atol(temp);
    std::cout<<PK[0]<<std::endl;

    using namespace CryptoPP;
    std::string msg = "124314514651";
    std::string digest;

    SHAKE128 hash;
    HexEncoder encoder(new StringSink(s));
    hash.Update((const byte*)msg.data(), msg.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*)&digest[0]);
    StringSource(digest, true, new Redirector(encoder));
    std::cout<<s<<std::endl;
    s[s.size()-1] = ((s[s.size()-1]-'0')^1)+'0';
    std::cout<<s<<std::endl;
    int tempval;
    sscanf("0x"+s[14], "%x", &tempval);
    std::cout<<tempval<<std::endl;
    return 0;
}