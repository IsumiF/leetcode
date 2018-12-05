#include <leetcode/709.hpp>
#include <catch2/catch.hpp>

using namespace leetcode::p709;

TEST_CASE("leetcode 709") {
    Solution solution;

    SECTION("simple cases") {
        REQUIRE(solution.toLowerCase("").empty());
        REQUIRE(solution.toLowerCase("AbC") == "abc");
    }
}
