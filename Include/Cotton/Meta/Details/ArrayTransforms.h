#pragma once

#include "Cotton/Core/Types.h"

#include "Cotton/Meta/Details/IsType.h"
#include "Cotton/Meta/Details/Conditionals.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct RemoveExtentHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveExtentHelper<T[]>
        {
            using Type = T;
        };

        template<class T, Usize N>
        struct RemoveExtentHelper<T[N]>
        {
            using Type = T;
        };

        template<class T>
        struct RemoveAllExtentsHelper
        {
            using Type = T;
        };

        template<class T>
        struct RemoveAllExtentsHelper<T[]>
        {
            using Type = RemoveAllExtentsHelper<T>::Type;
        };

        template<class T, Usize N>
        struct RemoveAllExtentsHelper<T[N]>
        {
            using Type = RemoveAllExtentsHelper<T>::Type;
        };
    }   // namespace Internal

    template<class T>
    using RemoveExtent = Internal::RemoveExtentHelper<T>::Type;

    template<class T>
    using RemoveAllExtents = Internal::RemoveAllExtentsHelper<T>::Type;
}   // namespace Cotton
