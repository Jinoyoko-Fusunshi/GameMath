#include <cmath>
#include "Angle.hpp"

template<FloatType N> Radian<N> Degree<N>::ToRadian() {
    N converted_angle = angle * (M_PI / 180.0);
    return Radian(converted_angle);
}

template<FloatType N> Degree<N> Radian<N>::ToDegree() {
    N converted_angle = angle * (180.0 / M_PI);
    return Degree(converted_angle);
}

template class Degree<float>;
template class Radian<float>;