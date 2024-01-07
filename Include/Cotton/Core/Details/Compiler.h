#pragma once

//* ARM Compiler
#if defined(__CC_ARM)
    #define COTTON_COMPILER_ARM 1
    #define COTTON_COMPILER_NAME "ARM Compiler"

//* Borland C++ Compiler
#elif defined(__BORLANDC__)
    #define COTTON_COMPILER_BORLAND 1
    #define COTTON_COMPILER_NAME "Borland C++"

//* Clang Compiler
// "The meaning of the __clang__ and related macros has changed subtly over the years,
// from identifying the Clang compiler to identifying compilers that use the Clang infrastructure.
// For example, IBM XL C/C++ also defines these macros."
#elif defined(__clang__) && !defined(__ibmxl__)
    #define COTTON_COMPILER_CLANG 1
    #define COTTON_COMPILER_NAME "Clang"

//* GCC Compiler
// "Notice that the meaning of the __GNUC__ macro has changed subtly over the years,
// from identifying the GNU C/C++ compiler to identifying any compiler that implements the GNU compiler extensions.
// For example, the Intel C++ on Linux also defines these macros from version 8.1"
#elif defined(__GNUC__) && !(defined(__INTEL_COMPILER) || defined(__ICC) || defined(_ICL))
    #define COTTON_COMPILER_GCC 1
    #define COTTON_COMPILER_NAME "GNU C/C++"

//* Green Hills C/C++ Compiler
#elif defined(__ghs__)
    #define COTTON_COMPILER_GREENHILLS 1
    #define COTTON_COMPILER_NAME "Green Hills C/C++"

//* IBM XL C/C++ Compiler
#elif defined(__ibmxl__) || defined(__xlC__)
    #define COTTON_COMPILER_XLC 1
    #define COTTON_COMPILER_NAME "IBM XL C/C++"

//* Intel C/C++ Compiler
#elif defined(__INTEL_COMPILER) || defined(__ICC) || defined(_ICL)
    #define COTTON_COMPILER_INTEL 1
    #define COTTON_COMPILER_NAME "Intel C/C++"

//* Microsoft Visual C/C++
// "Intel's compiler also defines _MSC_VER and _MSC_FULL_VER on Windows.
// You can exclude it by checking that __INTEL_COMPILER is not defined."
#elif defined(_MSC_VER) && !defined(__INTEL_COMPILER)
    #define COTTON_COMPILER_MSVC 1
    #define COTTON_COMPILER_NAME "MSVC"

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
