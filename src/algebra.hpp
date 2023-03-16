#include <vector>
#include <iostream>
#include <cmath>


void vector_print(std::vector<double> &V){
    for(double i: V){
        std::cout << i << " ";
    }std::cout << std::endl;
}


std::vector<double> vector_addition(std::vector<double> V, std::vector<double> &W){
    // Assumes input vectors have equal dimensions
    for(int i {0}; i < V.size(); ++i){
        V[i] += W[i];
    }
    return V;
}


std::vector<double> vector_subtraction(std::vector<double> V, std::vector<double> &W){
    // Assumes input vectors have equal dimensions
    for(int i {0}; i < V.size(); ++i){
        V[i] -= W[i];
    }
    return V;
}


double vector_modulus(std::vector<double> &V){
    double result {0};
    for(double i: V){
        result += std::pow(i, 2);
    }
    return std::sqrt(result);
}


std::vector<double> vector_scalar(std::vector<double> V, double x){
    for(int i {0}; i < V.size(); ++i){
        V[i] *= x;
    }
    return V;
}


double vector_dot(std::vector<double> &V, std::vector<double> &W){
    // Assumes input vectors have equal lengths
    double result {};
    for(int i {0}; i < V.size(); ++i){
        result += V[i]*W[i];
    }
    return result;
}


std::vector<double> vector_cross(std::vector<double> &V, std::vector<double> &W){
    // Assumes input vectors have 3 components
    std::vector<double> X {0, 0, 0};
    X[0] += V[1]*W[2] - V[2]*W[1];
    X[1] += V[2]*W[0] - V[0]*W[2];
    X[2] += V[0]*W[1] - V[1]*W[0];
    return X;
}


std::vector<double> vector_projection(std::vector<double> V, std::vector<double> W){
    // To be developed
    return std::vector<double> {1, 2, 3};
}


void matrix_print(std::vector<std::vector<double>> &A){
    for(std::vector<double> &V: A){
        vector_print(V);
    }
}


std::vector<std::vector<double>> matrix_transpose(std::vector<std::vector<double>> &A){
    std::vector<std::vector<double>> B (A[0].size(), std::vector<double> (A.size(), 0));
    for(int i {0}; i < A.size(); ++i){
        for(int j {0}; j < A[0].size(); ++j){
            B[j][i] = A[i][j];
        }
    }
    return B;
}


std::vector<std::vector<double>> matrix_addition(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B){
    // Assumes input matrices have equal dimensions
    for(int i {0}; i < A.size(); ++i){
        for(int j {0}; j < A[0].size(); ++j){
            A[i][j] += B[i][j];
        }
    }
    return A;
}


std::vector<std::vector<double>> matrix_subtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B){
    // Assumes input matrices have equal dimensions
    for(int i {0}; i < A.size(); ++i){
        for(int j {0}; j < A[0].size(); ++j){
            A[i][j] -= B[i][j];
        }
    }
    return A;
}


std::vector<std::vector<double>> matrix_multiplication(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B){
    // Assumes input matrices have correct dimensions
    std::vector<std::vector<double>> C (A.size(), std::vector<double> (B[0].size(), 0));
    for(int i {0}; i < A.size(); ++i){
        for(int j {0}; j < B[0].size(); ++j){
            for(int n {0}; n < A[0].size(); ++n){
                C[i][j] += A[i][n]*B[n][j];
            }
        }
    }
    return C;
}
