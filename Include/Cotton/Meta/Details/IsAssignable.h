#pragma once

#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__is_trivially_assignable)
    #define COTTON_BUILTIN_IS_TRIVIALLY_ASSIGNABLE(to, from) \
        __is_trivially_assignable(to, from)

#else
    #include <type_traits>
    #define COTTON_BUILTIN_IS_TRIVIALLY_ASSIGNABLE(to, from) \
        ::std::is_trivially_assignable_v<to, from>
#endif

namespace Cotton
{
    template<class To, class From>
    static constexpr bool IsAssignable = requires(To to, From from) { to = from; };

    template<class To, class From>
    static constexpr bool IsTriviallyAssignable =
        COTTON_BUILTIN_IS_TRIVIALLY_ASSIGNABLE(To, From);

    template<class T>
    static constexpr bool IsCopyAssignable = IsAssignable<T&, const T&>;

    template<class T>
    static constexpr bool IsTriviallyCopyAssignable = IsTriviallyAssignable<T&, const T&>;

    template<class T>
    static constexpr bool IsMoveAssignable = IsAssignable<T&, T&&>;

    template<class T>
    static constexpr bool IsTriviallyMoveAssignable = IsTriviallyAssignable<T&, T&&>;

}   // namespace Cotton
