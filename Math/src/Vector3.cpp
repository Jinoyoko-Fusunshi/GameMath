#include "Vector3.hpp"

template<FloatType N>
Vector3<N> Vector3<N>::AsNegated() {
    Vector3<N> scalar_product = *this * -1.0;
    return scalar_product;
}


template<FloatType N> Vector3<N> Vector3<N>::operator-(Vector3<N> other) {
    return Vector3<N>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template<FloatType N> void Vector3<N>::operator-=(Vector3<N> other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
}

template<FloatType N> Vector3<N> Vector3<N>::operator+(Vector3<N> other) {
    return Vector3<N>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<FloatType N> void Vector3<N>::operator+=(Vector3<N> other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}

template<FloatType N> Vector3<N> Vector3<N>::operator*(N factor) {
    return Vector3<N>(this->x == 0 ? 0 : this->x * factor, this->y == 0 ? 0 : this->y * factor, this->z == 0 ? 0 : this->z * factor);
}

template<FloatType N> void Vector3<N>::operator*=(N factor) {
    this->x *= factor;
    this->y *= factor;
    this->z *= factor;
}

template<FloatType N> bool Vector3<N>::operator==(Vector3<N> other) {
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

template class Vector3<float>;