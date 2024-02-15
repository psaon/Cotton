#pragma once

#include "Cotton/Core/Predefined.h"

#include "Cotton/Meta/Details/Comparisons.h"
#include "Cotton/Meta/Details/QualifierTransforms.h"

#if __has_include(<stdfloat>) && (COTTON_VERSION_CPP > COTTON_VERSION_CPP20)
    #define COTTON_STD_HAS_FIXED_WIDTH_FLOAT_ 1
    #include <stdfloat>
#else
    #define COTTON_STD_HAS_FIXED_WIDTH_FLOAT_ 0
#endif

namespace Cotton
{
    template<class T>
    static constexpr bool IsIntegral =
        IsAnyOf<RemoveQualifiers<T>, bool, signed char, signed short, signed int,
                signed long, signed long long, unsigned char, unsigned short,
                unsigned int, unsigned long, unsigned long long, char, wchar_t, char8_t,
                char16_t, char32_t>;

    template<class T>
    static constexpr bool IsCharacter =
        IsAnyOf<RemoveQualifiers<T>, char, wchar_t, char8_t, char16_t, char32_t>;

    template<class T>
    static constexpr bool IsFloatingPoint =
        IsAnyOf<RemoveQualifiers<T>, float, double, long double

#if COTTON_STD_HAS_FIXED_WIDTH_FLOAT_
                ,
                ::std::float16_t, ::std::float32_t, ::std::float64_t, ::std::float128_t,
                ::std::bfloat16_t
#endif
                >;

    template<class T>
    static constexpr bool IsArithmetic = IsIntegral<T> || IsFloatingPoint<T>;
}   // namespace Cotton

#undef COTTON_STD_HAS_FIXED_WIDTH_FLOAT_
