#pragma once

#include <cstddef>
#include <cstdint>
#include <climits>

#include "Cotton/Core/Predefined.h"

namespace Cotton
{
    //* Fixed-width integers
    // Assuming that CHAR_BIT is equal to 8.
    using Int8 = signed char;
    using Uint8 = unsigned char;

// MSVC provides fixed-size integer types with the __intN type specifier.
#if COTTON_COMPILER_MSVC
    using Int16 = __int16;
    using Int32 = __int32;
    using Int64 = __int64;

    using Uint16 = unsigned __int16;
    using Uint32 = unsigned __int32;
    using Uint64 = unsigned __int64;

#else
    #if USHRT_MAX == 0xffff
    using Int16 = short;
    using Uint16 = unsigned short;
    #elif UINT_MAX == 0xffff
    using Int16 = int;
    using Uint16 = unsigned int;
    #else
        #error Cannot determine type to use for Int16 and Uint16.
    #endif

    #if UINT_MAX == 0xffffffff
    using Int32 = int;
    using Uint32 = unsigned int;
    #elif ULONG_MAX == 0xffffffff
    using Int32 = long;
    using Uint32 = unsigned long;
    #else
        #error Cannot determine type to use for Int32 and Uint32.
    #endif

    #if ULLONG_MAX == 0xffffffffffffffff
    using Int64 = signed long long;
    using Uint64 = unsigned long long;
    #elif ULONG_MAX == 0xffffffffffffffff
    using Int64 = signed long;
    using Uint64 = unsigned long;
    #else
        #error Cannot determine type to use for Int64 and Uint64.
    #endif
#endif

//* Pointer Arithmetic Types
// __SIZEOF_POINTER__ is defined by GCC
// __sizeof_ptr       is defined by ARM Compiler
#if defined(__SIZEOF_POINTER__)
    #define COTTON_SIZEOF_POINTER __SIZEOF_POINTER__
#elif defined(__sizeof_ptr)
    #define COTTON_SIZEOF_POINTER __sizeof_ptr

// Windows 64-bit uses the LLP64 data model.
// __LP64__ is defined by GCC
// _LP64    is defined by Sun Studio and HP aCC
#elif defined(__LP64__) || defined(_LP64) || defined(_WIN64)
    #define COTTON_SIZEOF_POINTER 8

// _ILP32           is defined by Sun Studio and HP aCC
// __ILP32__        is defined by GCC
// __fourbyteints__ is defined by MPW and Metrowerks on
// Motorola 68k targets when configured to use 32-bit int
#elif defined(_ILP32) || defined(__ILP32__) || \
    (defined(__fourbyteints__) && __fourbyteints__) ||
    (defined(_WIN32) &&
     !defined(_WIN64))   // Make it clear that we're checking for 32-bits.
    #define COTTON_SIZEOF_POINTER 4

#else
    #error Cannot determine pointer size.
#endif

#if defined(INTPTR_MAX) && defined(UINTPTR_MAX)
    using Intptr = ::std::intptr_t;
    using Uintptr = ::std::uintptr_t;

#elif COTTON_SIZEOF_POINTER == 8
    using Intptr = Int64;
    using Uintptr = Uint64;

#elif COTTON_SIZEOF_POINTER == 4
    using Intptr = Int32;
    using Uintptr = Uint32;

#elif COTTON_SIZEOF_POINTER == 2
        using Intptr = Int16;
    using Uintptr = Uint16;

#else
    #error Cannot determine types to use for Intptr and Uintptr.
#endif

    //* Pointer Checking Types
    // Specify that whoever owns this 'Owner' object is responsible for freeing
    // it. Purely syntactical, doesn't affect runtime.
    template<class T>
    using Owner = T;

    // The type of nullptr. Equivalent to ::std::nullptr_t.
    using NullptrType = decltype(nullptr);

    //* Miscellaneous Types
    using Usize = ::std::size_t;
    using Index = ::std::ptrdiff_t;

    using Ptrdiff = ::std::ptrdiff_t;

#if SIZE_MAX == 0xffffffffffffffff
    using Ssize = Int64;
#elif SIZE_MAX == 0xffffffff
    using Ssize = Int32;
#elif SIZE_MAX == 0xffff
    using Ssize = Int16;
#else
    #error SIZE_MAX is of an unusual value, edit this file manually to remove this error.
#endif

#if COTTON_OS_WINDOWS
    using NativeChar = wchar_t;
#else
    using NativeChar = char;
#endif
}   // namespace Cotton
