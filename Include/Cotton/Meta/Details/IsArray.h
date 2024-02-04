#pragma once

#include "Cotton/Core/Types.h"
#include "Cotton/Meta/Details/TypeConstant.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct IsBoundedArrayHelper : BoolConstant<false>
        {
        };

        template<class T, Usize N>
        struct IsBoundedArrayHelper<T[N]> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsUnboundedArrayHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsUnboundedArrayHelper<T[]> : BoolConstant<true>
        {
        };

    }   // namespace Internal

    template<class T>
    static constexpr bool IsBoundedArray = Internal::IsBoundedArrayHelper<T>::Value;

    template<class T>
    static constexpr bool IsUnboundedArray = Internal::IsUnboundedArrayHelper<T>::Value;

    template<class T>
    static constexpr bool IsArray = IsBoundedArray<T> || IsUnboundedArray<T>;
}   // namespace Cotton
