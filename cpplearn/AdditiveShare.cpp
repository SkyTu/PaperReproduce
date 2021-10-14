/*
 * @Author: your name
 * @Date: 2021-10-14 13:51:22
 * @LastEditTime: 2021-10-14 19:56:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/cpplearn/AdditiveShare.cpp
 */
#include "AdditiveShare.hpp"

void AdditiveShare::set_rows_cols(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
}

std::vector<MatrixDI> AdditiveShare::get_share(MatrixDI& mat_temp){
    MatrixDI rand_mat_temp = MatrixDI::Random(this->rows, this->cols); 
    mat_temp -= rand_mat_temp;
    return {mat_temp, rand_mat_temp};
}

MatrixDI AdditiveShare::add(const MatrixDI& mat_a, const MatrixDI& mat_b){
    return mat_a + mat_b;
}


std::vector<MatrixDI> AdditiveShare::get_E_F(int idx, const MatrixDI& share_matrix_U, const MatrixDI& share_matrix_V, const MatrixDI& share_matrix_A, const MatrixDI share_matrix_B){
    //计算Ei和Fi
    return {share_matrix_A - share_matrix_U,  share_matrix_B - share_matrix_V};
}

MatrixDI AdditiveShare::multiply(int idx, std::vector<MatrixDI>share_matrix_E_F_0, std::vector<MatrixDI>share_matrix_E_F_1, std::vector<std::vector<MatrixDI>> triplets){
    MatrixDI E = share_matrix_E_F_0[0] + share_matrix_E_F_1[0];
    MatrixDI F = share_matrix_E_F_0[1] + share_matrix_E_F_1[1];
    return idx*(E.array()*F.array())+E.array()*triplets[1][idx].array()+F.array()*triplets[0][idx].array()+triplets[2][idx].array();
}

std::vector<std::vector<MatrixDI>> AdditiveShare::get_triplets(){
    MatrixDI U = MatrixDI::Random(this->rows, this->cols);
    MatrixDI V = MatrixDI::Random(this->rows, this->cols);
    MatrixDI Z = U.array()*V.array();
    std::vector<std::vector<MatrixDI>> res;

    res.push_back(this->get_share(U));
    res.push_back(this->get_share(V));
    res.push_back(this->get_share(Z));
    return res;
}