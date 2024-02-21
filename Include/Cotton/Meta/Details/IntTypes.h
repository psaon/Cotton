#pragma once

#include "Cotton/Core/Types.h"

#define COTTON_DEFINE_SIGNED_TYPE_(size, bits) \
    template<>                                 \
    struct SignedIntTypeHelper<size>           \
    {                                          \
        using Type = Int##bits;                \
    }

#define COTTON_DEFINE_UNSIGNED_TYPE_(size, bits) \
    template<>                                   \
    struct UnsignedIntTypeHelper<size>           \
    {                                            \
        using Type = Uint##bits;                 \
    }

namespace Cotton
{
    namespace Internal
    {
        template<Usize N>
        struct SignedIntTypeHelper
        {
        };

        COTTON_DEFINE_SIGNED_TYPE_(1, 8);
        COTTON_DEFINE_SIGNED_TYPE_(2, 16);
        COTTON_DEFINE_SIGNED_TYPE_(4, 32);
        COTTON_DEFINE_SIGNED_TYPE_(8, 64);

        template<Usize N>
        struct UnsignedIntTypeHelper
        {
        };

        COTTON_DEFINE_UNSIGNED_TYPE_(1, 8);
        COTTON_DEFINE_UNSIGNED_TYPE_(2, 16);
        COTTON_DEFINE_UNSIGNED_TYPE_(4, 32);
        COTTON_DEFINE_UNSIGNED_TYPE_(8, 64);
    }   // namespace Internal

    template<Usize N>
    using SignedIntType = Internal::SignedIntTypeHelper<N>::Type;

    template<Usize N>
    using UnsignedIntType = Internal::UnsignedIntTypeHelper<N>::Type;
}   // namespace Cotton

#undef COTTON_DEFINE_SIGNED_TYPE_
#undef COTTON_DEFINE_UNSIGNED_TYPE_
