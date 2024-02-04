#pragma once

#include "Cotton/Meta/Details/IsFunction.h"
#include "Cotton/Meta/Details/TypeConstant.h"

#include "Cotton/Meta/Details/PointerTransforms.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct IsPointerHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsPointerHelper<T*> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsMemberPointerHelper : BoolConstant<false>
        {
        };

        template<class T, class U>
        struct IsMemberPointerHelper<T U::*> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsMemberFunctionPointerHelper : BoolConstant<false>
        {
        };

        template<class T, class U>
        struct IsMemberFunctionPointerHelper<T U::*> : BoolConstant<IsFunction<T>>
        {
        };
    }   // namespace Internal

    template<class T>
    static constexpr bool IsPointer =
        Internal::IsPointerHelper<RemoveQualifiers<T>>::Value;

    template<class T>
    static constexpr bool IsFunctionPointer =
        IsPointer<T> && IsFunction<RemovePointer<T>>;

    template<class T>
    static constexpr bool IsMemberPointer =
        Internal::IsMemberPointerHelper<RemoveQualifiers<T>>::Value;

    template<class T>
    static constexpr bool IsMemberFunctionPointer =
        Internal::IsMemberFunctionPointerHelper<RemoveQualifiers<T>>::Value;

    template<class T>
    static constexpr bool IsMemberObjectPointer =
        IsMemberPointer<T> && !IsMemberFunctionPointer<T>;

}   // namespace Cotton
