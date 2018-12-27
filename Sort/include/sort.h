#ifndef SORT_H
#define SORT_H

/*
    base class for sort
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Sort
{
protected:
    void swap(T&a,T&b) {
        T tmp = a;
        a = b;
        b = tmp;    
    }
public:
    virtual ~Sort() {}
    virtual void sort(T a[],int start,int end) = 0;
    void show(T a[],int start,int end) {
        while(start < end) std::cout<<a[start++]<<" ";
        std::cout<<std::endl;
    }
    bool isSorted(T a[],int start,int end) {
        while(start < end-1) {
            if(a[start] > a[start+1]) return false;
        }
        return true;
    }
    static int sortCompare(Sort<T>* m1,Sort<T>* m2);
};

/*
** 用于比较两种不同的排序算法的性能
*/
template <typename T>
int Sort<T>::sortCompare(Sort<T>* m1,Sort<T>* m2) {
    T array1[10000];
    T array2[10000];
    srand(time(NULL));
    for(size_t i = 0;i < 10000;++i) {
        int tmp = rand() % 300;
        array1[i] = tmp;
        array2[i] = tmp;
    }

    time_t start1,end1,start2,end2;
    time(&start1);
    m1->sort(array1,0,10000);
    time(&end1);

    time(&start2);
    m2->sort(array2,0,10000);
    time(&end2);

    return ((end1-start1)-(end2-start2));
}
#endif