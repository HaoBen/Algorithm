#include "gtest/gtest.h"
#include "InsertSort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "common.hpp"
#include <vector>
#include <fstream>

#define SortTestHelper(n, SortFunc) \
    std::vector<int> v; \
    for (int i = 0; i < n; ++i) \
    { \
        v.push_back(i%1000); \
    } \
    RandomOrder<int>(v); \
    \
    auto begin = clock(); \
    SortFunc(v); \
    auto end = clock(); \
    printf("Cost For: [%lu ms] = [%lu us]\n", (end-begin)/1000, end-begin); \
    \
    for (int i = 0; i < v.size()-1; ++i) \
    { \
        ASSERT_LE(v[i], v[i+1]); \
    } \

TEST(Sort, InsertSort_1000)
{
    SortTestHelper(1000, InsertSort);
}

TEST(Sort, InsertSort_10000)
{
    SortTestHelper(10000, InsertSort)
}

TEST(Sort, BubbleSort_1000)
{
    SortTestHelper(1000, BubbleSort);
}

TEST(Sort, BubbleSort_10000)
{
    SortTestHelper(10000, BubbleSort);
}

TEST(Sort, QuickSort_1000)
{
    SortTestHelper(1000, QuickSort);
}

TEST(Sort, QuickSort_10000)
{
    SortTestHelper(10000, QuickSort);
}

TEST(Sort, QuickSort_100000)
{
    SortTestHelper(100000, QuickSort);
}

TEST(Sort, QuickSort_1000000)
{
    SortTestHelper(1000000, QuickSort);
}
