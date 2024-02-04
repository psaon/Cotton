#pragma once

#include "Cotton/Meta/Details/IsType.h"
#include "Cotton/Meta/Details/TypeConstant.h"

namespace Cotton
{
    namespace Internal
    {
        template<class To>
        static void TestImplicitConversion(To);

        template<class From, class To, bool = IsVoid<From> || IsVoid<To>>
        struct IsImplicitlyConvertibleHelper : BoolConstant<IsVoid<From> && IsVoid<To>>
        {
        };

        // clang-format off
        //? The clang-format version used (17.0.6) parses this code very strangely..
        template<class From, class To>
        struct IsImplicitlyConvertibleHelper<From, To, false>
            : BoolConstant<requires(From& x) { TestImplicitConversion<To>(x); }>
        {
        };

        // clang-format on
    }   // namespace Internal

    template<class From, class To>
    static constexpr bool IsImplicitlyConvertible =
        Internal::IsImplicitlyConvertibleHelper<From, To>::Value;

    template<class From, class To>
    static constexpr bool IsExplicitlyConvertible =
        requires(From& from) { static_cast<To>(from); };
}   // namespace Cotton
