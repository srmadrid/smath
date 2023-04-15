#include <vector>
#include <iostream>
#include <cmath>
#include "../../include/algebra/vector.h"


namespace vector{

void print(std::vector<double> &V){
    for(double &i: V){
        std::cout << i << " ";
    }std::cout << std::endl;
}


std::vector<double> addition(std::vector<double> V, std::vector<double> &W){
    // Assumes input vectors have equal dimensions
    for(int i {0}; i < V.size(); ++i){
        V[i] += W[i];
    }
    return V;
}


std::vector<double> subtraction(std::vector<double> V, std::vector<double> &W){
    // Assumes input vectors have equal dimensions
    for(int i {0}; i < V.size(); ++i){
        V[i] -= W[i];
    }
    return V;
}


double modulus(std::vector<double> &V){
    double result {0};
    for(double &i: V){
        result += std::pow(i, 2);
    }
    return std::sqrt(result);
}


std::vector<double> scalar(std::vector<double> V, double x){
    for(int i {0}; i < V.size(); ++i){
        V[i] *= x;
    }
    return V;
}


double dot(std::vector<double> &V, std::vector<double> &W){
    // Assumes input vectors have equal lengths
    double result {};
    for(int i {0}; i < V.size(); ++i){
        result += V[i]*W[i];
    }
    return result;
}


std::vector<double> projection(std::vector<double> V, std::vector<double> W){
    // To be developed
    return std::vector<double> {1, 2, 3};
}

}
