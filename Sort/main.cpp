#include <iostream>
#include "selection.h"
#include "bubble.h"

using namespace std;


int main(int argc, char const *argv[])
{
    int a[] = {0,5,2,5,8,7,2,3,8,4};
    Bubble<int> bsort;
    cout<<bsort.isSorted(a,0,10)<<endl;
    bsort.sort(a,0,10);
    bsort.show(a,0,10);
    return 0;
}
