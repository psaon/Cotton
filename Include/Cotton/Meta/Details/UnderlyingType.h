#pragma once

#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__underlying_type)
    #define COTTON_BUILTIN_UNDERLYING_TYPE(type) __underlying_type(type)
#else
    #include <type_traits>
    #define COTTON_BUILTIN_UNDERLYING_TYPE(type) ::std::underlying_type_t<type>
#endif

namespace Cotton
{
    template<class T>
    using UnderlyingType = COTTON_BUILTIN_UNDERLYING_TYPE(T);
}
