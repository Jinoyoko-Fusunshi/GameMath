#pragma once

#include "Common.hpp"
#include "Vector2.hpp"

template<FloatType N>
class Vector3 : public Vector2<N> {
protected:
    N z = 0.0;

public:
    Vector3() : Vector2<N>(), z(0) {}
    explicit Vector3(N x, N y, N z) : Vector2<N>(x, y), z(z) {}
    ~Vector3() = default;

    N DotProduct(Vector3<N> other);

    N GetZ() const { return z; }

    static Vector3<N> XUnitVector3() { return Vector3<N>(1.0, 0.0, 0.0); };
    static Vector3<N> YUnitVector3() { return Vector3<N>(0.0, 1.0, 0.0); };
    static Vector3<N> ZUnitVector3() { return Vector3<N>(0.0, 0.0, 1.0); };

    Vector3<N> operator +(Vector3<N> other);
    void operator +=(Vector3<N> other);

    Vector3<N> operator -(Vector3<N> other);
    void operator -=(Vector3<N> other);

    Vector3<N> operator*(N factor);
    void operator*=(N factor);

    bool operator==(Vector3<N> other);
};

typedef Vector3<float> Vector3F;