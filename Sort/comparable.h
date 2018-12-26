#ifndef CPMPARABLE_H
#define COMPARABLE_H

#include <iostream>

//This is an interface used to compare to data
class Comparable {
public:
    /*
    ** @param a  another to be compared
    ** @return int if(this<a),return -1;if(this == a) return 0;if(this>a) return 1;
    */
    virtual int compareTo(Comparable& a) = 0;
};

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
    virtual bool isSorted(T a[],int i,int j) = 0;
    void show(T a[],int i,int j) {
        while(i < j) {
            std::cout<<a[i++]<<" ";
        }
        std::cout<<std::endl;
    }
};
#endif