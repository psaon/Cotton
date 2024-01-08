#pragma once

// Wrapper around '__has_builtin'
#if defined(__has_builtin)
    #define COTTON_HAS_BUILTIN(fn) __has_builtin(fn)
#else
    #define COTTON_HAS_BUILTIN(fn) (false)
#endif

// Similar to __has_builtin, but also tests whether the function
// is constexpr.
#if defined(__has_constexpr_builtin)
    #define COTTON_HAS_CONSTEXPR_BUILTIN(fn) __has_constexpr_builtin(fn)
#else
    #define COTTON_HAS_CONSTEXPR_BUILTIN(fn) (false)
#endif

// This macro is already available as of C++20, but '__has_cpp_attribute'
// doesn't look good with other macros. So this is just a wrapper around that..
//
// Checks for the availability of '[[attribute]]'
#define COTTON_HAS_CPP_ATTRIBUTE(attrib) __has_cpp_attribute(attrib)

// Checks for the availability of '__attribute__((attribute))'
#if defined(__has_attribute)
    #define COTTON_HAS_GNU_ATTRIBUTE(attrib) __has_attribute(attrib)
#else
    #define COTTON_HAS_GNU_ATTRIBUTE(attrib) (false)
#endif

// Checks for the availability of __declspec(attrib)
#if defined(__has_declspec_attribute)
    #define COTTON_HAS_DECLSPEC_ATTRIBUTE(attrib) __has_declspec_attribute(attrib)
#else
    #define COTTON_HAS_DECLSPEC_ATTRIBUTE(attrib) (false)
#endif

// Macro to check whether the warning passed in is a valid warning option.
#if defined(__has_warning)
    #define COTTON_HAS_WARNING(warning) __has_warning(warning)
#else
    #define COTTON_HAS_WARNING(warning) (false)
#endif
