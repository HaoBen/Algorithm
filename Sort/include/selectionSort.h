#ifndef SELECTION_H
#define SELECTION_H

#include "sort.h"

//选择排序算法类

template <typename T>
class SelectionSort : public Sort<T> {
public:
    void sort(T a[],int start,int end);
};

template <typename T>
void SelectionSort<T>::sort(T a[],int start,int end) {
    while(start < end) {
        int min = start;
        for(int i = start;i < end;++i) {
            if(a[i] < a[min]) min = i;
        }
        this->swap(a[min],a[start++]);
    }
}
#endif