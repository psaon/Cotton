#include <CottonTest.h>
#include <Cotton/Utility/Swap.h>

TEST(TestSwap, Swap)
{
    int x = 2;
    int y = 5;

    Cotton::Swap(x, y);

    EXPECT_EQ(x, 5);
    EXPECT_EQ(y, 2);
}
