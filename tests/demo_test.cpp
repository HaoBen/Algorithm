#include "catch2/catch.hpp"

bool inc_order(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size()-1; ++i) {
        if (vec[i] > vec[i+1]) return false;
    }
    return true;
}
bool dec_order(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size()-1; ++i) {
        if (vec[i] < vec[i+1]) return false;
    }
    return true;
}

TEST_CASE("std sort", "[sort]") {
    std::vector<int> vec = { 1, 3, 2, 4, 5, 6, 7, 8, 9, 0 };

    SECTION("sort inc") {
        std::sort(vec.begin(), vec.end());
        REQUIRE(inc_order(vec));
    }

    SECTION("sort dec") {
        std::sort(vec.begin(), vec.end(), [](int l, int r) { return !(l < r); });
        REQUIRE(dec_order(vec));
    }
}