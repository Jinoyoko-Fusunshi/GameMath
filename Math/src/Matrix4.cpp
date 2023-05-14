#include "Matrix4.hpp"

template<FloatType N> Matrix4<N>::Matrix4(N *elements) {
    for (uint16_t i = 0u; i < MatrixDimension * MatrixDimension; i++)
        this->elements[i] = elements[i];
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

template<FloatType N>
Matrix4<N> Matrix4<N>::CreateTranslationMatrix(Vector3<N> &translation) {
    N elements[MatrixDimension * MatrixDimension] = {
        1.0, 0.0, 0.0, translation.GetX(),
        0.0, 1.0, 0.0, translation.GetY(),
        0.0, 0.0, 1.0, translation.GetZ(),
        0.0, 0.0, 0.0, 1.0
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

template<FloatType N>Vector3<N> Matrix4<N>::operator*(Vector3<N> other) {
    N vector_data[MatrixDimension] { other.GetX(), other.GetY(), other.GetZ(), 1.0 };
    N product_vector_data[MatrixDimension] { 0.0, 0.0, 0.0, 0.0 };

    for (uint8_t this_row = 0; this_row < MatrixDimension; this_row++) {
        for (uint8_t this_column = 0; this_column < MatrixDimension; this_column++) {
            const uint8_t index = this_row * MatrixDimension + this_column;

            product_vector_data[this_row] += vector_data[this_column] * elements[index];
        }
    }

    return Vector3<N>(product_vector_data[0], product_vector_data[1], product_vector_data[2]);
}

template<FloatType N> float Matrix4<N>::operator[](uint8_t index) {
    return elements[index];
}

template<FloatType N> bool Matrix4<N>::operator==(Matrix4<N> other) {
    for (uint8_t i = 0; i < MatrixDimension * MatrixDimension; i++) {
        if (elements[i] != other[i])
            return false;
    }

    return true;
}

template class Matrix4<float>;