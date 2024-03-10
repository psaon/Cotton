#include <CottonTest.h>
#include <Cotton/String/CharTraits.h>

#include <string>

TEST(TestCharTraits, Length)
{
    EXPECT_EQ(Cotton::CharTraits<char>::Length(""), 0);
    EXPECT_EQ(Cotton::CharTraits<char>::Length("dsxadaefcnbvcrt2w3q46653"), 24);
}

TEST(TestCharTraits, Copy)
{
    char to[25];
    const char* from = "09jadakjnkjnKJNSskemrnse";

    Cotton::CharTraits<char>::Copy(to, from, 25);
    EXPECT_STREQ(to, from);
}

TEST(TestCharTraits, Equal)
{
    EXPECT_TRUE(Cotton::CharTraits<char>::Equal('c', 'c'));

    EXPECT_FALSE(Cotton::CharTraits<char>::Equal('f', 'g'));
    EXPECT_FALSE(Cotton::CharTraits<char>::Equal('C', 'c'));
}

TEST(TestCharTraits, LessThan)
{
    EXPECT_TRUE(Cotton::CharTraits<char>::LessThan('*', '0'));    // 42 (*) < 48 (0)
    EXPECT_FALSE(Cotton::CharTraits<char>::LessThan('@', '?'));   // 64 (@) < 63 (?)
}

TEST(TestCharTraits, Compare)
{
    EXPECT_ZERO(Cotton::CharTraits<char>::Compare("Hello!", "Hello!", 6));
    EXPECT_ZERO(Cotton::CharTraits<char>::Compare("Hello! palw", "Hello! aasda", 7));

    EXPECT_GE(Cotton::CharTraits<char>::Compare("Hello! palw", "Hello! aasd", 11), 0);
    EXPECT_LE(Cotton::CharTraits<char>::Compare("dqsasasd", "fkjn,mnw", 8), 0);
}

TEST(TestCharTraits, Find)
{
    const char* string = "sfl sl;dnffffuwmerwef";
    const char* found = Cotton::CharTraits<char>::Find(string, 21, ' ');
    const char* not_found = Cotton::CharTraits<char>::Find(string, 21, 'x');

    EXPECT_NULL(not_found);
    EXPECT_EQ(found, string + 3);
}

TEST(TestWideCharTraits, Length)
{
    EXPECT_EQ(Cotton::CharTraits<wchar_t>::Length(L""), 0);
    EXPECT_EQ(Cotton::CharTraits<wchar_t>::Length(L"dsxadaefcnbvcrt2w3q46653"), 24);
}

TEST(TestWideCharTraits, Copy)
{
    wchar_t to[25];
    const wchar_t* from = L"09jadakjnkjnKJNSskemrnse";

    Cotton::CharTraits<wchar_t>::Copy(to, from, 25);
    EXPECT_STREQ(to, from);
}

TEST(TestWideCharTraits, Equal)
{
    EXPECT_TRUE(Cotton::CharTraits<wchar_t>::Equal(L'c', L'c'));

    EXPECT_FALSE(Cotton::CharTraits<wchar_t>::Equal(L'f', L'g'));
    EXPECT_FALSE(Cotton::CharTraits<wchar_t>::Equal(L'C', L'c'));
}

TEST(TestWideCharTraits, Compare)
{
    EXPECT_ZERO(Cotton::CharTraits<wchar_t>::Compare(L"Hello!", L"Hello!", 6));
    EXPECT_ZERO(Cotton::CharTraits<wchar_t>::Compare(L"Hello! palw", L"Hello! aasda", 7));

    EXPECT_NZ(Cotton::CharTraits<wchar_t>::Compare(L"Hello! pal", L"Hello! aas", 10));
    EXPECT_NZ(Cotton::CharTraits<wchar_t>::Compare(L"dqsasasd", L"fkjn,mnw", 8));
}

TEST(TestWideCharTraits, Find)
{
    const wchar_t* string = L"sfl sl;dnffffuwmerwef";
    const wchar_t* found = Cotton::CharTraits<wchar_t>::Find(string, 21, L' ');
    const wchar_t* not_found = Cotton::CharTraits<wchar_t>::Find(string, 21, L'x');

    EXPECT_NULL(not_found);
    EXPECT_EQ(found, string + 3);
}

TEST(TestUTF8CharTraits, Length)
{
    EXPECT_EQ(Cotton::CharTraits<char8_t>::Length(u8""), 0);
    EXPECT_EQ(Cotton::CharTraits<char8_t>::Length(u8"dsxadaefcnbvcrt2w3q46653"), 24);
}

TEST(TestUTF8CharTraits, Copy)
{
    char8_t to[25];
    const char8_t* from = u8"09jadakjnkjnKJNSskemrnse";

    Cotton::CharTraits<char8_t>::Copy(to, from, 25);
    EXPECT_ZERO(std::char_traits<char8_t>::compare(to, from, 25));
}

TEST(TestUTF8CharTraits, Equal)
{
    EXPECT_TRUE(Cotton::CharTraits<char8_t>::Equal(u8'c', u8'c'));

    EXPECT_FALSE(Cotton::CharTraits<char8_t>::Equal(u8'f', u8'g'));
    EXPECT_FALSE(Cotton::CharTraits<char8_t>::Equal(u8'C', u8'c'));
}

TEST(TestUTF8CharTraits, LessThan)
{
    EXPECT_TRUE(Cotton::CharTraits<char8_t>::LessThan(u8'*', u8'0'));   // 42 (*) < 48 (0)
    EXPECT_FALSE(
        Cotton::CharTraits<char8_t>::LessThan(u8'@', u8'?'));           // 64 (@) < 63 (?)
}

TEST(TestUTF8CharTraits, Compare)
{
    EXPECT_ZERO(Cotton::CharTraits<char8_t>::Compare(u8"Hello!", u8"Hello!", 6));
    EXPECT_ZERO(Cotton::CharTraits<char8_t>::Compare(u8"Hello! paw", u8"Hello! aaa", 7));

    EXPECT_GE(Cotton::CharTraits<char8_t>::Compare(u8"Hello! pal", u8"Hello! aas", 10),
              0);
    EXPECT_LE(Cotton::CharTraits<char8_t>::Compare(u8"dqsasasd", u8"fkjn,mnw", 8), 0);
}

TEST(TestUTF8CharTraits, Find)
{
    const char8_t* string = u8"sfl sl;dnffffuwmerwef";
    const char8_t* found = Cotton::CharTraits<char8_t>::Find(string, 21, u8' ');
    const char8_t* not_found = Cotton::CharTraits<char8_t>::Find(string, 21, u8'x');

    EXPECT_NULL(not_found);
    EXPECT_EQ(found, string + 3);
}

TEST(TestUTF16CharTraits, Length)
{
    EXPECT_EQ(Cotton::CharTraits<char16_t>::Length(u""), 0);
    EXPECT_EQ(Cotton::CharTraits<char16_t>::Length(u"dsxadaefcnbvcrt2w3q46653"), 24);
}

TEST(TestUTF16CharTraits, Copy)
{
    char16_t to[25];
    const char16_t* from = u"09jadakjnkjnKJNSskemrnse";

    Cotton::CharTraits<char16_t>::Copy(to, from, 25);
    EXPECT_ZERO(std::char_traits<char16_t>::compare(to, from, 25));
}

TEST(TestUTF16CharTraits, Equal)
{
    EXPECT_TRUE(Cotton::CharTraits<char16_t>::Equal(u'c', u'c'));

    EXPECT_FALSE(Cotton::CharTraits<char16_t>::Equal(u'f', u'g'));
    EXPECT_FALSE(Cotton::CharTraits<char16_t>::Equal(u'C', u'c'));
}

TEST(TestUTF16CharTraits, LessThan)
{
    EXPECT_TRUE(Cotton::CharTraits<char16_t>::LessThan(u'*', u'0'));
    EXPECT_FALSE(Cotton::CharTraits<char16_t>::LessThan(u'@', u'?'));
}

TEST(TestUTF16CharTraits, Compare)
{
    EXPECT_ZERO(Cotton::CharTraits<char16_t>::Compare(u"Hello!", u"Hello!", 6));
    EXPECT_ZERO(
        Cotton::CharTraits<char16_t>::Compare(u"Hello! palw", u"Hello! aasda", 7));

    EXPECT_GE(Cotton::CharTraits<char16_t>::Compare(u"Hello! pal", u"Hello! aas", 10), 0);
    EXPECT_LE(Cotton::CharTraits<char16_t>::Compare(u"dqsasasd", u"fkjn,mnw", 8), 0);
}

TEST(TestUTF16CharTraits, Find)
{
    const char16_t* string = u"sfl sl;dnffffuwmerwef";
    const char16_t* found = Cotton::CharTraits<char16_t>::Find(string, 21, u' ');
    const char16_t* not_found = Cotton::CharTraits<char16_t>::Find(string, 21, u'x');

    EXPECT_NULL(not_found);
    EXPECT_EQ(found, string + 3);
}

TEST(TestUTF32CharTraits, Length)
{
    EXPECT_EQ(Cotton::CharTraits<char32_t>::Length(U""), 0);
    EXPECT_EQ(Cotton::CharTraits<char32_t>::Length(U"dsxadaefcnbvcrt2w3q46653"), 24);
}

TEST(TestUTF32CharTraits, Copy)
{
    char32_t to[25];
    const char32_t* from = U"09jadakjnkjnKJNSskemrnse";

    Cotton::CharTraits<char32_t>::Copy(to, from, 25);
    EXPECT_ZERO(std::char_traits<char32_t>::compare(to, from, 25));
}

TEST(TestUTF32CharTraits, Equal)
{
    EXPECT_TRUE(Cotton::CharTraits<char32_t>::Equal(U'c', U'c'));

    EXPECT_FALSE(Cotton::CharTraits<char32_t>::Equal(U'f', U'g'));
    EXPECT_FALSE(Cotton::CharTraits<char32_t>::Equal(U'C', U'c'));
}

TEST(TestUTF32CharTraits, LessThan)
{
    EXPECT_TRUE(Cotton::CharTraits<char32_t>::LessThan(U'*', U'0'));
    EXPECT_FALSE(Cotton::CharTraits<char32_t>::LessThan(U'@', U'?'));
}

TEST(TestUTF32CharTraits, Compare)
{
    EXPECT_ZERO(Cotton::CharTraits<char32_t>::Compare(U"Hello!", U"Hello!", 6));
    EXPECT_ZERO(
        Cotton::CharTraits<char32_t>::Compare(U"Hello! palw", U"Hello! aasda", 7));

    EXPECT_GE(Cotton::CharTraits<char32_t>::Compare(U"Hello! pal", U"Hello! aas", 10), 0);
    EXPECT_LE(Cotton::CharTraits<char32_t>::Compare(U"dqsasasd", U"fkjn,mnw", 8), 0);
}

TEST(TestUTF32CharTraits, Find)
{
    const char32_t* string = U"sfl sl;dnffffuwmerwef";
    const char32_t* found = Cotton::CharTraits<char32_t>::Find(string, 21, U' ');
    const char32_t* not_found = Cotton::CharTraits<char32_t>::Find(string, 21, U'x');

    EXPECT_NULL(not_found);
    EXPECT_EQ(found, string + 3);
}
