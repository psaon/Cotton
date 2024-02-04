#pragma once

#include "Cotton/Core/Types.h"

#include "Cotton/Meta/Details/Comparisons.h"
#include "Cotton/Meta/Details/QualifierTransforms.h"

namespace Cotton
{
    template<class T>
    static constexpr bool IsVoid = IsSame<RemoveQualifiers<T>, void>;

    template<class T>
    static constexpr bool IsNullptr = IsSame<RemoveQualifiers<T>, NullptrType>;
}   // namespace Cotton
