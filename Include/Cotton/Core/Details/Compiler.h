#pragma once

//* ARM Compiler
#if defined(__CC_ARM)
    #define COTTON_COMPILER_ARM  1
    #define COTTON_COMPILER_NAME "ARM Compiler"

    // __ARMCC_VERSION's format is [Mmmppxx],
    // where:
    // X = Reserved for ARM internal use
    #define COTTON_ARMCC_MAJOR_VERSION (__ARMCOMPILER_VERSION / 100'000)
    #define COTTON_ARMCC_MINOR_VERSION ((__ARMCOMPILER_VERSION % 1'000'000) / 10'000)
    #define COTTON_ARMCC_PATCH_VERSION ((__ARMCOMPILER_VERSION % 10'000) / 100)

//* Borland C++ Compiler
#elif defined(__BORLANDC__)
    #define COTTON_COMPILER_BORLAND 1
    #define COTTON_COMPILER_NAME    "Borland C++"

//* Clang Compiler
// "The meaning of the __clang__ and related macros has changed subtly over the years,
// from identifying the Clang compiler to identifying compilers that use the Clang
// infrastructure. For example, IBM XL C/C++ also defines these macros."
#elif defined(__clang__) && !defined(__ibmxl__)
    #define COTTON_COMPILER_CLANG 1
    #define COTTON_COMPILER_NAME  "Clang"

    #define COTTON_CLANG_MAJOR_VERSION __clang_major__
    #define COTTON_CLANG_MINOR_VERSION __clang_minor__
    #define COTTON_CLANG_PATCH_VERSION __clang_patchlevel__

//* GCC Compiler
// "Notice that the meaning of the __GNUC__ macro has changed subtly over the years,
// from identifying the GNU C/C++ compiler to identifying any compiler that implements the
// GNU compiler extensions. For example, the Intel C++ on Linux also defines these macros
// from version 8.1"
#elif defined(__GNUC__) && !(defined(__INTEL_COMPILER) || defined(__ICC) || defined(_ICL))
    #define COTTON_COMPILER_GCC  1
    #define COTTON_COMPILER_NAME "GNU C/C++"

    #define COTTON_GCC_MAJOR_VERSION __GNUC__
    #define COTTON_GCC_MINOR_VERSION __GNUC_MINOR__
    #define COTTON_GCC_PATCH_VERSION __GNUC_PATCHLEVEL__

//* Green Hills C/C++ Compiler
#elif defined(__ghs__)
    #define COTTON_COMPILER_GREENHILLS      1
    #define COTTON_COMPILER_NAME            "Green Hills C/C++"

    // __GHS_VERSION_NUMBER__ is formatted:
    // [Mmp]
    #define COTTON_GREENHILLS_MAJOR_VERSION ((__GHS_VERSION_NUMBER__) / 100)
    #define COTTON_GREENHILLS_MINOR_VERSION (((__GHS_VERSION_NUMBER__ % 100)) / 10)
    #define COTTON_GREENHILLS_MINOR_VERSION ((__GHS_VERSION_NUMBER__) % 10)

//* IBM XL C/C++ Compiler
#elif defined(__ibmxl__) || defined(__xlC__)
    #define COTTON_COMPILER_XLC  1
    #define COTTON_COMPILER_NAME "IBM XL C/C++"

    #define COTTON_XLC_MAJOR_VERSION __ibmxl_version__
    #define COTTON_XLC_MINOR_VERSION __ibmxl_release__
    #define COTTON_XLC_PATCH_VERSION __ibmxl_modification__

//* Intel C/C++ Compiler
#elif defined(__INTEL_COMPILER) || defined(__ICC) || defined(_ICL)
    #define COTTON_COMPILER_INTEL 1
    #define COTTON_COMPILER_NAME  "Intel C/C++"

    // Intel changed their version format from [M.m.p] to [Y.m.x],
    // shown by Intel C++ 19.1 --> Intel C++ 2021.1.2
    // Where:
    // Y = Year
    // m = Minor
    // x = ???
    #if __INTEL_COMPILER >= 2021
        #define COTTON_INTELCC_MAJOR_VERSION __INTEL_COMPILER
        #define COTTON_INTELCC_MINOR_VERSION __INTEL_COMPILER_UPDATE
        #define COTTON_INTELCC_PATCH_VERSION 0
    #else
        #define COTTON_INTELCC_MAJOR_VERSION (__INTEL_COMPILER / 100)
        #define COTTON_INTELCC_MINOR_VERSION (__INTEL_COMPILER % 100)
        #define COTTON_INTELCC_PATCH_VERSION __INTEL_COMPILER_UPDATE
    #endif

//* Microsoft Visual C/C++
// "Intel's compiler also defines _MSC_VER and _MSC_FULL_VER on Windows.
// You can exclude it by checking that __INTEL_COMPILER is not defined."
#elif defined(_MSC_VER) && !defined(__INTEL_COMPILER)
    #define COTTON_COMPILER_MSVC 1
    #define COTTON_COMPILER_NAME "MSVC"

    // >= VC++ 6.0 SP6
    #if defined(_MSC_FULL_VER)
        // < VC++ 8.0
        // [MMmmpppp]
        #if _MSC_VER < 1400
            #define COTTON_MSVC_MAJOR_VERSION (_MSC_FULL_VER / 1'000'000)
            #define COTTON_MSVC_MINOR_VERSION ((_MSC_FULL_VER % 1'000'000) / 10'000)
            #define COTTON_MSVC_PATCH_VERSION (_MSC_FULL_VER % 10'000)

        // >= VC++ 8.0
        // [MMmmppppp]
        // From VC++ 8.0, _MSC_FULL_VER will encode one extra digit in it's patch version.
        #else
            #define COTTON_MSVC_MAJOR_VERSION (_MSC_FULL_VER / 10'000'000)
            #define COTTON_MSVC_MINOR_VERSION ((_MSC_FULL_VER % 10'000'000) / 100'000)
            #define COTTON_MSVC_PATCH_VERSION (_MSC_FULL_VER % 100'000)
        #endif

    // < VC++ 6.0 SP6
    // [MMmm]
    #else
        #define COTTON_MSVC_MAJOR_VERSION (_MSC_VER / 100)
        #define COTTON_MSVC_MINOR_VERSION (_MSC_VER % 100)
        #define COTTON_MSVC_PATCH_VERSION 0
    #endif

#else
    #error Cannot determine compiler.
#endif

//* !ARM
#if !defined(COTTON_COMPILER_ARM)
    #define COTTON_COMPILER_ARM 0
#endif

//* !BORLAND
#if !defined(COTTON_COMPILER_BORLAND)
    #define COTTON_COMPILER_BORLAND 0
#endif

//* !CLANG
#if !defined(COTTON_COMPILER_CLANG)
    #define COTTON_COMPILER_CLANG 0
#endif

//* !GCC
#if !defined(COTTON_COMPILER_GCC)
    #define COTTON_COMPILER_GCC 0
#endif

//* !GREENHILLS
#if !defined(COTTON_COMPILER_GREENHILLS)
    #define COTTON_COMPILER_GREENHILLS 0
#endif

//* !XLC
#if !defined(COTTON_COMPILER_XLC)
    #define COTTON_COMPILER_XLC 0
#endif

//* Intel
#if !defined(COTTON_COMPILER_INTEL)
    #define COTTON_COMPILER_INTEL 0
#endif

//* MSVC
#if !defined(COTTON_COMPILER_MSVC)
    #define COTTON_COMPILER_MSVC 0
#endif
