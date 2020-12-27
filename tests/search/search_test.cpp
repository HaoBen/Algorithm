#include <vector>

#include "search/violent_search.hpp"
#include "search/binary_search.hpp"
#include "catch2/catch.hpp"

TEST_CASE("for search tests", "[search]") {
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};

    SECTION("violent search tests") {
        CHECK(my::violent_search(vec.begin(), vec.end(), 1) == vec.begin());
        CHECK(my::violent_search(vec.begin(), vec.end(), 5) == vec.begin()+4);
        CHECK(my::violent_search(vec.begin(), vec.end(), 9) == vec.end()-1);
        CHECK(my::violent_search(vec.begin(), vec.end(), 10) == vec.end());
    }

    SECTION("binary search tests") {
        CHECK(my::binary_search(vec.begin(), vec.end(), 1) == vec.begin());
        CHECK(my::binary_search(vec.begin(), vec.end(), 5) == vec.begin()+4);
        CHECK(my::binary_search(vec.begin(), vec.end(), 9) == vec.end()-1);
        CHECK(my::binary_search(vec.begin(), vec.end(), 10) == vec.end());
    }
}