#pragma once

#include "Cotton/Meta/Details/TypeConstant.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct IsConstHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsConstHelper<const T> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsVolatileHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsVolatileHelper<volatile T> : BoolConstant<true>
        {
        };
    }   // namespace Internal

    template<class T>
    static constexpr bool IsConst = Internal::IsConstHelper<T>::Value;

    template<class T>
    static constexpr bool IsVolatile = Internal::IsVolatileHelper<T>::Value;

    template<class T>
    static constexpr bool IsConstVolatile = IsConst<T> && IsVolatile<T>;

    template<class T>
    static constexpr bool HasQualifiers = IsConst<T> || IsVolatile<T>;
}   // namespace Cotton
