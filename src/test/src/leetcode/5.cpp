#include <leetcode/5.hpp>
#include <catch2/catch.hpp>

using namespace leetcode::p5;

TEST_CASE("leetcode #5") {
    Solution solution;

    SECTION("given examples") {
        REQUIRE(solution.longestPalindrome("babad") == "bab");
        REQUIRE(solution.longestPalindrome("cbbd") == "bb");
    }
    SECTION("other cases") {
        REQUIRE(solution.longestPalindrome("").empty());
    }
}
