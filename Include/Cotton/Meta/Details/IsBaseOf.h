#pragma once

#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__is_base_of)
    #define COTTON_BUILTIN_IS_BASE_OF(base, derived) __is_base_of(base, derived)
#else
    #include <type_traits>
    #define COTTON_BUILTIN_IS_BASE_OF(base, derived) ::std::is_base_of_v<base, derived>
#endif

namespace Cotton
{
    template<class Base, class Derived>
    static constexpr bool IsBaseOf = COTTON_BUILTIN_IS_BASE_OF(Base, Derived);
}
