#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <vector>
#include <iostream>
#include <cmath>


namespace algebra{
    namespace vector{

        void print(std::vector<double> &V);

        std::vector<double> addition(std::vector<double> V, std::vector<double> &W);

        std::vector<double> subtraction(std::vector<double> V, std::vector<double> &W);

        double modulus(std::vector<double> &V);

        std::vector<double> scalar(std::vector<double> V, double x);

        double dot(std::vector<double> &V, std::vector<double> &W);

        std::vector<double> cross(std::vector<double> &V, std::vector<double> &W);

        std::vector<double> projection(std::vector<double> V, std::vector<double> W);

    }
}


#endif
