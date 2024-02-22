#include <CottonTest.h>
#include <Cotton/Meta/IsConstantEvaluated.h>

TEST(TestIsConstantEvaluated, True)
{
    int y = 0;
    const int x = Cotton::IsConstantEvaluated() ? 0xC0DE : y;

    EXPECT_TRUE(x == 0xC0DE);
}

TEST(TestIsConstantEvaluated, False)
{
    int y = 0;
    const int x = Cotton::IsConstantEvaluated() ? y : 2;

    EXPECT_TRUE(x == 2);
}
