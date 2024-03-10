#include <type_traits>
#include <gtest/gtest.h>

#define EXPECT_TYPE_EQ(tp1, tp2)                                           \
    GTEST_ASSERT_((CottonTesting::TestTypeEquality<tp1, tp2>(#tp1, #tp2)), \
                  GTEST_NONFATAL_FAILURE_)

#define EXPECT_NULL(val) EXPECT_EQ((val), nullptr)
#define EXPECT_ZERO(val) EXPECT_EQ((val), 0)
#define EXPECT_NZ(val)   EXPECT_NE((val), 0)

namespace CottonTesting
{
    class ExampleClass
    {
    };

    using EmptyClass = ExampleClass;

    union ExampleUnion
    {
    };

    enum ExampleEnum : short
    {
        ExampleMember
    };

    enum class ExampleScopedEnum : long
    {
        ExampleMember
    };

    template<class T, class U>
    ::testing::AssertionResult TestTypeEquality(const char* tp1, const char* tp2)
    {
        if constexpr (std::is_same_v<T, U>)
            return ::testing::AssertionSuccess();

        return ::testing::AssertionFailure() << "Types are not equal.\n"
                                                "Type 1: "
                                             << tp1
                                             << "\n"
                                                "Type 2: "
                                             << tp2;
    }
}   // namespace CottonTesting
