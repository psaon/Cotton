#include <CottonTest.h>
#include <Cotton/Meta/Concepts.h>

#include <concepts>

namespace CottonTesting
{
    class BaseClass
    {
    };

    class DerivedClass : BaseClass
    {
    };

    template<class T>
    class ExplicitlyConvertibleTo
    {
    public:
        explicit operator T() const { return T(); }
    };

    template<class T>
        requires Cotton::DerivedFrom<BaseClass, T>
    constexpr bool TestDerivedFrom()
    {
        return true;
    };

    template<class T>
    constexpr bool TestDerivedFrom()
    {
        return false;
    }

    template<class T, class U>
    constexpr bool TestSameAs()
        requires Cotton::SameAs<T, U>
    {
        return true;
    }

    template<class T, class U>
    constexpr bool TestSameAs()
    {
        return false;
    }

    template<class T, class U>
    constexpr bool TestSameAs()
        requires Cotton::SameAs<U, T> && std::integral<U> && std::integral<T>
    {
        return false;
    }

    template<class T>
    constexpr bool TestImplConversion()
        requires Cotton::ImplicitlyConvertible<T, float>
    {
        return true;
    }

    template<class T>
    constexpr bool TestImplConversion()
    {
        return false;
    }

    template<class T>
    constexpr bool TestExplConversion()
        requires Cotton::ExplicitlyConvertible<T, float>
    {
        return true;
    }

    template<class T>
    constexpr bool TestExplConversion()
    {
        return false;
    }

    template<Cotton::Integral T>
    constexpr bool TestIntegral()
    {
        return true;
    }

    template<class T>
    constexpr bool TestIntegral()
    {
        return false;
    }

    template<Cotton::FloatingPoint T>
    constexpr bool TestFloatingPoint()
    {
        return true;
    }

    template<class T>
    constexpr bool TestFloatingPoint()
    {
        return false;
    }

    template<Cotton::SignedIntegral T>
    constexpr bool TestSignedIntegral()
    {
        return true;
    }

    template<class T>
    constexpr bool TestSignedIntegral()
    {
        return false;
    }

    template<Cotton::UnsignedIntegral T>
    constexpr bool TestUnsignedIntegral()
    {
        return true;
    }

    template<class T>
    constexpr bool TestUnsignedIntegral()
    {
        return false;
    }

}   // namespace CottonTesting

TEST(TestConcepts, DerivedFrom)
{
    using CottonTesting::TestDerivedFrom, CottonTesting::DerivedClass,
        CottonTesting::BaseClass;

    EXPECT_TRUE(TestDerivedFrom<DerivedClass>());
    EXPECT_TRUE(TestDerivedFrom<BaseClass>());

    EXPECT_FALSE(TestDerivedFrom<int>());
}

TEST(TestConcepts, SameAs)
{
    using CottonTesting::TestSameAs;

    EXPECT_TRUE((TestSameAs<float, float>()));
    EXPECT_TRUE((TestSameAs<double, double>()));

    EXPECT_FALSE((TestSameAs<short, int>()));
    EXPECT_FALSE((TestSameAs<int, int>()));
    EXPECT_FALSE((TestSameAs<float, int>()));
    EXPECT_FALSE((TestSameAs<float, double>()));
}

TEST(TestConcepts, ImplicitlyConvertible)
{
    using CottonTesting::ExplicitlyConvertibleTo, CottonTesting::TestImplConversion;

    EXPECT_TRUE(TestImplConversion<int>());
    EXPECT_FALSE(TestImplConversion<ExplicitlyConvertibleTo<float>>());
}

TEST(TestConcepts, ExplicitlyConvertible)
{
    using CottonTesting::ExplicitlyConvertibleTo, CottonTesting::TestExplConversion;

    EXPECT_TRUE(TestExplConversion<int>());
    EXPECT_TRUE(TestExplConversion<ExplicitlyConvertibleTo<float>>());
}

TEST(TestConcepts, Integral)
{
    using CottonTesting::TestIntegral;

    EXPECT_TRUE(TestIntegral<int>());
    EXPECT_TRUE(TestIntegral<long long>());

    EXPECT_FALSE(TestIntegral<float>());
    EXPECT_FALSE(TestIntegral<double>());
}

TEST(TestConcepts, FloatingPoint)
{
    using CottonTesting::TestFloatingPoint;

    EXPECT_TRUE(TestFloatingPoint<float>());
    EXPECT_TRUE(TestFloatingPoint<double>());
    EXPECT_TRUE(TestFloatingPoint<long double>());

    EXPECT_FALSE(TestFloatingPoint<int>());
    EXPECT_FALSE(TestFloatingPoint<short>());
    EXPECT_FALSE(TestFloatingPoint<long>());
    EXPECT_FALSE(TestFloatingPoint<unsigned long long>());
}

TEST(TestConcepts, SignedIntegral)
{
    using CottonTesting::TestSignedIntegral;

    EXPECT_TRUE(TestSignedIntegral<signed short>());
    EXPECT_TRUE(TestSignedIntegral<signed int>());
    EXPECT_TRUE(TestSignedIntegral<signed long>());
    EXPECT_TRUE(TestSignedIntegral<signed char>());

    EXPECT_FALSE(TestSignedIntegral<unsigned char>());
    EXPECT_FALSE(TestSignedIntegral<unsigned int>());
    EXPECT_FALSE(TestSignedIntegral<unsigned char>());
    EXPECT_FALSE(TestSignedIntegral<float>());
}

TEST(TestConcepts, UnsignedIntegral)
{
    using CottonTesting::TestUnsignedIntegral;

    EXPECT_FALSE(TestUnsignedIntegral<signed short>());
    EXPECT_FALSE(TestUnsignedIntegral<signed int>());
    EXPECT_FALSE(TestUnsignedIntegral<signed long>());
    EXPECT_FALSE(TestUnsignedIntegral<signed char>());
    EXPECT_FALSE(TestUnsignedIntegral<float>());
    EXPECT_FALSE(TestUnsignedIntegral<double>());
    EXPECT_FALSE(TestUnsignedIntegral<long double>());

    EXPECT_TRUE(TestUnsignedIntegral<unsigned char>());
    EXPECT_TRUE(TestUnsignedIntegral<unsigned int>());
    EXPECT_TRUE(TestUnsignedIntegral<unsigned char>());
}
