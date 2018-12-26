#ifndef COMMON_H
#define COMMON_H

#include <iostream>

//This is an shared class for sort
template <typename T>
class Sort {
protected:
    void swap(T a[],int i,int j) {
        T tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
public:
    virtual void sort(T a[],int i,int j) = 0;
    bool isSorted(T a[],int i,int j) {
        while(i < j-1) {
            if(a[i] >= a[++i]) return false;
        }
        return true;
    }
    void show(T a[],int i,int j) {
        while(i < j) {
            std::cout<<a[i++]<<" ";
        }
        std::cout<<std::endl;
    }
};
#endif