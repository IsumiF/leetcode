#include <leetcode/4.hpp>
#include <catch2/catch.hpp>
#include <rapidcheck.h>

#include <vector>
#include <algorithm>

TEST_CASE("leetcode p4") {
    using namespace leetcode::p4;
    Solution solution;

    SECTION("simple examples") {
        REQUIRE(solution.findMedianSortedArraysNaive({900}, {5, 8, 10, 20}) == 10);
        REQUIRE(solution.findMedianSortedArraysNaive({3, 2}, {1, 4}) == 2.5);
        REQUIRE(solution.findMedianSortedArrays({900}, {5, 8, 10, 20}) == 10);
        REQUIRE(solution.findMedianSortedArrays({3, 2}, {1, 4}) == 2.5);
        REQUIRE(solution.findMedianSortedArrays({}, {1}) == 1);
        REQUIRE(solution.findMedianSortedArrays({1}, {0, 0, 0}) == 0);
        REQUIRE(solution.findMedianSortedArrays({0, 0}, {-1, -1, -1}) == -1);
        REQUIRE(solution.findMedianSortedArrays({-1, -1, 0}, {-2, 0, 0}) == -0.5);
        REQUIRE(solution.findMedianSortedArrays({-1, -1, -1}, {-1, 0, 0, 0, 0}) == -0.5);
        REQUIRE(solution.findMedianSortedArrays({0, 0, 0, 0}, {-2, -2, 1, 1}) == 0);
    }

    SECTION("always gives the same answer as direct method") {
        rc::check([&solution](const std::vector<int> &v1, const std::vector<int> &v2) {
            std::vector<int> v1Asc = v1;
            std::sort(v1Asc.begin(), v1Asc.end());
            std::vector<int> v2Asc = v2;
            std::sort(v2Asc.begin(), v2Asc.end());
            double actual = solution.findMedianSortedArrays(v1Asc, v2Asc);
            double expected = solution.findMedianSortedArraysNaive(v1Asc, v2Asc);
            RC_ASSERT(actual == expected);
        });
    }
}
