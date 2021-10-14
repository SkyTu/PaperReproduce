/*
 * @Author: your name
 * @Date: 2021-10-13 15:17:45
 * @LastEditTime: 2021-10-14 10:56:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/cpplearn/test.cpp
 */
# include<iostream>
# include "Utils.hpp"

int main(){
    MatrixDD ptx = MatrixDD::Random(5,5).array().abs();//double尾数最多32bit
    Utils u;
    u.set_plaintext(ptx);
    u.get_plaintext();
    u.additive_secret_share(2);
    std::cout<<"明文*2^32结果为："<<ptx*(1l<<32)<<std::endl;
    std::cout<<u.recover(u.share[0],u.share[1]).cast<double>()/(1l<<32)<<std::endl;
}