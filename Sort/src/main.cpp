#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bubbleSort.h"

using namespace std;

int main() {
    /*
        produce a random array
    */
    int a[10];
    srand(time(0));
    for(size_t i = 0; i < 10; i++)
    {
        a[i] = rand() % 100;
    }
    
    BubbleSort<int> bsort;
    bsort.show(a,0,10);
    bsort.sort(a,0,10);
    bsort.show(a,0,10);
}
