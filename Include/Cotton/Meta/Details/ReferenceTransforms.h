#pragma once

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct AddLvalueReferenceHelper
        {
            using Type = T&;
        };

        template<>
        struct AddLvalueReferenceHelper<void>
        {
            using Type = void;
        };

        template<>
        struct AddLvalueReferenceHelper<const void>
        {
            using Type = const void;
        };

        template<>
        struct AddLvalueReferenceHelper<volatile void>
        {
            using Type = volatile void;
        };

        template<>
        struct AddLvalueReferenceHelper<const volatile void>
        {
            using Type = const volatile void;
        };

        template<class T>
        struct AddRvalueReferenceHelper
        {
            using Type = T&&;
        };

        template<>
        struct AddRvalueReferenceHelper<void>
        {
            using Type = void;
        };

        template<>
        struct AddRvalueReferenceHelper<const void>
        {
            using Type = const void;
        };

        template<>
        struct AddRvalueReferenceHelper<volatile void>
        {
            using Type = volatile void;
        };

        template<>
        struct AddRvalueReferenceHelper<const volatile void>
        {
            using Type = const volatile void;
        };

        template<class T>
        struct RemoveReferenceHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveReferenceHelper<T&>
        {
            using Type = T;
        };

        template<class T>
        struct RemoveReferenceHelper<T&&>
        {
            using Type = T;
        };
    }   // namespace Internal

    template<class T>
    using AddLvalueReference = Internal::AddLvalueReferenceHelper<T>::Type;

    template<class T>
    using AddRvalueReference = Internal::AddRvalueReferenceHelper<T>::Type;

    template<class T>
    using RemoveReference = Internal::RemoveReferenceHelper<T>::Type;
}   // namespace Cotton
