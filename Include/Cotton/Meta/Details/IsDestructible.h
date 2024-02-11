#pragma once

#include "Cotton/Core/FeatureChecks.h"

#include "Cotton/Meta/Details/IsType.h"
#include "Cotton/Meta/Details/IsArray.h"
#include "Cotton/Meta/Details/IsFunction.h"
#include "Cotton/Meta/Details/IsReference.h"

#include "Cotton/Meta/Details/TypeConstant.h"
#include "Cotton/Meta/Details/ArrayTransforms.h"

#if COTTON_HAS_BUILTIN(__has_virtual_destructor)
    #define COTTON_BUILTIN_HAS_VIRTUAL_DESTRUCTOR(type) __has_virtual_destructor(type)
#else
    #include <type_traits>
    #define COTTON_BUILTIN_HAS_VIRTUAL_DESTRUCTOR(type) \
        ::std::has_virtual_destructor<type>
#endif

#if COTTON_HAS_BUILTIN(__is_trivially_destructible)
    #define COTTON_BUILTIN_IS_TRIVIALLY_DESTRUCTIBLE(type) \
        __is_trivially_destructible(type)

#elif COTTON_HAS_BUILTIN(__has_trivial_destructor)
    #define COTTON_BUILTIN_IS_TRIVIALLY_DESTRUCTIBLE(type) __has_trivial_destructor(type)
#else
    #include <type_traits>
    #define COTTON_BUILTIN_IS_TRIVIALLY_DESTRUCTIBLE(type) \
        ::std::has_virtual_destructor<type>
#endif

namespace Cotton
{
    namespace Internal
    {
        template<class T, bool Tester,
                 bool = IsVoid<T> || IsFunction<T> || IsUnboundedArray<T>>
        struct IsDestructibleHelper : BoolConstant<IsReference<T> || Tester>
        {
        };

        template<class T, bool Tester>
        struct IsDestructibleHelper<T, Tester, true> : BoolConstant<false>
        {
        };
    }   // namespace Internal

    template<class T>
    static constexpr bool IsDestructible = Internal::IsDestructibleHelper<T, []
    {
        using U = RemoveAllExtents<T>;
        return requires(U& x) { x.~U(); };
    }()>::Value;

    template<class T>
    static constexpr bool IsTriviallyDestructible =
        Internal::IsDestructibleHelper<T, COTTON_BUILTIN_IS_TRIVIALLY_DESTRUCTIBLE(
                                              T)>::Value;

    template<class T>
    static constexpr bool HasVirtualDestructor = COTTON_BUILTIN_HAS_VIRTUAL_DESTRUCTOR(T);
}   // namespace Cotton
