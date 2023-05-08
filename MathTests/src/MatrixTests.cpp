#include <gtest/gtest.h>
#include "Matrix4.hpp"

TEST(Matrix4F, CreateIdentyMatrixIsCorrect) {
    Matrix4F matrix = Matrix4F::CreateIdentityMatrix();

    EXPECT_EQ(matrix[0], 1);
    EXPECT_EQ(matrix[1], 0);
    EXPECT_EQ(matrix[2], 0);
    EXPECT_EQ(matrix[3], 0);
    EXPECT_EQ(matrix[4], 0);
    EXPECT_EQ(matrix[5], 1);
    EXPECT_EQ(matrix[6], 0);
    EXPECT_EQ(matrix[7], 0);
    EXPECT_EQ(matrix[8], 0);
    EXPECT_EQ(matrix[9], 0);
    EXPECT_EQ(matrix[10], 1);
    EXPECT_EQ(matrix[11], 0);
    EXPECT_EQ(matrix[12], 0);
    EXPECT_EQ(matrix[13], 0);
    EXPECT_EQ(matrix[14], 0);
    EXPECT_EQ(matrix[15], 1);
}

TEST(Matrix4F, MultiplyIdentityMatricsProductIsCorrect) {
    Matrix4F matrix_one = Matrix4F::CreateIdentityMatrix();
    Matrix4F matrix_two = Matrix4F::CreateIdentityMatrix();
    Matrix4F matrix_product = matrix_one * matrix_two;
    Matrix4F expected_matrix_product = Matrix4F::CreateIdentityMatrix();

    EXPECT_TRUE(matrix_product == expected_matrix_product);
}