#include "catch2/catch.hpp"

int binary_search(std::vector<int> &vec, int key) {
    if (vec.empty()) return -1;

    int left = 0, right = vec.size()-1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (vec[mid] == key) return mid;
        else if (vec[mid] > key) right = mid-1;
        else left = mid+1;
    }
    if (left > right) return -1;
    else return vec[left];
}

using std::vector;
TEST_CASE("binary search algorithm", "[search]") {
    SECTION("no duplicate numbers") {
        vector<int> vec = {1,2,3,4,5,6, /*no 7*/ 8,9,10};

        CHECK(binary_search(vec, 1) == 0);
        CHECK(binary_search(vec, 10) == 8);
        CHECK(binary_search(vec, 5) == 4);

        CHECK(binary_search(vec, 0) == -1);
        CHECK(binary_search(vec, 7) == -1);
        CHECK(binary_search(vec, 11) == -1);
    }
    SECTION("with duplicate numbers") {
        vector<int> vec = {1, 1, 2, 2, 3, 4, 5, 5};

        CHECK(vec[binary_search(vec, 1)] == 1);
        CHECK(vec[binary_search(vec, 2)] == 2);
        CHECK(vec[binary_search(vec, 3)] == 3);
        CHECK(vec[binary_search(vec, 4)] == 4);
        CHECK(vec[binary_search(vec, 5)] == 5);
        CHECK(binary_search(vec, 6) == -1);
    }
}