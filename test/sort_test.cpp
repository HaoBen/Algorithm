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
        v.push_back(i); \
    } \
    RandomOrder<int>(v); \
    \
    auto begin = clock(); \
    SortFunc(v); \
    auto end = clock(); \
    printf("Cost For: %lu ms\n", (end-begin)/1000); \
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

//TEST(Sort, QuickSort_1000)
//{
    //SortTestHelper(1000, QuickSort);
//}

//TEST(Sort, QuickSort_10000)
//{
    //std::ofstream("tmp.txt");
    //std::vector<int> v;
    //for (int i = 0; i < 10000; ++i)
    //{
        //v.push_back(i);
    //}
    //RandomOrder<int>(v);
    
    //auto begin = clock(); 
    //QuickSort(v); 
    //auto end = clock(); 
    //printf("Cost For: %lu ms\n", (end-begin)/1000); 
    
    //for (int i = 0; i < v.size()-1; ++i) 
    //{ 
        //ASSERT_LE(v[i], v[i+1]); 
    //} 
//}
TEST(Sort, QuickSort_Test)
{
    std::vector<int> v = {9,8,7,7,5,5,3,2,1};
    QuickSort(v);
    for (int i = 0; i < v.size()-1; ++i) 
    { 
        ASSERT_LE(v[i], v[i+1]); 
    } 
}
