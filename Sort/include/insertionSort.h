#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sort.h"

//插入排序算法类
template <typename T>
class InsertionSort : public Sort<T> {
private:
    //把[start,end]中的元素向后移动n一个位置
    void shift(T a[],int start,int end,int n);
public:
    void sort(T a[],int,int);
};

template <typename T>
void InsertionSort<T>::shift(T a[],int start,int end,int n) {
    while(end >= start) {
        a[end+n] = a[end--];
    }
}

template <typename T>
void InsertionSort<T>::sort(T a[],int start,int end) {
    for(int i = start+1;i < end;++i) {    //选择即将被插入的元素[start,end)
        for (int j = start; j < i; ++j)
        {
            if (a[i] <= a[start] || (a[i] > a[j - 1] && a[i] <= a[j]))
            {
                int tmp = a[i];
                for (int k = i; k > j; --k)
                    a[k] = a[k - 1];
                a[j] = tmp;
                break;
            }
        }
    }
}

#endif
