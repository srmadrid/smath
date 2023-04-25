#include "../../include/linear-algebra/linear-algebra.h"
#include <gtest/gtest.h>


//------------------------------------------------------------------------------
// Vector2 tests
//------------------------------------------------------------------------------

// +=
TEST(Vector2, Addition_assig_1){
    Vector2 v(1, 3);
    v += Vector2(4, 2);
    EXPECT_EQ(Vector2(5, 5), v);
}

TEST(Vector2, Addition_assig_2){
    Vector2 v(6, 1);
    v += Vector2(2, -2);
    EXPECT_EQ(Vector2(8, -1), v);
}

// -=
TEST(Vector2, Subtraction_assig_1){
    Vector2 v(1, 3);
    v -= Vector2(4, 2);
    EXPECT_EQ(Vector2(-3, 1), v);
}

TEST(Vector2, Subtraction_assig_2){
    Vector2 v(6, 1);
    v -= Vector2(4, 2);
    EXPECT_EQ(Vector2(2, -1), v);
}

// *=
TEST(Vector2, Multiplication_assig_1){
    Vector2 v(2, 4);
    v *= 3;
    EXPECT_EQ(Vector2(6, 12), v);
}

TEST(Vector2, Multiplication_assig_2){
    Vector2 v(3, -1);
    v *= -2;
    EXPECT_EQ(Vector2(-6, 2), v);
}

// /=
TEST(Vector2, Division_assig_1){
    Vector2 v(1, 3);
    v /= 2;
    EXPECT_EQ(Vector2(0.5, 1.5), v);
}

TEST(Vector2, Division_assig_2){
    Vector2 v(3, 1);
    v /= 3;
    EXPECT_EQ(Vector2(1, 0.33333333333), v);
}

// this->modulus
TEST(Vector2, Self_modulus_1){
    Vector2 v(2, 4);
    EXPECT_EQ(4.47213595499958, v.modulus());
}

TEST(Vector2, Self_modulus_2){
    Vector2 v(-4, 3);
    EXPECT_EQ(5, v.modulus());
}

// this->normalize
TEST(Vector2, Self_normalize_1){
    Vector2 v(3, 5);
    v.normalize();
    EXPECT_EQ(Vector2(0.5144957554275265, 0.8574929257125441), v);
}

TEST(Vector2, Self_normalize_2){
    Vector2 v(4, -3);
    v.normalize();
    EXPECT_EQ(Vector2(0.8, -0.6), v);
}

// +
TEST(Vector2, Addition_1){
    Vector2 v(1, 3);
    Vector2 u(4, 2);
    Vector2 w = v + u;
    EXPECT_EQ(Vector2(5, 5), w);
}

TEST(Vector2, Addition_2){
    Vector2 v(6, 1);
    Vector2 u(2, -2);
    Vector2 w = v + u;
    EXPECT_EQ(Vector2(8, -1), w);
}

// -
TEST(Vector2, Subtraction_1){
    Vector2 v(1, 3);
    Vector2 u(4, 2);
    Vector2 w = v - u;
    EXPECT_EQ(Vector2(-3, 1), w);
}

TEST(Vector2, Subtraction_2){
    Vector2 v(6, 1);
    Vector2 u(4, 2);
    Vector2 w = v - u;
    EXPECT_EQ(Vector2(2, -1), w);
}

// *
TEST(Vector2, Multiplication_1){
    Vector2 v(2, 4);
    Vector2 u = v*3;
    EXPECT_EQ(Vector2(6, 12), u);
}

TEST(Vector2, Multiplication_2){
    Vector2 v(3, -1);
    Vector2 u = -2*v;
    EXPECT_EQ(Vector2(-6, 2), u);
}

// /
TEST(Vector2, Division_1){
    Vector2 v(1, 3);
    Vector2 u = v/2;
    EXPECT_EQ(Vector2(0.5, 1.5), u);
}

TEST(Vector2, Division_2){
    Vector2 v(3, 1);
    Vector2 u = v/3;
    EXPECT_EQ(Vector2(1, 0.33333333333), u);
}

// dot
TEST(Vector2, Dot_1){
    Vector2 v(2, 5);
    Vector2 u(4, 2);
    EXPECT_EQ(18, vector2::dot(v, u));
}

TEST(Vector2, Dot_2){
    Vector2 v(2, 5);
    Vector2 u(5, -2);
    EXPECT_EQ(0, vector2::dot(v, u));
}


//------------------------------------------------------------------------------
// Vector3 tests
//------------------------------------------------------------------------------

// +=
TEST(Vector3, Addition_assig_1){
    Vector3 v(1, 3, 5);
    v += Vector3(4, 2, 6);
    EXPECT_EQ(Vector3(5, 5, 11), v);
}

TEST(Vector3, Addition_assig_2){
    Vector3 v(6, 1, -2);
    v += Vector3(2, -2, -3);
    EXPECT_EQ(Vector3(8, -1, -5), v);
}

// -=
TEST(Vector3, Subtraction_assig_1){
    Vector3 v(1, 3, 5);
    v -= Vector3(4, 2, 6);
    EXPECT_EQ(Vector3(-3, 1, -1), v);
}

TEST(Vector3, Subtraction_assig_2){
    Vector3 v(6, 1, -2);
    v -= Vector3(4, 2, 6);
    EXPECT_EQ(Vector3(2, -1, -8), v);
}

// *=
TEST(Vector3, Multiplication_assig_1){
    Vector3 v(2, 4, -2);
    v *= 3;
    EXPECT_EQ(Vector3(6, 12, -6), v);
}

TEST(Vector3, Multiplication_assig_2){
    Vector3 v(3, -1, 1);
    v *= -2;
    EXPECT_EQ(Vector3(-6, 2, -2), v);
}

// /=
TEST(Vector3, Division_assig_1){
    Vector3 v(1, 3, 4);
    v /= 2;
    EXPECT_EQ(Vector3(0.5, 1.5, 2), v);
}

TEST(Vector3, Division_assig_2){
    Vector3 v(3, 1, 6);
    v /= 3;
    EXPECT_EQ(Vector3(1, 0.33333333333, 2), v);
}

// this->modulus
TEST(Vector3, Self_modulus_1){
    Vector3 v(2, 4, 1);
    EXPECT_EQ(4.58257569495584, v.modulus());
}

TEST(Vector3, Self_modulus_2){
    Vector3 v(0, -4, 3);
    EXPECT_EQ(5, v.modulus());
}

// this->normalize
TEST(Vector3, Self_normalize_1){
    Vector3 v(3, 5, 1);
    v.normalize();
    EXPECT_EQ(Vector3(0.50709255283711, 0.8451542547285166, 0.1690308509957033), v);
}

TEST(Vector3, Self_normalize_2){
    Vector3 v(0, 4, -3);
    v.normalize();
    EXPECT_EQ(Vector3(0, 0.8, -0.6), v);
}

// +
TEST(Vector3, Addition_1){
    Vector3 v(1, 3, 5);
    Vector3 u(4, 2, 6);
    Vector3 w = v + u;
    EXPECT_EQ(Vector3(5, 5, 11), w);
}

TEST(Vector3, Addition_2){
    Vector3 v(6, 1, -2);
    Vector3 u(2, -2, -3);
    Vector3 w = v + u;
    EXPECT_EQ(Vector3(8, -1, -5), w);
}

// -
TEST(Vector3, Subtraction_1){
    Vector3 v(1, 3, 5);
    Vector3 u(4, 2, 6);
    Vector3 w = v - u;
    EXPECT_EQ(Vector3(-3, 1, -1), w);
}

TEST(Vector3, Subtraction_2){
    Vector3 v(6, 1, -2);
    Vector3 u(4, 2, 6);
    Vector3 w = v - u;
    EXPECT_EQ(Vector3(2, -1, -8), w);
}

// *
TEST(Vector3, Multiplication_1){
    Vector3 v(2, 4, -2);
    Vector3 u = v*3;
    EXPECT_EQ(Vector3(6, 12, -6), u);
}

TEST(Vector3, Multiplication_2){
    Vector3 v(3, -1, 1);
    Vector3 u = -2*v;
    EXPECT_EQ(Vector3(-6, 2, -2), u);
}

// /
TEST(Vector3, Division_1){
    Vector3 v(1, 3, 4);
    Vector3 u = v/2;
    EXPECT_EQ(Vector3(0.5, 1.5, 2), u);
}

TEST(Vector3, Division_2){
    Vector3 v(3, 1, 6);
    Vector3 u = v/3;
    EXPECT_EQ(Vector3(1, 0.33333333333, 2), u);
}

// dot
TEST(Vector3, Dot_1){
    Vector3 v(2, 5, 1);
    Vector3 u(4, 2, 8);
    EXPECT_EQ(26, vector3::dot(v, u));
}

TEST(Vector3, Dot_2){
    Vector3 v(2, 5, 2);
    Vector3 u(3, -2, 2);
    EXPECT_EQ(0, vector3::dot(v, u));
}

// cross
TEST(Vector3, Cross_1){
    Vector3 v(3, 1, 5);
    Vector3 u(2, -8, 3);
    EXPECT_EQ(Vector3(43, 1, -26), vector3::cross(v, u));
}

TEST(Vector3, Cross_2){
    Vector3 v(6, 7, 1);
    Vector3 u(0, 0, 1);
    EXPECT_EQ(Vector3(7, -6, 0), vector3::cross(v, u));
}


//------------------------------------------------------------------------------
// Vector4 tests
//------------------------------------------------------------------------------

// +=
TEST(Vector4, Addition_assig_1){
    Vector4 v(1, 3, 5, 2);
    v += Vector4(4, 2, 6, 1);
    EXPECT_EQ(Vector4(5, 5, 11, 3), v);
}

TEST(Vector4, Addition_assig_2){
    Vector4 v(6, 1, -2, -5);
    v += Vector4(2, -2, -3, 5);
    EXPECT_EQ(Vector4(8, -1, -5, 0), v);
}

// -=
TEST(Vector4, Subtraction_assig_1){
    Vector4 v(1, 3, 5, 1);
    v -= Vector4(4, 2, 6, 1);
    EXPECT_EQ(Vector4(-3, 1, -1, 0), v);
}

TEST(Vector4, Subtraction_assig_2){
    Vector4 v(6, 1, -2, 0);
    v -= Vector4(4, 2, 6, -5);
    EXPECT_EQ(Vector4(2, -1, -8, 5), v);
}

// *=
TEST(Vector4, Multiplication_assig_1){
    Vector4 v(2, 4, -2, 0);
    v *= 3;
    EXPECT_EQ(Vector4(6, 12, -6, 0), v);
}

TEST(Vector4, Multiplication_assig_2){
    Vector4 v(3, -1, 1, 3);
    v *= -2;
    EXPECT_EQ(Vector4(-6, 2, -2, -6), v);
}

// /=
TEST(Vector4, Division_assig_1){
    Vector4 v(1, 3, 4, 7);
    v /= 2;
    EXPECT_EQ(Vector4(0.5, 1.5, 2, 3.5), v);
}

TEST(Vector4, Division_assig_2){
    Vector4 v(3, 1, 6, 2);
    v /= 3;
    EXPECT_EQ(Vector4(1, 0.33333333333, 2, 0.66666666666), v);
}

// this->modulus
TEST(Vector4, Self_modulus_1){
    Vector4 v(2, 4, 1, 0);
    EXPECT_EQ(4.58257569495584, v.modulus());
}

TEST(Vector4, Self_modulus_2){
    Vector4 v(0, -4, 3, 0);
    EXPECT_EQ(5, v.modulus());
}

// this->normalize
TEST(Vector4, Self_normalize_1){
    Vector4 v(3, 5, 1, 3);
    v.normalize();
    EXPECT_EQ(Vector4(0.452267016866645, 0.753778361444409, 0.150755672288882, 0.452267016866645), v);
}

TEST(Vector4, Self_normalize_2){
    Vector4 v(0, 4, -3, 0);
    v.normalize();
    EXPECT_EQ(Vector4(0, 0.8, -0.6, 0), v);
}

// +
TEST(Vector4, Addition_1){
    Vector4 v(1, 3, 5, 2);
    Vector4 u(4, 2, 6, 1);
    Vector4 w = v + u;
    EXPECT_EQ(Vector4(5, 5, 11, 3), w);
}

TEST(Vector4, Addition_2){
    Vector4 v(6, 1, -2, 5);
    Vector4 u(2, -2, -3, -5);
    Vector4 w = v + u;
    EXPECT_EQ(Vector4(8, -1, -5, 0), w);
}

// -
TEST(Vector4, Subtraction_1){
    Vector4 v(1, 3, 5, -2);
    Vector4 u(4, 2, 6, -2);
    Vector4 w = v - u;
    EXPECT_EQ(Vector4(-3, 1, -1, 0), w);
}

TEST(Vector4, Subtraction_2){
    Vector4 v(6, 1, -2, 3);
    Vector4 u(4, 2, 6, -5);
    Vector4 w = v - u;
    EXPECT_EQ(Vector4(2, -1, -8, 8), w);
}

// *
TEST(Vector4, Multiplication_1){
    Vector4 v(2, 4, -2, 0);
    Vector4 u = v*3;
    EXPECT_EQ(Vector4(6, 12, -6, 0), u);
}

TEST(Vector4, Multiplication_2){
    Vector4 v(3, -1, 1, 9);
    Vector4 u = -2*v;
    EXPECT_EQ(Vector4(-6, 2, -2, -18), u);
}

// /
TEST(Vector4, Division_1){
    Vector4 v(1, 3, 4, 7);
    Vector4 u = v/2;
    EXPECT_EQ(Vector4(0.5, 1.5, 2, 3.5), u);
}

TEST(Vector4, Division_2){
    Vector4 v(3, 1, 6, 0);
    Vector4 u = v/3;
    EXPECT_EQ(Vector4(1, 0.33333333333, 2, 0), u);
}

// dot
TEST(Vector4, Dot_1){
    Vector4 v(2, 5, 1, 0);
    Vector4 u(4, 2, 8, 2);
    EXPECT_EQ(26, vector4::dot(v, u));
}

TEST(Vector4, Dot_2){
    Vector4 v(2, 5, 2, 3);
    Vector4 u(3, 1, 2, -5);
    EXPECT_EQ(0, vector4::dot(v, u));
}


//------------------------------------------------------------------------------
// Matrix2 tests
//------------------------------------------------------------------------------

// +=
TEST(Matrix2, Addition_assig_1){
    Matrix2 A(1, 5,
              3, 2);
    A += Matrix2(3, -1,
                 3, 2);
    EXPECT_EQ(Matrix2(4, 4, 6, 4), A);
}

TEST(Matrix2, Addition_assig_2){
    Matrix2 A(3, -2,
              -1, 0);
    A += Matrix2(5, 1,
                 -2, -2);
    EXPECT_EQ(Matrix2(8, -1, -3, -2), A);
}

// -=
TEST(Matrix2, Subtraction_assig_1){
    Matrix2 A(3, 2,
              1, 0);
    A -= Matrix2(4, 0,
                 8, 9);
    EXPECT_EQ(Matrix2(-1, 2, -7, -9), A);
}

TEST(Matrix2, Subtraction_assig_2){
    Matrix2 A(9, 1,
              -6, -1);
    A -= Matrix2(8, -3,
                 5, 1);
    EXPECT_EQ(Matrix2(1, 4, -11, -2), A);
}

// *= (scalar)
TEST(Matrix2, Multiplication_assig_1){
    Matrix2 A(2, 4,
              -2, 0);
    A *= 3;
    EXPECT_EQ(Matrix2(6, 12, -6, 0), A);
}

TEST(Matrix2, Multiplication_assig_2){
    Matrix2 A(4, -9,
              0, 2);
    A *= -2;
    EXPECT_EQ(Matrix2(-8, 18, 0, -4), A);
}

// *= (matrix)
TEST(Matrix2, Multiplication_assig_3){
    Matrix2 A(3, 2,
              -1, 0);
    A *= Matrix2(0, 6,
                 2, 1);
    EXPECT_EQ(Matrix2(4, 20, 0, -6), A);
}

TEST(Matrix2, Multiplication_assig_4){
    Matrix2 A(0, 0,
              1, -2);
    A *= Matrix2(2, 4,
                 0, -1);
    EXPECT_EQ(Matrix2(0, 0, 2, 6), A);
}

// /=
TEST(Matrix2, Division_assig_1){
    Matrix2 A(2, 1,
              3, 8);
    A /= 2;
    EXPECT_EQ(Matrix2(1, 0.5, 1.5, 4), A);
}

TEST(Matrix2, Division_assig_2){
    Matrix2 A(0, 2,
              3, 0);
    A /= 3;
    EXPECT_EQ(Matrix2(0, 0.66666666666, 1, 0), A);
}

// this->determinant
TEST(Matrix2, Self_determinant_1){
    Matrix2 A(3, 9,
              0, 3);
    EXPECT_EQ(9, A.determinant());
}

TEST(Matrix2, Self_determinant_2){
    Matrix2 A(5, 2,
              4, 1);
    EXPECT_EQ(-3, A.determinant());
}

// this->transpose
TEST(Matrix2, Self_transpose_1){
    Matrix2 A(0, 1,
              1, 0);
    A.transpose();
    EXPECT_EQ(Matrix2(0, 1, 1, 0), A);
}

TEST(Matrix2, Self_transpose_2){
    Matrix2 A(2, 0,
              3, 1);
    A.transpose();
    EXPECT_EQ(Matrix2(2, 3, 0, 1), A);
}

// this->inverse
TEST(Matrix2, Self_inverse_1){
    Matrix2 A(1, 0,
              1, 1);
    A.inverse();
    EXPECT_EQ(Matrix2(1, 0, -1, 1), A);
}

TEST(Matrix2, Self_inverse_2){
    Matrix2 A(3, 8,
              0, 5);
    A.inverse();
    EXPECT_EQ(Matrix2(0.33333333333, -0.5333333333333, 0, 0.2), A);
}

// +
TEST(Matrix2, Addition_1){
    Matrix2 A(1, 5,
              3, 2);
    Matrix2 B(3, -1,
              3, 2);
    Matrix2 C = A + B;
    EXPECT_EQ(Matrix2(4, 4, 6, 4), C);
}

TEST(Matrix2, Addition_2){
    Matrix2 A(3, -2,
              -1, 0);
    Matrix2 B(5, 1,
              -2, -2);
    Matrix2 C = A + B;
    EXPECT_EQ(Matrix2(8, -1, -3, -2), C);
}

// -
TEST(Matrix2, Subtraction_1){
    Matrix2 A(3, 2,
              1, 0);
    Matrix2 B(4, 0,
              8, 9);
    Matrix2 C = A - B;
    EXPECT_EQ(Matrix2(-1, 2, -7, -9), C);
}

TEST(Matrix2, Subtraction_2){
    Matrix2 A(9, 1,
              -6, -1);
    Matrix2 B(8, -3,
              5, 1);
    Matrix2 C = A - B;
    EXPECT_EQ(Matrix2(1, 4, -11, -2), C);
}

// * (scalar)
TEST(Matrix2, Multiplication_1){
    Matrix2 A(2, 4,
              -2, 0);
    Matrix2 B = A*3;
    EXPECT_EQ(Matrix2(6, 12, -6, 0), B);
}

TEST(Matrix2, Multiplication_2){
    Matrix2 A(4, -9,
              0, 2);
    Matrix2 B = -2*A;
    EXPECT_EQ(Matrix2(-8, 18, 0, -4), B);
}

// * (matrix x matrix)
TEST(Matrix2, Multiplication_3){
    Matrix2 A(3, 2,
              -1, 0);
    Matrix2 B(0, 6,
              2, 1);
    Matrix2 C = A*B;
    EXPECT_EQ(Matrix2(4, 20, 0, -6), C);
}

TEST(Matrix2, Multiplication_4){
    Matrix2 A(0, 0,
              1, -2);
    Matrix2 B(2, 4,
              0, -1);
    Matrix2 C = A*B;
    EXPECT_EQ(Matrix2(0, 0, 2, 6), C);
}

// * (matrix x vector)
TEST(Matrix2, Multiplication_5){
    Matrix2 A(2, 3,
              1, 0);
    Vector2 v(4, -5);
    Vector2 u = A*v;
    EXPECT_EQ(Vector2(-7, 4), u);
}

TEST(Matrix2, Multiplication_6){
    Matrix2 A(6, 1,
              -8, -2);
    Vector2 v(-3, 0);
    Vector2 u = A*v;
    EXPECT_EQ(Vector2(-18, 24), u);
}

// * (vector x matrix)
TEST(Matrix2, Multiplication_7){
    Vector2 v(4, -5);
    Matrix2 A(2, 3,
              1, 0);
    Vector2 u = v*A;
    EXPECT_EQ(Vector2(3, 12), u);
}

TEST(Matrix2, Multiplication_8){
    Vector2 v(-3, 0);
    Matrix2 A(6, 1,
              -8, -2);
    Vector2 u = v*A;
    EXPECT_EQ(Vector2(-18, -3), u);
}

// /
TEST(Matrix2, Division_1){
    Matrix2 A(2, 1,
              3, 8);
    Matrix2 B = A/2;
    EXPECT_EQ(Matrix2(1, 0.5, 1.5, 4), B);
}

TEST(Matrix2, Division_2){
    Matrix2 A(0, 2,
              3, 0);
    Matrix2 B = A/3;
    EXPECT_EQ(Matrix2(0, 0.66666666666, 1, 0), B);
}

// identity
TEST(Matrix2, Identity_1){
    Matrix2 A = matrix2::identity();
    EXPECT_EQ(Matrix2(1, 0, 0, 1), A);
}

// determinant
TEST(Matrix2, Determinant_1){
    Matrix2 A(3, 9,
              0, 3);
    EXPECT_EQ(9, matrix2::determinant(A));
}

TEST(Matrix2, Determinant_2){
    Matrix2 A(5, 2,
              4, 1);
    EXPECT_EQ(-3, matrix2::determinant(A));
}

// transpose
TEST(Matrix2, Transpose_1){
    Matrix2 A(0, 1,
              1, 0);
    Matrix2 B = matrix2::transpose(A);
    EXPECT_EQ(Matrix2(0, 1, 1, 0), B);
}

TEST(Matrix2, Transpose_2){
    Matrix2 A(2, 0,
              3, 1);
    Matrix2 B = matrix2::transpose(A);
    EXPECT_EQ(Matrix2(2, 3, 0, 1), B);
}

// inverse
TEST(Matrix2, Inverse_1){
    Matrix2 A(1, 0,
              1, 1);
    Matrix2 B = matrix2::inverse(A);
    EXPECT_EQ(Matrix2(1, 0, -1, 1), B);
}

TEST(Matrix2, Inverse_2){
    Matrix2 A(3, 8,
              0, 5);
    Matrix2 B = matrix2::inverse(A);
    EXPECT_EQ(Matrix2(0.33333333333, -0.5333333333333, 0, 0.2), B);
}


//------------------------------------------------------------------------------
// Matrix3 tests
//------------------------------------------------------------------------------

// +=
TEST(Matrix3, Addition_assig_1){
    Matrix3 A(1, 5, 3,
              3, 2, 0,
              9, 1, 4);
    A += Matrix3(3, -1, 0,
                 3, 2, 9,
                 2, -9, -8);
    EXPECT_EQ(Matrix3(4, 4, 3, 6, 4, 9, 11, -8, -4), A);
}

TEST(Matrix3, Addition_assig_2){
    Matrix3 A(3, -2, 9,
              -1, 0, 2,
              -3, 5, -1);
    A += Matrix3(5, 1, 0,
                 -2, -2, 3,
                 -9, 0, 2);
    EXPECT_EQ(Matrix3(8, -1, 9, -3, -2, 5, -12, 5, 1), A);
}

// -=
TEST(Matrix3, Subtraction_assig_1){
    Matrix3 A(3, 2, 1,
              1, 0, -8,
              7, 1, 3);
    A -= Matrix3(4, 0, 0,
                 8, 9, 1,
                 -6, 1, -13);
    EXPECT_EQ(Matrix3(-1, 2, 1, -7, -9, -9, 13, 0, 16), A);
}

TEST(Matrix3, Subtraction_assig_2){
    Matrix3 A(9, 1, 0,
              -6, -1, -2,
              5, 2, 0);
    A -= Matrix3(8, -3, 1,
                 5, 1, -2,
                 0, 0, 4);
    EXPECT_EQ(Matrix3(1, 4, -1, -11, -2, 0, 5, 2, -4), A);
}

// *= (scalar)
TEST(Matrix3, Multiplication_assig_1){
    Matrix3 A(2, 4, 0,
              -2, 0, 3,
              5, 1, 6);
    A *= 3;
    EXPECT_EQ(Matrix3(6, 12, 0, -6, 0, 9, 15, 3, 18), A);
}

TEST(Matrix3, Multiplication_assig_2){
    Matrix3 A(4, -9, 2,
              0, 2, -9,
              3, -1, -5);
    A *= -2;
    EXPECT_EQ(Matrix3(-8, 18, -4, 0, -4, 18, -6, 2, 10), A);
}

// *= (matrix)
TEST(Matrix3, Multiplication_assig_3){
    Matrix3 A(3, 2, 8,
              -1, 0, 2,
              -4, 2, -7);
    A *= Matrix3(0, 6, 4,
                 2, 1, -1,
                 -3, 4, 0);
    EXPECT_EQ(Matrix3(-20, 52, 10, -6, 2, -4, 25, -50, -18), A);
}

TEST(Matrix3, Multiplication_assig_4){
    Matrix3 A(0, 0, 0,
              1, -2, 3,
              9, 1, -8);
    A *= Matrix3(2, 4, 0,
                 0, -1, 2,
                 8, 3, -3);
    EXPECT_EQ(Matrix3(0, 0, 0, 26, 15, -13, -46, 11, 26), A);
}

// /=
TEST(Matrix3, Division_assig_1){
    Matrix3 A(2, 1, 0,
              3, 8, -2,
              0, 2, 6);
    A /= 2;
    EXPECT_EQ(Matrix3(1, 0.5, 0, 1.5, 4, -1, 0, 1, 3), A);
}

TEST(Matrix3, Division_assig_2){
    Matrix3 A(0, 2, 6,
              3, 0, 4,
              18, -9, 1);
    A /= 3;
    EXPECT_EQ(Matrix3(0, 0.66666666666, 2, 1, 0, 1.33333333333, 6, -3, 0.333333333333), A);
}

// this->determinant
TEST(Matrix3, Self_determinant_1){
    Matrix3 A(3, 9, 7,
              0, 3, 3,
              5, -9, 1);
    EXPECT_EQ(120, A.determinant());
}

TEST(Matrix3, Self_determinant_2){
    Matrix3 A(5, 2, 0,
              4, 1, 0,
              1, 2, 1);
    EXPECT_EQ(-3, A.determinant());
}

// this->transpose
TEST(Matrix3, Self_transpose_1){
    Matrix3 A(0, 1, 0,
              1, 0, 1,
              0, 1, 0);
    A.transpose();
    EXPECT_EQ(Matrix3(0, 1, 0, 1, 0, 1, 0, 1, 0), A);
}

TEST(Matrix3, Self_transpose_2){
    Matrix3 A(2, 0, 9,
              3, 1, 2,
              1, 6, 7);
    A.transpose();
    EXPECT_EQ(Matrix3(2, 3, 1, 0, 1, 6, 9, 2, 7), A);
}

// this->inverse
TEST(Matrix3, Self_inverse_1){
    Matrix3 A(1, 0, 1,
              1, 1, 1,
              0, 0, 1);
    A.inverse();
    EXPECT_EQ(Matrix3(1, 0, -1, -1, 1, 0, 0, 0, 1), A);
}

TEST(Matrix3, Self_inverse_2){
    Matrix3 A(3, 8, -2,
              0, 5, 2,
              -6, 0, 1);
    A.inverse();
    EXPECT_EQ(Matrix3(-0.0354609929078014184, 0.05673758865248226946, -0.18439716312056737585,
                      0.085106382978723404252, 0.0638297872340425532, 0.042553191489361702124,
                      -0.21276595744680851063, 0.34042553191489361702, -0.10638297872340425531), A);
}

// +
TEST(Matrix3, Addition_1){
    Matrix3 A(1, 5, 3,
              3, 2, 0,
              -4, 1, -10);
    Matrix3 B(3, -1, 0,
              3, 2, 10,
              -3, -2, 8);
    Matrix3 C = A + B;
    EXPECT_EQ(Matrix3(4, 4, 3, 6, 4, 10, -7, -1, -2), C);
}

TEST(Matrix3, Addition_2){
    Matrix3 A(3, -2, 0,
              -1, 0, -3,
              2, 4, 8);
    Matrix3 B(5, 1, -4,
              -2, -2, 0,
              5, 3, 6);
    Matrix3 C = A + B;
    EXPECT_EQ(Matrix3(8, -1, -4, -3, -2, -3, 7, 7, 14), C);
}

// -
TEST(Matrix3, Subtraction_1){
    Matrix3 A(3, 2, 1,
              1, 0, -2,
              6, 0, 0);
    Matrix3 B(4, 0, 4,
              8, 9, 1,
              3, -4, 1);
    Matrix3 C = A - B;
    EXPECT_EQ(Matrix3(-1, 2, -3, -7, -9, -3, 3, 4, -1), C);
}

TEST(Matrix3, Subtraction_2){
    Matrix3 A(9, 1, 0,
              -6, -1, 8,
              6, 1, -5);
    Matrix3 B(8, -3, 0,
              5, 1, 5,
              -9, 8, 1);
    Matrix3 C = A - B;
    EXPECT_EQ(Matrix3(1, 4, 0, -11, -2, 3, 15, -7, -6), C);
}

// * (scalar)
TEST(Matrix3, Multiplication_1){
    Matrix3 A(2, 4, 1,
              -2, 0, 3,
              -7, -2, -1);
    Matrix3 B = A*3;
    EXPECT_EQ(Matrix3(6, 12, 3, -6, 0, 9, -21, -6, -3), B);
}

TEST(Matrix3, Multiplication_2){
    Matrix3 A(4, -9, 8,
              0, 2, 0,
              2, -5, 1);
    Matrix3 B = -2*A;
    EXPECT_EQ(Matrix3(-8, 18, -16, 0, -4, 0, -4, 10, -2), B);
}

// * (matrix x matrix)
TEST(Matrix3, Multiplication_3){
    Matrix3 A(3, 2, 8,
              -1, 0, 2,
              -4, 2, -7);
    Matrix3 B(0, 6, 4,
              2, 1, -1,
              -3, 4, 0);
    Matrix3 C = A*B;
    EXPECT_EQ(Matrix3(-20, 52, 10, -6, 2, -4, 25, -50, -18), C);
}

TEST(Matrix3, Multiplication_4){
    Matrix3 A(0, 0, 0,
              1, -2, 3,
              9, 1, -8);
    Matrix3 B(2, 4, 0,
              0, -1, 2,
              8, 3, -3);
    Matrix3 C = A*B;
    EXPECT_EQ(Matrix3(0, 0, 0, 26, 15, -13, -46, 11, 26), C);
}

// * (matrix x vector)
TEST(Matrix3, Multiplication_5){
    Matrix3 A(2, 3, 4,
              1, 0, 7,
              -4, 1, 0);
    Vector3 v(4, -5, -2);
    Vector3 u = A*v;
    EXPECT_EQ(Vector3(-15, -10, -21), u);
}

TEST(Matrix3, Multiplication_6){
    Matrix3 A(6, 1, 0,
              -8, -2, 2,
              0, 5, 2);
    Vector3 v(-3, 0, 1);
    Vector3 u = A*v;
    EXPECT_EQ(Vector3(-18, 26, 2), u);
}

// * (vector x matrix)
TEST(Matrix3, Multiplication_7){
    Vector3 v(4, -5, -2);
    Matrix3 A(2, 3, 4,
              1, 0, 7,
              -4, 1, 0);
    Vector3 u = v*A;
    EXPECT_EQ(Vector3(11, 10, -19), u);
}

TEST(Matrix3, Multiplication_8){
    Vector3 v(-3, 0, 1);
    Matrix3 A(6, 1, 0,
              -8, -2, 2,
              0, 5, 2);
    Vector3 u = v*A;
    EXPECT_EQ(Vector3(-18, 2, 2), u);
}

// /
TEST(Matrix3, Division_1){
    Matrix3 A(2, 1, 9,
              3, 8, 3,
              0, 0, 2);
    Matrix3 B = A/2;
    EXPECT_EQ(Matrix3(1, 0.5, 4.5, 1.5, 4, 1.5, 0, 0, 1), B);
}

TEST(Matrix3, Division_2){
    Matrix3 A(0, 2, -3,
              3, 0, 6,
              6, 2, -1);
    Matrix3 B = A/3;
    EXPECT_EQ(Matrix3(0, 0.66666666666, -1, 1, 0, 2, 2, 0.66666666666, -0.3333333333333), B);
}

// identity
TEST(Matrix3, Identity_1){
    Matrix3 A = matrix3::identity();
    EXPECT_EQ(Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1), A);
}

// determinant
TEST(Matrix3, Determinant_1){
    Matrix3 A(3, 9, 5,
              0, 3, -5,
              9, 2, 1);
    EXPECT_EQ(-501, matrix3::determinant(A));
}

TEST(Matrix3, Determinant_2){
    Matrix3 A(5, 2, 0,
              4, 1, 2,
              0, 2, 5);
    EXPECT_EQ(-35, matrix3::determinant(A));
}

// transpose
TEST(Matrix3, Transpose_1){
    Matrix3 A(0, 1, 0,
              1, 0, 0,
              0, 0, 0);
    Matrix3 B = matrix3::transpose(A);
    EXPECT_EQ(Matrix3(0, 1, 0, 1, 0, 0, 0, 0, 0), B);
}

TEST(Matrix3, Transpose_2){
    Matrix3 A(2, 0, 9,
              3, 1, 0,
              9, 1, 3);
    Matrix3 B = matrix3::transpose(A);
    EXPECT_EQ(Matrix3(2, 3, 9, 0, 1, 1, 9, 0, 3), B);
}

// inverse
TEST(Matrix3, Inverse_1){
    Matrix3 A(1, 0, 1,
              1, 1, 1,
              0, 0, 1);
    Matrix3 B = matrix3::inverse(A);
    EXPECT_EQ(Matrix3(1, 0, -1, -1, 1, 0, 0, 0, 1), B);
}

TEST(Matrix3, Inverse_2){
    Matrix3 A(3, 8, -2,
              0, 5, 2,
              -6, 0, 1);
    Matrix3 B = matrix3::inverse(A);
    EXPECT_EQ(Matrix3(-0.0354609929078014184, 0.05673758865248226946, -0.18439716312056737585,
                      0.085106382978723404252, 0.0638297872340425532, 0.042553191489361702124,
                      -0.21276595744680851063, 0.34042553191489361702, -0.10638297872340425531), B);
}


//------------------------------------------------------------------------------
// Matrix3 tests
//------------------------------------------------------------------------------

// +=
TEST(Matrix4, Addition_assig_1){
    Matrix4 A(1, 5, 3, 8,
              3, 2, 0, 2,
              9, 1, 4, -2,
              2, 0, -1, 0);
    A += Matrix4(3, -1, 0, 8,
                 3, 2, 9, -3,
                 2, -9, -8, 0,
                 7, 3, -2, 1);
    EXPECT_EQ(Matrix4(4, 4, 3, 16, 6, 4, 9, -1, 11, -8, -4, -2, 9, 3, -3, 1), A);
}

TEST(Matrix4, Addition_assig_2){
    Matrix4 A(3, -2, 9, 0,
              -1, 0, 2, -3,
              -3, 5, -1, 5,
              2, 8, 0, 0);
    A += Matrix4(5, 1, 0, 4,
                 -2, -2, 3, 0,
                 -9, 0, 2, -4,
                 0, 0, -9, -2);
    EXPECT_EQ(Matrix4(8, -1, 9, 4, -3, -2, 5, -3, -12, 5, 1, 1, 2, 8, -9, -2), A);
}

// -=
TEST(Matrix4, Subtraction_assig_1){
    Matrix4 A(3, 2, 1, 9,
              1, 0, -8, 0,
              7, 1, 3, 9,
              3, 1, -5, 1);
    A -= Matrix4(4, 0, 0, 9,
                 8, 9, 1, -4,
                 -6, 1, -13, 2,
                 3, 1, -5, 3);
    EXPECT_EQ(Matrix4(-1, 2, 1, 0, -7, -9, -9, 4, 13, 0, 16, 7, 0, 0, 0, -2), A);
}

TEST(Matrix4, Subtraction_assig_2){
    Matrix4 A(9, 1, 0, 8,
              -6, -1, -2, -7,
              5, 2, 0, 6,
              1, 5, -1, 5);
    A -= Matrix4(8, -3, 1, 0,
                 5, 1, -2, 4,
                 0, 0, 4, 0,
                 -1, 1, 1, -1);
    EXPECT_EQ(Matrix4(1, 4, -1, 8, -11, -2, 0, -11, 5, 2, -4, 6, 2, 4, -2, 6), A);
}

// *= (scalar)
TEST(Matrix4, Multiplication_assig_1){
    Matrix4 A(2, 4, 0, 9,
              -2, 0, 3, 11,
              5, 1, 6, -2,
              4, 1, 0, 0);
    A *= 3;
    EXPECT_EQ(Matrix4(6, 12, 0, 27, -6, 0, 9, 33, 15, 3, 18, -6, 12, 3, 0, 0), A);
}

TEST(Matrix4, Multiplication_assig_2){
    Matrix4 A(4, -9, 2, 0,
              0, 2, -9, -1,
              3, -1, -5, 7,
              1, 7, 19, 0);
    A *= -2;
    EXPECT_EQ(Matrix4(-8, 18, -4, 0, 0, -4, 18, 2, -6, 2, 10, -14, -2, -14, -38, 0), A);
}

// *= (matrix)
TEST(Matrix4, Multiplication_assig_3){
    Matrix4 A(3, 2, 8, 1,
              -1, 0, 2, 0,
              -4, 2, -7, -2,
              1, 3, 1, -5);
    A *= Matrix4(0, 6, 4, 0,
                 2, 1, -1, 3,
                 -3, 4, 0, -1,
                 0, 4, 1, -3);
    EXPECT_EQ(Matrix4(-20, 56, 11, -5, -6, 2, -4, -2, 25, -58, -20, 19, 3, -7, -4, 23), A);
}

TEST(Matrix4, Multiplication_assig_4){
    Matrix4 A(0, 0, 0, 0,
              1, -2, 3, 0,
              9, 1, -8, 0,
              0, 0, 0, 1);
    A *= Matrix4(2, 4, 0, 8,
                 0, -1, 2, -2,
                 8, 3, -3, 2,
                 0, -1, 3, -2);
    EXPECT_EQ(Matrix4(0, 0, 0, 0, 26, 15, -13, 18, -46, 11, 26, 54, 0, -1, 3, -2), A);
}

// /=
TEST(Matrix4, Division_assig_1){
    Matrix4 A(2, 1, 0, 8,
              3, 8, -2, -1,
              0, 2, 6, 0,
              0, 2, 3, 6);
    A /= 2;
    EXPECT_EQ(Matrix4(1, 0.5, 0, 4, 1.5, 4, -1, -0.5, 0, 1, 3, 0, 0, 1, 1.5, 3), A);
}

TEST(Matrix4, Division_assig_2){
    Matrix4 A(0, 2, 6, 3,
              3, 0, 4, 27,
              18, -9, 1, 12,
              0, 3, 6, -6);
    A /= 3;
    EXPECT_EQ(Matrix4(0, 0.66666666666, 2, 1, 1, 0, 1.33333333333, 9, 6, -3, 0.333333333333, 4, 0, 1, 2, -2), A);
}

// this->determinant
TEST(Matrix4, Self_determinant_1){
    Matrix4 A(3, 9, 7, 9,
              0, 3, 3, 8,
              5, -9, 1, -5,
              2, 4, 1, -5);
    EXPECT_EQ(-20, A.determinant());
}

TEST(Matrix4, Self_determinant_2){
    Matrix4 A(5, 2, 0, 0,
              4, 1, 0, 0,
              1, 2, 1, -2,
              3, 1, 2, -1);
    EXPECT_EQ(-9, A.determinant());
}

// this->transpose
TEST(Matrix4, Self_transpose_1){
    Matrix4 A(0, 1, 0, 0,
              1, 0, 1, 0,
              0, 1, 0, 0,
              0, 0, 0, 0);
    A.transpose();
    EXPECT_EQ(Matrix4(0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0), A);
}

TEST(Matrix4, Self_transpose_2){
    Matrix4 A(2, 0, 9, 3,
              3, 1, 2, -2,
              1, 6, 7, 8,
              -5, 2, 7, 0);
    A.transpose();
    EXPECT_EQ(Matrix4(2, 3, 1, -5, 0, 1, 6, 2, 9, 2, 7, 7, 3, -2, 8, 0), A);
}

// this->inverse
TEST(Matrix4, Self_inverse_1){
    Matrix4 A(1, 0, 1, 1,
              1, 1, 1, 0,
              0, 0, 1, 0,
              1, 0, 1, 0);
    A.inverse();
    EXPECT_EQ(Matrix4(0, 0, -1, 1, 0, 1, 0, -1, 0, 0, 1, 0, 1, 0, 0, -1), A);
}

TEST(Matrix4, Self_inverse_2){
    Matrix4 A(3, 8, -2, 0,
              0, 5, 2, 1,
              -6, 0, 1, 2,
              -1, 2, 3, 3);
    A.inverse();
    EXPECT_EQ(Matrix4(0.031802120141342756194, -0.11307420494699646644, -0.17667844522968197879, 0.1554770318021201413,
                      0.053003533568904593638, 0.14487632508833922262, 0.038869257950530035334, -0.0742049469964664311,
                      -0.24028268551236749116, 0.40989399293286219079, -0.10954063604240282685, -0.06360424028268551233,
                      0.21554770318021201413, -0.54416961130742049468, 0.02473498233215547703, 0.49823321554770318018), A);
}
// undone below this line
// +
TEST(Matrix4, Addition_1){
    Matrix4 A(1, 5, 3, 8,
              3, 2, 0, 2,
              9, 1, 4, -2,
              2, 0, -1, 0);
    Matrix4 B(3, -1, 0, 8,
              3, 2, 9, -3,
              2, -9, -8, 0,
              7, 3, -2, 1);
    Matrix4 C = A + B;
    EXPECT_EQ(Matrix4(4, 4, 3, 16, 6, 4, 9, -1, 11, -8, -4, -2, 9, 3, -3, 1), C);
}

TEST(Matrix4, Addition_2){
    Matrix4 A(3, -2, 9, 0,
              -1, 0, 2, -3,
              -3, 5, -1, 5,
              2, 8, 0, 0);
    Matrix4 B(5, 1, 0, 4,
              -2, -2, 3, 0,
              -9, 0, 2, -4,
              0, 0, -9, -2);
    Matrix4 C = A + B;
    EXPECT_EQ(Matrix4(8, -1, 9, 4, -3, -2, 5, -3, -12, 5, 1, 1, 2, 8, -9, -2), C);
}

// -
TEST(Matrix4, Subtraction_1){
    Matrix4 A(3, 2, 1, 9,
              1, 0, -8, 0,
              7, 1, 3, 9,
              3, 1, -5, 1);
    Matrix4 B(4, 0, 0, 9,
              8, 9, 1, -4,
              -6, 1, -13, 2,
              3, 1, -5, 3);
    Matrix4 C = A - B;
    EXPECT_EQ(Matrix4(-1, 2, 1, 0, -7, -9, -9, 4, 13, 0, 16, 7, 0, 0, 0, -2), C);
}

TEST(Matrix4, Subtraction_2){
    Matrix4 A(9, 1, 0, 8,
              -6, -1, -2, -7,
              5, 2, 0, 6,
              1, 5, -1, 5);
    Matrix4 B(8, -3, 1, 0,
              5, 1, -2, 4,
              0, 0, 4, 0,
              -1, 1, 1, -1);
    Matrix4 C = A - B;
    EXPECT_EQ(Matrix4(1, 4, -1, 8, -11, -2, 0, -11, 5, 2, -4, 6, 2, 4, -2, 6), C);
}

// * (scalar)
TEST(Matrix4, Multiplication_1){
    Matrix4 A(2, 4, 0, 9,
              -2, 0, 3, 11,
              5, 1, 6, -2,
              4, 1, 0, 0);
    Matrix4 B = A*3;
    EXPECT_EQ(Matrix4(6, 12, 0, 27, -6, 0, 9, 33, 15, 3, 18, -6, 12, 3, 0, 0), B);
}

TEST(Matrix4, Multiplication_2){
    Matrix4 A(4, -9, 2, 0,
              0, 2, -9, -1,
              3, -1, -5, 7,
              1, 7, 19, 0);
    Matrix4 B = -2*A;
    EXPECT_EQ(Matrix4(-8, 18, -4, 0, 0, -4, 18, 2, -6, 2, 10, -14, -2, -14, -38, 0), B);
}

// * (matrix x matrix)
TEST(Matrix4, Multiplication_3){
    Matrix4 A(3, 2, 8, 3,
              -1, 0, 2, -2,
              -4, 2, -7, 0,
              -9, 1, 4, 5);
    Matrix4 B(0, 6, 4, 0,
              2, 1, -1, 6,
              -3, 4, 0, 3,
              -10, 9, 0, 0);
    Matrix4 C = A*B;
    EXPECT_EQ(Matrix4(-50, 79, 10, 36, 14, -16, -4, 6, 25, -50, -18, -9, -60, 8, -37, 18), C);
}

TEST(Matrix4, Multiplication_4){
    Matrix4 A(0, 0, 0, 0,
              1, -2, 3, 1,
              9, 1, -8, 0,
              1, 5, 2, -1);
    Matrix4 B(2, 4, 0, 0,
              0, -1, 2, 3,
              8, 3, -3, 3,
              1, 5, -2, 3);
    Matrix4 C = A*B;
    EXPECT_EQ(Matrix4(0, 0, 0, 0, 27, 20, -15, 6, -46, 11, 26, -21, 17, 0, 6, 18), C);
}

// * (matrix x vector)
TEST(Matrix4, Multiplication_5){
    Matrix4 A(2, 3, 4, 9,
              1, 0, 7, 3,
              -4, 1, 0, -8,
              1, 4, 0, 3);
    Vector4 v(4, -5, -2, 0);
    Vector4 u = A*v;
    EXPECT_EQ(Vector4(-15, -10, -21, -16), u);
}

TEST(Matrix4, Multiplication_6){
    Matrix4 A(6, 1, 0, 3,
              -8, -2, 2, 9,
              0, 5, 2, 0,
              1, 6, 8, 1);
    Vector4 v(-3, 0, 1, 3);
    Vector4 u = A*v;
    EXPECT_EQ(Vector4(-9, 53, 2, 8), u);
}

// * (vector x matrix)
TEST(Matrix4, Multiplication_7){
    Vector4 v(4, -5, -2, 0);
    Matrix4 A(2, 3, 4, 9,
              1, 0, 7, 3,
              -4, 1, 0, -8,
              1, 4, 0, 3);
    Vector4 u = v*A;
    EXPECT_EQ(Vector4(11, 10, -19, 37), u);
}

TEST(Matrix4, Multiplication_8){
    Vector4 v(-3, 0, 1, 3);
    Matrix4 A(6, 1, 0, 3,
              -8, -2, 2, 9,
              0, 5, 2, 0,
              1, 6, 8, 1);
    Vector4 u = v*A;
    EXPECT_EQ(Vector4(-15, 20, 26, -6), u);
}

// /
TEST(Matrix4, Division_1){
    Matrix4 A(2, 1, 0, 8,
              3, 8, -2, -1,
              0, 2, 6, 0,
              0, 2, 3, 6);
    Matrix4 B = A/2;
    EXPECT_EQ(Matrix4(1, 0.5, 0, 4, 1.5, 4, -1, -0.5, 0, 1, 3, 0, 0, 1, 1.5, 3), B);
}

TEST(Matrix4, Division_2){
    Matrix4 A(0, 2, 6, 3,
              3, 0, 4, 27,
              18, -9, 1, 12,
              0, 3, 6, -6);
    Matrix4 B = A/3;
    EXPECT_EQ(Matrix4(0, 0.66666666666, 2, 1, 1, 0, 1.33333333333, 9, 6, -3, 0.333333333333, 4, 0, 1, 2, -2), B);
}

// identity
TEST(Matrix4, Identity_1){
    Matrix4 A = matrix4::identity();
    EXPECT_EQ(Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), A);
}

// determinant
TEST(Matrix4, Determinant_1){
    Matrix4 A(3, 9, 7, 9,
              0, 3, 3, 8,
              5, -9, 1, -5,
              2, 4, 1, -5);
    EXPECT_EQ(-20, matrix4::determinant(A));
}

TEST(Matrix4, Determinant_2){
    Matrix4 A(5, 2, 0, 0,
              4, 1, 0, 0,
              1, 2, 1, -2,
              3, 1, 2, -1);
    EXPECT_EQ(-9, matrix4::determinant(A));
}

// transpose
TEST(Matrix4, Transpose_1){
    Matrix4 A(0, 1, 0, 0,
              1, 0, 1, 0,
              0, 1, 0, 0,
              0, 0, 0, 0);
    Matrix4 B = matrix4::transpose(A);
    EXPECT_EQ(Matrix4(0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0), B);
}

TEST(Matrix4, Transpose_2){
    Matrix4 A(2, 0, 9, 3,
              3, 1, 2, -2,
              1, 6, 7, 8,
              -5, 2, 7, 0);
    Matrix4 B = matrix4::transpose(A);
    EXPECT_EQ(Matrix4(2, 3, 1, -5, 0, 1, 6, 2, 9, 2, 7, 7, 3, -2, 8, 0), B);
}

// inverse
TEST(Matrix4, Inverse_1){
    Matrix4 A(1, 0, 1, 1,
              1, 1, 1, 0,
              0, 0, 1, 0,
              1, 0, 1, 0);
    Matrix4 B = matrix4::inverse(A);
    EXPECT_EQ(Matrix4(0, 0, -1, 1, 0, 1, 0, -1, 0, 0, 1, 0, 1, 0, 0, -1), B);
}

TEST(Matrix4, Inverse_2){
    Matrix4 A(3, 8, -2, 0,
              0, 5, 2, 1,
              -6, 0, 1, 2,
              -1, 2, 3, 3);
    Matrix4 B = matrix4::inverse(A);
    EXPECT_EQ(Matrix4(0.031802120141342756194, -0.11307420494699646644, -0.17667844522968197879, 0.1554770318021201413,
                      0.053003533568904593638, 0.14487632508833922262, 0.038869257950530035334, -0.0742049469964664311,
                      -0.24028268551236749116, 0.40989399293286219079, -0.10954063604240282685, -0.06360424028268551233,
                      0.21554770318021201413, -0.54416961130742049468, 0.02473498233215547703, 0.49823321554770318018), B);
}




int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
