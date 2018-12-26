#ifndef SELECTION_H
#define SELECTION_H

#include "comparable.h"

template <typename T>
class Selection : public Sort<T> {
public:
    void sort(T a[],int start,int end);
    bool isSorted(T a[],int start,int end) {}
};

template <typename T>
void Selection<T>::sort(T a[],int start,int end) {
    while(start < end) {
        int min = start;
        for(int i = start+1;i < end;++i) {
            if(a[i] < a[min]) min = i;
        }
        if(min != start) this->swap(a,min,start);
        ++start;
    }
}
#endif