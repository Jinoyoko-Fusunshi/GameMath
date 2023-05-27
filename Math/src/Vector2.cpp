#include "Vector2.hpp"

template<FloatType N> 
Vector2<N> Vector2<N>::operator-(Vector2<N> other) {
    return Vector2<N>(this->x - other.x, this->y - other.y);
}

template<FloatType N> 
void Vector2<N>::operator-=(Vector2<N> other) {
    this->x -= other.x;
    this->y -= other.y;
}

template<FloatType N>
Vector2<N> Vector2<N>::operator+(Vector2<N> other) {
    return Vector2<N>(this->x + other.x, this->y + other.y);
}

template<FloatType N> 
void Vector2<N>::operator+=(Vector2<N> other) {
    this->x += other.x;
    this->y += other.y;
}

template<FloatType N> 
bool Vector2<N>::operator==(Vector2<N> other) {
    return this->x == other.x && this->y == other.y;
}

template<FloatType N>
template<FloatType M>
Vector2<N>::operator Vector2<M>() {
    return Vector2<M>(this->x, this->y);
}

template class Vector2<float>;
template class Vector2<double>;
template Vector2<double>::operator Vector2<float>();
template Vector2<float>::operator Vector2<double>();