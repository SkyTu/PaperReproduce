本项目实现了SecureML中additive_share的加法和乘法

1.域的大小是Z2^64，因此有定义：typedef Eigen::Matrix<__uint64_t, Eigen::Dynamic, Eigen::Dynamic> MatrixDI;//dynamic matrix with integer elements 
