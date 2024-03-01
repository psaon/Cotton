#include <CottonTest.h>
#include <Cotton/Utility/Exchange.h>

TEST(TestExchange, Exchange)
{
    int x = 5;
    int old_val = Cotton::Exchange(x, 52);

    EXPECT_EQ(x, 52);
    EXPECT_EQ(old_val, 5);
}
