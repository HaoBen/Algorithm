#include <iostream>
#include "selection.h"

using namespace std;


int main(int argc, char const *argv[])
{
    int a[] = {5,1,4,5,8,7,9,7,5};
    Selection<int> helper;
    helper.sort(a,0,9);
    helper.show(a,0,9);
    return 0;
}
