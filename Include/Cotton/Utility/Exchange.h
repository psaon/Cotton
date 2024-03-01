#pragma once

#include "Cotton/Utility/Move.h"
#include "Cotton/Utility/Forward.h"

namespace Cotton
{
    template<class T, class U = T>
    constexpr T Exchange(T& obj, U&& new_val)
    {
        T old_val = Move(obj);
        obj = Forward<U>(new_val);

        return old_val;
    }
}   // namespace Cotton
