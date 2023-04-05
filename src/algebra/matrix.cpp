#include <vector>
#include <iostream>
#include <cmath>
#include "../../include/algebra/matrix.hpp"
#include "../../include/algebra/vector.hpp"


namespace algebra{
    namespace matrix{

        void print(std::vector<std::vector<double>> &A){
            for(std::vector<double> &V: A){
                for(double &x: V){
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
        }


        std::vector<std::vector<double>> identity(int n, int m){
            std::vector<std::vector<double>> A (n, std::vector<double> (m, 0));
            for(int i {0}; i < A.size(); ++i){
                for(int j {0}; j < A[0].size(); ++j){
                    if(i == j){
                        A[i][j] = 1;
                    }
                }
            }
            return A;
        }


        std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> &A){
            std::vector<std::vector<double>> B (A[0].size(), std::vector<double> (A.size(), 0));
            for(int i {0}; i < A.size(); ++i){
                for(int j {0}; j < A[0].size(); ++j){
                    B[j][i] = A[i][j];
                }
            }
            return B;
        }


        std::vector<std::vector<double>> addition(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B){
            // Assumes input matrices have equal dimensions
            for(int i {0}; i < A.size(); ++i){
                for(int j {0}; j < A[0].size(); ++j){
                    A[i][j] += B[i][j];
                }
            }
            return A;
        }


        std::vector<std::vector<double>> subtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B){
            // Assumes input matrices have equal dimensions
            for(int i {0}; i < A.size(); ++i){
                for(int j {0}; j < A[0].size(); ++j){
                    A[i][j] -= B[i][j];
                }
            }
            return A;
        }


        std::vector<std::vector<double>> scalar(std::vector<std::vector<double>> A, double x){
            for(int i {0}; i < A.size(); ++i){
                for(int j {0}; j < A[0].size(); ++j){
                    A[i][j] *= x;
                }
            }
            return A;
        }


        std::vector<std::vector<double>> multiplication(std::vector<std::vector<double>> A, std::vector<std::vector<double>> &B){
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


        std::vector<std::vector<double>> power(std::vector<std::vector<double>> A, int x){
            if(x == 0){
                return identity(A.size(), A.size());
            }else{
                std::vector<std::vector<double>> B {A};
                for(int i {0}; i < x - 1; ++i){
                    B = multiplication(B, A);
                }
                return B;
            }
        }

    }
}
