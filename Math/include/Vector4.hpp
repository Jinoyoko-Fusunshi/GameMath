#pragma once

#include "Common.hpp"
#include "Vector3.hpp"

template <FloatType N>
class Vector4 : public Vector3<N> {
private:
    N w = 0.0;

public:
    Vector4() : Vector3<N>(), w(0) {}
    explicit Vector4(N x, N y, N z, N w) : Vector3<N>(x, y, z), w(w) {}
    explicit Vector4(Vector3<N> base_vector, N w) : Vector3<N>(base_vector), w(w) {}
    ~Vector4() = default;

    N DotProduct(Vector4<N> other);

    N GetW() const { return w; }

    static Vector4<N> XUnitVector4() { return Vector4<N>(1.0, 0.0, 0.0, 0.0); };
    static Vector4<N> YUnitVector4() { return Vector4<N>(0.0, 1.0, 0.0, 0.0); };
    static Vector4<N> ZUnitVector4() { return Vector4<N>(0.0, 0.0, 1.0, 0.0); };
    static Vector4<N> WUnitVector4() { return Vector4<N>(0.0, 0.0, 0.0, 1.0); };

    Vector4<N> operator +(Vector4<N> other);
    void operator +=(Vector4<N> other);

    Vector4<N> operator -(Vector4<N> other);
    void operator -=(Vector4<N> other);

    Vector4<N> operator*(N factor);
    void operator*=(N factor);

    bool operator==(Vector4<N> other);

    template <FloatType M>
    operator Vector4<M>();
};

typedef Vector4<float> Vector4F;
typedef Vector4<double> Vector4D;
