#include <CottonTest.h>
#include <Cotton/Debug/SourceLocation.h>

namespace CottonTesting
{
    const char* TestSourceLocFunction()
    {
        Cotton::SourceLocation loc;
        return loc.FunctionName();
    }
}   // namespace CottonTesting

TEST(TestSourceLocation, Line)
{
    Cotton::SourceLocation loc;
    EXPECT_EQ(loc.Line(), __LINE__ - 1);
}

TEST(TestSourceLocation, File)
{
    Cotton::SourceLocation loc;
    EXPECT_STREQ(loc.FileName(), __FILE__);
}
