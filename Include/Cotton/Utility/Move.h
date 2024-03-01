#pragma once

#include "Cotton/Meta/TypeTransforms.h"

namespace Cotton
{
    template<class T>
    [[nodiscard]]
    constexpr RemoveReference<T>&& Move(T&& val)
    {
        using RvalueT = RemoveReference<T>&&;
        return static_cast<RvalueT>(val);
    }
}   // namespace Cotton
