#include <leetcode/4.hpp>
#include <algorithm>
#include <tuple>
#include <cstdint>
#include <stdexcept>

namespace {

template<typename RandIt>
std::tuple<double, RandIt, RandIt> medianOf(RandIt beg, RandIt end) {
    if (beg == end) {
        return std::make_tuple(0, beg, end);
    }

    if ((end - beg) % 2 == 0) {
        size_t i = (end - beg) / 2 - 1;
        double value = ((double) beg[i] + (double) beg[i + 1]) / 2;
        return std::make_tuple(value, beg + i, beg + i + 2);
    } else {
        size_t i = (end - beg) / 2;
        double value = beg[i];
        return std::make_tuple(value, beg + i, beg + i + 1);
    }
}

}

namespace leetcode {
namespace p4 {

double Solution::findMedianSortedArrays(const std::vector<int> &xs, const std::vector<int> &ys) {
    auto xBeg = xs.cbegin();
    auto xEnd = xs.cend();
    auto yBeg = ys.cbegin();
    auto yEnd = ys.cend();

    while (true) {
        if (yEnd - yBeg < xEnd - xBeg) {
            std::swap(xBeg, yBeg);
            std::swap(xEnd, yEnd);
        }

        std::ptrdiff_t n = xEnd - xBeg;
        std::ptrdiff_t m = yEnd - yBeg;
        if (n <= 2) {
            if (n == 0) {
                return std::get<0>(medianOf(yBeg, yEnd));
            } else if (n == 1) {
                if (m == 1) {
                    return static_cast<double>(*xBeg + *yBeg) / 2;
                } else if (m % 2 == 0) { // m is even
                    int x = *xBeg;
                    int y1 = yBeg[m / 2 - 1];
                    int y2 = yBeg[m / 2];
                    if (x < y1) {
                        return y1;
                    } else if (x < y2) {
                        return x;
                    } else {
                        return y2;
                    }
                } else { // m is odd
                    int x = *xBeg;
                    double y0 = yBeg[m / 2 - 1];
                    double y1 = yBeg[m / 2];
                    double y2 = yBeg[m / 2 + 1];
                    if (x < y0) {
                        return (y0 + y1) / 2;
                    } else if (x < y2) {
                        return (x + y1) / 2;
                    } else {
                        return (y1 + y2) / 2;
                    }
                }
            } else if (n == 2) {
                if (m == 2) {
                    std::array<int, 4> nums = {0};
                    std::copy(xBeg, xEnd, nums.begin());
                    std::copy(yBeg, yEnd, nums.begin() + 2);
                    std::sort(nums.begin(), nums.end());
                    return static_cast<double>(nums[1] + nums[2]) / 2;
                } else if (m % 2 == 0) { // m is even
                    std::array<int, 4> nums = {0};
                    nums[0] = yBeg[m / 2];
                    nums[1] = yBeg[m / 2 - 1];
                    nums[2] = std::max(xBeg[0], yBeg[m / 2 - 2]);
                    nums[3] = std::min(xBeg[1], yBeg[m / 2 + 1]);
                    std::sort(nums.begin(), nums.end());
                    return std::get<0>(medianOf(nums.cbegin(), nums.cend()));
                } else { // m is odd
                    std::array<int, 3> nums = {0};
                    nums[0] = yBeg[m / 2];
                    nums[1] = std::max(xBeg[0], yBeg[m / 2 - 1]);
                    nums[2] = std::min(xBeg[1], yBeg[m / 2 + 1]);
                    std::sort(nums.begin(), nums.end());
                    return std::get<0>(medianOf(nums.cbegin(), nums.cend()));
                }
            }
        } else {
            auto xMed = medianOf(xBeg, xEnd);
            auto yMed = medianOf(yBeg, yEnd);
            if (std::get<0>(xMed) > std::get<0>(yMed)) {
                auto xEndNew = std::get<2>(xMed);
                auto diff = xEnd - xEndNew;
                yBeg += diff;
                xEnd = xEndNew;
            } else if (std::get<0>(xMed) < std::get<0>(yMed)) {
                auto xBegNew = std::get<1>(xMed);
                auto diff = xBegNew - xBeg;
                yEnd -= diff;
                xBeg = xBegNew;
            } else {
                return std::get<0>(xMed);
            }
        }
    }

    throw std::logic_error("Impossible code path");
}

double Solution::findMedianSortedArraysNaive(
        std::vector<int> v1,
        const std::vector<int> &v2) {
    v1.insert(v1.end(), v2.cbegin(), v2.cend());
    std::sort(v1.begin(), v1.end());
    return std::get<0>(medianOf(v1.cbegin(), v1.cend()));
}

}
}
