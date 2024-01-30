#pragma once

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct RemoveConstHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveConstHelper<const T>
        {
            using Type = T;
        };

        template<class T>
        struct RemoveVolatileHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveVolatileHelper<volatile T>
        {
            using Type = T;
        };

        template<class T>
        struct RemoveConstVolatileHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveConstVolatileHelper<const volatile T>
        {
            using Type = T;
        };
    }   // namespace Internal

    template<class T>
    using AddConst = const T;

    template<class T>
    using AddVolatile = volatile T;

    template<class T>
    using AddConstVolatile = const volatile T;

    template<class T>
    using RemoveConst = Internal::RemoveConstHelper<T>::Type;

    template<class T>
    using RemoveVolatile = Internal::RemoveVolatileHelper<T>::Type;

    template<class T>
    using RemoveConstVolatile = Internal::RemoveConstVolatileHelper<T>::Type;

    template<class T>
    using RemoveQualifiers = RemoveConst<RemoveVolatile<T>>;
}   // namespace Cotton
