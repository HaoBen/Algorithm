#ifndef BUBBLE_H
#define BUBBLE_H

#include "common.h"

//class for BubbleSort
template <typename T>
class Bubble : public Sort<T> {
public:
    void sort(T a[],int start,int end);
};

template <typename T>
void Bubble<T>::sort(T a[],int start,int end) {
    bool flag;
    for(end--;end > start;--end) {
        flag = true;
        for(int i = start;i < end;++i) {
            if(a[i+1]<a[i]) {
                Sort<T>::swap(a,i,i+1);
                flag = false;
            }
        }
        if(flag) break;
    }
}

#endif