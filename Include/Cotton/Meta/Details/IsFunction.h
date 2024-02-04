#pragma once

#include "Cotton/Meta/Details/IsQualifier.h"
#include "Cotton/Meta/Details/IsReference.h"

namespace Cotton
{
    template<class T>
    static constexpr bool IsFunction = !IsConst<const T> && !IsReference<T>;
}
