#pragma once

#include "Cotton/Core/FeatureChecks.h"

#include "Cotton/Meta/Details/Conversions.h"
#include "Cotton/Meta/Details/UnderlyingType.h"

#if COTTON_HAS_BUILTIN(__is_class) && COTTON_HAS_BUILTIN(__is_enum) && \
    COTTON_HAS_BUILTIN(__is_union)
    #define COTTON_BUILTIN_IS_CLASS(type) __is_class(type)
    #define COTTON_BUILTIN_IS_ENUM(type)  __is_enum(type)
    #define COTTON_BUILTIN_IS_UNION(type) __is_union(type)

#else
    #include <type_traits>

    #define COTTON_BUILTIN_IS_CLASS(type) ::std::is_class_v<type>
    #define COTTON_BUILTIN_IS_ENUM        ::std::is_enum_v<type>
    #define COTTON_BUILTIN_IS_UNION       ::std::is_union_v<type>
#endif

namespace Cotton
{
    template<class T>
    static constexpr bool IsClass = COTTON_BUILTIN_IS_CLASS(T);

    template<class T>
    static constexpr bool IsEnum = COTTON_BUILTIN_IS_ENUM(T);

    template<class T>
    static constexpr bool IsUnion = COTTON_BUILTIN_IS_UNION(T);

    // clang-format off
    //? The clang-format version used (17.0.6) parses this code very strangely..
    template<class T>
    static constexpr bool IsScopedEnum = requires
    {
        requires IsEnum<T>;
        requires !IsImplicitlyConvertible<T, UnderlyingType<T>>;
    };
    // clang-format on
}   // namespace Cotton
