#pragma once

#include "Cotton/Core/Types.h"
#include "Cotton/Meta/Concepts.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        using AddRefCR = T&;

        template<class T>
        concept CanReference = requires { typename AddRefCR<T>; };
    }   // namespace Internal

    // clang-format off
    template<class It>
    concept ForwardIterator = requires(It it, const It const_it)
    {
        const_it == const_it;
        const_it != const_it;

        { ++it } -> SameAs<It&>;
        { it++ } -> SameAs<It>;

        { *it } -> Internal::CanReference;
    };

    template<class It>
    concept BidirectionalIterator =
        ForwardIterator<It> && requires (It it)
    {
        { --it } -> SameAs<It&>;
        { it-- } -> SameAs<It>;
    };

    template<class It>
    concept RandomAccessIterator =
        BidirectionalIterator<It> && requires (It it, const It const_it, Ptrdiff n)
    {
        { it += n } -> SameAs<It&>;
        { it -= n } -> SameAs<It&>;

        { const_it + n } -> SameAs<It>;
        { n + const_it } -> SameAs<It>;
        { const_it - n } -> SameAs<It>;

        const_it < const_it;
        const_it > const_it;

        const_it <= const_it;
        const_it >= const_it;
    };

    // clang-format on
}   // namespace Cotton
