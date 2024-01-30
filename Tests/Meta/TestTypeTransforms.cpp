#include "CottonTest.h"
#include "Cotton/Meta/TypeTransforms.h"

TEST(TestTypeTransforms, AddConst)
{
    EXPECT_TYPE_EQ(Cotton::AddConst<int>, const int);
    EXPECT_TYPE_EQ(Cotton::AddConst<int*>, int* const);
    EXPECT_TYPE_EQ(Cotton::AddConst<float[]>, const float[]);
}

TEST(TestTypeTransforms, AddVolatile)
{
    EXPECT_TYPE_EQ(Cotton::AddVolatile<int>, volatile int);
    EXPECT_TYPE_EQ(Cotton::AddVolatile<short*>, short* volatile);
    EXPECT_TYPE_EQ(Cotton::AddVolatile<float[5]>, volatile float[5]);
}

TEST(TestTypeTransforms, AddConstVolatile)
{
    EXPECT_TYPE_EQ(Cotton::AddConstVolatile<int>, const volatile int);
    EXPECT_TYPE_EQ(Cotton::AddConstVolatile<long*>, long* const volatile);
    EXPECT_TYPE_EQ(Cotton::AddConstVolatile<char[3]>, const volatile char[3]);
}

TEST(TestTypeTransforms, RemoveConst)
{
    EXPECT_TYPE_EQ(Cotton::RemoveConst<int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveConst<const int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveConst<volatile int>, volatile int);
    EXPECT_TYPE_EQ(Cotton::RemoveConst<const volatile int>, volatile int);
}

TEST(TestTypeTransforms, RemoveVolatile)
{
    EXPECT_TYPE_EQ(Cotton::RemoveVolatile<int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveVolatile<const int>, const int);
    EXPECT_TYPE_EQ(Cotton::RemoveVolatile<volatile int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveVolatile<const volatile int>, const int);
}

TEST(TestTypeTransforms, RemoveConstVolatile)
{
    EXPECT_TYPE_EQ(Cotton::RemoveConstVolatile<int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveConstVolatile<const int>, const int);
    EXPECT_TYPE_EQ(Cotton::RemoveConstVolatile<volatile int>, volatile int);
    EXPECT_TYPE_EQ(Cotton::RemoveConstVolatile<const volatile int>, int);
}

TEST(TestTypeTransforms, RemoveQualifiers)
{
    EXPECT_TYPE_EQ(Cotton::RemoveQualifiers<int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveQualifiers<const int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveQualifiers<volatile int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveQualifiers<const volatile int>, int);
}

TEST(TestTypeTransforms, AddLvalueReference)
{
    EXPECT_TYPE_EQ(Cotton::AddLvalueReference<int>, int&);
    EXPECT_TYPE_EQ(Cotton::AddLvalueReference<int*>, int*&);

    EXPECT_TYPE_EQ(Cotton::AddLvalueReference<void>, void);
    EXPECT_TYPE_EQ(Cotton::AddLvalueReference<const void>, const void);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<volatile void>, volatile void);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<const volatile void>, const volatile void);

    EXPECT_TYPE_EQ(Cotton::AddLvalueReference<int&>, int&);
    EXPECT_TYPE_EQ(Cotton::AddLvalueReference<int&&>, int&);
}

TEST(TestTypeTransforms, AddRvalueReference)
{
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<int>, int&&);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<int*>, int*&&);

    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<void>, void);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<const void>, const void);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<volatile void>, volatile void);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<const volatile void>, const volatile void);

    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<int&>, int&);
    EXPECT_TYPE_EQ(Cotton::AddRvalueReference<int&&>, int&&);
}

TEST(TestTypeTransforms, RemoveReference)
{
    EXPECT_TYPE_EQ(Cotton::RemoveReference<const int>, const int);
    EXPECT_TYPE_EQ(Cotton::RemoveReference<volatile int&>, volatile int);
    EXPECT_TYPE_EQ(Cotton::RemoveReference<const int&&>, const int);

    EXPECT_TYPE_EQ(Cotton::RemoveReference<int* const&&>, int* const);
}

TEST(TestTypeTransforms, MakeSigned)
{
    EXPECT_TYPE_EQ(Cotton::MakeSigned<signed char>, signed char);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<short>, signed short);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<int>, signed int);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<long>, signed long);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<long long>, signed long long);

    EXPECT_TYPE_EQ(Cotton::MakeSigned<unsigned char>, signed char);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<unsigned short>, signed short);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<unsigned int>, signed int);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<unsigned long>, signed long);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<unsigned long long>, signed long long);

    EXPECT_TYPE_EQ(Cotton::MakeSigned<char>, Cotton::Int8);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<char8_t>, Cotton::Int8);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<char16_t>, Cotton::Int16);
    EXPECT_TYPE_EQ(Cotton::MakeSigned<char32_t>, Cotton::Int32);
}

TEST(TestTypeTransforms, MakeUnsigned)
{
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<signed char>, unsigned char);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<short>, unsigned short);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<int>, unsigned int);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<long>, unsigned long);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<long long>, unsigned long long);

    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<unsigned char>, unsigned char);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<unsigned short>, unsigned short);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<unsigned int>, unsigned int);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<unsigned long>, unsigned long);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<unsigned long long>, unsigned long long);

    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<char>, Cotton::Uint8);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<char8_t>, Cotton::Uint8);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<char16_t>, Cotton::Uint16);
    EXPECT_TYPE_EQ(Cotton::MakeUnsigned<char32_t>, Cotton::Uint32);
}

TEST(TestTypeTransforms, RemoveExtent)
{
    EXPECT_TYPE_EQ(Cotton::RemoveExtent<int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveExtent<int[]>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveExtent<int[5]>, int);

    EXPECT_TYPE_EQ(Cotton::RemoveExtent<int[5][6]>, int[6]);
    EXPECT_TYPE_EQ(Cotton::RemoveExtent<int[][5]>, int[5]);
}

TEST(TestTypeTransforms, RemoveAllExtents)
{
    EXPECT_TYPE_EQ(Cotton::RemoveAllExtents<int>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveAllExtents<int[]>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveAllExtents<int[5]>, int);

    EXPECT_TYPE_EQ(Cotton::RemoveAllExtents<int[5][6]>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveAllExtents<int[][5]>, int);
}

TEST(TestTypeTransforms, AddPointer)
{
    EXPECT_TYPE_EQ(Cotton::AddPointer<int>, int*);
    EXPECT_TYPE_EQ(Cotton::AddPointer<float* const>, float* const*);

    EXPECT_TYPE_EQ(Cotton::AddPointer<int&>, int*);
    EXPECT_TYPE_EQ(Cotton::AddPointer<int&&>, int*);
}

TEST(TestTypeTransforms, RemovePointer)
{
    EXPECT_TYPE_EQ(Cotton::RemovePointer<int*>, int);
    EXPECT_TYPE_EQ(Cotton::RemovePointer<int**>, int*);
    EXPECT_TYPE_EQ(Cotton::RemovePointer<int*&>, int*&);
    EXPECT_TYPE_EQ(Cotton::RemovePointer<int&>, int&);
}

TEST(TestTypeTransforms, RemoveAllPointers)
{
    EXPECT_TYPE_EQ(Cotton::RemoveAllPointers<int*>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveAllPointers<int**>, int);
    EXPECT_TYPE_EQ(Cotton::RemoveAllPointers<int*&>, int*&);
    EXPECT_TYPE_EQ(Cotton::RemoveAllPointers<int&>, int&);
}
