#include <leetcode/6.hpp>
#include <catch2/catch.hpp>


TEST_CASE("leetcode p6") {
    using namespace leetcode::p6;
    Solution solution;

    SECTION("examples") {
        REQUIRE(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
        REQUIRE(solution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
        REQUIRE(solution.convert("AB", 1) == "AB");
    }
}