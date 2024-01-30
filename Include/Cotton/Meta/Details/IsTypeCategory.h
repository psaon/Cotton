#pragma once

#include "Cotton/Core/Types.h"
#include "Cotton/Meta/Details/TypeConstant.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct IsReferenceHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsReferenceHelper<T&> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsReferenceHelper<T&&> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsArrayHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsArrayHelper<T[]> : BoolConstant<true>
        {
        };

        template<class T, Usize N>
        struct IsArrayHelper<T[N]> : BoolConstant<true>
        {
        };
    }   // namespace Internal

    template<class T>
    static constexpr bool IsReference = Internal::IsReferenceHelper<T>::Value;

    template<class T>
    static constexpr bool IsArray = Internal::IsArrayHelper<T>::Value;
}   // namespace Cotton
