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
    for(int i = start;i < end;++i) {    //选择即将被插入的元素[start,end)
        if(a[i] <= a[start]) {      //插到起始位置
            int tmp = a[i];
            shift(a,start,i,1);
            a[start] = tmp;
        }
        else {
            for(int j = start;j < i;++j) {  //找到该元素的合适插入位置，并插入
                if(a[i] > a[j] && a[i] <= a[j+1]) { //将元素插到j位置后面
                    int tmp = a[i];
                    shift(a,j+1,i,1);
                    a[j+1] = tmp;
                }
            }
        }
    }
}

#endif