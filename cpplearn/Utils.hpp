/*
 * @Author: your name
 * @Date: 2021-10-13 15:30:28
 * @LastEditTime: 2021-10-14 11:26:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/cpplearn/Utils.hpp
 */
#include<vector>
#include<Eigen/Dense>
#include<iostream>

typedef Eigen::Matrix<__uint64_t, Eigen::Dynamic, Eigen::Dynamic> MatrixDI;//dynamic matrix with integer elements(128 bits) 
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MatrixDD;//dynamic matrix with double elements 

class Utils{
    /**
     * @description: 
     * plaintext: 明文
     * cols: 矩阵列数 
     * rows: 矩阵行数
     * bits: （小数位）最多有多少位的比特数
     */    
    private:
        MatrixDD plaintext;
        int cols;
        int rows;
        int bits = 32;
    public:
        vector<MatrixDI>share;
        int participants = 2;//Default 2PC
        void ptx_additive_secret_share(int participantes);
        MatrixDI recover(const MatrixDI &Mat_a, const MatrixDI &Mat_b);

        //getter & setter
        void get_plaintext();
        void set_plaintext(const MatrixDD &inp);
        void set_participants(int participants);
        void get_triplets();
};