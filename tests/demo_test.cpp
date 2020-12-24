#include "catch2/catch.hpp"

TEST_CASE("this demonstrates how the tests work", "[demo_test]") {
    CHECK(std::min(1,2) == 1);
    CHECK(std::max(1,2) == 2);

    REQUIRE(INT_MIN == (int)0x80000000);
}