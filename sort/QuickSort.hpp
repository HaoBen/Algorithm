#include "common.hpp"
#include <vector>
#include <cstdio>
/*
 * 快速排序算法简要介绍
 * 快速排序算法是分治思想的一种应用
 * 我们从待排序向量中选一个做关键字（一般选第一个），然后分别从向量的左右两端向中间推进
 *   比如升序排列的时候，如果从左边找到了一个大于关键字的，就把这个值和右边的锚点进行交换
 *                       如果从右边找到了一个小于等于关键字的，就把这个值和左边的锚点进行交换
 * 一轮下来之后，我们就能保证我们正在排序的这个向量在最终锚点左边的都小于等于关键字，在最终锚点右边的都大于等于关键字，然后我们可以分别对左右两个向量再进行快速排序，最终保证整个向量都是有序的。
 * 快速排序的时间复杂度是O(nlog{2}n)
 */

/*
 * @description  快速排序
 * @param v 待排序向量
 */
template <class Iter>
void SortHelper(Iter from, Iter to)
{
    auto left_anchor = from;
    auto right_anchor = to-1;
    if (left_anchor >= right_anchor) return;
    auto key = *from;  // 去最左边的元素作为关键字

#ifdef _DEBUG_PRINT
    printf("before: ");
    PrintRange(from, to-1);
#endif

    while (left_anchor != right_anchor)
    {
        // 从右边开始，找到一个可以放到左边锚点的元素
        while (right_anchor != left_anchor && *right_anchor > key) --right_anchor;
        if (right_anchor > left_anchor) *left_anchor++ = *right_anchor;

        // 然后从左边找到一个可以放到右边锚点的元素
        while (left_anchor != right_anchor && *left_anchor < key) ++left_anchor;
        if (left_anchor < right_anchor) *right_anchor-- = *left_anchor;
    }
    
    // 两个锚点相撞了，将重心锚点位置的值置为关键字
    *left_anchor = key;

#ifdef _DEBUG_PRINT
    printf(" after[%ld]: ", left_anchor-from);
    PrintRange(from, to-1);
#endif

    // 对左右两部分再分别排序
    SortHelper(from, left_anchor);
    SortHelper(left_anchor+1, to);
}

template <typename T>
void QuickSort(std::vector<T> &v)
{
    SortHelper(v.begin(), v.end());      
}
