#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"

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
    
    Sort<int>* s = new InsertionSort<int>;
    s->show(a,0,10);
    s->sort(a,0,10);
    s->show(a,0,10);
    delete s;
}
