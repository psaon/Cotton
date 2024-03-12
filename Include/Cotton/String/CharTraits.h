#pragma once

#include <new>

#include "Cotton/Core/Types.h"
#include "Cotton/Core/FeatureChecks.h"

#include "Cotton/Meta/TypeTraits.h"
#include "Cotton/Meta/TypeTransforms.h"

#include "Cotton/Meta/IsConstantEvaluated.h"

#if COTTON_HAS_BUILTIN(__builtin_strlen) && COTTON_HAS_BUILTIN(__builtin_strcpy) && \
    COTTON_HAS_BUILTIN(__builtin_memcmp) && COTTON_HAS_BUILTIN(__builtin_memchr)
    #define COTTON_BUILTIN_STRLEN(str)               __builtin_strlen(str)
    #define COTTON_BUILTIN_MEMCPY(to, from, count)   __builtin_memcpy(to, from, count)
    #define COTTON_BUILTIN_MEMCMP(str1, str2, count) __builtin_memcmp(str1, str2, count)
    #define COTTON_BUILTIN_MEMCHR(str, count, ch)    __builtin_memchr(str, ch, count)

#else
    #include <cstring>

    #define COTTON_BUILTIN_STRLEN(str)               ::std::strlen(str)
    #define COTTON_BUILTIN_MEMCPY(to, from, count)   ::std::memcpy(to, from, count)
    #define COTTON_BUILTIN_MEMCMP(str1, str2, count) ::std::memcmp(str1, str2, count);
    #define COTTON_BUILTIN_MEMCHR(str, count, ch)    ::std::memchr(str, ch, count)
#endif

#if COTTON_HAS_BUILTIN(__builtin_wcslen) && COTTON_HAS_BUILTIN(__builtin_wmemcmp) && \
    COTTON_HAS_BUILTIN(__builtin_wmemchr)
    #define COTTON_BUILTIN_WCSLEN(str)                __builtin_wcslen(str)
    #define COTTON_BUILTIN_WMEMCMP(str1, str2, count) __builtin_wmemcmp(str1, str2, count)
    #define COTTON_BUILTIN_WMEMCHR(str1, count, ch)   __builtin_wmemchr(str, ch, count)
#else
    #include <cwchar>

    #define COTTON_BUILTIN_WCSLEN(str)                ::std::wcslen(str)
    #define COTTON_BUILTIN_WMEMCMP(str1, str2, count) ::std::wmemcmp(str1, str2, count)
    #define COTTON_BUILTIN_WMEMCHR(str1, count, ch)   ::std::wmemchr(str, ch, count)
#endif

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct GenericCharTraits
        {
            using CharType = T;
            using IntType = SignedIntType<sizeof(T)>;

            // clang-format off
            //? clang-format formats the while loop by tabbing & moving the semicolon to
            //? the next line.
            static constexpr Usize Length(const T* str)
            {
                const T* end = str;
                while (!Equal(*end++, T()));

                return (end - str - 1);
            }

            // clang-format on

            static constexpr void Copy(T* to, const T* from, Usize count)
            {
                for (Usize i = 0; i < count; ++i)
                    new (static_cast<void*>(to + i)) T(from[i]);
            }

            static constexpr bool Equal(T ch1, T ch2) { return (ch1 == ch2); }
            static constexpr bool LessThan(T ch1, T ch2)
            {
                using Unsgn = MakeUnsigned<T>;
                return (static_cast<Unsgn>(ch1) < static_cast<Unsgn>(ch2));
            }

            static constexpr int Compare(const T* str1, const T* str2, Usize count)
            {
                for (Usize i = 0; i < count; ++i)
                {
                    if (LessThan(str1[i], str2[i]))
                        return -1;
                    else if (LessThan(str2[i], str1[i]))
                        return 1;
                }

                return 0;
            }

            static const T* Find(const T* str, Usize count, const T& ch)
            {
                for (Usize i = 0; i < count; ++i)
                {
                    if (Equal(str[i], ch))
                        return (str + i);
                }

                return nullptr;
            }
        };
    }   // namespace Internal

    template<class T>
    struct CharTraits : Internal::GenericCharTraits<T>
    {
    };

    template<>
    struct CharTraits<char>
    {
    private:
        using GenericCharTraits_ = Internal::GenericCharTraits<char>;

    public:
        using CharType = typename GenericCharTraits_::CharType;
        using IntType = typename GenericCharTraits_::IntType;

    public:
        static constexpr Usize Length(const char* str)
        {
            if (IsConstantEvaluated())
                return GenericCharTraits_::Length(str);

            return COTTON_BUILTIN_STRLEN(str);
        }

        static constexpr void Copy(char* to, const char* from, Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Copy(to, from, count);

            COTTON_BUILTIN_MEMCPY(to, from, count);
        }

        static constexpr bool Equal(char ch1, char ch2) { return (ch1 == ch2); }
        static constexpr bool LessThan(char lhs, char rhs)
        {
            return (static_cast<unsigned char>(lhs) < static_cast<unsigned char>(rhs));
        }

        static constexpr int Compare(const char* str1, const char* str2, Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Compare(str1, str2, count);

            return COTTON_BUILTIN_MEMCMP(str1, str2, count);
        }

        static constexpr const char* Find(const char* str, Usize count, const char& ch)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Find(str, count, ch);

            return static_cast<const char*>(COTTON_BUILTIN_MEMCHR(str, count, ch));
        }
    };

    template<>
    struct CharTraits<wchar_t>
    {
    private:
        using GenericCharTraits_ = Internal::GenericCharTraits<wchar_t>;

    public:
        using CharType = typename GenericCharTraits_::CharType;
        using IntType = typename GenericCharTraits_::IntType;

    public:
        static constexpr Usize Length(const wchar_t* str)
        {
            if (IsConstantEvaluated())
                return GenericCharTraits_::Length(str);

            return COTTON_BUILTIN_WCSLEN(str);
        }

        static constexpr void Copy(wchar_t* to, const wchar_t* from, Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Copy(to, from, count);

            COTTON_BUILTIN_MEMCPY(to, from, count * sizeof(wchar_t));
        }

        static constexpr bool Equal(wchar_t ch1, wchar_t ch2) { return (ch1 == ch2); }
        static constexpr bool LessThan(wchar_t lhs, wchar_t rhs)
        {
            return GenericCharTraits_::LessThan(lhs, rhs);
        }

        static constexpr int Compare(const wchar_t* str1, const wchar_t* str2,
                                     Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Compare(str1, str2, count);

            return COTTON_BUILTIN_WMEMCMP(str1, str2, count);
        }

        static constexpr const wchar_t* Find(const wchar_t* str, Usize count,
                                             const wchar_t& ch)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Find(str, count, ch);

            return static_cast<const wchar_t*>(COTTON_BUILTIN_WMEMCHR(str, count, ch));
        }
    };

    template<>
    struct CharTraits<char8_t>
    {
    private:
        using GenericCharTraits_ = Internal::GenericCharTraits<char8_t>;

    public:
        using CharType = typename GenericCharTraits_::CharType;
        using IntType = typename GenericCharTraits_::IntType;

    public:
        static constexpr Usize Length(const char8_t* str)
        {
            return GenericCharTraits_::Length(str);
        }

        static constexpr void Copy(char8_t* to, const char8_t* from, Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Copy(to, from, count);
            else
                COTTON_BUILTIN_MEMCPY(to, from, count * sizeof(char8_t));
        }

        static constexpr bool Equal(char8_t ch1, char8_t ch2) { return (ch1 == ch2); }
        static constexpr bool LessThan(char8_t lhs, char8_t rhs) { return (lhs < rhs); }

        static constexpr int Compare(const char8_t* str1, const char8_t* str2,
                                     Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Compare(str1, str2, count);

            return COTTON_BUILTIN_MEMCMP(str1, str2, count * sizeof(char8_t));
        }

        static constexpr const char8_t* Find(const char8_t* str, Usize count,
                                             const char8_t& ch)
        {
            if (IsConstantEvaluated())
                return GenericCharTraits_::Find(str, count, ch);

            return static_cast<const char8_t*>(COTTON_BUILTIN_MEMCHR(str, count, ch));
        }
    };

    template<>
    struct CharTraits<char16_t>
    {
    private:
        using GenericCharTraits_ = Internal::GenericCharTraits<char16_t>;

    public:
        using CharType = typename GenericCharTraits_::CharType;
        using IntType = typename GenericCharTraits_::IntType;

    public:
        static constexpr Usize Length(const char16_t* str)
        {
            return GenericCharTraits_::Length(str);
        }

        static constexpr void Copy(char16_t* to, const char16_t* from, Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Copy(to, from, count);
            else
                COTTON_BUILTIN_MEMCPY(to, from, count * sizeof(char16_t));
        }

        static constexpr bool Equal(char16_t ch1, char16_t ch2) { return (ch1 == ch2); }
        static constexpr bool LessThan(char16_t lhs, char16_t rhs) { return (lhs < rhs); }

        static constexpr int Compare(const char16_t* str1, const char16_t* str2,
                                     Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Compare(str1, str2, count);

            return COTTON_BUILTIN_MEMCMP(str1, str2, count * sizeof(char16_t));
        }

        static constexpr const char16_t* Find(const char16_t* str, Usize count,
                                              const char16_t& ch)
        {
            return GenericCharTraits_::Find(str, count, ch);
        }
    };

    template<>
    struct CharTraits<char32_t>
    {
    private:
        using GenericCharTraits_ = Internal::GenericCharTraits<char32_t>;

    public:
        using CharType = typename GenericCharTraits_::CharType;
        using IntType = typename GenericCharTraits_::IntType;

    public:
        static constexpr Usize Length(const char32_t* str)
        {
            return GenericCharTraits_::Length(str);
        }

        static constexpr void Copy(char32_t* to, const char32_t* from, Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Copy(to, from, count);
            else
                COTTON_BUILTIN_MEMCPY(to, from, count * sizeof(char32_t));
        }

        static constexpr bool Equal(char32_t ch1, char32_t ch2) { return (ch1 == ch2); }
        static constexpr bool LessThan(char32_t lhs, char32_t rhs) { return (lhs < rhs); }

        static constexpr int Compare(const char32_t* str1, const char32_t* str2,
                                     Usize count)
        {
            if (IsConstantEvaluated())
                GenericCharTraits_::Compare(str1, str2, count);

            return COTTON_BUILTIN_MEMCMP(str1, str2, count * sizeof(char32_t));
        }

        static constexpr const char32_t* Find(const char32_t* str, Usize count,
                                              const char32_t& ch)
        {
            return GenericCharTraits_::Find(str, count, ch);
        }
    };
}   // namespace Cotton
