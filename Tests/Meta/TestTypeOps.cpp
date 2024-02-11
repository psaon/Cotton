#include <CottonTest.h>
#include <Cotton/Meta/TypeTraits.h>

namespace CottonTesting
{
    template<class... Args>
    class ConstructibleClass
    {
    public:
        ConstructibleClass(Args... args);
    };

    class DefaultConstructibleClass
    {
    public:
        DefaultConstructibleClass() { }
    };

    class CopyConstructibleClass
    {
    public:
        CopyConstructibleClass(const CopyConstructibleClass&) { }
        CopyConstructibleClass(CopyConstructibleClass&&) = delete;
    };

    class MoveConstructibleClass
    {
    public:
        MoveConstructibleClass(const MoveConstructibleClass&) { }
        MoveConstructibleClass(MoveConstructibleClass&&) { }
    };

    class DestructibleClass
    {
    public:
        ~DestructibleClass() { }
    };

    template<class T>
    class AssignableClass
    {
    public:
        AssignableClass& operator=(T) { }
    };

    class CopyAssignableClass
    {
    public:
        CopyAssignableClass& operator=(const CopyAssignableClass&) { return *this; }
    };

    class MoveAssignableClass
    {
    public:
        MoveAssignableClass& operator=(const MoveAssignableClass&) { return *this; }
        MoveAssignableClass& operator=(MoveAssignableClass&&) { return *this; }
    };

    class NonDefaultConstructibleClass
    {
    public:
        NonDefaultConstructibleClass() = delete;
    };

    class NonCopyConstructibleClass
    {
    public:
        NonCopyConstructibleClass(const NonCopyConstructibleClass&) = delete;
    };

    class NonMoveConstructibleClass
    {
    public:
        NonMoveConstructibleClass(NonMoveConstructibleClass&&) = delete;
    };

    class NonDestructibleClass
    {
    public:
        ~NonDestructibleClass() = delete;
    };

    class NonCopyAssignableClass
    {
    public:
        NonCopyAssignableClass& operator=(const NonCopyAssignableClass&) = delete;
    };

    class NonMoveAssignableClass
    {
    public:
        NonMoveAssignableClass& operator=(NonMoveAssignableClass&&) = delete;
    };

    class TrivialClass
    {
    public:
        TrivialClass() = default;
        TrivialClass(const TrivialClass&) = default;
        TrivialClass(TrivialClass&&) = default;

        ~TrivialClass() = default;

    public:
        TrivialClass& operator=(const TrivialClass&) = default;
        TrivialClass& operator=(TrivialClass&&) = default;
    };

    class VirtDestructor
    {
    public:
        virtual ~VirtDestructor() { }
    };
}   // namespace CottonTesting

TEST(TestTypeTraits, IsConstructible)
{
    using CottonTesting::ConstructibleClass;
    using FloatIntConst = ConstructibleClass<float, int>;

    EXPECT_TRUE((Cotton::IsConstructible<FloatIntConst, float, int>));
    EXPECT_TRUE((Cotton::IsConstructible<FloatIntConst, double, double>));
}

TEST(TestTypeTraits, IsTriviallyConstructible)
{
    using CottonTesting::TrivialClass, CottonTesting::DefaultConstructibleClass;

    EXPECT_TRUE(Cotton::IsTriviallyConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyConstructible<DefaultConstructibleClass>);
}

TEST(TestTypeTraits, IsDefaultConstructible)
{
    using CottonTesting::DefaultConstructibleClass,
        CottonTesting::NonDefaultConstructibleClass, CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsDefaultConstructible<DefaultConstructibleClass>);
    EXPECT_TRUE(Cotton::IsDefaultConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsDefaultConstructible<NonDefaultConstructibleClass>);
}

TEST(TestTypeTraits, IsTriviallyDefaultConstructible)
{
    using CottonTesting::DefaultConstructibleClass, CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsTriviallyDefaultConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyDefaultConstructible<DefaultConstructibleClass>);
}

TEST(TestTypeTraits, IsCopyConstructible)
{
    using CottonTesting::CopyConstructibleClass, CottonTesting::NonCopyConstructibleClass,
        CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsCopyConstructible<CopyConstructibleClass>);
    EXPECT_TRUE(Cotton::IsCopyConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsCopyConstructible<NonCopyConstructibleClass>);
}

TEST(TestTypeTraits, IsTriviallyCopyConstructible)
{
    using CottonTesting::CopyConstructibleClass, CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsTriviallyCopyConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyCopyConstructible<CopyConstructibleClass>);
}

TEST(TestTypeTraits, IsMoveConstructible)
{
    using CottonTesting::MoveConstructibleClass, CottonTesting::NonMoveConstructibleClass,
        CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsMoveConstructible<MoveConstructibleClass>);
    EXPECT_TRUE(Cotton::IsMoveConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsMoveConstructible<NonMoveConstructibleClass>);
}

TEST(TestTypeTraits, IsTriviallyMoveConstructible)
{
    using CottonTesting::MoveConstructibleClass, CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsTriviallyCopyConstructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyCopyConstructible<MoveConstructibleClass>);
}

TEST(TestTypeTraits, IsDestructible)
{
    using CottonTesting::DestructibleClass, CottonTesting::NonDestructibleClass,
        CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsDestructible<DestructibleClass>);
    EXPECT_TRUE(Cotton::IsDestructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsDestructible<NonDestructibleClass>);
}

TEST(TestTypeTraits, IsTrivallyDestructible)
{
    using CottonTesting::DestructibleClass, CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsTriviallyDestructible<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyDestructible<DestructibleClass>);
}

TEST(TestTypeTraits, IsAssignable)
{
    EXPECT_TRUE((Cotton::IsAssignable<std::string&, const char*>));
    EXPECT_FALSE((Cotton::IsAssignable<std::unique_ptr<float>&, float>));
}

TEST(TestTypeTraits, IsTriviallyAssignable)
{
    using CottonTesting::TrivialClass, CottonTesting::AssignableClass;

    EXPECT_TRUE((Cotton::IsTriviallyAssignable<TrivialClass&, const TrivialClass&>));
    EXPECT_FALSE((Cotton::IsTriviallyAssignable<AssignableClass<float>&, float>));
}

TEST(TestTypeTraits, IsCopyAssignable)
{
    using CottonTesting::CopyAssignableClass, CottonTesting::NonCopyAssignableClass,
        CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsCopyAssignable<CopyAssignableClass>);
    EXPECT_TRUE(Cotton::IsCopyAssignable<TrivialClass>);

    EXPECT_FALSE(Cotton::IsCopyAssignable<NonCopyAssignableClass>);
}

TEST(TestTypeTraits, IsTriviallyCopyAssignable)
{
    using CottonTesting::TrivialClass, CottonTesting::CopyAssignableClass;

    EXPECT_TRUE(Cotton::IsTriviallyCopyAssignable<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyCopyAssignable<CopyAssignableClass>);
}

TEST(TestTypeTraits, IsMoveAssignable)
{
    using CottonTesting::MoveAssignableClass, CottonTesting::NonMoveAssignableClass,
        CottonTesting::TrivialClass;

    EXPECT_TRUE(Cotton::IsMoveAssignable<MoveAssignableClass>);
    EXPECT_TRUE(Cotton::IsMoveAssignable<TrivialClass>);

    EXPECT_FALSE(Cotton::IsMoveAssignable<NonMoveAssignableClass>);
}

TEST(TestTypeTraits, IsTriviallyMoveAssignable)
{
    using CottonTesting::TrivialClass, CottonTesting::MoveAssignableClass;

    EXPECT_TRUE(Cotton::IsTriviallyMoveAssignable<TrivialClass>);
    EXPECT_FALSE(Cotton::IsTriviallyMoveAssignable<MoveAssignableClass>);
}

TEST(TestTypeTraits, HasVirtualDestructor)
{
    using CottonTesting::DestructibleClass, CottonTesting::NonDestructibleClass,
        CottonTesting::VirtDestructor;

    EXPECT_TRUE(Cotton::HasVirtualDestructor<VirtDestructor>);
    EXPECT_FALSE(Cotton::HasVirtualDestructor<DestructibleClass>);
    EXPECT_FALSE(Cotton::HasVirtualDestructor<NonDestructibleClass>);
}
