#include "Common.hpp"

template<FloatType N> class Degree;
template<FloatType N> class Radian;

template<FloatType N> class Degree {
private:
    N angle = 0.0;

public:
    Degree() = default;
    explicit Degree(N angle) : angle(angle) {}
    ~Degree() = default;

    Radian<N> ToRadian();

    operator N() { return angle; }
};

template<FloatType N> class Radian {
private:
    N angle = 0.0;

public:
    Radian() = default;
    explicit Radian(N angle) : angle(angle) {}
    ~Radian() = default;

    Degree<N> ToDegree();

    operator N() { return angle; }
};

typedef Degree<float> FDegree;
typedef Radian<float> FRadian;