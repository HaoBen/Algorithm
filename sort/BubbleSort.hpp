#include <vector>

/*
 * 冒泡排序的主要思想
 * 把待排序的向量，分成左右两部分，左边是无序的，右边是有序的
 * 每次从左边以冒泡的方式，将左边现存最大（小）的元素，移动到右边
 * 时间复杂度 O(n^2)
 */
/*
 * @description 冒泡排序
 * @param    
 */
template <typename T>
void BubbleSort(std::vector<T> &v)
{
    // 水平面的位置，冒泡的位置到此为止
    for (int plane = v.size() - 1; plane > 0; --plane)
    {
        //冒泡的过程
        for (int bubble = 0; bubble < plane; ++bubble)
        {
            //稳定排序，原先相等的元素，排序之后顺序不变
            if (v[bubble] > v[bubble+1])
            {
                std::swap(v[bubble], v[bubble+1]);
            }
        }
    }
}
