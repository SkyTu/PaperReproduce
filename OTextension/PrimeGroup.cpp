/*
 * @Author: your name
 * @Date: 2021-10-20 09:59:52
 * @LastEditTime: 2021-10-20 10:54:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/OTextension/PrimeGroup.cpp
 */
#include "PrimeGroup.hpp"

int64 PrimeGroup::get_exp(int64 a){
    if(a == 1)return 0;
    int temp_exp = 0;
    while(a>0){
        a = a>>1;
        temp_exp++;
    }
    return temp_exp;
}
int64 PrimeGroup::pow(int64 base, int64 exp){
    if(base == 1)return 1;
    int64 temp_exp = get_exp(base)*exp;
    return cyc_group[temp_exp%cyc_group.size()];
}

int64 PrimeGroup::inverse(int64 a){
    int64 temp_exp = get_exp(a);
    temp_exp = 61-temp_exp;
    return 1<<temp_exp;
}

int64 PrimeGroup::multiply(int64 a, int64 b){
    return (a*b)%prime64;
}

int64 PrimeGroup::divide(int64 a, int64 b){
    return multiply(a,inverse(b));
}

void PrimeGroup::initC(){
    //获得Zq域中的任意元素
    srand(time(0));
    c = cyc_group[rand()%cyc_group.size()];
}

