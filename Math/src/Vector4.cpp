#include "Vector4.hpp"

template<FloatType N> 
N Vector4<N>::DotProduct(Vector4<N> other) {
    N dot_product = (this->x * other.x) + (this->y * other.y) + (this->z * other.z) + (this->w * other.w);
    return dot_product;
}

template<FloatType N> 
Vector4<N> Vector4<N>::operator-(Vector4<N> other) {
    return Vector4<N>(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

template<FloatType N> 
void Vector4<N>::operator-=(Vector4<N> other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;
}

template<FloatType N> 
Vector4<N> Vector4<N>::operator+(Vector4<N> other) {
    return Vector4<N>(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

template<FloatType N> 
void Vector3<N>::operator+=(Vector3<N> other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;
}

template<FloatType N> 
Vector4<N> Vector4<N>::operator*(N factor) {
    return Vector4<N>(this->x * factor, this->y * factor, this->z * factor, this->w * factor);
}

template<FloatType N> 
void Vector4<N>::operator*=(N factor) {
    this->x *= factor;
    this->y *= factor;
    this->z *= factor;
    this->w *= factor;
}

template<FloatType N> 
bool Vector4<N>::operator==(Vector4<N> other) {
    return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

template <FloatType N>
template <FloatType M>
Vector4<N>::operator Vector4<M>() {
    return Vector4<M>(this->x, this->y, this->z, this->w);
}

template class Vector4<float>;
template class Vector4<double>;
template Vector4<double>::operator Vector4<float>();
template Vector4<float>::operator Vector4<double>();