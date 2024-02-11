#pragma once

#include "Cotton/Meta/Details/Conditionals.h"
#include "Cotton/Meta/Details/ReferenceTransforms.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T, bool = requires(T* x) { x; }>
        struct AddPointerTypedef
        {
            using Type = T*;
        };

        template<class T>
        struct AddPointerTypedef<T, false>
        {
            using Type = T;
        };

        template<class T>
        struct AddPointerHelper : AddPointerTypedef<T>
        {
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
