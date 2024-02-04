#pragma once

#include "Cotton/Meta/Details/TypeConstant.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T, class U>
        struct IsSameHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsSameHelper<T, T> : BoolConstant<true>
        {
        };

        template<class T, class... Rest>
        struct IsAnyOfHelper : BoolConstant<false>
        {
        };

        template<class T, class U>
        struct IsAnyOfHelper<T, U> : IsSameHelper<T, U>
        {
        };

        template<class T, class U, class... Rest>
        struct IsAnyOfHelper<T, U, Rest...>
            : BoolConstant<IsSameHelper<T, U>::Value || IsAnyOfHelper<T, Rest...>::Value>
        {
        };

    }   // namespace Internal

    template<class T, class U>
    static constexpr bool IsSame = Internal::IsSameHelper<T, U>::Value;

    template<class T, class... Rest>
    static constexpr bool IsAnyOf = Internal::IsAnyOfHelper<T, Rest...>::Value;

}   // namespace Cotton
