#include <vector>
/*
 * 归并排序
 *
 * 归并排序的基本思想是，把待排序向量分成左右两部分，先对两部分进行分别排序，保证两部分都是有序的，然后将两部分合并为一部分（这个过程只需要遍历一遍即可完成）。
 * 归并排序也是分治思想的一种体现
 *
 * 常用的是二路归并，三路归并等
 *
 * 其时间复杂度是O(nlgn)
 */

/*
 * 归并过程(原地归并)
 *
 * 原地归并的基本思想是，内存块交换
 */
template <class T>
void Merge(std::vector<T> &v, int from, int mid, int to)
{
    int left_anchor = from;
    int right_anchor = mid;
    int flag_anchor = mid;

    // swap [l,m),[m,r)
    auto SwapRange = [&v] (int l, int m, int r)
    {
        for (int i = 0; i < r-m; ++i)
        {
            auto tmp = v[m+i];
            for (int j = 0; j < m-l; ++j)
            {

            }
            ++l;
        }
    };

    /*
     * 所以我们主要需要做的就是
     * 找到满足条件的left_anchor,right_anchor,flag_anchor，然后交换left_anchor~flag_anchor和flag_anchor~right_anchor，左闭右开的内存块
     * 条件是V:right_anchor > V:left_anchor && V:[left_anchor~flag_anchor) > V:[flag_anchor~right_anchor)
     */
    while (left_anchor < right_anchor)
    {
        // 找到一个V:left_anchor > V:flag_anchor
        while (left_anchor < right_anchor && v[left_anchor] <= v[flag_anchor]) ++left_anchor;
        // 找到一个V:right_anchor > V:left_anchor
        // 这样就能保证V:[left_anchor~flag_anchor) > V:[flag_anchor~right_anchor)
        while (right_anchor <= to && v[right_anchor] <= v[left_anchor]) ++right_anchor;

        // 交换[left_anchor~flag_anchor)和[flag_anchor~right_anchor)之间的内存块

    }
}
