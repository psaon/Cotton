#pragma once

#include "Cotton/Meta/Details/IsArithmetic.h"

namespace Cotton
{
    template<class T>
    static constexpr bool IsSigned = (T(-1) < T(0)) && IsArithmetic<T>;

    template<class T>
    static constexpr bool IsUnsigned = !IsSigned<T> && IsArithmetic<T>;
}   // namespace Cotton
