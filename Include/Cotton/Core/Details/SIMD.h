#pragma once

#include "Cotton/Core/Details/Architecture.h"

//* x86-specific SIMD Instruction Sets
//* Intel MMX SIMD Instruction Set
#if defined(__MMX__) && __MMX__
    #define COTTON_ARCH_HAS_MMX 1
#else
    #define COTTON_ARCH_HAS_MMX 0
#endif

//* Intel SSE, SSE2, SSSE3, SSE4.1, SSE4.2, SSE4a SIMD Instruction Sets
#if defined(__SSE__) && __SSE__
    #define COTTON_ARCH_HAS_SSE 1
#else
    #define COTTON_ARCH_HAS_SSE 0
#endif

#if defined(__SSE2__) && __SSE2__
    #define COTTON_ARCH_HAS_SSE2 1
#else
    #define COTTON_ARCH_HAS_SSE2 0
#endif

#if defined(__SSE3__) && __SSE3__
    #define COTTON_ARCH_HAS_SSE3 1
#else
    #define COTTON_ARCH_HAS_SSE3 0
#endif

#if defined(__SSSE3__) && __SSSE3__
    #define COTTON_ARCH_HAS_SSSE3 1
#else
    #define COTTON_ARCH_HAS_SSSE3 0
#endif

#if defined(__SSE4_1__) && __SSE4_1__
    #define COTTON_ARCH_HAS_SSE4_1 1
#else
    #define COTTON_ARCH_HAS_SSE4_1 0
#endif

#if defined(__SSE4_2__) && __SSE4_2__
    #define COTTON_ARCH_HAS_SSE4_2 1
#else
    #define COTTON_ARCH_HAS_SSE4_2 0
#endif

#if defined(__SSE4A__) && __SSE4A__
    #define COTTON_ARCH_HAS_SSE4A 1
#else
    #define COTTON_ARCH_HAS_SSE4A 0
#endif

//* AMD 3DNow! SIMD Instruction Set
//* (Deprecated)
#if defined(__3dNOW__)
    #define COTTON_ARCH_HAS_3DNOW 1
#else
    #define COTTON_ARCH_HAS_3DNOW 0
#endif

//* Intel AVX, AVX2, AVX512,
//* AVX512F, AVX512BW, AVX512CD, AVX512DQ, AVX512VL Instruction Sets
#if defined(__AVX__)
    #define COTTON_ARCH_HAS_AVX 1
#else
    #define COTTON_ARCH_HAS_AVX 0
#endif

#if defined(__AVX2__)
    #define COTTON_ARCH_HAS_AVX2 1
#else
    #define COTTON_ARCH_HAS_AVX2 0
#endif

#if defined(__AVX512F__)
    #define COTTON_ARCH_HAS_AVX512 1
#else
    #define COTTON_ARCH_HAS_AVX512 0
#endif

#if defined(__AVX512BW__)
    #define COTTON_ARCH_HAS_AVX512BW 1
#else
    #define COTTON_ARCH_HAS_AVX512BW 0
#endif

#if defined(__AVX512CD__)
    #define COTTON_ARCH_HAS_AVX512CD 1
#else
    #define COTTON_ARCH_HAS_AVX512CD 0
#endif

#if defined(__AVX512DQ__)
    #define COTTON_ARCH_HAS_AVX512DQ 1
#else
    #define COTTON_ARCH_HAS_AVX512DQ 0
#endif

#if defined(__AVX512VL__)
    #define COTTON_ARCH_HAS_AVX512VL 1
#else
    #define COTTON_ARCH_HAS_AVX512VL 0
#endif

//* ARM-specific Instruction Sets
//* ARM NEON Instruction Set
#if defined(__ARM_NEON__) && __ARM_NEON__
    #define COTTON_ARCH_HAS_NEON 1
#else
    #define COTTON_ARCH_HAS_NEON 0
#endif
