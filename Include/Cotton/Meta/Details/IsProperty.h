#pragma once

#include "Cotton/Core/FeatureChecks.h"

#include "Cotton/Meta/Details/IsCategory.h"
#include "Cotton/Meta/Details/IsReference.h"

#include "Cotton/Meta/Details/IsType.h"
#include "Cotton/Meta/Details/IsArithmetic.h"

#include "Cotton/Meta/Details/IsPointer.h"
#include "Cotton/Meta/Details/IsArray.h"

#if COTTON_HAS_BUILTIN(__is_empty) && COTTON_HAS_BUILTIN(__is_final) && \
    COTTON_HAS_BUILTIN(__is_abstract)
    #define COTTON_BUILTIN_IS_FINAL(type)    __is_final(type)
    #define COTTON_BUILTIN_IS_EMPTY(type)    __is_empty(type)
    #define COTTON_BUILTIN_IS_ABSTRACT(type) __is_abstract(type)

#else
    #include <type_traits>

    #define COTTON_BUILTIN_IS_FINAL(type)    ::std::is_final_v<type>
    #define COTTON_BUILTIN_IS_EMPTY(type)    ::std::is_empty_v<type>
    #define COTTON_BUILTIN_IS_ABSTRACT(type) ::std::is_abstract_v<type>
#endif

namespace Cotton
{
    template<class T>
    static constexpr bool IsEmpty = COTTON_BUILTIN_IS_EMPTY(T);

    template<class T>
    static constexpr bool IsFinal = COTTON_BUILTIN_IS_FINAL(T);

    template<class T>
    static constexpr bool IsAbstract = COTTON_BUILTIN_IS_ABSTRACT(T);

    template<class T>
    static constexpr bool IsFundamental = IsArithmetic<T> || IsVoid<T> || IsNullptr<T>;

    template<class T>
    static constexpr bool IsScalar = IsArithmetic<T> || IsEnum<T> || IsPointer<T> ||
                                     IsMemberPointer<T> || IsNullptr<T>;

    template<class T>
    static constexpr bool IsObject =
        IsScalar<T> || IsArray<T> || IsUnion<T> || IsClass<T>;

    template<class T>
    static constexpr bool IsCompound = !IsFundamental<T>;

    // clang-format off
    //? The clang-format version used (17.0.6) parses this code very strangely..
    template<class T>
    static constexpr bool IsPolymorphic =
        !IsReference<T> && !IsUnion<T> &&
        requires(T* ptr)
        {
            // dynamic_cast needs a polymorphic type passed into it or else
            // it will throw a compile error.
            dynamic_cast<const volatile void*>(ptr);
        };

    // clang-format on
}   // namespace Cotton
