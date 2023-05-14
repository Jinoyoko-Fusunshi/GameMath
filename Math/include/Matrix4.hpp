#pragma once

#include <stdint-gcc.h>
#include <cmath>
#include "Vector3.hpp"
#include "Angle.hpp"

constexpr uint8_t MatrixDimension = 4;

template<FloatType N> class Matrix4 {
private:
    N elements[MatrixDimension * MatrixDimension] = {0};

public:
    Matrix4() = default;
    explicit Matrix4(N *elements);
    ~Matrix4() = default;

    const N* GetElements() const { return elements; }

    static Matrix4<N> EmptyMatrix();
    static Matrix4<N> IdentityMatrix();
    static Matrix4<N> TranslationMatrix(Vector3<N> &translation);
    static Matrix4<N> XRotationMatrix(Degree<N> angle);
    static Matrix4<N> YRotationMatrix(Degree<N> angle);
    static Matrix4<N> ZRotationMatrix(Degree<N> angle);
    static Matrix4<N> ProjectionMatrix(float near_distance, float far_distance, float fov);

    Matrix4<N> operator *(Matrix4<N> other);
    Vector3<N> operator *(Vector3<N> other);
    float operator[](uint8_t index);
    bool operator==(Matrix4<N> other);
};

typedef Matrix4<float> Matrix4F;