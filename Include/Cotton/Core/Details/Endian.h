#pragma once

#include "Cotton/Core/Details/Architecture.h"

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) ||   \
    defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || defined(_MIPSEB) || defined(__MIPSEB) ||       \
    defined(__MIPSEB__)

    #define COTTON_ENDIAN_BIG 1

#elif COTTON_ARCH_X86_FAMILY ||                                                 \
    (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||   \
    defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || defined(__THUMBEL__) || \
    defined(__AARCH64EB__) || defined(_MIPSEL) || defined(__MIPSEL) ||          \
    defined(__MIPSEL__)

    #define COTTON_ENDIAN_LITTLE 1

#else
    #define COTTON_ENDIAN_MIXED 1
#endif

#if !defined(COTTON_ENDIAN_BIG)
    #define COTTON_ENDIAN_BIG 0
#endif

#if !defined(COTTON_ENDIAN_LITTLE)
    #define COTTON_ENDIAN_LITTLE 0
#endif

#if !defined(COTTON_ENDIAN_MIXED)
    #define COTTON_ENDIAN_MIXED 0
#endif
