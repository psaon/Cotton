#pragma once

#include "Cotton/Meta/TypeTraits.h"
#include "Cotton/Meta/TypeTransforms.h"

namespace Cotton
{
    template<class T>
    [[nodiscard]]
    constexpr T&& Forward(RemoveReference<T>& val)
    {
        return static_cast<T&&>(val);
    }

    template<class T>
    [[nodiscard]]
    constexpr T&& Forward(RemoveReference<T>&& val)
    {
        static_assert(!IsLvalueReference<T>,
                      "Forward cannot be used to forward an lvalue as an rvalue.");
        return static_cast<T&&>(val);
    }
}   // namespace Cotton
