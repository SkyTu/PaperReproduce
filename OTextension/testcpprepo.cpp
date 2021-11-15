/*
 * @Author: your name
 * @Date: 2021-11-09 13:37:05
 * @LastEditTime: 2021-11-09 14:58:01
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /txy/PaperReproduce/OTextension/testcpprepo.cpp
 */
#include "cryptopp/cryptlib.h"
#include "cryptopp/shake.h"
#include <iostream>

int main ()
{
    using namespace CryptoPP;

    SHAKE128 hash;
	
    std::cout << "Name: " << hash.AlgorithmName() << std::endl;
    std::cout << "Digest size: " << hash.DigestSize() << std::endl;
    std::cout << "Block size: " << hash.BlockSize() << std::endl;

    return 0; 
}