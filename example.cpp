#include <iostream>
#include <vector>
#include "QuickSort.hpp"

using namespace std;

int main()
{
    std::vector<int> v = {9,8,7,6,5,4,3,2,1};
    //test1(v.begin(), v.end()-1);
    QuickSort(v);
}
