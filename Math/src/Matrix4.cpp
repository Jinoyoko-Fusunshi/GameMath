#include "Matrix4.hpp"

template<FloatType N> 
Matrix4<N>::Matrix4(N *elements) {
    for (uint16_t i = 0u; i < MatrixDimension * MatrixDimension; i++)
        this->elements[i] = elements[i];
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::EmptyMatrix() {
    N elements[MatrixDimension * MatrixDimension] = {
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::IdentityMatrix() {
    N elements[MatrixDimension * MatrixDimension] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::TranslationMatrix(Vector3<N> &translation) {
    N elements[MatrixDimension * MatrixDimension] = {
        1.0, 0.0, 0.0, translation.GetX(),
        0.0, 1.0, 0.0, translation.GetY(),
        0.0, 0.0, 1.0, translation.GetZ(),
        0.0, 0.0, 0.0, 1.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::XRotationMatrix(Degree<N> angle) {
    N elements[MatrixDimension * MatrixDimension] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, (N)cos(angle.ToRadian()), (N)-sin(angle.ToRadian()), 0.0,
        0.0, (N)sin(angle.ToRadian()), (N)cos(angle.ToRadian()), 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::YRotationMatrix(Degree<N> angle) {
    N elements[MatrixDimension * MatrixDimension] = {
        (N)cos(angle.ToRadian()), 0.0, (N)sin(angle.ToRadian()), 0.0,
        0.0, 1.0, 0.0, 0.0,
        (N)-sin(angle.ToRadian()), 0.0, (N)cos(angle.ToRadian()), 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::ZRotationMatrix(Degree<N> angle) {
    N elements[MatrixDimension * MatrixDimension] = {
        (N)cos(angle.ToRadian()), (N)-sin(angle.ToRadian()), 0.0, 0.0,
        (N)sin(angle.ToRadian()), (N)cos(angle.ToRadian()), 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::ProjectionMatrix(N near_distance, N far_distance, N fov) {
    N scale = 1.0 / (tan((fov / 2.0f) * ((N)M_PI / 180.0)));
    N elements[MatrixDimension * MatrixDimension] = {
        scale, 0.0, 0.0, 0.0,
        0.0, scale, 0.0, 0.0,
        0.0, 0.0, -(far_distance / (far_distance - near_distance)), -1.0,
        0.0, 0.0, -((far_distance * near_distance) / (far_distance - near_distance)), 1.0,
    };

    return Matrix4<N>(elements);
}

template<FloatType N> 
Matrix4<N> Matrix4<N>::operator*(Matrix4<N> other) {
    auto product = EmptyMatrix();

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

template<FloatType N> 
N Matrix4<N>::operator[](uint8_t index) {
    return elements[index];
}

template<FloatType N> 
bool Matrix4<N>::operator==(Matrix4<N> other) {
    for (uint8_t i = 0; i < MatrixDimension * MatrixDimension; i++) {
        if (elements[i] != other[i])
            return false;
    }

    return true;
}

template class Matrix4<float>;
template class Matrix4<double>;