#pragma once

#include "Cotton/Meta/TypeTraits.h"

namespace Cotton
{
    namespace Internal
    {
        template<class T, class U>
        concept SameAsHelper = IsSame<T, U>;
    }

    template<class Base, class Derived>
    concept DerivedFrom = IsBaseOf<Base, Derived>;

    template<class T, class U>
    concept SameAs = Internal::SameAsHelper<T, U> && Internal::SameAsHelper<U, T>;

    template<class From, class To>
    concept ImplicitlyConvertible = IsImplicitlyConvertible<From, To>;

    template<class From, class To>
    concept ExplicitlyConvertible = IsExplicitlyConvertible<From, To>;

    template<class T>
    concept Integral = IsIntegral<T>;

    template<class T>
    concept SignedIntegral = Integral<T> && IsSigned<T>;

    template<class T>
    concept UnsignedIntegral = Integral<T> && IsUnsigned<T>;

    template<class T>
    concept FloatingPoint = IsFloatingPoint<T>;
}   // namespace Cotton
