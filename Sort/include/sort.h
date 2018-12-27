#ifndef SORT_H
#define SORT_H

/*
    base class for sort
*/
#include <iostream>

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
};

#endif