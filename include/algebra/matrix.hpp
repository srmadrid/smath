#ifndef MATRIX_HPP
#define MATRIX_HPP


#include <vector>
#include <iostream>
#include <cmath>


namespace algebra{
    namespace matrix{

        void print(std::vector<std::vector<double>> &A);

        std::vector<std::vector<double>> identity(int n, int m);

        std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> &A);

        std::vector<std::vector<double>> addition(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B);

        std::vector<std::vector<double>> subtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B);

        std::vector<std::vector<double>> scalar(std::vector<std::vector<double>> A, double x);

        std::vector<std::vector<double>> multiplication(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B);

        std::vector<std::vector<double>> power(std::vector<std::vector<double>> A, int x); 

    }
}


#endif
