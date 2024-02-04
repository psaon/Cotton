#pragma once

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct AddPointerHelper
        {
            using Type = T*;
        };

        template<class T>
        struct AddPointerHelper<T&>
        {
            using Type = T*;
        };

        template<class T>
        struct AddPointerHelper<T&&>
        {
            using Type = T*;
        };

        template<class T>
        struct RemovePointerHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemovePointerHelper<T*>
        {
            using Type = T;
        };

        template<class T>
        struct RemoveAllPointersHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveAllPointersHelper<T*>
        {
            using Type = RemoveAllPointersHelper<T>::Type;
        };

        template<class T>
        struct RemoveAllPointersHelper<T* const>
        {
            using Type = RemoveAllPointersHelper<T>::Type;
        };

        template<class T>
        struct RemoveAllPointersHelper<T* volatile>
        {
            using Type = RemoveAllPointersHelper<T>::Type;
        };

        template<class T>
        struct RemoveAllPointersHelper<T* const volatile>
        {
            using Type = RemoveAllPointersHelper<T>::Type;
        };
    }   // namespace Internal

    template<class T>
    using AddPointer = Internal::AddPointerHelper<T>::Type;

    template<class T>
    using RemovePointer = Internal::RemovePointerHelper<T>::Type;

    template<class T>
    using RemoveAllPointers = Internal::RemoveAllPointersHelper<T>::Type;
}   // namespace Cotton
