/*
 * @Author: your name
 * @Date: 2021-10-14 13:51:29
 * @LastEditTime: 2021-10-14 19:36:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /txy/PaperReproduce/cpplearn/AdditiveShare.hpp
 */
#include<vector>
#include<Eigen/Dense>
typedef Eigen::Matrix<__uint64_t, Eigen::Dynamic, Eigen::Dynamic> MatrixDI;//dynamic matrix with integer elements(64 bits) 

class AdditiveShare{
    //recover和add一样
    private:
        int rows = 5;
        int cols = 5;
    
    public:
        
        void set_rows_cols(int rows, int cols);

        std::vector<MatrixDI> get_share(MatrixDI& mat_temp);

        MatrixDI add(const MatrixDI& mat_a, const MatrixDI& mat_b);

        std::vector<MatrixDI> get_E_F(int idx, const MatrixDI& share_matrix_U, const MatrixDI& share_matrix_V, const MatrixDI& share_matrix_A, const MatrixDI share_matrix_B);

        MatrixDI multiply(int idx, std::vector<MatrixDI>share_matrix_E_F_0, std::vector<MatrixDI>share_matrix_E_F_1, std::vector<std::vector<MatrixDI>> triplets);

        std::vector<std::vector<MatrixDI>> get_triplets();
};