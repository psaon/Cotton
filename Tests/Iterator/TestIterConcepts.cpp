#include <CottonTest.h>
#include <Cotton/Iterator/IterConcepts.h>

#include <list>
#include <vector>
#include <forward_list>

TEST(TestIterConcepts, ForwardIterator)
{
    EXPECT_TRUE(Cotton::ForwardIterator<std::forward_list<int>::iterator>);
    EXPECT_TRUE(Cotton::ForwardIterator<std::list<float>::const_iterator>);
    EXPECT_TRUE(Cotton::ForwardIterator<std::vector<float>::reverse_iterator>);
}

TEST(TestIterConcepts, BidirectionalIterator)
{
    EXPECT_FALSE(Cotton::BidirectionalIterator<std::forward_list<int>::iterator>);
    EXPECT_TRUE(Cotton::BidirectionalIterator<std::list<float>::const_iterator>);
    EXPECT_TRUE(Cotton::BidirectionalIterator<std::vector<float>::reverse_iterator>);
}

TEST(TestIterConcepts, RandomAccessIterator)
{
    EXPECT_FALSE(Cotton::RandomAccessIterator<std::forward_list<int>::iterator>);
    EXPECT_FALSE(Cotton::RandomAccessIterator<std::list<float>::reverse_iterator>);
    EXPECT_TRUE(Cotton::RandomAccessIterator<std::vector<float>::const_reverse_iterator>);
}
