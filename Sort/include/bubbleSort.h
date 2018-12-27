#ifndef BUBBLESORT_H
#define BUBBLESORT_H

/*
* 冒泡排序算法类
*/
#include "sort.h"

template <typename T>
class BubbleSort : public Sort<T> {
public:
    void sort(T a[],int start,int end);
};

template <typename T>
void BubbleSort<T>::sort(T a[],int start,int end) {
    while(--end > start) {
        bool flag = true;
        for(int i = start; i < end; i++)
        {
            if(a[i] > a[i+1]) {
                this->swap(a[i],a[i+1]);
                flag = false;
            }
        }
        if(flag) break;
    }
}
#endif