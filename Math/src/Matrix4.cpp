#include "Matrix4.hpp"

template<FloatType N> Matrix4<N>::Matrix4(N *elements) {
    for (uint16_t i = 0u; i < MatrixDimension * MatrixDimension; i++)
        this->elements[i] = elements[i];
}

template<FloatType N> Matrix4<N>::Matrix4(
    Vector3F column_one, Vector3F column_two,
    Vector3F column_three, Vector3F column_four
) {
    elements[0] = column_one.GetX();
    elements[1] = column_two.GetX();
    elements[2] = column_three.GetX();
    elements[3] = column_four.GetX();
    elements[4] =  column_one.GetY();
    elements[5] = column_two.GetY();
    elements[6] = column_three.GetY();
    elements[7] = column_four.GetY();
    elements[8] = column_one.GetZ();
    elements[9] = column_two.GetZ();
    elements[10] = column_three.GetZ();
    elements[11] = column_four.GetZ();
    elements[12] = 0.0;
    elements[13] = 0.0;
    elements[14] = 0.0;
    elements[15] = 1.0;
}

template<FloatType N> Matrix4<N> Matrix4<N>::CreateEmptyMatrix() {
    N elements[16] = {
            0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> Matrix4<N> Matrix4<N>::CreateIdentityMatrix() {
    N elements[16] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> Matrix4<N> Matrix4<N>::CreateProjectionMatrix(N fov, N near_distance, N far_distance) {
    N scale = 1.0 / (tan((fov / 2.0) * ((N)M_PI / 180.0)));

    N elements[MatrixDimension * MatrixDimension] = {
        scale, 0.0, 0.0, 0.0,
        0.0, scale, 0.0, 0.0,
        0.0, 0.0, -(far_distance / (far_distance - near_distance)), -1.0,
        0.0, 0.0, -((far_distance * near_distance) / (far_distance - near_distance)), 1.0,
    };

    return Matrix4<N>(elements);
}

template<FloatType N> Matrix4<N> Matrix4<N>::operator*(Matrix4<N> other) {
    Matrix4<N> product;
    product.CreateEmptyMatrix();

    for (uint8_t this_row = 0; this_row < MatrixDimension; this_row++) {
        for (uint8_t other_column = 0; other_column < MatrixDimension; other_column++) {
            for (uint8_t other_index = 0; other_index < MatrixDimension; other_index++) {
                uint8_t this_element_index = (this_row * MatrixDimension) + other_index;
                uint8_t other_element_index = (other_index * MatrixDimension) + other_column;
                uint8_t result_element_index = (this_row * MatrixDimension) + other_column;

                product.elements[result_element_index] += this->elements[this_element_index] * other.elements[other_element_index];
            }
        }
    }

    return product;
}

template class Matrix4<float>;