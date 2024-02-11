#pragma once

#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__is_trivially_constructible)
    #define COTTON_HAS_BUILTIN_TRIVIALLY_CONSTRUCTIBLE_ 1
#else
    #define COTTON_HAS_BUILTIN_TRIVIALLY_CONSTRUCTIBLE_ 0
    #include <type_traits>
#endif

namespace Cotton
{
    template<class T, class... Args>
    static constexpr bool IsConstructible = requires(Args... args) { T(args...); };

    template<class T, class... Args>
    static constexpr bool IsTriviallyConstructible =
#if COTTON_HAS_BUILTIN_TRIVIALLY_CONSTRUCTIBLE_
        __is_trivially_constructible(T, Args...);
#else
        ::std::is_trivially_constructible_v<T, Args...>;
#endif

    template<class T>
    static constexpr bool IsDefaultConstructible = IsConstructible<T>;

    template<class T>
    static constexpr bool IsTriviallyDefaultConstructible = IsTriviallyConstructible<T>;

    template<class T>
    static constexpr bool IsCopyConstructible = IsConstructible<T, const T&>;

    template<class T>
    static constexpr bool IsTriviallyCopyConstructible =
        IsTriviallyConstructible<T, const T&>;

    template<class T>
    static constexpr bool IsMoveConstructible = IsConstructible<T, T&&>;

    template<class T>
    static constexpr bool IsTriviallyMoveConstructible = IsTriviallyConstructible<T, T&&>;
}   // namespace Cotton

#undef COTTON_HAS_BUILTIN_TRIVIALLY_CONSTRUCTIBLE_
