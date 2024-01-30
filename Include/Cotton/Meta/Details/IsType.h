#pragma once

#include "Cotton/Meta/Details/TypeConstant.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct IsVoidHelper : BoolConstant<false>
        {
        };

        template<>
        struct IsVoidHelper<void> : BoolConstant<true>
        {
        };

        template<>
        struct IsVoidHelper<const void> : BoolConstant<true>
        {
        };

        template<>
        struct IsVoidHelper<volatile void> : BoolConstant<true>
        {
        };

        template<>
        struct IsVoidHelper<const volatile void> : BoolConstant<true>
        {
        };
    }   // namespace Internal

    template<class T>
    static constexpr bool IsVoid = Internal::IsVoidHelper<T>::Value;
}   // namespace Cotton
