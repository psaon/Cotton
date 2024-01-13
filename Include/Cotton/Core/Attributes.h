#pragma once

#include "Cotton/Core/Predefined.h"
#include "Cotton/Core/FeatureChecks.h"

// Specify that the function doesn't return a null pointer.
#if COTTON_HAS_GNU_ATTRIBUTE(returns_nonnull)
    #define COTTON_RETURNS_NONNULL __attribute__((returns_nonnull))
#else
    #define COTTON_RETURNS_NONNULL
#endif

// Forces the compiler to inline the specified function.
// Clang & GCC define __attribute__((always_inline))
// MSVC defines __forceinline
#if COTTON_HAS_GNU_ATTRIBUTE(always_inline)
    #define COTTON_FORCEINLINE __attribute__((always_inline))
#elif COTTON_COMPILER_MSVC
    #define COTTON_FORCEINLINE __forceinline
#else
    #define COTTON_FORCEINLINE inline
#endif

// Forces the compiler NOT to inline the specified function.
#if COTTON_HAS_GNU_ATTRIBUTE(noinline)
    #define COTTON_NOINLINE __attribute__((noinline))
#elif COTTON_HAS_DECLSPEC_ATTRIBUTE(noinline)
    #define COTTON_NOINLINE __declspec(noinline)
#endif

// Specify that the compiler cannot replace anything in the function body with builtins.
#if COTTON_HAS_GNU_ATTRIBUTE(no_builtin)
    #define COTTON_NO_BUILTIN __attribute__((no_builtin))
#else
    #define COTTON_NO_BUILTIN
#endif

// Forces the compiler not to optimize the specified function.
// Clang defines [[clang::optnone]]
// GCC defines __attribute__((optimize(x)))
#if COTTON_COMPILER_CLANG && COTTON_HAS_GNU_ATTRIBUTE(optnone)
    #define COTTON_NO_OPTIMIZE [[clang::optnone]]
#elif COTTON_COMPILER_GCC && COTTON_HAS_GNU_ATTRIBUTE(optimize)
    #define COTTON_NO_OPTIMIZE __attribute__((optimize(0)))
#else
    #define COTTON_NO_OPTIMIZE
#endif

// Informs the compiler that this function is unlikely to be executed.
#if COTTON_HAS_GNU_ATTRIBUTE(cold)
    #define COTTON_COLD __attribute__((cold))
#else
    #define COTTON_COLD
#endif

// Informs the compiler that this function is likely to be executed.
#if COTTON_HAS_GNU_ATTRIBUTE(hot)
    #define COTTON_HOT __attribute__((hot))
#else
    #define COTTON_HOT
#endif

// Specifies that a function is unavailable, and that the compiler
// should emit an error when the function is used.
#if COTTON_HAS_GNU_ATTRIBUTE(unavailable)
    #define COTTON_UNAVAILABLE(msg) __attribute__((unavailable(msg)))
#else
    // If no alternative attributes can be found, then we
    // can just emit a warning instead.
    #define COTTON_UNAVAILABLE(msg) [[deprecated(msg)]]
#endif

// Specifies that every call in the function body be inlined.
#if COTTON_HAS_GNU_ATTRIBUTE(flatten)
    #define COTTON_FLATTEN __attribute__((flatten))
#else
    #define COTTON_FLATTEN inline
#endif

// Specifies that a function is "malloc-like".
#if COTTON_HAS_GNU_ATTRIBUTE(malloc)
    #define COTTON_MALLOC_LIKE __attribute__((malloc))
#else
    #define COTTON_MALLOC_LIKE
#endif

// Specifies that a function is pure. (Does not depend
// on any state and returns the same result if the same arguments
// are passed)
#if COTTON_HAS_GNU_ATTRIBUTE(pure)
    #define COTTON_PURE __attribute__((pure))
#else
    #define COTTON_PURE
#endif

// Specifies that the compiler should generate code for the specified
// function, even though it might not be referenced.
#if COTTON_HAS_GNU_ATTRIBUTE(used)
    #define COTTON_USED __attribute__((used))
#else
    #define COTTON_USED
#endif

// Specifies that the specified function should be avoided, as it might
// be prone to buffer overflows.
#if COTTON_HAS_GNU_ATTRIBUTE(unsafe_buffer_usage)
    #define COTTON_UNSAFE_BUFFER_USAGE [[clang::unsafe_buffer_usage]]
#else
    #define COTTON_UNSAFE_BUFFER_USAGE
#endif

// Fix for MSVC ignoring [[no_unique_address]]
// Specifies that a member variable might be overlapping.
#if COTTON_COMPILER_MSVC
    #define COTTON_NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#else
    #define COTTON_NO_UNIQUE_ADDRESS [[no_unique_address]]
#endif
