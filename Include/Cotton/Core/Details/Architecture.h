#pragma once

//* x86 family of architectures.
/*
 * Intel x86_32 Architecture
 * i386, __i386          is defined by GCC
 * __i386__ --> __i686__ is defined by GCC
 * _M_IX86               is defined by MSVC, Intel C++, Digital Mars, and Watcom C/C++
 * _M_I386               is defined by Watcom C/C++
 */
#if defined(i386) || defined(__i386) ||                                                 \
    defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || \
    defined(_M_IX86) || defined(_M_I386)

    #define COTTON_ARCH_X86_32 1
    #define COTTON_ARCH_X86_FAMILY 1
    #define COTTON_ARCH_NAME "x86_32"

    #define COTTON_ARCH_32_BITS 1

/*
 * AMD64/x86_64 Architecture
 * __amd64__, __amd64, __x86_64, and __x86_64__ is defined by GCC
 * _M_X64 and _M_AMD64                          is defined by MSVC
 */
#elif defined(__amd64__) || defined(__amd64) || defined(__x86_64) || defined(__x86_64__) || \
      defined(_M_X64) || defined(_M_AMD64)

    #define COTTON_ARCH_X86_64 1
    #define COTTON_ARCH_X86_FAMILY 1
    #define COTTON_ARCH_NAME "x86_64"

    #define COTTON_ARCH_64_BITS 1

//* ARM family of architectures.
/*
 * ARM Architecture (32-bits)
 * __arm__           is defined by GCC
 * __arm             is defined by Diab/Wind River
 * __TARGET_ARCH_ARM is defined by RealView
 * _M_ARM            is defined by MSVC
 */
#elif defined(__arm__) || defined(__arm) || defined(__TARGET_ARCH_ARM) || \
      defined(_M_ARM)

    #define COTTON_ARCH_ARM32 1
    #define COTTON_ARCH_ARM_FAMILY 1

    #define COTTON_ARCH_32_BITS 1

    #if defined(__ARM_ARCH_2__)
        #define COTTON_ARCH_ARM2 1
        #define COTTON_ARCH_NAME "ARM2"

    #elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
        #define COTTON_ARCH_ARM3 1
        #define COTTON_ARCH_NAME "ARM3"

    #elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
        #define COTTON_ARCH_ARM4T 1
        #define COTTON_ARCH_NAME "ARM4T"

    #elif defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E__) || \
          (_M_ARM == 5)

        #define COTTON_ARCH_ARM5 1
        #define COTTON_ARCH_NAME "ARM5"

    #elif defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__)
        #define COTTON_ARCH_ARM5T 1
        #define COTTON_ARCH_NAME "ARM5T"

    #elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) ||  \
          defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || \
          defined(__ARM_ARCH_6ZK__) ||                            \
          (_M_ARM == 6)

        #define COTTON_ARCH_ARM6 1
        #define COTTON_ARCH_NAME "ARM6"

    #elif defined(__ARM_ARCH_6T2__)
        #define COTTON_ARCH_ARM6T2 1
        #define COTTON_ARCH_NAME "ARM6T2"

    #elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7M__) || \
          defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7S__) ||                            \
          (_M_ARM == 7)

        #define COTTON_ARCH_ARM7 1
        #define COTTON_ARCH_NAME "ARM7"

    #else
        #define COTTON_ARCH_NAME "ARM"
    #endif

/*
 * ARM64 Architecture
 * __aarch64__ is defined by GCC
 * _M_ARM64    is defined by MSVC
 */
#elif defined(__aarch64__) || defined(_M_ARM64)
    #define COTTON_ARCH_ARM64 1
    #define COTTON_ARCH_ARM_FAMILY 1

    #define COTTON_ARCH_64_BITS 1

    #define COTTON_ARCH_NAME "ARM64"

/*
 * Itanium Architecture (IA-64)
 * __ia64__, _IA64, and __IA64__ is defined by GCC
 * _M_IA64                       is defined by MSVC
 * __itanium                     is defined by Intel C++
 */
#elif defined(__ia64__) || defined(_IA64) || defined(__IA64__) || \
      defined(_M_IA64) || defined(__itanium__)
    #define COTTON_ARCH_IA64 1
    #define COTTON_ARCH_ITANIUM_FAMILY 1

    #define COTTON_ARCH_64_BITS 1
    #define COTTON_ARCH_NAME "IA-64"

/*
 * RISC-V Architecture
 * __riscv__ is defined by older toolchains of GCC
 */
#elif defined(__riscv) || defined(__riscv__)
    #define COTTON_ARCH_RISCV 1

    #if defined(__riscv_len)
        #if (__riscv_len == 32)
            #define COTTON_ARCH_RISCV32 1
            #define COTTON_ARCH_32_BITS 1
            #define COTTON_ARCH_NAME "RV32"

        #elif (__riscv_len == 64)
            #define COTTON_ARCH_RISCV64 1
            #define COTTON_ARCH_64_BITS 1
            #define COTTON_ARCH_NAME "RV64"

        #else
            #error Cannot identify the architecture targeted.
        #endif
    #endif

/*
 * PowerPC (32-bits) Architecture
 * __powerpc__ and __ppc__ is defined by GCC
 * _ARCH_PPC               is defined by GCC and XL C/C++
 */
#elif defined(__powerpc__) || defined(__ppc__) || defined(_ARCH_PPC)
    #define COTTON_ARCH_POWERPC 1

    #define COTTON_ARCH_POWERPC32 1
    #define COTTON_ARCH_NAME "PowerPC32"

    #define COTTON_ARCH_32_BITS 1

/*
 * PowerPC (64-bits) Architecture
 * __powerpc64__ and __ppc64__ is defined by GCC
 * _ARCH_PPC64                 is defined by GCC and XL C/C++
 */
#elif defined(__powerpc64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
    #define COTTON_ARCH_POWERPC 1

    #define COTTON_ARCH_POWERPC64
    #define COTTON_ARCH_NAME "PowerPC64"

    #define COTTON_ARCH_64_BITS 1

/*
 * MIPS Architecture
 * __mips__ and mips is defined by GCC
 * __MIPS__          is defined by Metroworks
 */
#elif defined(__mips__) || defined(__MIPS__) || defined(mips) || defined(__mips64) || defined(__mips64__)
    #define COTTON_ARCH_MIPS 1

    #if defined(_MIPS_SIM)
        #if defined(__mips64) || defined(__mips64__) || (_MIPS_SIM == _ABI64)
            #define COTTON_ARCH_MIPS64 1
            #define COTTON_ARCH_NAME "MIPS64"

            #define COTTON_ARCH_64_BITS 1

        #else
            #define COTTON_ARCH_MIPS32 1
            #define COTTON_ARCH_NAME "MIPS32"

            #define COTTON_ARCH_32_BITS 1
        #endif
    #else
        #error Cannot identify the architecture targeted.
    #endif

/*
 * DEC Alpha Architecture
 * __alpha__ is defined by GCC
 * __alpha   is defined by DEC C
 * _M_ALPHA  is defined by MSVC
 */
#elif defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
    #define COTTON_ARCH_ALPHA 1
    #define COTTON_ARCH_64_BITS 1

    #define COTTON_ARCH_NAME "Alpha"

#else
    #error Cannot identify the architecture targeted.
#endif

//* !X86_32
#if !defined(COTTON_ARCH_X86_32)
    #define COTTON_ARCH_X86_32 0
#endif

//* !X86_64
#if !defined(COTTON_ARCH_X86_64)
    #define COTTON_ARCH_X86_64 0
#endif

//* !X86
#if !defined(COTTON_ARCH_X86_FAMILY)
    #define COTTON_ARCH_X86_FAMILY 0
#endif

//* !ARM32
#if !defined(COTTON_ARCH_ARM32)
    #define COTTON_ARCH_ARM32 0
#endif

#if !defined(COTTON_ARCH_ARM2)
    #define COTTON_ARCH_ARM2 0
#endif

#if !defined(COTTON_ARCH_ARM3)
    #define COTTON_ARCH_ARM3 0
#endif

#if !defined(COTTON_ARCH_ARM4T)
    #define COTTON_ARCH_ARM4T 0
#endif

#if !defined(COTTON_ARCH_ARM5)
    #define COTTON_ARCH_ARM5 0
#endif

#if !defined(COTTON_ARCH_ARM5T)
    #define COTTON_ARCH_ARM5T 0
#endif

#if !defined(COTTON_ARCH_ARM6)
    #define COTTON_ARCH_ARM6 0
#endif

#if !defined(COTTON_ARCH_ARM6T2)
    #define COTTON_ARCH_ARM6T2 0
#endif

#if !defined(COTTON_ARCH_ARM7)
    #define COTTON_ARCH_ARM7 0
#endif

//* !ARM64
#if !defined(COTTON_ARCH_ARM64)
    #define COTTON_ARCH_ARM64 0
#endif

//* !ARM
#if !defined(COTTON_ARCH_ARM_FAMILY)
    #define COTTON_ARCH_ARM_FAMILY 0
#endif

//* !IA64
#if !defined(COTTON_ARCH_IA64)
    #define COTTON_ARCH_IA64 0
#endif

#if !defined(COTTON_ARCH_ITANIUM_FAMILY)
    #define COTTON_ARCH_ITANIUM_FAMILY 0
#endif

//* !RISC_V
#if !defined(COTTON_ARCH_RISCV)
    #define COTTON_ARCH_RISCV 0
#endif

#if !defined(COTTON_ARCH_RISCV32)
    #define COTTON_ARCH_RISCV32 0
#endif

#if !defined(COTTON_ARCH_RISCV64)
    #define COTTON_ARCH_RISCV64 0
#endif

//* PPC
#if !defined(COTTON_ARCH_POWERPC)
    #define COTTON_ARCH_POWERPC 0
#endif

#if !defined(COTTON_ARCH_POWERPC32)
    #define COTTON_ARCH_POWERPC32 0
#endif

#if !defined(COTTON_ARCH_POWERPC64)
    #define COTTON_ARCH_POWERPC64 0
#endif

//* MIPS
#if !defined(COTTON_ARCH_MIPS)
    #define COTTON_ARCH_MIPS 0
#endif

#if !defined(COTTON_ARCH_MIPS32)
    #define COTTON_ARCH_MIPS32 0
#endif

#if !defined(COTTON_ARCH_MIPS64)
    #define COTTON_ARCH_MIPS64 0
#endif

//* Alpha
#if !defined(COTTON_ARCH_ALPHA)
    #define COTTON_ARCH_ALPHA 0
#endif

//* Miscellaneous
#if !defined(COTTON_ARCH_32_BITS)
    #define COTTON_ARCH_32_BITS 0
#endif

#if !defined(COTTON_ARCH_64_BITS)
    #define COTTON_ARCH_64_BITS 0
#endif
