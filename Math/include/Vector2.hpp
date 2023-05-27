#pragma once

#include "Common.hpp"

template<FloatType N>
class Vector2 {
protected:
    N x = 0.0;
    N y = 0.0;

public:
    Vector2() : x(0), y(0) {}
    explicit Vector2(N x, N y) : x(x), y(y) {}
    ~Vector2() = default;

    N GetX() const { return x; }
    N GetY() const { return y; }

    static Vector2<N> XUnitVector2() { return Vector2<N>(1.0, 0.0); };
    static Vector2<N> YUnitVector2() { return Vector2<N>(0.0, 1.0); };

    Vector2<N> operator +(Vector2<N> other);
    void operator +=(Vector2<N> other);

    Vector2<N> operator -(Vector2<N> other);
    void operator -=(Vector2<N> other);

    bool operator==(Vector2<N> other);

    template <FloatType M>
    operator Vector2<M>();
};

typedef Vector2<float> Vector2F;
typedef Vector2<double> Vector2D;