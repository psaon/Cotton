#pragma once

#include "Cotton/Utility/Move.h"

namespace Cotton
{
    template<class T>
    constexpr void Swap(T& val1, T& val2)
    {
        T tmp = Move(val2);
        val2 = Move(val1);
        val1 = Move(tmp);
    }
}   // namespace Cotton
