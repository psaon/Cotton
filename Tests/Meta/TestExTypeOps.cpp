#include <CottonTest.h>
#include <Cotton/Meta/TypeTraits.h>

namespace CottonTesting
{
    class AddableClass
    {
    public:
        AddableClass operator+(const AddableClass&) { return *this; }
        AddableClass& operator+=(float) { return *this; }
    };

    class SubtractableClass
    {
    public:
        SubtractableClass operator-(const SubtractableClass&) { return *this; }
        SubtractableClass& operator-=(float) { return *this; }
    };

    class MultiplicatableClass
    {
    public:
        MultiplicatableClass operator*(const MultiplicatableClass&) { return *this; }
        MultiplicatableClass& operator*=(float) { return *this; }
    };

    class DividableClass
    {
    public:
        DividableClass operator/(const DividableClass&) { return *this; }
        DividableClass& operator/=(float) { return *this; }
    };

    class ModableClass
    {
    public:
        ModableClass operator%(const ModableClass&) { return *this; }
        ModableClass& operator%=(float) { return *this; }
    };

    class PreincrementableClass
    {
    public:
        PreincrementableClass& operator++();
    };

    class PostincrementableClass
    {
    public:
        PostincrementableClass operator++(int);
    };

    class PredecrementableClass
    {
    public:
        PredecrementableClass& operator--();
    };

    class PostdecrementableClass
    {
    public:
        PostdecrementableClass operator--(int);
    };

    class ComparableEqClass
    {
    public:
        bool operator==(const ComparableEqClass&) const;

        bool operator!=(float) const;
        bool operator!=(const ComparableEqClass&) const = delete;
    };

    class ComparableGeClass
    {
    public:
        bool operator>(const ComparableGeClass&) const;
        bool operator>=(float) const;
    };

    class ComparableLeClass
    {
    public:
        bool operator<(const ComparableLeClass&) const;
        bool operator<=(float) const;
    };

    class NegatableClass
    {
    public:
        bool operator!() const;
    };

    class AndableClass
    {
    public:
        bool operator&&(const AndableClass&) const;
        bool operator&&(float) = delete;
    };

    class OrableClass
    {
    public:
        bool operator||(const OrableClass&) const;
        bool operator||(float) = delete;
    };

    class BitwiseNotableClass
    {
    public:
        BitwiseNotableClass operator~() const;
    };

    class BitwiseOrableClass
    {
    public:
        BitwiseOrableClass operator|(const BitwiseOrableClass&) const;
        BitwiseOrableClass& operator|=(float);
    };

    class BitwiseAndableClass
    {
    public:
        BitwiseAndableClass operator&(const BitwiseAndableClass&) const;
        BitwiseAndableClass& operator&=(float);
    };

    class BitwiseXorableClass
    {
    public:
        BitwiseXorableClass operator^(const BitwiseXorableClass&) const;
        BitwiseXorableClass& operator^=(float);
    };

    class BitwiseLShiftClass
    {
    public:
        BitwiseLShiftClass operator<<(const BitwiseLShiftClass&) const;
        BitwiseLShiftClass& operator<<=(float);
    };

    class BitwiseRShiftClass
    {
    public:
        BitwiseRShiftClass operator>>(const BitwiseRShiftClass&) const;
        BitwiseRShiftClass& operator>>=(float);
    };

    class DereferencableClass
    {
    public:
        DereferencableClass& operator*() const;
    };

    class AddressableClass
    {
    public:
        AddressableClass* operator&() const;
    };

    class UnaddressableClass
    {
    public:
        UnaddressableClass* operator&() const = delete;
    };
}   // namespace CottonTesting

TEST(TestTypeTraits, HasAddition)
{
    using CottonTesting::AddableClass;

    EXPECT_TRUE((Cotton::HasAddition<AddableClass&, const AddableClass&>));
    EXPECT_FALSE((Cotton::HasAddition<AddableClass&, float>));
}

TEST(TestTypeTraits, HasSubtraction)
{
    using CottonTesting::SubtractableClass;

    EXPECT_TRUE((Cotton::HasSubtraction<SubtractableClass&, const SubtractableClass&>));
    EXPECT_FALSE((Cotton::HasSubtraction<SubtractableClass&, float>));
}

TEST(TestTypeTraits, HasMultiplication)
{
    using CottonTesting::MultiplicatableClass;

    EXPECT_TRUE(
        (Cotton::HasMultiplication<MultiplicatableClass&, const MultiplicatableClass&>));
    EXPECT_FALSE((Cotton::HasMultiplication<MultiplicatableClass&, float>));
}

TEST(TestTypeTraits, HasDivision)
{
    using CottonTesting::DividableClass;

    EXPECT_TRUE((Cotton::HasDivision<DividableClass&, const DividableClass&>));
    EXPECT_FALSE((Cotton::HasDivision<DividableClass&, float>));
}

TEST(TestTypeTraits, HasModulo)
{
    using CottonTesting::ModableClass;

    EXPECT_TRUE((Cotton::HasModulo<ModableClass&, const ModableClass&>));
    EXPECT_FALSE((Cotton::HasModulo<ModableClass&, float>));
}

TEST(TestTypeTraits, HasAddAssign)
{
    using CottonTesting::AddableClass;

    EXPECT_FALSE((Cotton::HasAddAssign<AddableClass&, const AddableClass&>));
    EXPECT_TRUE((Cotton::HasAddAssign<AddableClass&, float>));
}

TEST(TestTypeTraits, HasSubtractAssign)
{
    using CottonTesting::SubtractableClass;

    EXPECT_FALSE(
        (Cotton::HasSubtractAssign<SubtractableClass&, const SubtractableClass&>));
    EXPECT_TRUE((Cotton::HasSubtractAssign<SubtractableClass&, float>));
}

TEST(TestTypeTraits, HasMultiplyAssign)
{
    using CottonTesting::MultiplicatableClass;

    EXPECT_FALSE(
        (Cotton::HasMultiplyAssign<MultiplicatableClass&, const MultiplicatableClass&>));
    EXPECT_TRUE((Cotton::HasMultiplyAssign<MultiplicatableClass&, float>));
}

TEST(TestTypeTraits, HasDivideAssign)
{
    using CottonTesting::DividableClass;

    EXPECT_FALSE((Cotton::HasDivideAssign<DividableClass&, const DividableClass&>));
    EXPECT_TRUE((Cotton::HasDivideAssign<DividableClass&, float>));
}

TEST(TestTypeTraits, HasModuloAssign)
{
    using CottonTesting::ModableClass;

    EXPECT_FALSE((Cotton::HasModuloAssign<ModableClass&, const ModableClass&>));
    EXPECT_TRUE((Cotton::HasModuloAssign<ModableClass&, float>));
}

TEST(TestTypeTraits, HasPreincrement)
{
    using CottonTesting::PreincrementableClass, CottonTesting::PostincrementableClass;

    EXPECT_TRUE(Cotton::HasPreincrement<PreincrementableClass&>);
    EXPECT_FALSE(Cotton::HasPreincrement<PostincrementableClass&>);
}

TEST(TestTypeTraits, HasPostincrement)
{
    using CottonTesting::PreincrementableClass, CottonTesting::PostincrementableClass;

    EXPECT_TRUE(Cotton::HasPostincrement<PostincrementableClass&>);
    EXPECT_FALSE(Cotton::HasPostincrement<PreincrementableClass&>);
}

TEST(TestTypeTraits, HasPredecrement)
{
    using CottonTesting::PredecrementableClass, CottonTesting::PostdecrementableClass;

    EXPECT_TRUE(Cotton::HasPredecrement<PredecrementableClass&>);
    EXPECT_FALSE(Cotton::HasPredecrement<PostdecrementableClass&>);
}

TEST(TestTypeTraits, HasPostdecrement)
{
    using CottonTesting::PredecrementableClass, CottonTesting::PostdecrementableClass;

    EXPECT_TRUE(Cotton::HasPostdecrement<PostdecrementableClass&>);
    EXPECT_FALSE(Cotton::HasPostdecrement<PredecrementableClass&>);
}

TEST(TestTypeTraits, HasEqual)
{
    using CottonTesting::ComparableEqClass;

    EXPECT_TRUE((Cotton::HasEqual<ComparableEqClass, ComparableEqClass>));
    EXPECT_FALSE((Cotton::HasEqual<ComparableEqClass, float>));
}

TEST(TestTypeTraits, HasNotEqual)
{
    using CottonTesting::ComparableEqClass;

    EXPECT_TRUE((Cotton::HasNotEqual<ComparableEqClass, float>));
    EXPECT_FALSE((Cotton::HasNotEqual<ComparableEqClass, ComparableEqClass>));
}

TEST(TestTypeTraits, HasGreater)
{
    using CottonTesting::ComparableGeClass;

    EXPECT_TRUE((Cotton::HasGreater<ComparableGeClass, ComparableGeClass>));
    EXPECT_FALSE((Cotton::HasGreater<ComparableGeClass, float>));
}

TEST(TestTypeTraits, HasGreaterEqual)
{
    using CottonTesting::ComparableGeClass;

    EXPECT_TRUE((Cotton::HasGreaterEqual<ComparableGeClass, float>));
    EXPECT_FALSE((Cotton::HasGreaterEqual<ComparableGeClass, ComparableGeClass>));
}

TEST(TestTypeTraits, HasLess)
{
    using CottonTesting::ComparableLeClass;

    EXPECT_TRUE((Cotton::HasLess<ComparableLeClass, ComparableLeClass>));
    EXPECT_FALSE((Cotton::HasLess<ComparableLeClass, float>));
}

TEST(TestTypeTraits, HasLessEqual)
{
    using CottonTesting::ComparableLeClass;

    EXPECT_TRUE((Cotton::HasLessEqual<ComparableLeClass, float>));
    EXPECT_FALSE((Cotton::HasLessEqual<ComparableLeClass, ComparableLeClass>));
}

TEST(TestTypeTraits, HasNegation)
{
    using CottonTesting::NegatableClass, CottonTesting::EmptyClass;

    EXPECT_TRUE((Cotton::HasNegation<NegatableClass>));
    EXPECT_FALSE((Cotton::HasNegation<EmptyClass>));
}

TEST(TestTypeTraits, HasAnd)
{
    using CottonTesting::AndableClass;

    EXPECT_TRUE((Cotton::HasAnd<AndableClass, AndableClass>));
    EXPECT_FALSE((Cotton::HasAnd<AndableClass, float>));
}

TEST(TestTypeTraits, HasOr)
{
    using CottonTesting::OrableClass;

    EXPECT_TRUE((Cotton::HasOr<OrableClass, OrableClass>));
    EXPECT_FALSE((Cotton::HasOr<OrableClass, float>));
}

TEST(TestTypeTraits, HasBitwiseNot)
{
    using CottonTesting::BitwiseNotableClass, CottonTesting::EmptyClass;

    EXPECT_TRUE((Cotton::HasBitwiseNot<BitwiseNotableClass>));
    EXPECT_FALSE((Cotton::HasBitwiseNot<EmptyClass>));
}

TEST(TestTypeTraits, HasBitwiseAnd)
{
    using CottonTesting::BitwiseAndableClass;

    EXPECT_TRUE((Cotton::HasBitwiseAnd<BitwiseAndableClass, BitwiseAndableClass>));
    EXPECT_FALSE((Cotton::HasBitwiseAnd<BitwiseAndableClass, float>));
}

TEST(TestTypeTraits, HasBitwiseOr)
{
    using CottonTesting::BitwiseOrableClass;

    EXPECT_TRUE((Cotton::HasBitwiseOr<BitwiseOrableClass, BitwiseOrableClass>));
    EXPECT_FALSE((Cotton::HasBitwiseOr<BitwiseOrableClass, float>));
}

TEST(TestTypeTraits, HasBitwiseXor)
{
    using CottonTesting::BitwiseXorableClass;

    EXPECT_TRUE((Cotton::HasBitwiseXor<BitwiseXorableClass, BitwiseXorableClass>));
    EXPECT_FALSE((Cotton::HasBitwiseXor<BitwiseXorableClass, float>));
}

TEST(TestTypeTraits, HasLeftShift)
{
    using CottonTesting::BitwiseLShiftClass;

    EXPECT_TRUE((Cotton::HasLeftShift<BitwiseLShiftClass, BitwiseLShiftClass>));
    EXPECT_FALSE((Cotton::HasLeftShift<BitwiseLShiftClass, float>));
}

TEST(TestTypeTraits, HasRightShift)
{
    using CottonTesting::BitwiseRShiftClass;

    EXPECT_TRUE((Cotton::HasRightShift<BitwiseRShiftClass, BitwiseRShiftClass>));
    EXPECT_FALSE((Cotton::HasRightShift<BitwiseRShiftClass, float>));
}

TEST(TestTypeTraits, HasBitwiseAndAssign)
{
    using CottonTesting::BitwiseAndableClass;

    EXPECT_TRUE((Cotton::HasBitwiseAndAssign<BitwiseAndableClass, float>));
    EXPECT_FALSE((Cotton::HasBitwiseAndAssign<BitwiseAndableClass, BitwiseAndableClass>));
}

TEST(TestTypeTraits, HasBitwiseOrAssign)
{
    using CottonTesting::BitwiseOrableClass;

    EXPECT_TRUE((Cotton::HasBitwiseOrAssign<BitwiseOrableClass, float>));
    EXPECT_FALSE((Cotton::HasBitwiseOrAssign<BitwiseOrableClass, BitwiseOrableClass>));
}

TEST(TestTypeTraits, HasBitwiseXorAssign)
{
    using CottonTesting::BitwiseXorableClass;

    EXPECT_TRUE((Cotton::HasBitwiseXorAssign<BitwiseXorableClass, float>));
    EXPECT_FALSE((Cotton::HasBitwiseXorAssign<BitwiseXorableClass, BitwiseXorableClass>));
}

TEST(TestTypeTraits, HasLeftShiftAssign)
{
    using CottonTesting::BitwiseLShiftClass;

    EXPECT_TRUE((Cotton::HasLeftShiftAssign<BitwiseLShiftClass, float>));
    EXPECT_FALSE((Cotton::HasLeftShiftAssign<BitwiseLShiftClass, BitwiseLShiftClass>));
}

TEST(TestTypeTraits, HasRightShiftAssign)
{
    using CottonTesting::BitwiseRShiftClass;

    EXPECT_TRUE((Cotton::HasRightShiftAssign<BitwiseRShiftClass, float>));
    EXPECT_FALSE((Cotton::HasRightShiftAssign<BitwiseRShiftClass, BitwiseRShiftClass>));
}

TEST(TestTypeTraits, HasDereference)
{
    using CottonTesting::DereferencableClass, CottonTesting::EmptyClass;

    EXPECT_TRUE(Cotton::HasDereference<DereferencableClass>);
    EXPECT_FALSE(Cotton::HasDereference<EmptyClass>);
}

TEST(TestTypeTraits, HasAddress)
{
    using CottonTesting::AddressableClass, CottonTesting::UnaddressableClass;

    EXPECT_TRUE(Cotton::HasAddress<AddressableClass>);
    EXPECT_FALSE(Cotton::HasAddress<UnaddressableClass>);
}
