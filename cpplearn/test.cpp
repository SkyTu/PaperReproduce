/*
 * @Author: your name
 * @Date: 2021-10-13 15:17:45
 * @LastEditTime: 2021-10-14 20:00:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/cpplearn/test.cpp
 */
# include<iostream>
# include "Utils.hpp"
# include"AdditiveShare.hpp"
int main(){
    Utils A;
    Utils B;
    AdditiveShare as;
    MatrixDD ptxA = MatrixDD::Random(5,5).array().abs();//double尾数最多32bit
    A.set_plaintext(ptxA);
    A.ptx_additive_secret_share();
    MatrixDD ptxB = MatrixDD::Random(5,5).array().abs();//double尾数最多32bit
    B.set_plaintext(ptxB);
    B.ptx_additive_secret_share();
    // std::cout<<"明文*2^32结果为："<<ptx*(1l<<32)<<std::endl;
    // std::cout<<u.recover(u.share[0],u.share[1]).cast<double>()/(1l<<32)<<std::endl;
    std::vector<std::vector<MatrixDI>>triplets_share_vec  = as.get_triplets();//triplets_share_vec saves all shares of <U,V,Z>
    
    std::vector<MatrixDI>E_F_vec_0 = as.get_E_F(0, triplets_share_vec[0][0], triplets_share_vec[1][0],A.share[0],B.share[0]);//Get the recover of E and F
    std::vector<MatrixDI>E_F_vec_1 = as.get_E_F(1, triplets_share_vec[0][1], triplets_share_vec[1][1],A.share[1],B.share[1]);//Get the recover of E and F
    MatrixDI C_share_0 = as.multiply(0,E_F_vec_0,E_F_vec_1,triplets_share_vec);
    MatrixDI C_share_1 = as.multiply(1,E_F_vec_0,E_F_vec_1,triplets_share_vec);
    MatrixDD C = ((C_share_0 + C_share_1)/(1l<<32)).cast<double>();
    C /= 1l<<32;
    std::cout<<"The result of Additive sharing is:"<<std::endl<<C<<std::endl;
    std::cout<<"The ground truth is:"<<std::endl<<ptxA.array()*ptxB.array()<<std::endl;
}
