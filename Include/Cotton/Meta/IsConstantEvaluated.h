#pragma once

#include <version>

#include "Cotton/Core/Predefined.h"
#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__is_constant_evaluated)
    #define COTTON_BUILTIN_IS_CONST_EVALUATED() __is_constant_evaluated()
#elif __cpp_if_consteval < 202106L
    #include <type_traits>
    #define COTTON_BUILTIN_IS_CONST_EVALUATED() ::std::is_constant_evaluated()
#endif

namespace Cotton
{
    constexpr bool IsConstantEvaluated()
    {
#if defined(COTTON_BUILTIN_IS_CONST_EVALUATED)
        return COTTON_BUILTIN_IS_CONST_EVALUATED();
#else
        if consteval
            return true;
        else
            return false;
#endif
    }
}   // namespace Cotton
