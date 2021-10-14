/*
 * @Author: your name
 * @Date: 2021-10-10 20:36:59
 * @LastEditTime: 2021-10-14 12:12:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/cpplearn/TestForSecureML.cpp
 */
#include"Utils.hpp"

void Utils::ptx_additive_secret_share(){
    //participants:参与方
    MatrixDI final = ((this->plaintext)*(1l<<this->bits)).cast<__uint64_t>();
    for(int i = 0 ; i < this->participants-1; i++){
        MatrixDI rand_mat_temp = MatrixDI::Random(this->rows, this->cols); 
        final -= rand_mat_temp;
        share.push_back(rand_mat_temp);
    }
    share.push_back(final);
}

MatrixDI Utils::recover(MatrixDI &Mat_a, MatrixDI &Mat_b){
    return Mat_a+Mat_b;
}

MatrixDI Utils::get_triplelets(){
    MatrixDI U = MatrixDI::Random(this->rows, this->cols); 
    MatrixDI V = MatrixDI::Random(this->rows, this->cols);
    MatrixDI Z = 
}

void Utils::get_plaintext(){
    std::cout<<this->plaintext<<std::endl;
}

void Utils::set_plaintext(MatrixDD &inp){
    //inp:the input matrix(plaintext)
    this->rows = inp.rows();
    this->cols = inp.cols();
    this->plaintext = inp;
}
