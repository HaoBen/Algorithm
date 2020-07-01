#include <vector>

/*
 * @description 插入排序
 * @param v     待排序的向量
 * @param Cmp   比较大小的函数，int Cmp(a,b) a>b:+  a=b:0 a<b:-
 */
/*
 * 插入排序的基本思想
 * 把待排序的数组，分成左右两部分，左边是已经排序的部分，右边是未排序的地方
 * 每次把右边第一个元素取出来，在左边找到一个可以插入的位置,直到右边没有元素
 * 插入排序的复杂度是是O(n^2)
 */

template <typename T>
void InsertSort(std::vector<T> &v)
{
    for (int tobeInsert = 0; tobeInsert < v.size(); ++tobeInsert)
    {
        // 遍历找到一个可以插入的位置
        for (int i = 0; i < tobeInsert; ++i)
        {
            if (v[tobeInsert] < v[i])
            {
                auto insertItem = v[tobeInsert];
                for (int j = tobeInsert; j > i; --j)
                {
                    v[j] = v[j-1];
                }
                v[i] = insertItem;
            }
        }
    }
}
