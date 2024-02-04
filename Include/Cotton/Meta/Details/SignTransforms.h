#pragma once

#include "Cotton/Core/Types.h"

#include "Cotton/Meta/Details/IsQualifier.h"
#include "Cotton/Meta/Details/Conditionals.h"

// Hodge-podge
#define COTTON_DEFINE_MAKESIGNED_(type) \
    template<>                          \
    struct ToSigned<signed type>        \
    {                                   \
        using Type = signed type;       \
    };                                  \
    template<>                          \
    struct ToSigned<unsigned type>      \
    {                                   \
        using Type = signed type;       \
    };

#define COTTON_DEFINE_MAKEUNSIGNED_(type) \
    template<>                            \
    struct ToUnsigned<signed type>        \
    {                                     \
        using Type = unsigned type;       \
    };                                    \
    template<>                            \
    struct ToUnsigned<unsigned type>      \
    {                                     \
        using Type = unsigned type;       \
    };

#define COTTON_DEFINE_MAKESIGNED_CHAR2_(ch, size) \
    template<>                                    \
    struct ToSigned<ch>                           \
    {                                             \
        using Type = Int##size;                   \
    };

#define COTTON_DEFINE_MAKEUNSIGNED_CHAR2_(ch, size) \
    template<>                                      \
    struct ToUnsigned<ch>                           \
    {                                               \
        using Type = Uint##size;                    \
    };

#define COTTON_DEFINE_MAKESIGNED_CHAR_(ch, size) COTTON_DEFINE_MAKESIGNED_CHAR2_(ch, size)
#define COTTON_DEFINE_MAKEUNSIGNED_CHAR_(ch, size) \
    COTTON_DEFINE_MAKEUNSIGNED_CHAR2_(ch, size)

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct ToSigned
        {
        };

        COTTON_DEFINE_MAKESIGNED_(char);
        COTTON_DEFINE_MAKESIGNED_(short);
        COTTON_DEFINE_MAKESIGNED_(int);
        COTTON_DEFINE_MAKESIGNED_(long);
        COTTON_DEFINE_MAKESIGNED_(long long);

        COTTON_DEFINE_MAKESIGNED_CHAR_(char, CHAR_BIT);
        COTTON_DEFINE_MAKESIGNED_CHAR_(char8_t, 8);
        COTTON_DEFINE_MAKESIGNED_CHAR_(char16_t, 16);
        COTTON_DEFINE_MAKESIGNED_CHAR_(char32_t, 32);

        template<class T>
        struct ToUnsigned
        {
        };

        COTTON_DEFINE_MAKEUNSIGNED_(char);
        COTTON_DEFINE_MAKEUNSIGNED_(short);
        COTTON_DEFINE_MAKEUNSIGNED_(int);
        COTTON_DEFINE_MAKEUNSIGNED_(long);
        COTTON_DEFINE_MAKEUNSIGNED_(long long);

        COTTON_DEFINE_MAKEUNSIGNED_CHAR_(char, CHAR_BIT);
        COTTON_DEFINE_MAKEUNSIGNED_CHAR_(char8_t, 8);
        COTTON_DEFINE_MAKEUNSIGNED_CHAR_(char16_t, 16);
        COTTON_DEFINE_MAKEUNSIGNED_CHAR_(char32_t, 32);

        template<class T, bool Const, bool Volatile>
        struct AddQualifiers
        {
        private:
            using ConstAdded_ = SelectType<Const, const T, T>;
            using QualifiersAdded_ =
                SelectType<Volatile, volatile ConstAdded_, ConstAdded_>;

        public:
            using Type = QualifiersAdded_;
        };

        template<class T>
        using MakeSignedHelper =
            AddQualifiers<typename ToSigned<RemoveQualifiers<T>>::Type, IsConst<T>,
                          IsVolatile<T>>::Type;
        template<class T>
        using MakeUnsignedHelper =
            AddQualifiers<typename ToUnsigned<RemoveQualifiers<T>>::Type, IsConst<T>,
                          IsVolatile<T>>::Type;
    }   // namespace Internal

    template<class T>
    using MakeSigned = Internal::MakeSignedHelper<T>;

    template<class T>
    using MakeUnsigned = Internal::MakeUnsignedHelper<T>;
}   // namespace Cotton

#undef COTTON_DEFINE_MAKESIGNED_
#undef COTTON_DEFINE_MAKESIGNED_CHAR_

#undef COTTON_DEFINE_MAKEUNSIGNED_
#undef COTTON_DEFINE_MAKEUNSIGNED_CHAR_
