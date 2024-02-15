#include <Cotton/Meta/TypeTraits.h>
#include <CottonTest.h>

#include <Cotton/Core/Predefined.h>
#if __has_include(<stdfloat>) && (COTTON_VERSION_CPP > COTTON_VERSION_CPP20)
    #define COTTON_TEST_HAS_STDFLOAT 1
    #include <stdfloat>

#else
    #define COTTON_TEST_HAS_STDFLOAT 0
#endif

namespace CottonTesting
{
    class FinalClass final
    {
    };

    class AbstractClass
    {
    public:
        virtual void Foo() = 0;
    };

    class PolymorphicClass : public AbstractClass
    {
    };
}   // namespace CottonTesting

TEST(TestTypeTraits, IsVoid)
{
    EXPECT_TRUE(Cotton::IsVoid<void>);
    EXPECT_TRUE(Cotton::IsVoid<const void>);
    EXPECT_TRUE(Cotton::IsVoid<volatile void>);
    EXPECT_TRUE(Cotton::IsVoid<const volatile void>);

    EXPECT_FALSE(Cotton::IsVoid<int>);
    EXPECT_FALSE(Cotton::IsVoid<int*>);
    EXPECT_FALSE(Cotton::IsVoid<int&>);
    EXPECT_FALSE(Cotton::IsVoid<void*>);
}

TEST(TestTypeTraits, IsNullptr)
{
    EXPECT_TRUE(Cotton::IsNullptr<::std::nullptr_t>);
    EXPECT_TRUE(Cotton::IsNullptr<const ::std::nullptr_t>);
    EXPECT_TRUE(Cotton::IsNullptr<volatile ::std::nullptr_t>);
    EXPECT_TRUE(Cotton::IsNullptr<const volatile ::std::nullptr_t>);

    EXPECT_FALSE(Cotton::IsNullptr<int*>);
    EXPECT_FALSE(Cotton::IsNullptr<void*>);
}

TEST(TestTypeTraits, IsArray)
{
    EXPECT_TRUE(Cotton::IsArray<float[2]>);
    EXPECT_TRUE(Cotton::IsArray<float[]>);
    EXPECT_TRUE(Cotton::IsArray<float[][4]>);

    EXPECT_FALSE(Cotton::IsArray<float>);
    EXPECT_FALSE(Cotton::IsArray<float*>);
    EXPECT_FALSE(Cotton::IsArray<float*&>);
}

TEST(TestTypeTraits, IsBoundedArray)
{
    EXPECT_TRUE(Cotton::IsBoundedArray<float[3]>);
    EXPECT_TRUE(Cotton::IsBoundedArray<float[3][4]>);

    EXPECT_FALSE(Cotton::IsBoundedArray<float[]>);
    EXPECT_FALSE(Cotton::IsBoundedArray<float[][4]>);
}

TEST(TestTypeTraits, IsUnboundedArray)
{
    EXPECT_TRUE(Cotton::IsUnboundedArray<float[]>);
    EXPECT_TRUE(Cotton::IsUnboundedArray<float[][3]>);

    EXPECT_FALSE(Cotton::IsUnboundedArray<float[3]>);
    EXPECT_FALSE(Cotton::IsUnboundedArray<float[3][64]>);
}

TEST(TestTypeTraits, IsClass)
{
    using CottonTesting::ExampleClass, CottonTesting::ExampleUnion,
        CottonTesting::ExampleEnum;

    EXPECT_TRUE(Cotton::IsClass<ExampleClass>);
    EXPECT_TRUE(Cotton::IsClass<std::string>);

    EXPECT_FALSE(Cotton::IsClass<ExampleUnion>);
    EXPECT_FALSE(Cotton::IsClass<ExampleEnum>);
}

TEST(TestTypeTraits, IsUnion)
{
    using CottonTesting::ExampleClass, CottonTesting::ExampleUnion,
        CottonTesting::ExampleEnum;

    EXPECT_TRUE(Cotton::IsUnion<ExampleUnion>);

    EXPECT_FALSE(Cotton::IsUnion<ExampleClass>);
    EXPECT_FALSE(Cotton::IsUnion<ExampleEnum>);
}

TEST(TestTypeTraits, IsEnum)
{
    using CottonTesting::ExampleClass, CottonTesting::ExampleUnion,
        CottonTesting::ExampleEnum;

    EXPECT_TRUE(Cotton::IsEnum<ExampleEnum>);

    EXPECT_FALSE(Cotton::IsEnum<ExampleUnion>);
    EXPECT_FALSE(Cotton::IsEnum<ExampleClass>);
}

TEST(TestTypeTraits, IsScopedEnum)
{
    using CottonTesting::ExampleClass, CottonTesting::ExampleEnum,
        CottonTesting::ExampleUnion, CottonTesting::ExampleScopedEnum;

    EXPECT_TRUE(Cotton::IsScopedEnum<ExampleScopedEnum>);

    EXPECT_FALSE(Cotton::IsScopedEnum<ExampleClass>);
    EXPECT_FALSE(Cotton::IsScopedEnum<ExampleUnion>);
    EXPECT_FALSE(Cotton::IsScopedEnum<ExampleEnum>);
}

TEST(TestTypeTraits, IsPointer)
{
    EXPECT_TRUE(Cotton::IsPointer<int*>);
    EXPECT_TRUE(Cotton::IsPointer<int* const>);
    EXPECT_TRUE(Cotton::IsPointer<int* volatile>);
    EXPECT_TRUE(Cotton::IsPointer<int* const volatile>);

    EXPECT_FALSE(Cotton::IsPointer<int&>);
    EXPECT_FALSE(Cotton::IsPointer<int*&>);
    EXPECT_FALSE(Cotton::IsPointer<int>);
}

TEST(TestTypeTraits, IsFunction)
{
    EXPECT_TRUE(Cotton::IsFunction<int(float)>);
    EXPECT_TRUE(Cotton::IsFunction<void()>);

    EXPECT_FALSE(Cotton::IsFunction<int (*)(float)>);
    EXPECT_FALSE(Cotton::IsFunction<void (*)(float)>);
}

TEST(TestTypeTraits, IsLvalueReference)
{
    EXPECT_TRUE(Cotton::IsLvalueReference<int&>);
    EXPECT_TRUE(Cotton::IsLvalueReference<float*&>);

    EXPECT_FALSE(Cotton::IsLvalueReference<float&&>);
    EXPECT_FALSE(Cotton::IsLvalueReference<float>);
}

TEST(TestTypeTraits, IsRvalueReference)
{
    EXPECT_TRUE(Cotton::IsRvalueReference<float&&>);
    EXPECT_TRUE(Cotton::IsRvalueReference<float*&&>);

    EXPECT_FALSE(Cotton::IsRvalueReference<int&>);
    EXPECT_FALSE(Cotton::IsRvalueReference<float*&>);
    EXPECT_FALSE(Cotton::IsRvalueReference<float>);
}

TEST(TestTypeTraits, IsReference)
{
    EXPECT_TRUE(Cotton::IsReference<float&>);
    EXPECT_TRUE(Cotton::IsReference<float&&>);

    EXPECT_FALSE(Cotton::IsReference<float>);
    EXPECT_FALSE(Cotton::IsReference<float*>);
}

TEST(TestTypeTraits, IsFunctionPointer)
{
    EXPECT_FALSE(Cotton::IsFunctionPointer<int(float)>);
    EXPECT_FALSE(Cotton::IsFunctionPointer<void()>);

    EXPECT_TRUE(Cotton::IsFunctionPointer<int (*)(float)>);
    EXPECT_TRUE(Cotton::IsFunctionPointer<void (*)(float)>);
}

TEST(TestTypeTraits, IsMemberPointer)
{
    using CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsMemberPointer<int (ExampleClass::*)(float)>);
    EXPECT_TRUE(Cotton::IsMemberPointer<int ExampleClass::*>);

    EXPECT_FALSE(Cotton::IsMemberPointer<int (*)(float)>);
    EXPECT_FALSE(Cotton::IsMemberPointer<int*>);
}

TEST(TestTypeTraits, IsMemberFunctionPointer)
{
    using CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsMemberFunctionPointer<int (ExampleClass::*)(float)>);

    EXPECT_FALSE(Cotton::IsMemberFunctionPointer<int ExampleClass::*>);
    EXPECT_FALSE(Cotton::IsMemberFunctionPointer<int (*)(float)>);
    EXPECT_FALSE(Cotton::IsMemberFunctionPointer<int*>);
}

TEST(TestTypeTraits, IsMemberObjectPointer)
{
    using CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsMemberObjectPointer<int ExampleClass::*>);

    EXPECT_FALSE(Cotton::IsMemberObjectPointer<int (ExampleClass::*)(float)>);
    EXPECT_FALSE(Cotton::IsMemberFunctionPointer<int (*)(float)>);
    EXPECT_FALSE(Cotton::IsMemberFunctionPointer<int*>);
}

TEST(TestTypeTraits, IsIntegral)
{
    EXPECT_TRUE(Cotton::IsIntegral<const bool>);
    EXPECT_TRUE(Cotton::IsIntegral<const signed char>);
    EXPECT_TRUE(Cotton::IsIntegral<const signed short>);
    EXPECT_TRUE(Cotton::IsIntegral<const signed int>);
    EXPECT_TRUE(Cotton::IsIntegral<const signed long>);
    EXPECT_TRUE(Cotton::IsIntegral<const signed long long>);

    EXPECT_TRUE(Cotton::IsIntegral<const unsigned char>);
    EXPECT_TRUE(Cotton::IsIntegral<const unsigned short>);
    EXPECT_TRUE(Cotton::IsIntegral<const unsigned int>);
    EXPECT_TRUE(Cotton::IsIntegral<const unsigned long>);
    EXPECT_TRUE(Cotton::IsIntegral<const unsigned long long>);

    EXPECT_TRUE(Cotton::IsIntegral<const char>);
    EXPECT_TRUE(Cotton::IsIntegral<const char8_t>);
    EXPECT_TRUE(Cotton::IsIntegral<const char16_t>);
    EXPECT_TRUE(Cotton::IsIntegral<const char32_t>);
    EXPECT_TRUE(Cotton::IsIntegral<const wchar_t>);

    EXPECT_FALSE(Cotton::IsIntegral<const float>);
    EXPECT_FALSE(Cotton::IsIntegral<const double>);
    EXPECT_FALSE(Cotton::IsIntegral<const long double>);

#if COTTON_TEST_HAS_STDFLOAT
    EXPECT_FALSE(Cotton::IsIntegral<const std::float16_t>);
    EXPECT_FALSE(Cotton::IsIntegral<const std::float32_t>);
    EXPECT_FALSE(Cotton::IsIntegral<const std::float64_t>);
    EXPECT_FALSE(Cotton::IsIntegral<const std::float128_t>);
    EXPECT_FALSE(Cotton::IsIntegral<const std::bfloat16_t>);
#endif
}

TEST(TestTypeTraits, IsCharacter)
{
    EXPECT_TRUE(Cotton::IsCharacter<const char>);
    EXPECT_TRUE(Cotton::IsCharacter<const wchar_t>);
    EXPECT_TRUE(Cotton::IsCharacter<const char8_t>);
    EXPECT_TRUE(Cotton::IsCharacter<const char16_t>);
    EXPECT_TRUE(Cotton::IsCharacter<const char32_t>);
}

TEST(TestTypeTraits, IsFloatingPoint)
{
    EXPECT_TRUE(Cotton::IsFloatingPoint<const float>);
    EXPECT_TRUE(Cotton::IsFloatingPoint<const double>);
    EXPECT_TRUE(Cotton::IsFloatingPoint<const long double>);

#if COTTON_TEST_HAS_STDFLOAT
    EXPECT_TRUE(Cotton::IsFloatingPoint<const std::float16_t>);
    EXPECT_TRUE(Cotton::IsFloatingPoint<const std::float32_t>);
    EXPECT_TRUE(Cotton::IsFloatingPoint<const std::float64_t>);
    EXPECT_TRUE(Cotton::IsFloatingPoint<const std::float128_t>);
    EXPECT_TRUE(Cotton::IsFloatingPoint<const std::bfloat16_t>);
#endif

    EXPECT_FALSE(Cotton::IsFloatingPoint<const bool>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const signed char>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const signed short>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const signed int>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const signed long>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const signed long long>);

    EXPECT_FALSE(Cotton::IsFloatingPoint<const unsigned char>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const unsigned short>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const unsigned int>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const unsigned long>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const unsigned long long>);

    EXPECT_FALSE(Cotton::IsFloatingPoint<const char>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const char8_t>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const char16_t>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const char32_t>);
    EXPECT_FALSE(Cotton::IsFloatingPoint<const wchar_t>);
}

TEST(TestTypeTraits, IsArithmetic)
{
    EXPECT_TRUE(Cotton::IsArithmetic<const float>);
    EXPECT_TRUE(Cotton::IsArithmetic<const double>);
    EXPECT_TRUE(Cotton::IsArithmetic<const long double>);

#if COTTON_TEST_HAS_STDFLOAT
    EXPECT_TRUE(Cotton::IsArithmetic<const std::float16_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const std::float32_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const std::float64_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const std::float128_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const std::bfloat16_t>);
#endif

    EXPECT_TRUE(Cotton::IsArithmetic<const bool>);
    EXPECT_TRUE(Cotton::IsArithmetic<const signed char>);
    EXPECT_TRUE(Cotton::IsArithmetic<const signed short>);
    EXPECT_TRUE(Cotton::IsArithmetic<const signed int>);
    EXPECT_TRUE(Cotton::IsArithmetic<const signed long>);
    EXPECT_TRUE(Cotton::IsArithmetic<const signed long long>);

    EXPECT_TRUE(Cotton::IsArithmetic<const unsigned char>);
    EXPECT_TRUE(Cotton::IsArithmetic<const unsigned short>);
    EXPECT_TRUE(Cotton::IsArithmetic<const unsigned int>);
    EXPECT_TRUE(Cotton::IsArithmetic<const unsigned long>);
    EXPECT_TRUE(Cotton::IsArithmetic<const unsigned long long>);

    EXPECT_TRUE(Cotton::IsArithmetic<const char>);
    EXPECT_TRUE(Cotton::IsArithmetic<const char8_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const char16_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const char32_t>);
    EXPECT_TRUE(Cotton::IsArithmetic<const wchar_t>);
}

TEST(TestTypeTraits, IsSigned)
{
    EXPECT_TRUE(Cotton::IsSigned<const signed char>);
    EXPECT_TRUE(Cotton::IsSigned<const signed short>);
    EXPECT_TRUE(Cotton::IsSigned<const signed int>);
    EXPECT_TRUE(Cotton::IsSigned<const signed long>);
    EXPECT_TRUE(Cotton::IsSigned<const signed long long>);

    EXPECT_FALSE(Cotton::IsSigned<const bool>);
    EXPECT_FALSE(Cotton::IsSigned<const unsigned char>);
    EXPECT_FALSE(Cotton::IsSigned<const unsigned short>);
    EXPECT_FALSE(Cotton::IsSigned<const unsigned int>);
    EXPECT_FALSE(Cotton::IsSigned<const unsigned long>);
    EXPECT_FALSE(Cotton::IsSigned<const unsigned long long>);

    EXPECT_FALSE(Cotton::IsSigned<const char8_t>);
    EXPECT_FALSE(Cotton::IsSigned<const char16_t>);
    EXPECT_FALSE(Cotton::IsSigned<const char32_t>);
}

TEST(TestTypeTraits, IsUnsigned)
{
    EXPECT_TRUE(Cotton::IsUnsigned<const bool>);
    EXPECT_TRUE(Cotton::IsUnsigned<const unsigned char>);
    EXPECT_TRUE(Cotton::IsUnsigned<const unsigned short>);
    EXPECT_TRUE(Cotton::IsUnsigned<const unsigned int>);
    EXPECT_TRUE(Cotton::IsUnsigned<const unsigned long>);
    EXPECT_TRUE(Cotton::IsUnsigned<const unsigned long long>);

    EXPECT_TRUE(Cotton::IsUnsigned<const char8_t>);
    EXPECT_TRUE(Cotton::IsUnsigned<const char16_t>);
    EXPECT_TRUE(Cotton::IsUnsigned<const char32_t>);

    EXPECT_FALSE(Cotton::IsUnsigned<const signed char>);
    EXPECT_FALSE(Cotton::IsUnsigned<const signed short>);
    EXPECT_FALSE(Cotton::IsUnsigned<const signed int>);
    EXPECT_FALSE(Cotton::IsUnsigned<const signed long>);
    EXPECT_FALSE(Cotton::IsUnsigned<const signed long long>);
}

TEST(TestTypeTraits, IsConst)
{
    EXPECT_TRUE(Cotton::IsConst<const float>);
    EXPECT_TRUE(Cotton::IsConst<const volatile float>);

    EXPECT_FALSE(Cotton::IsConst<float>);
    EXPECT_FALSE(Cotton::IsConst<volatile float>);
    EXPECT_FALSE(Cotton::IsConst<const float*>);
}

TEST(TestTypeTraits, IsVolatile)
{
    EXPECT_TRUE(Cotton::IsVolatile<volatile float>);
    EXPECT_TRUE(Cotton::IsVolatile<const volatile float>);

    EXPECT_FALSE(Cotton::IsVolatile<float>);
    EXPECT_FALSE(Cotton::IsVolatile<const float>);
    EXPECT_FALSE(Cotton::IsVolatile<volatile float*>);
}

TEST(TestTypeTraits, IsConstVolatile)
{
    EXPECT_TRUE(Cotton::IsConstVolatile<const volatile float>);

    EXPECT_FALSE(Cotton::IsConstVolatile<float>);
    EXPECT_FALSE(Cotton::IsConstVolatile<const float>);
    EXPECT_FALSE(Cotton::IsConstVolatile<volatile float>);
    EXPECT_FALSE(Cotton::IsConstVolatile<const volatile float*>);
}

TEST(TestTypeTraits, HasQualifiers)
{
    EXPECT_TRUE(Cotton::HasQualifiers<const float>);
    EXPECT_TRUE(Cotton::HasQualifiers<volatile float>);
    EXPECT_TRUE(Cotton::HasQualifiers<const volatile float>);

    EXPECT_FALSE(Cotton::HasQualifiers<float>);
    EXPECT_FALSE(Cotton::HasQualifiers<const volatile float*>);
}

TEST(TestTypeTraits, IsEmpty)
{
    using CottonTesting::EmptyClass, CottonTesting::ExampleEnum;

    EXPECT_TRUE(Cotton::IsEmpty<EmptyClass>);
    EXPECT_TRUE(Cotton::IsEmpty<const EmptyClass>);

    EXPECT_FALSE(Cotton::IsEmpty<int>);
    EXPECT_FALSE(Cotton::IsEmpty<float>);
    EXPECT_FALSE(Cotton::IsEmpty<ExampleEnum>);
}

TEST(TestTypeTraits, IsPolymorphic)
{
    using CottonTesting::PolymorphicClass, CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsPolymorphic<PolymorphicClass>);
    EXPECT_TRUE(Cotton::IsPolymorphic<const PolymorphicClass>);

    EXPECT_FALSE(Cotton::IsPolymorphic<int>);
    EXPECT_FALSE(Cotton::IsPolymorphic<float>);
    EXPECT_FALSE(Cotton::IsPolymorphic<ExampleClass>);
}

TEST(TestTypeTraits, IsAbstract)
{
    using CottonTesting::AbstractClass, CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsAbstract<AbstractClass>);
    EXPECT_TRUE(Cotton::IsAbstract<const AbstractClass>);

    EXPECT_FALSE(Cotton::IsAbstract<int>);
    EXPECT_FALSE(Cotton::IsAbstract<float>);
    EXPECT_FALSE(Cotton::IsAbstract<ExampleClass>);
}

TEST(TestTypeTraits, IsFinal)
{
    using CottonTesting::FinalClass, CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsFinal<FinalClass>);
    EXPECT_TRUE(Cotton::IsFinal<const FinalClass>);

    EXPECT_FALSE(Cotton::IsFinal<ExampleClass>);
}

TEST(TestTypeTraits, IsFundamental)
{
    EXPECT_TRUE(Cotton::IsFundamental<const char>);
    EXPECT_TRUE(Cotton::IsFundamental<const int>);
    EXPECT_TRUE(Cotton::IsFundamental<const float>);
    EXPECT_TRUE(Cotton::IsFundamental<const double>);

    EXPECT_TRUE(Cotton::IsFundamental<const void>);
    EXPECT_TRUE(Cotton::IsFundamental<const std::nullptr_t>);

    EXPECT_FALSE(Cotton::IsFundamental<const int* const>);
    EXPECT_FALSE(Cotton::IsFundamental<const int&>);
    EXPECT_FALSE(Cotton::IsFundamental<const int[3]>);
    EXPECT_FALSE(Cotton::IsFundamental<const int[]>);
}

TEST(TestTypeTraits, IsScalar)
{
    using CottonTesting::ExampleEnum, CottonTesting::ExampleClass;

    EXPECT_TRUE(Cotton::IsScalar<const char>);
    EXPECT_TRUE(Cotton::IsScalar<const int>);
    EXPECT_TRUE(Cotton::IsScalar<const float>);
    EXPECT_TRUE(Cotton::IsScalar<const double>);

    EXPECT_TRUE(Cotton::IsScalar<const int* const>);
    EXPECT_TRUE(Cotton::IsScalar<const float* const>);
    EXPECT_TRUE(Cotton::IsScalar<const void* const>);
    EXPECT_TRUE(Cotton::IsScalar<const std::nullptr_t>);

    EXPECT_TRUE(Cotton::IsScalar<int ExampleClass::*const>);
    EXPECT_TRUE(Cotton::IsScalar<const ExampleEnum>);
}

TEST(TestTypeTraits, IsObject)
{
    using CottonTesting::ExampleEnum, CottonTesting::ExampleClass,
        CottonTesting::ExampleUnion;

    EXPECT_TRUE(Cotton::IsObject<const char>);
    EXPECT_TRUE(Cotton::IsObject<const int>);
    EXPECT_TRUE(Cotton::IsObject<const float>);
    EXPECT_TRUE(Cotton::IsObject<const double>);

    EXPECT_TRUE(Cotton::IsObject<const int* const>);
    EXPECT_TRUE(Cotton::IsObject<const float* const>);
    EXPECT_TRUE(Cotton::IsObject<const void* const>);
    EXPECT_TRUE(Cotton::IsObject<const std::nullptr_t>);

    EXPECT_TRUE(Cotton::IsObject<int ExampleClass::*const>);
    EXPECT_TRUE(Cotton::IsObject<const ExampleEnum>);

    EXPECT_TRUE(Cotton::IsObject<const int[3]>);
    EXPECT_TRUE(Cotton::IsObject<const int[]>);

    EXPECT_TRUE(Cotton::IsObject<const ExampleClass>);
    EXPECT_TRUE(Cotton::IsObject<const ExampleUnion>);
}

TEST(TestTypeTraits, IsCompound)
{
    EXPECT_FALSE(Cotton::IsCompound<const char>);
    EXPECT_FALSE(Cotton::IsCompound<const int>);
    EXPECT_FALSE(Cotton::IsCompound<const float>);
    EXPECT_FALSE(Cotton::IsCompound<const double>);

    EXPECT_FALSE(Cotton::IsCompound<const void>);
    EXPECT_FALSE(Cotton::IsCompound<const std::nullptr_t>);

    EXPECT_TRUE(Cotton::IsCompound<const int* const>);
    EXPECT_TRUE(Cotton::IsCompound<const int&>);
    EXPECT_TRUE(Cotton::IsCompound<const int[3]>);
    EXPECT_TRUE(Cotton::IsCompound<const int[]>);
}

TEST(TestTypeTraits, IsSame)
{
    EXPECT_TRUE((Cotton::IsSame<float, float>));
    EXPECT_TRUE((Cotton::IsSame<volatile float, volatile float>));

    EXPECT_FALSE((Cotton::IsSame<float, int>));
    EXPECT_FALSE((Cotton::IsSame<float, const float>));
}

TEST(TestTypeTraits, IsAnyOf)
{
    EXPECT_TRUE((Cotton::IsAnyOf<float, float>));
    EXPECT_TRUE((Cotton::IsAnyOf<volatile float, const float, volatile float>));

    EXPECT_FALSE((Cotton::IsAnyOf<float, int, long, short, double>));
    EXPECT_FALSE(
        (Cotton::IsAnyOf<float, const float, volatile float, const volatile float>));
}

TEST(TestTypeTraits, IsImplicitlyConvertible)
{
    using CottonTesting::EmptyClass, CottonTesting::ExampleScopedEnum;

    EXPECT_TRUE((Cotton::IsImplicitlyConvertible<int, float>));

    EXPECT_FALSE((Cotton::IsImplicitlyConvertible<float, EmptyClass>));
    EXPECT_FALSE((Cotton::IsImplicitlyConvertible<ExampleScopedEnum, int>));
}

TEST(TestTypeTraits, IsExplicitlyConvertible)
{
    using CottonTesting::EmptyClass, CottonTesting::ExampleScopedEnum;

    EXPECT_TRUE((Cotton::IsExplicitlyConvertible<int, float>));
    EXPECT_TRUE((Cotton::IsExplicitlyConvertible<ExampleScopedEnum, int>));

    EXPECT_FALSE((Cotton::IsExplicitlyConvertible<float, EmptyClass>));
}

TEST(TestTypeTraits, UnderlyingType)
{
    using CottonTesting::ExampleEnum, CottonTesting::ExampleScopedEnum;

    EXPECT_TYPE_EQ(Cotton::UnderlyingType<ExampleEnum>, short);
    EXPECT_TYPE_EQ(Cotton::UnderlyingType<ExampleScopedEnum>, long);
}
