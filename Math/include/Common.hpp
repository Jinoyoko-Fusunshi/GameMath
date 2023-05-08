#pragma once

#include <type_traits>
#include <cstdint>

template<typename N>
concept FloatType = std::is_floating_point<N>::value;