/*
 * @Author: your name
 * @Date: 2021-10-20 09:59:52
 * @LastEditTime: 2021-11-06 00:22:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/PrimeGroup.cpp
 */
#include "PrimeGroup.hpp"

int64 PrimeGroup::get_exp(int64 a){
    if(a == 1)return 0;
    int64 temp_exp = 0;
    while(a>1){
        a = a>>1;
        temp_exp++;
    }
    return temp_exp;
}
int64 PrimeGroup::pow(int64 base, int64 exp){
    if(base == 1)return 1;
    if(base == 2)return cyc_group[exp%cyc_group.size()];
    int64 temp_exp = get_exp(base)*exp;
    return cyc_group[temp_exp%cyc_group.size()];
}

int64 PrimeGroup::inverse(int64 a){
    int64 temp_exp = get_exp(a);
    std::cout<<"temp_exp = "<<temp_exp<<std::endl;
    temp_exp = 61-temp_exp;
    return 1<<temp_exp;
}

int64 PrimeGroup::multiply(int64 a, int64 b){
    return cyc_group[(get_exp(a)+get_exp(b))%61];
}

int64 PrimeGroup::divide(int64 a, int64 b){
    return multiply(a,inverse(b));
}

void PrimeGroup::initC(){
    //获得Zq域中的任意元素
    srand(time(0));
    c = cyc_group[rand()%cyc_group.size()];
    return;
}

