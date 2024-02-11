#pragma once

#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__is_trivially_assignable)
    #define COTTON_BUILTIN_IS_TRIVIALLY_ASSIGNABLE(from, to) \
        __is_trivially_assignable(from, to)

#else
    #include <type_traits>
    #define COTTON_BUILTIN_IS_TRIVIALLY_ASSIGNABLE(from, to) \
        ::std::is_trivially_assignable_v<from, to>
#endif

namespace Cotton
{
    template<class From, class To>
    static constexpr bool IsAssignable = requires(From from, To to) { from = to; };

    template<class From, class To>
    static constexpr bool IsTriviallyAssignable =
        COTTON_BUILTIN_IS_TRIVIALLY_ASSIGNABLE(From, To);

    template<class T>
    static constexpr bool IsCopyAssignable = IsAssignable<T&, const T&>;

    template<class T>
    static constexpr bool IsTriviallyCopyAssignable = IsTriviallyAssignable<T&, const T&>;

    template<class T>
    static constexpr bool IsMoveAssignable = IsAssignable<T&, T&&>;

    template<class T>
    static constexpr bool IsTriviallyMoveAssignable = IsTriviallyAssignable<T&, T&&>;

}   // namespace Cotton
